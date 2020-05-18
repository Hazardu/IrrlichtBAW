#ifndef _IRR_EXT_TONE_MAPPER_C_TONE_MAPPER_INCLUDED_
#define _IRR_EXT_TONE_MAPPER_C_TONE_MAPPER_INCLUDED_

#include "irrlicht.h"
#include "../ext/LumaMeter/CLumaMeter.h"
#include "../ext/ToneMapper/CGLSLToneMappingBuiltinIncludeLoader.h"

namespace irr
{
namespace ext
{
namespace ToneMapper
{


class CToneMapper : public core::IReferenceCounted, public core::InterfaceUnmovable
{
    public:
		enum E_OPERATOR
		{
			EO_REINHARD,
			EO_ACES, // its not full ACES, its one particular ACES from Stephen Hill
			EO_COUNT,
		};
		//
		struct ParamsBase
		{
			inline void setAdaptationFactorFromFrameDelta(float frameDeltaSeconds, float upAdaptationPerSecondLog2=-0.5f, float downAdaptationPerSecondLog2=-0.1f)
			{
				float up = core::exp2(upAdaptationPerSecondLog2*frameDeltaSeconds);
				float down = core::exp2(downAdaptationPerSecondLog2*frameDeltaSeconds);

				upExposureAdaptationFactorAsHalf = core::Float16Compressor::compress(up);
				downExposureAdaptationFactorAsHalf = core::Float16Compressor::compress(down);
			}

			uint16_t lastFrameExtraEVAsHalf[2] = { 0u,0u };
		protected:
			// target+(current-target)*exp(-k*t) == mix(target,current,factor)
			uint16_t upExposureAdaptationFactorAsHalf = 0u;
			uint16_t downExposureAdaptationFactorAsHalf = 0u;
		};
		//
		template<E_OPERATOR _operator>
		struct Params_t;
		template<>
		struct alignas(16) Params_t<EO_REINHARD> : ParamsBase
		{
			Params_t(float EV, float key=0.18f, float WhitePointRelToEV=16.f)
			{
				keyAndLinearExposure = key*exp2(EV);
				rcpWhite2 = 1.f/(WhitePointRelToEV*WhitePointRelToEV);
			}

			float keyAndLinearExposure; // usually 0.18*exp2(exposure)
			float rcpWhite2; // the white is relative to post-exposed luma
		};
		template<>
		struct alignas(16) Params_t<EO_ACES> : ParamsBase
		{
			Params_t(float EV, float key=0.18f, float Contrast=1.f) : gamma(Contrast)
			{
				setExposure(EV,key);
			}

			inline void setExposure(float EV, float key=0.18f)
			{
				exposure = EV+log2(key);
			}

			float gamma; // 1.0
		private:
			float exposure; // actualExposure+midGrayLog2
		};

		//
		static void registerBuiltinGLSLIncludes(asset::IGLSLCompiler* compilerToAddBuiltinIncludeTo);

		//
		static inline core::SRange<const asset::SPushConstantRange> getDefaultPushConstantRanges(bool usingLumaMeter=false)
		{
			if (usingLumaMeter)
				return LumaMeter::CGLSLLumaBuiltinIncludeLoader::getDefaultPushConstantRanges();
			else
				return {nullptr,nullptr};
		}

		//
		static core::SRange<const video::IGPUDescriptorSetLayout::SBinding> getDefaultBindings(video::IVideoDriver* driver, bool usingLumaMeter=false);

		//
		static inline core::smart_refctd_ptr<video::IGPUPipelineLayout> getDefaultPipelineLayout(video::IVideoDriver* driver, bool usingLumaMeter=false)
		{
			auto pcRange = getDefaultPushConstantRanges(usingLumaMeter);
			auto bindings = getDefaultBindings(driver,usingLumaMeter);
			return driver->createGPUPipelineLayout(
				pcRange.begin(),pcRange.end(),
				driver->createGPUDescriptorSetLayout(bindings.begin(),bindings.end()),nullptr,nullptr,nullptr
			);
		}

		//
		template<E_OPERATOR _operator>
		static inline size_t getParameterBufferSize(
			bool usingLumaMeter=false,
			LumaMeter::CLumaMeter::E_METERING_MODE meterMode=LumaMeter::CLumaMeter::EMM_COUNT,
			uint32_t arrayLayers=1u
		)
		{
			size_t retval = sizeof(Params_t<_operator>);
			if (usingLumaMeter)
				retval += LumaMeter::CLumaMeter::getOutputBufferSize(meterMode,arrayLayers);
			return retval;
		}

		//
		_IRR_STATIC_INLINE_CONSTEXPR uint32_t MAX_DESCRIPTOR_COUNT = 4u;
		template<E_OPERATOR _operator>
		static inline void updateDescriptorSet(
			video::IVideoDriver* driver, video::IGPUDescriptorSet* set,
			core::smart_refctd_ptr<video::IGPUBuffer> inputParameterDescriptor, 
			core::smart_refctd_ptr<video::IGPUImageView> inputImageDescriptor,
			core::smart_refctd_ptr<video::IGPUImageView> outputImageDescriptor,
			uint32_t inputParameterBinding,
			uint32_t inputImageBinding,
			uint32_t outputImageBinding,
			core::smart_refctd_ptr<video::IGPUBuffer> lumaUniformsDescriptor=nullptr,
			uint32_t lumaUniformsBinding=0u,
			LumaMeter::CLumaMeter::E_METERING_MODE meterMode=LumaMeter::CLumaMeter::EMM_COUNT,
			bool usingTemporalAdaptation = false,
			uint32_t arrayLayers=1u
		)
		{
			video::IGPUDescriptorSet::SDescriptorInfo pInfos[MAX_DESCRIPTOR_COUNT];
			video::IGPUDescriptorSet::SWriteDescriptorSet pWrites[MAX_DESCRIPTOR_COUNT];
			for (auto i=0; i< MAX_DESCRIPTOR_COUNT; i++)
			{
				pWrites[i].dstSet = set;
				pWrites[i].arrayElement = 0u;
				pWrites[i].count = 1u;
				pWrites[i].info = pInfos+i;
			}
			
			pInfos[1].desc = inputParameterDescriptor;
			pInfos[1].buffer.size = getParameterBufferSize<_operator>(!!lumaUniformsDescriptor,meterMode,arrayLayers);
			pInfos[1].buffer.offset = 0u;
			pInfos[2].desc = inputImageDescriptor;
			pInfos[2].image.imageLayout = static_cast<asset::E_IMAGE_LAYOUT>(0u);
			pInfos[2].image.sampler = nullptr;

			uint32_t outputImageIx;
			if (lumaUniformsDescriptor)
			{
				outputImageIx = 3u;

				pInfos[0].desc = lumaUniformsDescriptor;
				pInfos[0].buffer.offset = 0u;
				switch (meterMode)
				{
					case LumaMeter::CLumaMeter::EMM_GEOM_MEAN:
					case LumaMeter::CLumaMeter::EMM_MODE:
					default:
						_IRR_DEBUG_BREAK_IF(true);
						break;
				}
				pInfos[0].buffer.size = sizeof(LumaMeter::CLumaMeter::Uniforms_t);

				pWrites[0].binding = lumaUniformsBinding;
				pWrites[0].descriptorType = asset::EDT_UNIFORM_BUFFER_DYNAMIC;
			}
			else
				outputImageIx = 0u;

			pInfos[outputImageIx].desc = outputImageDescriptor;
			pInfos[outputImageIx].image.imageLayout = static_cast<asset::E_IMAGE_LAYOUT>(0u);
			pInfos[outputImageIx].image.sampler = nullptr;


			pWrites[1].binding = inputParameterBinding;
			pWrites[1].descriptorType = asset::EDT_STORAGE_BUFFER_DYNAMIC;
			pWrites[2].binding = inputImageBinding;
			pWrites[2].descriptorType = asset::EDT_COMBINED_IMAGE_SAMPLER;
			pWrites[outputImageIx].binding = outputImageBinding;
			pWrites[outputImageIx].descriptorType = asset::EDT_STORAGE_IMAGE;

			driver->updateDescriptorSets(lumaUniformsDescriptor ? 4u:3u, pWrites, 0u, nullptr);
		}
		
		//
		static core::smart_refctd_ptr<asset::ICPUSpecializedShader> createShader(
			asset::IGLSLCompiler* compilerToAddBuiltinIncludeTo,
			const std::tuple<asset::E_FORMAT,asset::E_COLOR_PRIMARIES,asset::ELECTRO_OPTICAL_TRANSFER_FUNCTION>& inputColorSpace,
			const std::tuple<asset::E_FORMAT,asset::E_COLOR_PRIMARIES,asset::OPTICO_ELECTRICAL_TRANSFER_FUNCTION>& outputColorSpace,
			E_OPERATOR _operator,
			bool usingLumaMeter=false, LumaMeter::CLumaMeter::E_METERING_MODE meterMode=LumaMeter::CLumaMeter::EMM_COUNT, float minLuma=core::nan<float>(), float maxLuma=core::nan<float>(),
			bool usingTemporalAdaptation=false
		);

		//
		static inline core::smart_refctd_ptr<video::IGPUImageView> createViewForImage(
			video::IVideoDriver* driver, bool usedAsInput,
			core::smart_refctd_ptr<video::IGPUImage>&& image,
			const asset::IImage::SSubresourceRange& subresource
		)
		{
			if (!driver || !image)
				return nullptr;

			auto nativeFormat = image->getCreationParameters().format;

			video::IGPUImageView::SCreationParams params;
			params.flags = static_cast<video::IGPUImageView::E_CREATE_FLAGS>(0u);
			params.image = std::move(image);
			params.viewType = video::IGPUImageView::ET_2D_ARRAY;
			params.format = usedAsInput ? getInputViewFormat(nativeFormat):getOutputViewFormat(nativeFormat);
			params.components = {};
			params.subresourceRange = subresource;
			return driver->createGPUImageView(std::move(params));
		}

		// we expect user binds correct pipeline, descriptor sets and pushes the push constants by themselves
		_IRR_STATIC_INLINE_CONSTEXPR uint32_t DEFAULT_WORKGROUP_DIM = 16u;
		static inline void dispatchHelper(
			video::IVideoDriver* driver, const video::IGPUImageView* outputView,
			bool issueDefaultBarrier=true, uint32_t workGroupSizeX=DEFAULT_WORKGROUP_DIM, uint32_t workGroupSizeY=DEFAULT_WORKGROUP_DIM
		)
		{
			const auto& params = outputView->getCreationParameters();
			auto imgViewSize = params.image->getMipSize(params.subresourceRange.baseMipLevel);
			imgViewSize.w = params.subresourceRange.layerCount;
			
			const core::vectorSIMDu32 workgroupSize(workGroupSizeX,workGroupSizeY,1,1);
			auto groups = (imgViewSize+workgroupSize-core::vectorSIMDu32(1,1,1,1))/workgroupSize;
			driver->dispatch(groups.x, groups.y, groups.w);

			if (issueDefaultBarrier)
				defaultBarrier();
		}

    private:
		static inline asset::E_FORMAT getInputViewFormat(asset::E_FORMAT imageFormat)
		{
			// before adding any more formats to the support list consult the `createShader` function
			switch (imageFormat)
			{
				case asset::EF_B10G11R11_UFLOAT_PACK32:
				case asset::EF_E5B9G9R9_UFLOAT_PACK32:
					return asset::EF_R32_UINT;
					break;
				case asset::EF_R16G16B16A16_SFLOAT:
					return asset::EF_R32G32_UINT;
					break;
				case asset::EF_R32G32B32A32_SFLOAT:
				case asset::EF_R64G64B64A64_SFLOAT:
				case asset::EF_BC6H_SFLOAT_BLOCK:
				case asset::EF_BC6H_UFLOAT_BLOCK:
					return imageFormat;
					break;
				default:
					break;
			}
			// the input format has to be HDR for ths to make sense!
			_IRR_DEBUG_BREAK_IF(true);
			return asset::EF_UNKNOWN;
		}
		static inline asset::E_FORMAT getOutputViewFormat(asset::E_FORMAT imageFormat)
		{
			// before adding any more formats to the support list consult the `createShader` function
			if (asset::isBlockCompressionFormat(imageFormat))
			{
				// you don't know what you're doing, do you?
				_IRR_DEBUG_BREAK_IF(true);
				return asset::EF_UNKNOWN;
			}
			switch (imageFormat)
			{
				case asset::EF_R8G8B8A8_UNORM:
				case asset::EF_R8G8B8A8_SRGB:
				case asset::EF_A2B10G10R10_UNORM_PACK32:
					return asset::EF_R32_UINT;
					break;
				case asset::EF_R16G16B16A16_UNORM:
				case asset::EF_R16G16B16A16_SFLOAT:
					return asset::EF_R32G32_UINT;
					break;
				default:
					break;
			}
			// other formats not supported yet
			_IRR_DEBUG_BREAK_IF(true);
			return asset::EF_UNKNOWN;
		}

		static void defaultBarrier();
};

}
}
}

#endif