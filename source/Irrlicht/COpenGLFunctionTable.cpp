//#ifdef _IRR_COMPILE_WITH_OPENGL_

#include "COpenGLFunctionTable.h"
namespace irr
{
	namespace video
	{

		uint16_t COpenGLFunctionTable::Version = 0;
		uint16_t COpenGLFunctionTable::ShaderLanguageVersion = 0;
		bool COpenGLFunctionTable::functionsAlreadyLoaded = false;
		int32_t COpenGLFunctionTable::pixelUnpackAlignment = 2;
		bool COpenGLFunctionTable::FeatureAvailable[] = { false };

		int32_t COpenGLFunctionTable::reqUBOAlignment = 0;
		int32_t COpenGLFunctionTable::reqSSBOAlignment = 0;
		int32_t COpenGLFunctionTable::reqTBOAlignment = 0;

		uint64_t COpenGLFunctionTable::maxUBOSize = 0;
		uint64_t COpenGLFunctionTable::maxSSBOSize = 0;
		uint64_t COpenGLFunctionTable::maxTBOSizeInTexels = 0;
		uint64_t COpenGLFunctionTable::maxBufferSize = 0;

		int32_t COpenGLFunctionTable::minMemoryMapAlignment = 0;

		int32_t COpenGLFunctionTable::MaxComputeWGSize[3]{ 0, 0, 0 };

		uint32_t COpenGLFunctionTable::MaxArrayTextureLayers = 2048;
		uint8_t COpenGLFunctionTable::MaxTextureUnits = 96;
		uint8_t COpenGLFunctionTable::MaxAnisotropy = 8;
		uint8_t COpenGLFunctionTable::MaxUserClipPlanes = 8;
		uint8_t COpenGLFunctionTable::MaxMultipleRenderTargets = 4;
		uint32_t COpenGLFunctionTable::MaxIndices = 65535;
		uint32_t COpenGLFunctionTable::MaxVertices = 0xffffffffu;
		uint32_t COpenGLFunctionTable::MaxVertexStreams = 1;
		uint32_t COpenGLFunctionTable::MaxXFormFeedbackComponents = 64;
		uint32_t COpenGLFunctionTable::MaxGPUWaitTimeout = 0;
		uint32_t COpenGLFunctionTable::InvocationSubGroupSize[2] = { 32,64 };
		GLuint COpenGLFunctionTable::SPIR_VextensionsCount = 0u;
		core::smart_refctd_dynamic_array<const GLubyte*> COpenGLFunctionTable::SPIR_Vextensions;
		uint32_t COpenGLFunctionTable::MaxGeometryVerticesOut = 65535;
		float COpenGLFunctionTable::MaxTextureLODBias = 0.f;

		uint32_t COpenGLFunctionTable::maxUBOBindings = 0u;
		uint32_t COpenGLFunctionTable::maxSSBOBindings = 0u;
		uint32_t COpenGLFunctionTable::maxTextureBindings = 0u;
		uint32_t COpenGLFunctionTable::maxTextureBindingsCompute = 0u;
		uint32_t COpenGLFunctionTable::maxImageBindings = 0u;

		//uint32_t COpenGLFunctionTable::MaxXFormFeedbackInterleavedAttributes = GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS;
		//uint32_t COpenGLFunctionTable::MaxXFormFeedbackSeparateAttributes = GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS;

		bool COpenGLFunctionTable::IsIntelGPU = false;
		bool COpenGLFunctionTable::needsDSAFramebufferHack = true;

		//
		PFNGLISENABLEDIPROC COpenGLFunctionTable::pGlIsEnabledi = nullptr;
		PFNGLENABLEIPROC COpenGLFunctionTable::pGlEnablei = nullptr;
		PFNGLDISABLEIPROC COpenGLFunctionTable::pGlDisablei = nullptr;
		PFNGLGETBOOLEANI_VPROC COpenGLFunctionTable::pGlGetBooleani_v = nullptr;
		PFNGLGETFLOATI_VPROC COpenGLFunctionTable::pGlGetFloati_v = nullptr;
		PFNGLGETINTEGER64VPROC COpenGLFunctionTable::pGlGetInteger64v = nullptr;
		PFNGLGETINTEGERI_VPROC COpenGLFunctionTable::pGlGetIntegeri_v = nullptr;
		PFNGLGETSTRINGIPROC COpenGLFunctionTable::pGlGetStringi = nullptr;
		PFNGLPROVOKINGVERTEXPROC COpenGLFunctionTable::pGlProvokingVertex = nullptr;
		PFNGLCLIPCONTROLPROC COpenGLFunctionTable::pGlClipControl = nullptr;

		//fences
		PFNGLFENCESYNCPROC COpenGLFunctionTable::pGlFenceSync = nullptr;
		PFNGLDELETESYNCPROC COpenGLFunctionTable::pGlDeleteSync = nullptr;
		PFNGLCLIENTWAITSYNCPROC COpenGLFunctionTable::pGlClientWaitSync = nullptr;
		PFNGLWAITSYNCPROC COpenGLFunctionTable::pGlWaitSync = nullptr;

		//textures
		PFNGLACTIVETEXTUREPROC COpenGLFunctionTable::pGlActiveTexture = nullptr;
		PFNGLBINDTEXTURESPROC COpenGLFunctionTable::pGlBindTextures = nullptr;
		PFNGLCREATETEXTURESPROC COpenGLFunctionTable::pGlCreateTextures = nullptr;
		PFNGLTEXSTORAGE1DPROC COpenGLFunctionTable::pGlTexStorage1D = nullptr;
		PFNGLTEXSTORAGE2DPROC COpenGLFunctionTable::pGlTexStorage2D = nullptr;
		PFNGLTEXSTORAGE3DPROC COpenGLFunctionTable::pGlTexStorage3D = nullptr;
		PFNGLTEXSTORAGE2DMULTISAMPLEPROC COpenGLFunctionTable::pGlTexStorage2DMultisample = nullptr;
		PFNGLTEXSTORAGE3DMULTISAMPLEPROC COpenGLFunctionTable::pGlTexStorage3DMultisample = nullptr;
		PFNGLTEXBUFFERPROC COpenGLFunctionTable::pGlTexBuffer = nullptr;
		PFNGLTEXBUFFERRANGEPROC COpenGLFunctionTable::pGlTexBufferRange = nullptr;
		PFNGLTEXTURESTORAGE1DPROC COpenGLFunctionTable::pGlTextureStorage1D = nullptr;
		PFNGLTEXTURESTORAGE2DPROC COpenGLFunctionTable::pGlTextureStorage2D = nullptr;
		PFNGLTEXTURESTORAGE3DPROC COpenGLFunctionTable::pGlTextureStorage3D = nullptr;
		PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC COpenGLFunctionTable::pGlTextureStorage2DMultisample = nullptr;
		PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC COpenGLFunctionTable::pGlTextureStorage3DMultisample = nullptr;
		PFNGLTEXTUREBUFFERPROC COpenGLFunctionTable::pGlTextureBuffer = nullptr;
		PFNGLTEXTUREVIEWPROC COpenGLFunctionTable::pGlTextureView = nullptr;
		PFNGLTEXTUREBUFFERRANGEPROC COpenGLFunctionTable::pGlTextureBufferRange = nullptr;
		PFNGLTEXTURESTORAGE1DEXTPROC COpenGLFunctionTable::pGlTextureStorage1DEXT = nullptr;
		PFNGLTEXTURESTORAGE2DEXTPROC COpenGLFunctionTable::pGlTextureStorage2DEXT = nullptr;
		PFNGLTEXTURESTORAGE3DEXTPROC COpenGLFunctionTable::pGlTextureStorage3DEXT = nullptr;
		PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC COpenGLFunctionTable::pGlTextureStorage2DMultisampleEXT = nullptr;
		PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC COpenGLFunctionTable::pGlTextureStorage3DMultisampleEXT = nullptr;
		PFNGLTEXTUREBUFFEREXTPROC COpenGLFunctionTable::pGlTextureBufferEXT = nullptr;
		PFNGLTEXTUREBUFFERRANGEEXTPROC COpenGLFunctionTable::pGlTextureBufferRangeEXT = nullptr;
		PFNGLGETTEXTURESUBIMAGEPROC COpenGLFunctionTable::pGlGetTextureSubImage = nullptr;
		PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC COpenGLFunctionTable::pGlGetCompressedTextureSubImage = nullptr;
		PFNGLGETTEXTUREIMAGEPROC COpenGLFunctionTable::pGlGetTextureImage = nullptr;
		PFNGLGETTEXTUREIMAGEEXTPROC COpenGLFunctionTable::pGlGetTextureImageEXT = nullptr;
		PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC COpenGLFunctionTable::pGlGetCompressedTextureImage = nullptr;
		PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC COpenGLFunctionTable::pGlGetCompressedTextureImageEXT = nullptr;
		PFNGLGETCOMPRESSEDTEXIMAGEPROC COpenGLFunctionTable::pGlGetCompressedTexImage = nullptr;
		PFNGLTEXSUBIMAGE3DPROC COpenGLFunctionTable::pGlTexSubImage3D = nullptr;
		PFNGLMULTITEXSUBIMAGE1DEXTPROC COpenGLFunctionTable::pGlMultiTexSubImage1DEXT = nullptr;
		PFNGLMULTITEXSUBIMAGE2DEXTPROC COpenGLFunctionTable::pGlMultiTexSubImage2DEXT = nullptr;
		PFNGLMULTITEXSUBIMAGE3DEXTPROC COpenGLFunctionTable::pGlMultiTexSubImage3DEXT = nullptr;
		PFNGLTEXTURESUBIMAGE1DPROC COpenGLFunctionTable::pGlTextureSubImage1D = nullptr;
		PFNGLTEXTURESUBIMAGE2DPROC COpenGLFunctionTable::pGlTextureSubImage2D = nullptr;
		PFNGLTEXTURESUBIMAGE3DPROC COpenGLFunctionTable::pGlTextureSubImage3D = nullptr;
		PFNGLTEXTURESUBIMAGE1DEXTPROC COpenGLFunctionTable::pGlTextureSubImage1DEXT = nullptr;
		PFNGLTEXTURESUBIMAGE2DEXTPROC COpenGLFunctionTable::pGlTextureSubImage2DEXT = nullptr;
		PFNGLTEXTURESUBIMAGE3DEXTPROC COpenGLFunctionTable::pGlTextureSubImage3DEXT = nullptr;
		PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC COpenGLFunctionTable::pGlCompressedTexSubImage1D = nullptr;
		PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC COpenGLFunctionTable::pGlCompressedTexSubImage2D = nullptr;
		PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC COpenGLFunctionTable::pGlCompressedTexSubImage3D = nullptr;
		PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC COpenGLFunctionTable::pGlCompressedTextureSubImage1D = nullptr;
		PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC COpenGLFunctionTable::pGlCompressedTextureSubImage2D = nullptr;
		PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC COpenGLFunctionTable::pGlCompressedTextureSubImage3D = nullptr;
		PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC COpenGLFunctionTable::pGlCompressedTextureSubImage1DEXT = nullptr;
		PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC COpenGLFunctionTable::pGlCompressedTextureSubImage2DEXT = nullptr;
		PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC COpenGLFunctionTable::pGlCompressedTextureSubImage3DEXT = nullptr;
		PFNGLCOPYIMAGESUBDATAPROC COpenGLFunctionTable::pGlCopyImageSubData = nullptr;
		PFNGLTEXTUREPARAMETERIUIVPROC COpenGLFunctionTable::pGlTextureParameterIuiv = nullptr;
		PFNGLTEXTUREPARAMETERIUIVEXTPROC COpenGLFunctionTable::pGlTextureParameterIuivEXT = nullptr;
		PFNGLTEXPARAMETERIUIVPROC COpenGLFunctionTable::pGlTexParameterIuiv = nullptr;
		PFNGLGENERATEMIPMAPPROC COpenGLFunctionTable::pGlGenerateMipmap = nullptr;
		PFNGLGENERATETEXTUREMIPMAPPROC COpenGLFunctionTable::pGlGenerateTextureMipmap = nullptr;
		PFNGLGENERATETEXTUREMIPMAPEXTPROC COpenGLFunctionTable::pGlGenerateTextureMipmapEXT = nullptr;
		PFNGLCLAMPCOLORPROC COpenGLFunctionTable::pGlClampColor = nullptr;

		//samplers
		PFNGLGENSAMPLERSPROC COpenGLFunctionTable::pGlGenSamplers = nullptr;
		PFNGLCREATESAMPLERSPROC COpenGLFunctionTable::pGlCreateSamplers = nullptr;
		PFNGLDELETESAMPLERSPROC COpenGLFunctionTable::pGlDeleteSamplers = nullptr;
		PFNGLBINDSAMPLERPROC COpenGLFunctionTable::pGlBindSampler = nullptr;
		PFNGLBINDSAMPLERSPROC COpenGLFunctionTable::pGlBindSamplers = nullptr;
		PFNGLSAMPLERPARAMETERIPROC COpenGLFunctionTable::pGlSamplerParameteri = nullptr;
		PFNGLSAMPLERPARAMETERFPROC COpenGLFunctionTable::pGlSamplerParameterf = nullptr;
		PFNGLSAMPLERPARAMETERFVPROC COpenGLFunctionTable::pGlSamplerParameterfv = nullptr;

		//
		PFNGLBINDIMAGETEXTUREPROC COpenGLFunctionTable::pGlBindImageTexture = nullptr;
		PFNGLBINDIMAGETEXTURESPROC COpenGLFunctionTable::pGlBindImageTextures = nullptr;

		//bindless textures
		//ARB
		PFNGLGETTEXTUREHANDLEARBPROC COpenGLFunctionTable::pGlGetTextureHandleARB = nullptr;
		PFNGLGETTEXTURESAMPLERHANDLEARBPROC COpenGLFunctionTable::pGlGetTextureSamplerHandleARB = nullptr;
		PFNGLMAKETEXTUREHANDLERESIDENTARBPROC COpenGLFunctionTable::pGlMakeTextureHandleResidentARB = nullptr;
		PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC COpenGLFunctionTable::pGlMakeTextureHandleNonResidentARB = nullptr;
		PFNGLGETIMAGEHANDLEARBPROC COpenGLFunctionTable::pGlGetImageHandleARB = nullptr;
		PFNGLMAKEIMAGEHANDLERESIDENTARBPROC COpenGLFunctionTable::pGlMakeImageHandleResidentARB = nullptr;
		PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC COpenGLFunctionTable::pGlMakeImageHandleNonResidentARB = nullptr;
		PFNGLISTEXTUREHANDLERESIDENTARBPROC COpenGLFunctionTable::pGlIsTextureHandleResidentARB = nullptr;
		PFNGLISIMAGEHANDLERESIDENTARBPROC COpenGLFunctionTable::pGlIsImageHandleResidentARB = nullptr;
		//NV
		PFNGLGETTEXTUREHANDLENVPROC COpenGLFunctionTable::pGlGetTextureHandleNV = nullptr;
		PFNGLGETTEXTURESAMPLERHANDLENVPROC COpenGLFunctionTable::pGlGetTextureSamplerHandleNV = nullptr;
		PFNGLMAKETEXTUREHANDLERESIDENTNVPROC COpenGLFunctionTable::pGlMakeTextureHandleResidentNV = nullptr;
		PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC COpenGLFunctionTable::pGlMakeTextureHandleNonResidentNV = nullptr;
		PFNGLGETIMAGEHANDLENVPROC COpenGLFunctionTable::pGlGetImageHandleNV = nullptr;
		PFNGLMAKEIMAGEHANDLERESIDENTNVPROC COpenGLFunctionTable::pGlMakeImageHandleResidentNV = nullptr;
		PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC COpenGLFunctionTable::pGlMakeImageHandleNonResidentNV = nullptr;
		PFNGLISTEXTUREHANDLERESIDENTNVPROC COpenGLFunctionTable::pGlIsTextureHandleResidentNV = nullptr;
		PFNGLISIMAGEHANDLERESIDENTNVPROC COpenGLFunctionTable::pGlIsImageHandleResidentNV = nullptr;

		//stuff
		PFNGLBINDBUFFERBASEPROC COpenGLFunctionTable::pGlBindBufferBase = nullptr;
		PFNGLBINDBUFFERRANGEPROC COpenGLFunctionTable::pGlBindBufferRange = nullptr;
		PFNGLBINDBUFFERSBASEPROC COpenGLFunctionTable::pGlBindBuffersBase = nullptr;
		PFNGLBINDBUFFERSRANGEPROC COpenGLFunctionTable::pGlBindBuffersRange = nullptr;


		//shaders
		PFNGLBINDATTRIBLOCATIONPROC COpenGLFunctionTable::pGlBindAttribLocation = nullptr;
		PFNGLCREATEPROGRAMPROC COpenGLFunctionTable::pGlCreateProgram = nullptr;
		PFNGLUSEPROGRAMPROC COpenGLFunctionTable::pGlUseProgram = nullptr;
		PFNGLDELETEPROGRAMPROC COpenGLFunctionTable::pGlDeleteProgram = nullptr;
		PFNGLDELETESHADERPROC COpenGLFunctionTable::pGlDeleteShader = nullptr;
		PFNGLGETATTACHEDSHADERSPROC COpenGLFunctionTable::pGlGetAttachedShaders = nullptr;
		PFNGLCREATESHADERPROC COpenGLFunctionTable::pGlCreateShader = nullptr;
		PFNGLCREATESHADERPROGRAMVPROC COpenGLFunctionTable::pGlCreateShaderProgramv = nullptr;
		PFNGLCREATEPROGRAMPIPELINESPROC COpenGLFunctionTable::pGlCreateProgramPipelines = nullptr;
		PFNGLDELETEPROGRAMPIPELINESPROC COpenGLFunctionTable::pGlDeleteProgramPipelines = nullptr;
		PFNGLUSEPROGRAMSTAGESPROC COpenGLFunctionTable::pGlUseProgramStages = nullptr;
		PFNGLSHADERSOURCEPROC COpenGLFunctionTable::pGlShaderSource = nullptr;
		PFNGLCOMPILESHADERPROC COpenGLFunctionTable::pGlCompileShader = nullptr;
		PFNGLATTACHSHADERPROC COpenGLFunctionTable::pGlAttachShader = nullptr;
		PFNGLTRANSFORMFEEDBACKVARYINGSPROC COpenGLFunctionTable::pGlTransformFeedbackVaryings = nullptr;
		PFNGLLINKPROGRAMPROC COpenGLFunctionTable::pGlLinkProgram = nullptr;
		PFNGLGETSHADERINFOLOGPROC COpenGLFunctionTable::pGlGetShaderInfoLog = nullptr;
		PFNGLGETPROGRAMINFOLOGPROC COpenGLFunctionTable::pGlGetProgramInfoLog = nullptr;
		PFNGLGETSHADERIVPROC COpenGLFunctionTable::pGlGetShaderiv = nullptr;
		PFNGLGETSHADERIVPROC COpenGLFunctionTable::pGlGetProgramiv = nullptr;
		PFNGLGETUNIFORMLOCATIONPROC COpenGLFunctionTable::pGlGetUniformLocation = nullptr;
		//
		PFNGLPROGRAMUNIFORM1FVPROC COpenGLFunctionTable::pGlProgramUniform1fv = nullptr;
		PFNGLPROGRAMUNIFORM2FVPROC COpenGLFunctionTable::pGlProgramUniform2fv = nullptr;
		PFNGLPROGRAMUNIFORM3FVPROC COpenGLFunctionTable::pGlProgramUniform3fv = nullptr;
		PFNGLPROGRAMUNIFORM4FVPROC COpenGLFunctionTable::pGlProgramUniform4fv = nullptr;
		PFNGLPROGRAMUNIFORM1IVPROC COpenGLFunctionTable::pGlProgramUniform1iv = nullptr;
		PFNGLPROGRAMUNIFORM2IVPROC COpenGLFunctionTable::pGlProgramUniform2iv = nullptr;
		PFNGLPROGRAMUNIFORM3IVPROC COpenGLFunctionTable::pGlProgramUniform3iv = nullptr;
		PFNGLPROGRAMUNIFORM4IVPROC COpenGLFunctionTable::pGlProgramUniform4iv = nullptr;
		PFNGLPROGRAMUNIFORM1UIVPROC COpenGLFunctionTable::pGlProgramUniform1uiv = nullptr;
		PFNGLPROGRAMUNIFORM2UIVPROC COpenGLFunctionTable::pGlProgramUniform2uiv = nullptr;
		PFNGLPROGRAMUNIFORM3UIVPROC COpenGLFunctionTable::pGlProgramUniform3uiv = nullptr;
		PFNGLPROGRAMUNIFORM4UIVPROC COpenGLFunctionTable::pGlProgramUniform4uiv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX2FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix2fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX3FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix3fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX4FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix4fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix2x3fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix2x4fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix3x2fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix3x4fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix4x2fv = nullptr;
		PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC COpenGLFunctionTable::pGlProgramUniformMatrix4x3fv = nullptr;
		//
		PFNGLGETACTIVEUNIFORMPROC COpenGLFunctionTable::pGlGetActiveUniform = nullptr;
		PFNGLBINDPROGRAMPIPELINEPROC COpenGLFunctionTable::pGlBindProgramPipeline = nullptr;
		PFNGLGETPROGRAMBINARYPROC COpenGLFunctionTable::pGlGetProgramBinary = nullptr;
		PFNGLPROGRAMBINARYPROC COpenGLFunctionTable::pGlProgramBinary = nullptr;

		// Criss
		PFNGLMEMORYBARRIERPROC COpenGLFunctionTable::pGlMemoryBarrier = nullptr;
		PFNGLDISPATCHCOMPUTEPROC COpenGLFunctionTable::pGlDispatchCompute = nullptr;
		PFNGLDISPATCHCOMPUTEINDIRECTPROC COpenGLFunctionTable::pGlDispatchComputeIndirect = nullptr;
		//
		PFNGLPOINTPARAMETERFPROC COpenGLFunctionTable::pGlPointParameterf = nullptr;
		PFNGLPOINTPARAMETERFVPROC COpenGLFunctionTable::pGlPointParameterfv = nullptr;

		//ROP
		PFNGLBLENDCOLORPROC COpenGLFunctionTable::pGlBlendColor = nullptr;
		PFNGLDEPTHRANGEINDEXEDPROC COpenGLFunctionTable::pGlDepthRangeIndexed = nullptr;
		PFNGLVIEWPORTINDEXEDFVPROC COpenGLFunctionTable::pGlViewportIndexedfv = nullptr;
		PFNGLSCISSORINDEXEDVPROC COpenGLFunctionTable::pGlScissorIndexedv = nullptr;
		PFNGLSAMPLECOVERAGEPROC COpenGLFunctionTable::pGlSampleCoverage = nullptr;
		PFNGLSAMPLEMASKIPROC COpenGLFunctionTable::pGlSampleMaski = nullptr;
		PFNGLMINSAMPLESHADINGPROC COpenGLFunctionTable::pGlMinSampleShading = nullptr;
		PFNGLBLENDEQUATIONSEPARATEIPROC COpenGLFunctionTable::pGlBlendEquationSeparatei = nullptr;
		PFNGLBLENDFUNCSEPARATEIPROC COpenGLFunctionTable::pGlBlendFuncSeparatei = nullptr;
		PFNGLCOLORMASKIPROC COpenGLFunctionTable::pGlColorMaski = nullptr;
		PFNGLSTENCILFUNCSEPARATEPROC COpenGLFunctionTable::pGlStencilFuncSeparate = nullptr;
		PFNGLSTENCILOPSEPARATEPROC COpenGLFunctionTable::pGlStencilOpSeparate = nullptr;
		PFNGLSTENCILMASKSEPARATEPROC COpenGLFunctionTable::pGlStencilMaskSeparate = nullptr;


		// ARB framebuffer object
		PFNGLBLITNAMEDFRAMEBUFFERPROC COpenGLFunctionTable::pGlBlitNamedFramebuffer = nullptr;
		PFNGLBLITFRAMEBUFFERPROC COpenGLFunctionTable::pGlBlitFramebuffer = nullptr;
		PFNGLDELETEFRAMEBUFFERSPROC COpenGLFunctionTable::pGlDeleteFramebuffers = nullptr;
		PFNGLCREATEFRAMEBUFFERSPROC COpenGLFunctionTable::pGlCreateFramebuffers = nullptr;
		PFNGLGENFRAMEBUFFERSPROC COpenGLFunctionTable::pGlGenFramebuffers = nullptr;
		PFNGLBINDFRAMEBUFFERPROC COpenGLFunctionTable::pGlBindFramebuffer = nullptr;
		PFNGLCHECKFRAMEBUFFERSTATUSPROC COpenGLFunctionTable::pGlCheckFramebufferStatus = nullptr;
		PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC COpenGLFunctionTable::pGlCheckNamedFramebufferStatus = nullptr;
		PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC COpenGLFunctionTable::pGlCheckNamedFramebufferStatusEXT = nullptr;
		PFNGLFRAMEBUFFERTEXTUREPROC COpenGLFunctionTable::pGlFramebufferTexture = nullptr;
		PFNGLNAMEDFRAMEBUFFERTEXTUREPROC COpenGLFunctionTable::pGlNamedFramebufferTexture = nullptr;
		PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC COpenGLFunctionTable::pGlNamedFramebufferTextureEXT = nullptr;
		PFNGLFRAMEBUFFERTEXTURELAYERPROC COpenGLFunctionTable::pGlFramebufferTextureLayer = nullptr;
		PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC COpenGLFunctionTable::pGlNamedFramebufferTextureLayer = nullptr;
		PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC COpenGLFunctionTable::pGlNamedFramebufferTextureLayerEXT = nullptr;
		PFNGLFRAMEBUFFERTEXTURE2DPROC COpenGLFunctionTable::pGlFramebufferTexture2D = nullptr;
		PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC COpenGLFunctionTable::pGlNamedFramebufferTexture2DEXT = nullptr;
		// EXT framebuffer object
		PFNGLACTIVESTENCILFACEEXTPROC COpenGLFunctionTable::pGlActiveStencilFaceEXT = nullptr;
		PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC COpenGLFunctionTable::pGlNamedFramebufferReadBuffer = nullptr;
		PFNGLFRAMEBUFFERREADBUFFEREXTPROC COpenGLFunctionTable::pGlFramebufferReadBufferEXT = nullptr;
		PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC COpenGLFunctionTable::pGlNamedFramebufferDrawBuffer = nullptr;
		PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC COpenGLFunctionTable::pGlFramebufferDrawBufferEXT = nullptr;
		PFNGLDRAWBUFFERSPROC COpenGLFunctionTable::pGlDrawBuffers = nullptr;
		PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC COpenGLFunctionTable::pGlNamedFramebufferDrawBuffers = nullptr;
		PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC COpenGLFunctionTable::pGlFramebufferDrawBuffersEXT = nullptr;
		PFNGLCLEARNAMEDFRAMEBUFFERIVPROC COpenGLFunctionTable::pGlClearNamedFramebufferiv = nullptr;
		PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC COpenGLFunctionTable::pGlClearNamedFramebufferuiv = nullptr;
		PFNGLCLEARNAMEDFRAMEBUFFERFVPROC COpenGLFunctionTable::pGlClearNamedFramebufferfv = nullptr;
		PFNGLCLEARNAMEDFRAMEBUFFERFIPROC COpenGLFunctionTable::pGlClearNamedFramebufferfi = nullptr;
		PFNGLCLEARBUFFERIVPROC COpenGLFunctionTable::pGlClearBufferiv = nullptr;
		PFNGLCLEARBUFFERUIVPROC COpenGLFunctionTable::pGlClearBufferuiv = nullptr;
		PFNGLCLEARBUFFERFVPROC COpenGLFunctionTable::pGlClearBufferfv = nullptr;
		PFNGLCLEARBUFFERFIPROC COpenGLFunctionTable::pGlClearBufferfi = nullptr;

		//
		PFNGLGENBUFFERSPROC COpenGLFunctionTable::pGlGenBuffers = nullptr;
		PFNGLCREATEBUFFERSPROC COpenGLFunctionTable::pGlCreateBuffers = nullptr;
		PFNGLBINDBUFFERPROC COpenGLFunctionTable::pGlBindBuffer = nullptr;
		PFNGLDELETEBUFFERSPROC COpenGLFunctionTable::pGlDeleteBuffers = nullptr;
		PFNGLBUFFERSTORAGEPROC COpenGLFunctionTable::pGlBufferStorage = nullptr;
		PFNGLNAMEDBUFFERSTORAGEPROC COpenGLFunctionTable::pGlNamedBufferStorage = nullptr;
		PFNGLNAMEDBUFFERSTORAGEEXTPROC COpenGLFunctionTable::pGlNamedBufferStorageEXT = nullptr;
		PFNGLBUFFERSUBDATAPROC COpenGLFunctionTable::pGlBufferSubData = nullptr;
		PFNGLNAMEDBUFFERSUBDATAPROC COpenGLFunctionTable::pGlNamedBufferSubData = nullptr;
		PFNGLNAMEDBUFFERSUBDATAEXTPROC COpenGLFunctionTable::pGlNamedBufferSubDataEXT = nullptr;
		PFNGLGETBUFFERSUBDATAPROC COpenGLFunctionTable::pGlGetBufferSubData = nullptr;
		PFNGLGETNAMEDBUFFERSUBDATAPROC COpenGLFunctionTable::pGlGetNamedBufferSubData = nullptr;
		PFNGLGETNAMEDBUFFERSUBDATAEXTPROC COpenGLFunctionTable::pGlGetNamedBufferSubDataEXT = nullptr;
		PFNGLMAPBUFFERPROC COpenGLFunctionTable::pGlMapBuffer = nullptr;
		PFNGLMAPNAMEDBUFFERPROC COpenGLFunctionTable::pGlMapNamedBuffer = nullptr;
		PFNGLMAPNAMEDBUFFEREXTPROC COpenGLFunctionTable::pGlMapNamedBufferEXT = nullptr;
		PFNGLMAPBUFFERRANGEPROC COpenGLFunctionTable::pGlMapBufferRange = nullptr;
		PFNGLMAPNAMEDBUFFERRANGEPROC COpenGLFunctionTable::pGlMapNamedBufferRange = nullptr;
		PFNGLMAPNAMEDBUFFERRANGEEXTPROC COpenGLFunctionTable::pGlMapNamedBufferRangeEXT = nullptr;
		PFNGLFLUSHMAPPEDBUFFERRANGEPROC COpenGLFunctionTable::pGlFlushMappedBufferRange = nullptr;
		PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC COpenGLFunctionTable::pGlFlushMappedNamedBufferRange = nullptr;
		PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC COpenGLFunctionTable::pGlFlushMappedNamedBufferRangeEXT = nullptr;
		PFNGLUNMAPBUFFERPROC COpenGLFunctionTable::pGlUnmapBuffer = nullptr;
		PFNGLUNMAPNAMEDBUFFERPROC COpenGLFunctionTable::pGlUnmapNamedBuffer = nullptr;
		PFNGLUNMAPNAMEDBUFFEREXTPROC COpenGLFunctionTable::pGlUnmapNamedBufferEXT = nullptr;
		PFNGLCLEARBUFFERDATAPROC COpenGLFunctionTable::pGlClearBufferData = nullptr;
		PFNGLCLEARNAMEDBUFFERDATAPROC COpenGLFunctionTable::pGlClearNamedBufferData = nullptr;
		PFNGLCLEARNAMEDBUFFERDATAEXTPROC COpenGLFunctionTable::pGlClearNamedBufferDataEXT = nullptr;
		PFNGLCLEARBUFFERSUBDATAPROC COpenGLFunctionTable::pGlClearBufferSubData = nullptr;
		PFNGLCLEARNAMEDBUFFERSUBDATAPROC COpenGLFunctionTable::pGlClearNamedBufferSubData = nullptr;
		PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC COpenGLFunctionTable::pGlClearNamedBufferSubDataEXT = nullptr;
		PFNGLCOPYBUFFERSUBDATAPROC COpenGLFunctionTable::pGlCopyBufferSubData = nullptr;
		PFNGLCOPYNAMEDBUFFERSUBDATAPROC COpenGLFunctionTable::pGlCopyNamedBufferSubData = nullptr;
		PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC COpenGLFunctionTable::pGlNamedCopyBufferSubDataEXT = nullptr;
		PFNGLISBUFFERPROC COpenGLFunctionTable::pGlIsBuffer = nullptr;
		PFNGLGETNAMEDBUFFERPARAMETERI64VPROC COpenGLFunctionTable::pGlGetNamedBufferParameteri64v = nullptr;
		PFNGLGETBUFFERPARAMETERI64VPROC COpenGLFunctionTable::pGlGetBufferParameteri64v = nullptr;
		PFNGLGETNAMEDBUFFERPARAMETERIVPROC COpenGLFunctionTable::pGlGetNamedBufferParameteriv = nullptr;
		PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC COpenGLFunctionTable::pGlGetNamedBufferParameterivEXT = nullptr;
		PFNGLGETBUFFERPARAMETERIVPROC COpenGLFunctionTable::pGlGetBufferParameteriv = nullptr;
		//vao
		PFNGLGENVERTEXARRAYSPROC COpenGLFunctionTable::pGlGenVertexArrays = nullptr;
		PFNGLCREATEVERTEXARRAYSPROC COpenGLFunctionTable::pGlCreateVertexArrays = nullptr;
		PFNGLDELETEVERTEXARRAYSPROC COpenGLFunctionTable::pGlDeleteVertexArrays = nullptr;
		PFNGLBINDVERTEXARRAYPROC COpenGLFunctionTable::pGlBindVertexArray = nullptr;
		PFNGLVERTEXARRAYELEMENTBUFFERPROC COpenGLFunctionTable::pGlVertexArrayElementBuffer = nullptr;
		PFNGLBINDVERTEXBUFFERPROC COpenGLFunctionTable::pGlBindVertexBuffer = nullptr;
		PFNGLVERTEXARRAYVERTEXBUFFERPROC COpenGLFunctionTable::pGlVertexArrayVertexBuffer = nullptr;
		PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC COpenGLFunctionTable::pGlVertexArrayBindVertexBufferEXT = nullptr;
		PFNGLVERTEXATTRIBBINDINGPROC COpenGLFunctionTable::pGlVertexAttribBinding = nullptr;
		PFNGLVERTEXARRAYATTRIBBINDINGPROC COpenGLFunctionTable::pGlVertexArrayAttribBinding = nullptr;
		PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC COpenGLFunctionTable::pGlVertexArrayVertexAttribBindingEXT = nullptr;
		PFNGLENABLEVERTEXATTRIBARRAYPROC COpenGLFunctionTable::pGlEnableVertexAttribArray = nullptr;
		PFNGLENABLEVERTEXARRAYATTRIBPROC COpenGLFunctionTable::pGlEnableVertexArrayAttrib = nullptr;
		PFNGLENABLEVERTEXARRAYATTRIBEXTPROC COpenGLFunctionTable::pGlEnableVertexArrayAttribEXT = nullptr;
		PFNGLDISABLEVERTEXATTRIBARRAYPROC COpenGLFunctionTable::pGlDisableVertexAttribArray = nullptr;
		PFNGLDISABLEVERTEXARRAYATTRIBPROC COpenGLFunctionTable::pGlDisableVertexArrayAttrib = nullptr;
		PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC COpenGLFunctionTable::pGlDisableVertexArrayAttribEXT = nullptr;
		PFNGLVERTEXATTRIBFORMATPROC COpenGLFunctionTable::pGlVertexAttribFormat = nullptr;
		PFNGLVERTEXATTRIBIFORMATPROC COpenGLFunctionTable::pGlVertexAttribIFormat = nullptr;
		PFNGLVERTEXATTRIBLFORMATPROC COpenGLFunctionTable::pGlVertexAttribLFormat = nullptr;
		PFNGLVERTEXARRAYATTRIBFORMATPROC COpenGLFunctionTable::pGlVertexArrayAttribFormat = nullptr;
		PFNGLVERTEXARRAYATTRIBIFORMATPROC COpenGLFunctionTable::pGlVertexArrayAttribIFormat = nullptr;
		PFNGLVERTEXARRAYATTRIBLFORMATPROC COpenGLFunctionTable::pGlVertexArrayAttribLFormat = nullptr;
		PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC COpenGLFunctionTable::pGlVertexArrayVertexAttribFormatEXT = nullptr;
		PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC COpenGLFunctionTable::pGlVertexArrayVertexAttribIFormatEXT = nullptr;
		PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC COpenGLFunctionTable::pGlVertexArrayVertexAttribLFormatEXT = nullptr;
		PFNGLVERTEXARRAYBINDINGDIVISORPROC COpenGLFunctionTable::pGlVertexArrayBindingDivisor = nullptr;
		PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC COpenGLFunctionTable::pGlVertexArrayVertexBindingDivisorEXT = nullptr;
		PFNGLVERTEXBINDINGDIVISORPROC COpenGLFunctionTable::pGlVertexBindingDivisor = nullptr;
		//
		PFNGLPRIMITIVERESTARTINDEXPROC COpenGLFunctionTable::pGlPrimitiveRestartIndex = nullptr;
		PFNGLDRAWARRAYSINSTANCEDPROC COpenGLFunctionTable::pGlDrawArraysInstanced = nullptr;
		PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC COpenGLFunctionTable::pGlDrawArraysInstancedBaseInstance = nullptr;
		PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC COpenGLFunctionTable::pGlDrawElementsInstancedBaseVertex = nullptr;
		PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC COpenGLFunctionTable::pGlDrawElementsInstancedBaseVertexBaseInstance = nullptr;
		PFNGLDRAWTRANSFORMFEEDBACKPROC COpenGLFunctionTable::pGlDrawTransformFeedback = nullptr;
		PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC COpenGLFunctionTable::pGlDrawTransformFeedbackInstanced = nullptr;
		PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC COpenGLFunctionTable::pGlDrawTransformFeedbackStream = nullptr;
		PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC COpenGLFunctionTable::pGlDrawTransformFeedbackStreamInstanced = nullptr;
		PFNGLDRAWARRAYSINDIRECTPROC COpenGLFunctionTable::pGlDrawArraysIndirect = nullptr;
		PFNGLDRAWELEMENTSINDIRECTPROC COpenGLFunctionTable::pGlDrawElementsIndirect = nullptr;
		PFNGLMULTIDRAWARRAYSINDIRECTPROC COpenGLFunctionTable::pGlMultiDrawArraysIndirect = nullptr;
		PFNGLMULTIDRAWELEMENTSINDIRECTPROC COpenGLFunctionTable::pGlMultiDrawElementsIndirect = nullptr;
		PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC COpenGLFunctionTable::pGlMultiDrawArrysIndirectCount = nullptr;
		PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC COpenGLFunctionTable::pGlMultiDrawElementsIndirectCount = nullptr;
		//
		PFNGLCREATETRANSFORMFEEDBACKSPROC COpenGLFunctionTable::pGlCreateTransformFeedbacks = nullptr;
		PFNGLGENTRANSFORMFEEDBACKSPROC COpenGLFunctionTable::pGlGenTransformFeedbacks = nullptr;
		PFNGLDELETETRANSFORMFEEDBACKSPROC COpenGLFunctionTable::pGlDeleteTransformFeedbacks = nullptr;
		PFNGLBINDTRANSFORMFEEDBACKPROC COpenGLFunctionTable::pGlBindTransformFeedback = nullptr;
		PFNGLBEGINTRANSFORMFEEDBACKPROC COpenGLFunctionTable::pGlBeginTransformFeedback = nullptr;
		PFNGLPAUSETRANSFORMFEEDBACKPROC COpenGLFunctionTable::pGlPauseTransformFeedback = nullptr;
		PFNGLRESUMETRANSFORMFEEDBACKPROC COpenGLFunctionTable::pGlResumeTransformFeedback = nullptr;
		PFNGLENDTRANSFORMFEEDBACKPROC COpenGLFunctionTable::pGlEndTransformFeedback = nullptr;
		PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC COpenGLFunctionTable::pGlTransformFeedbackBufferBase = nullptr;
		PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC COpenGLFunctionTable::pGlTransformFeedbackBufferRange = nullptr;
		//
		PFNGLBLENDFUNCSEPARATEPROC COpenGLFunctionTable::pGlBlendFuncSeparate = nullptr;
		PFNGLBLENDFUNCINDEXEDAMDPROC COpenGLFunctionTable::pGlBlendFuncIndexedAMD = nullptr;
		PFNGLBLENDFUNCIPROC COpenGLFunctionTable::pGlBlendFunciARB = nullptr;
		PFNGLBLENDEQUATIONINDEXEDAMDPROC COpenGLFunctionTable::pGlBlendEquationIndexedAMD = nullptr;
		PFNGLBLENDEQUATIONIPROC COpenGLFunctionTable::pGlBlendEquationiARB = nullptr;
		PFNGLPROGRAMPARAMETERIPROC COpenGLFunctionTable::pGlProgramParameteri = nullptr;
		PFNGLPATCHPARAMETERIPROC COpenGLFunctionTable::pGlPatchParameteri = nullptr;
		PFNGLPATCHPARAMETERFVPROC COpenGLFunctionTable::pGlPatchParameterfv = nullptr;
		//
		PFNGLCREATEQUERIESPROC COpenGLFunctionTable::pGlCreateQueries = nullptr;
		PFNGLGENQUERIESPROC COpenGLFunctionTable::pGlGenQueries = nullptr;
		PFNGLDELETEQUERIESPROC COpenGLFunctionTable::pGlDeleteQueries = nullptr;
		PFNGLISQUERYPROC COpenGLFunctionTable::pGlIsQuery = nullptr;
		PFNGLBEGINQUERYPROC COpenGLFunctionTable::pGlBeginQuery = nullptr;
		PFNGLENDQUERYPROC COpenGLFunctionTable::pGlEndQuery = nullptr;
		PFNGLBEGINQUERYINDEXEDPROC COpenGLFunctionTable::pGlBeginQueryIndexed = nullptr;
		PFNGLENDQUERYINDEXEDPROC COpenGLFunctionTable::pGlEndQueryIndexed = nullptr;
		PFNGLGETQUERYIVPROC COpenGLFunctionTable::pGlGetQueryiv = nullptr;
		PFNGLGETQUERYOBJECTUIVPROC COpenGLFunctionTable::pGlGetQueryObjectuiv = nullptr;
		PFNGLGETQUERYOBJECTUI64VPROC COpenGLFunctionTable::pGlGetQueryObjectui64v = nullptr;
		PFNGLGETQUERYBUFFEROBJECTUIVPROC COpenGLFunctionTable::pGlGetQueryBufferObjectuiv = nullptr;
		PFNGLGETQUERYBUFFEROBJECTUI64VPROC COpenGLFunctionTable::pGlGetQueryBufferObjectui64v = nullptr;
		PFNGLQUERYCOUNTERPROC COpenGLFunctionTable::pGlQueryCounter = nullptr;
		PFNGLBEGINCONDITIONALRENDERPROC COpenGLFunctionTable::pGlBeginConditionalRender = nullptr;
		PFNGLENDCONDITIONALRENDERPROC COpenGLFunctionTable::pGlEndConditionalRender = nullptr;
		//
		PFNGLTEXTUREBARRIERPROC COpenGLFunctionTable::pGlTextureBarrier = nullptr;
		PFNGLTEXTUREBARRIERNVPROC COpenGLFunctionTable::pGlTextureBarrierNV = nullptr;
		//
		PFNGLBLENDEQUATIONEXTPROC COpenGLFunctionTable::pGlBlendEquationEXT = nullptr;
		PFNGLBLENDEQUATIONPROC COpenGLFunctionTable::pGlBlendEquation = nullptr;

		PFNGLGETINTERNALFORMATIVPROC COpenGLFunctionTable::pGlGetInternalformativ = nullptr;
		PFNGLGETINTERNALFORMATI64VPROC COpenGLFunctionTable::pGlGetInternalformati64v = nullptr;

		PFNGLDEBUGMESSAGECONTROLPROC COpenGLFunctionTable::pGlDebugMessageControl = nullptr;
		PFNGLDEBUGMESSAGECONTROLARBPROC COpenGLFunctionTable::pGlDebugMessageControlARB = nullptr;
		PFNGLDEBUGMESSAGECALLBACKPROC COpenGLFunctionTable::pGlDebugMessageCallback = nullptr;
		PFNGLDEBUGMESSAGECALLBACKARBPROC COpenGLFunctionTable::pGlDebugMessageCallbackARB = nullptr;

#if defined(WGL_EXT_swap_control)
		PFNWGLSWAPINTERVALEXTPROC COpenGLFunctionTable::pWglSwapIntervalEXT = nullptr;
#endif
#if defined(GLX_SGI_swap_control)
		PFNGLXSWAPINTERVALSGIPROC COpenGLFunctionTable::pGlxSwapIntervalSGI = nullptr;
#endif
#if defined(GLX_EXT_swap_control)
		PFNGLXSWAPINTERVALEXTPROC COpenGLFunctionTable::pGlxSwapIntervalEXT = nullptr;
#endif
#if defined(GLX_MESA_swap_control)
		PFNGLXSWAPINTERVALMESAPROC COpenGLFunctionTable::pGlxSwapIntervalMESA = nullptr;
#endif

		core::CLeakDebugger COpenGLFunctionTable::bufferLeaker("GLBuffer");
		core::CLeakDebugger COpenGLFunctionTable::textureLeaker("GLTex");



		COpenGLFunctionTable::COpenGLFunctionTable() :
			StencilBuffer(false),
			TextureCompressionExtension(false)
		{
			DimAliasedLine[0] = 1.f;
			DimAliasedLine[1] = 1.f;
			DimAliasedPoint[0] = 1.f;
			DimAliasedPoint[1] = 1.f;
			DimSmoothedLine[0] = 1.f;
			DimSmoothedLine[1] = 1.f;
			DimSmoothedPoint[0] = 1.f;
			DimSmoothedPoint[1] = 1.f;
		}


		void COpenGLFunctionTable::dump(std::string* outStr, bool onlyAvailable) const
		{
			if (onlyAvailable)
			{
				for (uint32_t i = 0; i < IRR_OpenGL_Feature_Count; ++i)
				{
					if (FeatureAvailable[i])
					{
						if (outStr)
						{
							(*outStr) += OpenGLFeatureStrings[i];
							(*outStr) += "\n";
						}
						else
							os::Printer::log(OpenGLFeatureStrings[i]);
					}
				}
			}
			else
			{
				for (uint32_t i = 0; i < IRR_OpenGL_Feature_Count; ++i)
				{
					if (outStr)
					{
						(*outStr) += OpenGLFeatureStrings[i];
						(*outStr) += FeatureAvailable[i] ? " true\n" : " false\n";
					}
					else
						os::Printer::log(OpenGLFeatureStrings[i], FeatureAvailable[i] ? " true" : " false");
				}
			}
		}


		void COpenGLFunctionTable::dumpFramebufferFormats() const
		{
#ifdef _IRR_WINDOWS_API_
			HDC hdc = wglGetCurrentDC();
			std::string wglExtensions;
#ifdef WGL_ARB_extensions_string
			PFNWGLGETEXTENSIONSSTRINGARBPROC irrGetExtensionsString = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");
			if (irrGetExtensionsString)
				wglExtensions = irrGetExtensionsString(hdc);
#elif defined(WGL_EXT_extensions_string)
			PFNWGLGETEXTENSIONSSTRINGEXTPROC irrGetExtensionsString = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");
			if (irrGetExtensionsString)
				wglExtensions = irrGetExtensionsString(hdc);
#endif
			const bool pixel_format_supported = (wglExtensions.find("WGL_ARB_pixel_format") != std::string::npos);
			const bool multi_sample_supported = ((wglExtensions.find("WGL_ARB_multisample") != std::string::npos) ||
				(wglExtensions.find("WGL_EXT_multisample") != std::string::npos) || (wglExtensions.find("WGL_3DFX_multisample") != std::string::npos));
#ifdef _IRR_DEBUG
			os::Printer::log("WGL_extensions", wglExtensions);
#endif

#ifdef WGL_ARB_pixel_format
			PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat_ARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
			if (pixel_format_supported && wglChoosePixelFormat_ARB)
			{
				// This value determines the number of samples used for antialiasing
				// My experience is that 8 does not show a big
				// improvement over 4, but 4 shows a big improvement
				// over 2.

				PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribiv_ARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribivARB");
				if (wglGetPixelFormatAttribiv_ARB)
				{
					int vals[128];
					int atts[] = {
						WGL_NUMBER_PIXEL_FORMATS_ARB,
						WGL_DRAW_TO_BITMAP_ARB,
						WGL_ACCELERATION_ARB,
						WGL_NEED_PALETTE_ARB,
						WGL_NEED_SYSTEM_PALETTE_ARB,
						WGL_SWAP_LAYER_BUFFERS_ARB,
						WGL_SWAP_METHOD_ARB,
						WGL_NUMBER_OVERLAYS_ARB,
						WGL_NUMBER_UNDERLAYS_ARB,
						WGL_TRANSPARENT_ARB,
						WGL_TRANSPARENT_RED_VALUE_ARB,
						WGL_TRANSPARENT_GREEN_VALUE_ARB,
						WGL_TRANSPARENT_BLUE_VALUE_ARB,
						WGL_TRANSPARENT_ALPHA_VALUE_ARB,
						WGL_TRANSPARENT_INDEX_VALUE_ARB,
						WGL_SHARE_DEPTH_ARB,
						WGL_SHARE_STENCIL_ARB,
						WGL_SHARE_ACCUM_ARB,
						WGL_SUPPORT_GDI_ARB,
						WGL_SUPPORT_OPENGL_ARB,
						WGL_DOUBLE_BUFFER_ARB,
						WGL_STEREO_ARB,
						WGL_PIXEL_TYPE_ARB,
						WGL_COLOR_BITS_ARB,
						WGL_RED_BITS_ARB,
						WGL_RED_SHIFT_ARB,
						WGL_GREEN_BITS_ARB,
						WGL_GREEN_SHIFT_ARB,
						WGL_BLUE_BITS_ARB,
						WGL_BLUE_SHIFT_ARB,
						WGL_ALPHA_BITS_ARB,
						WGL_ALPHA_SHIFT_ARB,
						WGL_ACCUM_BITS_ARB,
						WGL_ACCUM_RED_BITS_ARB,
						WGL_ACCUM_GREEN_BITS_ARB,
						WGL_ACCUM_BLUE_BITS_ARB,
						WGL_ACCUM_ALPHA_BITS_ARB,
						WGL_DEPTH_BITS_ARB,
						WGL_STENCIL_BITS_ARB,
						WGL_AUX_BUFFERS_ARB
		#ifdef WGL_ARB_render_texture
						,WGL_BIND_TO_TEXTURE_RGB_ARB //40
						,WGL_BIND_TO_TEXTURE_RGBA_ARB
		#endif
		#ifdef WGL_ARB_pbuffer
						,WGL_DRAW_TO_PBUFFER_ARB //42
						,WGL_MAX_PBUFFER_PIXELS_ARB
						,WGL_MAX_PBUFFER_WIDTH_ARB
						,WGL_MAX_PBUFFER_HEIGHT_ARB
		#endif
		#ifdef WGL_ARB_framebuffer_sRGB
						,WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB //46
		#endif
		#ifdef WGL_ARB_multisample
						,WGL_SAMPLES_ARB //47
						,WGL_SAMPLE_BUFFERS_ARB
		#endif
		#ifdef WGL_EXT_depth_float
						,WGL_DEPTH_FLOAT_EXT //49
		#endif
						,0,0,0,0
					};
					size_t nums = sizeof(atts) / sizeof(int);
					const bool depth_float_supported = (wglExtensions.find("WGL_EXT_depth_float") != std::string::npos);
					if (!depth_float_supported)
					{
						memmove(&atts[49], &atts[50], (nums - 50) * sizeof(int));
						nums -= 1;
					}
					if (!multi_sample_supported)
					{
						memmove(&atts[47], &atts[49], (nums - 49) * sizeof(int));
						nums -= 2;
					}
					const bool framebuffer_sRGB_supported = (wglExtensions.find("WGL_ARB_framebuffer_sRGB") != std::string::npos);
					if (!framebuffer_sRGB_supported)
					{
						memmove(&atts[46], &atts[47], (nums - 47) * sizeof(int));
						nums -= 1;
					}
					const bool pbuffer_supported = (wglExtensions.find("WGL_ARB_pbuffer") != std::string::npos);
					if (!pbuffer_supported)
					{
						memmove(&atts[42], &atts[46], (nums - 46) * sizeof(int));
						nums -= 4;
					}
					const bool render_texture_supported = (wglExtensions.find("WGL_ARB_render_texture") != std::string::npos);
					if (!render_texture_supported)
					{
						memmove(&atts[40], &atts[42], (nums - 42) * sizeof(int));
						nums -= 2;
					}
					wglGetPixelFormatAttribiv_ARB(hdc, 0, 0, 1, atts, vals);
					const int count = vals[0];
					atts[0] = WGL_DRAW_TO_WINDOW_ARB;
					for (int i = 1; i < count; ++i)
					{
						memset(vals, 0, sizeof(vals));
#define tmplog(x,y) os::Printer::log(x, std::to_string(y))
						const BOOL res = wglGetPixelFormatAttribiv_ARB(hdc, i, 0, nums, atts, vals);
						if (FALSE == res)
							continue;
						tmplog("Pixel format ", i);
						uint32_t j = 0;
						tmplog("Draw to window ", vals[j]);
						tmplog("Draw to bitmap ", vals[++j]);
						++j;
						os::Printer::log("Acceleration ", (vals[j] == WGL_NO_ACCELERATION_ARB ? "No" :
							vals[j] == WGL_GENERIC_ACCELERATION_ARB ? "Generic" : vals[j] == WGL_FULL_ACCELERATION_ARB ? "Full" : "ERROR"));
						tmplog("Need palette ", vals[++j]);
						tmplog("Need system palette ", vals[++j]);
						tmplog("Swap layer buffers ", vals[++j]);
						++j;
						os::Printer::log("Swap method ", (vals[j] == WGL_SWAP_EXCHANGE_ARB ? "Exchange" :
							vals[j] == WGL_SWAP_COPY_ARB ? "Copy" : vals[j] == WGL_SWAP_UNDEFINED_ARB ? "Undefined" : "ERROR"));
						tmplog("Number of overlays ", vals[++j]);
						tmplog("Number of underlays ", vals[++j]);
						tmplog("Transparent ", vals[++j]);
						tmplog("Transparent red value ", vals[++j]);
						tmplog("Transparent green value ", vals[++j]);
						tmplog("Transparent blue value ", vals[++j]);
						tmplog("Transparent alpha value ", vals[++j]);
						tmplog("Transparent index value ", vals[++j]);
						tmplog("Share depth ", vals[++j]);
						tmplog("Share stencil ", vals[++j]);
						tmplog("Share accum ", vals[++j]);
						tmplog("Support GDI ", vals[++j]);
						tmplog("Support OpenGL ", vals[++j]);
						tmplog("Double Buffer ", vals[++j]);
						tmplog("Stereo Buffer ", vals[++j]);
						tmplog("Pixel type ", vals[++j]);
						tmplog("Color bits", vals[++j]);
						tmplog("Red bits ", vals[++j]);
						tmplog("Red shift ", vals[++j]);
						tmplog("Green bits ", vals[++j]);
						tmplog("Green shift ", vals[++j]);
						tmplog("Blue bits ", vals[++j]);
						tmplog("Blue shift ", vals[++j]);
						tmplog("Alpha bits ", vals[++j]);
						tmplog("Alpha Shift ", vals[++j]);
						tmplog("Accum bits ", vals[++j]);
						tmplog("Accum red bits ", vals[++j]);
						tmplog("Accum green bits ", vals[++j]);
						tmplog("Accum blue bits ", vals[++j]);
						tmplog("Accum alpha bits ", vals[++j]);
						tmplog("Depth bits ", vals[++j]);
						tmplog("Stencil bits ", vals[++j]);
						tmplog("Aux buffers ", vals[++j]);
						if (render_texture_supported)
						{
							tmplog("Bind to texture RGB", vals[++j]);
							tmplog("Bind to texture RGBA", vals[++j]);
						}
						if (pbuffer_supported)
						{
							tmplog("Draw to pbuffer", vals[++j]);
							tmplog("Max pbuffer pixels ", vals[++j]);
							tmplog("Max pbuffer width", vals[++j]);
							tmplog("Max pbuffer height", vals[++j]);
						}
						if (framebuffer_sRGB_supported)
							tmplog("Framebuffer sRBG capable", vals[++j]);
						if (multi_sample_supported)
						{
							tmplog("Samples ", vals[++j]);
							tmplog("Sample buffers ", vals[++j]);
						}
						if (depth_float_supported)
							tmplog("Depth float", vals[++j]);
#undef tmplog
					}
				}
			}
#endif
#elif defined(IRR_LINUX_DEVICE)
#endif
		}


		void COpenGLFunctionTable::initFunctions(bool stencilBuffer)
		{
			core::stringc vendorString = (char*)glGetString(GL_VENDOR);
			if (vendorString.find("Intel") != -1 || vendorString.find("INTEL") != -1)
				IsIntelGPU = true;

			if (SDL_Init(0) != 0) {
				printf("Error initializing SDL:  %s\n", SDL_GetError());
				return;
			}

			if (SDL_VideoInit(NULL) != 0) {
				printf("Error initializing SDL video:  %s\n", SDL_GetError());
				return;
			}
			if (SDL_GL_LoadLibrary(NULL) != 0)
			{
				printf("Error loading openGL library via SDL:  %s\n", SDL_GetError());
				return;
			}
			loadFunctions();


			TextureCompressionExtension = FeatureAvailable[IRR_ARB_texture_compression];
			StencilBuffer = stencilBuffer;


			GLint num = 0;

			glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &reqUBOAlignment);
			assert(core::is_alignment(reqUBOAlignment));
			glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &reqSSBOAlignment);
			assert(core::is_alignment(reqSSBOAlignment));
			glGetIntegerv(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT, &reqTBOAlignment);
			assert(core::is_alignment(reqTBOAlignment));

			extGlGetInteger64v(GL_MAX_UNIFORM_BLOCK_SIZE, reinterpret_cast<GLint64*>(&maxUBOSize));
			extGlGetInteger64v(GL_MAX_SHADER_STORAGE_BLOCK_SIZE, reinterpret_cast<GLint64*>(&maxSSBOSize));
			extGlGetInteger64v(GL_MAX_TEXTURE_BUFFER_SIZE, reinterpret_cast<GLint64*>(&maxTBOSizeInTexels));
			maxBufferSize = std::max(maxUBOSize, maxSSBOSize);

			glGetIntegerv(GL_MAX_COMBINED_UNIFORM_BLOCKS, reinterpret_cast<GLint*>(&maxUBOBindings));
			glGetIntegerv(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS, reinterpret_cast<GLint*>(&maxSSBOBindings));
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, reinterpret_cast<GLint*>(&maxTextureBindings));
			glGetIntegerv(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, reinterpret_cast<GLint*>(&maxTextureBindingsCompute));
			glGetIntegerv(GL_MAX_COMBINED_IMAGE_UNIFORMS, reinterpret_cast<GLint*>(&maxImageBindings));

			glGetIntegerv(GL_MIN_MAP_BUFFER_ALIGNMENT, &minMemoryMapAlignment);

			extGlGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, MaxComputeWGSize);
			extGlGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, MaxComputeWGSize + 1);
			extGlGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, MaxComputeWGSize + 2);


			glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, &num);
			MaxArrayTextureLayers = num;

			if (FeatureAvailable[IRR_EXT_texture_filter_anisotropic])
			{
				glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &num);
				MaxAnisotropy = static_cast<uint8_t>(num);
			}


			if (FeatureAvailable[IRR_ARB_geometry_shader4])
			{
				glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES, &num);
				MaxGeometryVerticesOut = static_cast<uint32_t>(num);
			}

			if (FeatureAvailable[IRR_EXT_texture_lod_bias])
				glGetFloatv(GL_MAX_TEXTURE_LOD_BIAS_EXT, &MaxTextureLODBias);


			glGetIntegerv(GL_MAX_CLIP_DISTANCES, &num);
			MaxUserClipPlanes = static_cast<uint8_t>(num);
			glGetIntegerv(GL_MAX_DRAW_BUFFERS, &num);
			MaxMultipleRenderTargets = static_cast<uint8_t>(num);

			glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, DimAliasedLine);
			glGetFloatv(GL_ALIASED_POINT_SIZE_RANGE, DimAliasedPoint);
			glGetFloatv(GL_SMOOTH_LINE_WIDTH_RANGE, DimSmoothedLine);
			glGetFloatv(GL_SMOOTH_POINT_SIZE_RANGE, DimSmoothedPoint);

			const GLubyte* shaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
			float sl_ver;
			sscanf(reinterpret_cast<const char*>(shaderVersion), "%f", &sl_ver);
			ShaderLanguageVersion = static_cast<uint16_t>(core::round(sl_ver * 100.0f));


			//! For EXT-DSA testing
			if (IsIntelGPU)
			{
				Version = 440;
				FeatureAvailable[IRR_ARB_direct_state_access] = false;
				pGlCreateTextures = nullptr;
				pGlTextureStorage1D = nullptr;
				pGlTextureStorage2D = nullptr;
				pGlTextureStorage3D = nullptr;
				pGlTextureStorage2DMultisample = nullptr;
				pGlTextureStorage3DMultisample = nullptr;
				pGlTextureSubImage1D = nullptr;
				pGlTextureSubImage2D = nullptr;
				pGlTextureSubImage3D = nullptr;
				pGlCompressedTextureSubImage1D = nullptr;
				pGlCompressedTextureSubImage2D = nullptr;
				pGlCompressedTextureSubImage3D = nullptr;
				pGlGenerateTextureMipmap = nullptr;
				pGlCreateSamplers = nullptr;
				pGlBindAttribLocation = nullptr;
				pGlBlitNamedFramebuffer = nullptr;
				pGlCreateFramebuffers = nullptr;
				pGlCheckNamedFramebufferStatus = nullptr;
				pGlNamedFramebufferTexture = nullptr;
				pGlNamedFramebufferTextureLayer = nullptr;
				pGlActiveStencilFaceEXT = nullptr;
				pGlNamedFramebufferReadBuffer = nullptr;
				pGlNamedFramebufferDrawBuffer = nullptr;
				pGlNamedFramebufferDrawBuffers = nullptr;
				pGlClearNamedFramebufferiv = nullptr;
				pGlClearNamedFramebufferuiv = nullptr;
				pGlClearNamedFramebufferfv = nullptr;
				pGlClearNamedFramebufferfi = nullptr;
				pGlCreateBuffers = nullptr;
				pGlNamedBufferStorage = nullptr;
				pGlNamedBufferSubData = nullptr;
				pGlGetNamedBufferSubData = nullptr;
				pGlMapNamedBuffer = nullptr;
				pGlMapNamedBufferRange = nullptr;
				pGlFlushMappedNamedBufferRange = nullptr;
				pGlUnmapNamedBuffer = nullptr;
				pGlClearNamedBufferData = nullptr;
				pGlClearNamedBufferSubData = nullptr;
				pGlCopyNamedBufferSubData = nullptr;
				pGlCreateVertexArrays = nullptr;
				pGlVertexArrayElementBuffer = nullptr;
				pGlVertexArrayVertexBuffer = nullptr;
				pGlVertexArrayAttribBinding = nullptr;
				pGlEnableVertexArrayAttrib = nullptr;
				pGlDisableVertexArrayAttrib = nullptr;
				pGlVertexArrayAttribFormat = nullptr;
				pGlVertexArrayAttribIFormat = nullptr;
				pGlVertexArrayAttribLFormat = nullptr;
				pGlVertexArrayBindingDivisor = nullptr;
				pGlBlendFuncIndexedAMD = nullptr;
				pGlBlendEquationIndexedAMD = nullptr;
				pGlBlendEquationiARB = nullptr;
				pGlCreateQueries = nullptr;
			}/*
			//! Non-DSA testing
			Version = 430;
			FeatureAvailable[IRR_EXT_direct_state_access] = FeatureAvailable[IRR_ARB_direct_state_access] = false;
			pGlTextureStorage1DEXT = nullptr;
			pGlTextureStorage2DEXT = nullptr;
			pGlTextureStorage3DEXT = nullptr;
			pGlTextureStorage2DMultisampleEXT = nullptr;
			pGlTextureStorage3DMultisampleEXT = nullptr;
			pGlTextureSubImage1DEXT = nullptr;
			pGlTextureSubImage2DEXT = nullptr;
			pGlTextureSubImage3DEXT = nullptr;
			pGlCompressedTextureSubImage1DEXT = nullptr;
			pGlCompressedTextureSubImage2DEXT = nullptr;
			pGlCompressedTextureSubImage3DEXT = nullptr;
			pGlGenerateTextureMipmapEXT = nullptr;
			pGlCheckNamedFramebufferStatusEXT = nullptr;
			pGlNamedFramebufferTextureEXT = nullptr;
			pGlNamedFramebufferTextureLayerEXT = nullptr;
			pGlFramebufferReadBufferEXT = nullptr;
			pGlFramebufferDrawBufferEXT = nullptr;
			pGlFramebufferDrawBuffersEXT = nullptr;
			pGlNamedBufferStorageEXT = nullptr;
			pGlNamedBufferSubDataEXT = nullptr;
			pGlGetNamedBufferSubDataEXT = nullptr;
			pGlMapNamedBufferEXT = nullptr;
			pGlMapNamedBufferRangeEXT = nullptr;
			pGlFlushMappedNamedBufferRangeEXT = nullptr;
			pGlUnmapNamedBufferEXT = nullptr;
			pGlClearNamedBufferDataEXT = nullptr;
			pGlClearNamedBufferSubDataEXT = nullptr;
			pGlNamedCopyBufferSubDataEXT = nullptr;
			pGlVertexArrayBindVertexBufferEXT = nullptr;
			pGlVertexArrayVertexAttribBindingEXT = nullptr;
			pGlEnableVertexArrayAttribEXT = nullptr;
			pGlDisableVertexArrayAttribEXT = nullptr;
			pGlVertexArrayVertexAttribFormatEXT = nullptr;
			pGlVertexArrayVertexAttribIFormatEXT = nullptr;
			pGlVertexArrayVertexAttribLFormatEXT = nullptr;
			pGlVertexArrayVertexBindingDivisorEXT = nullptr;
			pGlCreateQueries = nullptr;*/


			num = 0;
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &num);
			MaxTextureUnits = num;

			//num=100000000u;
			//glGetIntegerv(GL_MAX_ELEMENTS_INDICES,&num);
#ifdef WIN32
#ifdef _IRR_DEBUG
			if (FeatureAvailable[IRR_NVX_gpu_memory_info])
			{
				// undocumented flags, so use the RAW values
				GLint val;
				glGetIntegerv(0x9047, &val);
				os::Printer::log("Dedicated video memory (kB)", std::to_string(val));
				glGetIntegerv(0x9048, &val);
				os::Printer::log("Total video memory (kB)", std::to_string(val));
				glGetIntegerv(0x9049, &val);
				os::Printer::log("Available video memory (kB)", std::to_string(val));
			}
			if (FeatureAvailable[IRR_ATI_meminfo])
			{
				GLint val[4];
				glGetIntegerv(GL_TEXTURE_FREE_MEMORY_ATI, val);
				os::Printer::log("Free texture memory (kB)", std::to_string(val[0]));
				glGetIntegerv(GL_VBO_FREE_MEMORY_ATI, val);
				os::Printer::log("Free VBO memory (kB)", std::to_string(val[0]));
				glGetIntegerv(GL_RENDERBUFFER_FREE_MEMORY_ATI, val);
				os::Printer::log("Free render buffer memory (kB)", std::to_string(val[0]));
			}
#endif
#endif
		}

		void COpenGLFunctionTable::loadFunctions()
		{
			if (functionsAlreadyLoaded)
				return;

			for (uint32_t i = 0; i < IRR_OpenGL_Feature_Count; ++i)
				FeatureAvailable[i] = false;



#ifdef _IRR_WINDOWS_API_
#define IRR_OGL_SDL_LOAD_FUNCTIONPTR(x) SDL_GL_GetProcAddress(reinterpret_cast<const char*>(x))
#elif defined(_IRR_COMPILE_WITH_SDL_DEVICE_) && !defined(_IRR_COMPILE_WITH_X11_DEVICE_)
#define IRR_OGL_SDL_LOAD_FUNCTIONPTR(x) SDL_GL_GetProcAddress(reinterpret_cast<const char*>(x))
#else
#define IRR_OGL_SDL_LOAD_FUNCTIONPTR(X) glXGetProcAddress(reinterpret_cast<const GLubyte*>(X))
#endif // Windows, SDL, or Linux
			pGlIsEnabledi = (PFNGLISENABLEDIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsEnabledi");
			pGlEnablei = (PFNGLENABLEIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEnablei");
			pGlDisablei = (PFNGLDISABLEIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDisablei");
			pGlGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetBooleani_v");
			pGlGetFloati_v = (PFNGLGETFLOATI_VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetFloati_v");
			pGlGetInteger64v = (PFNGLGETINTEGER64VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetInteger64v");
			pGlGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetIntegeri_v");
			pGlGetStringi = (PFNGLGETSTRINGIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetStringi");

			//should contain space-separated OpenGL extension names
			constexpr const char* OPENGL_EXTS_ENVVAR_NAME = "_IRR_OPENGL_EXTENSIONS_LIST";//move this to some top-level header?

			const char* envvar = std::getenv(OPENGL_EXTS_ENVVAR_NAME);
			if (!envvar)
			{
				GLint extensionCount;
				glGetIntegerv(GL_NUM_EXTENSIONS, &extensionCount);
				for (GLint i = 0; i < extensionCount; ++i)
				{
					const char* extensionName = reinterpret_cast<const char*>(pGlGetStringi(GL_EXTENSIONS, i));

					for (uint32_t j = 0; j < IRR_OpenGL_Feature_Count; ++j)
					{
						if (!strcmp(OpenGLFeatureStrings[j], extensionName))
						{
							FeatureAvailable[j] = true;
							break;
						}
					}
				}
			}
			else
			{
				std::stringstream ss{ std::string(envvar) };
				std::string extname;
				extname.reserve(100);
				while (std::getline(ss, extname))
				{
					for (uint32_t j = 0; j < IRR_OpenGL_Feature_Count; ++j)
					{
						if (extname == OpenGLFeatureStrings[j])
						{
							FeatureAvailable[j] = true;
							break;
						}
					}
				}
			}

			float ogl_ver;
			sscanf(reinterpret_cast<const char*>(glGetString(GL_VERSION)), "%f", &ogl_ver);
			Version = static_cast<uint16_t>(core::round(ogl_ver * 100.0f));

			GLint num = 0;
			glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &num);
			MaxIndices = num;
			glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &num);
			MaxVertices = num;
			glGetIntegerv(GL_MAX_VERTEX_STREAMS, &num);
			MaxVertexStreams = num;
			glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS, &num);
			MaxXFormFeedbackComponents = num;
			glGetIntegerv(GL_MAX_SERVER_WAIT_TIMEOUT, &num);
			MaxGPUWaitTimeout = reinterpret_cast<const uint32_t&>(num);

			if (FeatureAvailable[IRR_NV_shader_thread_group])
			{
				glGetIntegerv(GL_WARP_SIZE_NV, &num);
				InvocationSubGroupSize[0] = InvocationSubGroupSize[1] = reinterpret_cast<const uint32_t&>(num);
			}
			else if (IsIntelGPU)
			{
				InvocationSubGroupSize[0] = 4;
				InvocationSubGroupSize[1] = 32;
			}

			if (FeatureAvailable[IRR_ARB_spirv_extensions])
			{
				glGetIntegerv(GL_NUM_SPIR_V_EXTENSIONS, reinterpret_cast<GLint*>(&SPIR_VextensionsCount));
				if (SPIR_VextensionsCount)
					SPIR_Vextensions = core::make_refctd_dynamic_array<core::smart_refctd_dynamic_array<const GLubyte*> >(SPIR_VextensionsCount);
				for (GLuint i = 0u; i < SPIR_VextensionsCount; ++i)
					(*SPIR_Vextensions)[i] = pGlGetStringi(GL_SPIR_V_EXTENSIONS, i);
			}
			else
			{
				SPIR_VextensionsCount = 0u;
			}

			/**
			pGl = () IRR_OGL_SDL_LOAD_FUNCTIONPTR("gl");
			**/
			pGlProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProvokingVertex");
			pGlClipControl = (PFNGLCLIPCONTROLPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClipControl");

			//fences
			pGlFenceSync = (PFNGLFENCESYNCPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFenceSync");
			pGlDeleteSync = (PFNGLDELETESYNCPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteSync");
			pGlClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClientWaitSync");
			pGlWaitSync = (PFNGLWAITSYNCPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glWaitSync");

			// get multitexturing function pointers
			pGlActiveTexture = (PFNGLACTIVETEXTUREPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glActiveTexture");
			pGlBindTextures = (PFNGLBINDTEXTURESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindTextures");
			pGlCreateTextures = (PFNGLCREATETEXTURESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateTextures");
			pGlTexStorage1D = (PFNGLTEXSTORAGE1DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexStorage1D");
			pGlTexStorage2D = (PFNGLTEXSTORAGE2DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexStorage2D");
			pGlTexStorage3D = (PFNGLTEXSTORAGE3DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexStorage3D");
			pGlTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexStorage2DMultisample");
			pGlTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexStorage3DMultisample");
			pGlTexBuffer = (PFNGLTEXBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexBuffer");
			pGlTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexBufferRange");
			pGlTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage1D");
			pGlTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage2D");
			pGlTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage3D");
			pGlTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage2DMultisample");
			pGlTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage3DMultisample");
			pGlTextureBuffer = (PFNGLTEXTUREBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureBuffer");
			pGlTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureBufferRange");
			pGlTextureView = (PFNGLTEXTUREVIEWPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureView");
			pGlTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage1DEXT");
			pGlTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage2DEXT");
			pGlTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage3DEXT");
			pGlTextureBufferEXT = (PFNGLTEXTUREBUFFEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureBufferEXT");
			pGlTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureBufferRangeEXT");
			pGlTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage2DMultisampleEXT");
			pGlTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureStorage3DMultisampleEXT");
			pGlGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureSubImage");
			pGlGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetCompressedTextureSubImage");
			pGlGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureImage");
			pGlGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureImageEXT");
			pGlGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetCompressedTextureImage");
			pGlGetCompressedTextureImageEXT = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetCompressedTextureImageEXT");
			pGlGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetCompressedTexImage");
			pGlTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexSubImage3D");
			pGlMultiTexSubImage1DEXT = (PFNGLMULTITEXSUBIMAGE1DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiTexSubImage1DEXT");
			pGlMultiTexSubImage2DEXT = (PFNGLMULTITEXSUBIMAGE2DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiTexSubImage2DEXT");
			pGlMultiTexSubImage3DEXT = (PFNGLMULTITEXSUBIMAGE3DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiTexSubImage3DEXT");
			pGlTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureSubImage1D");
			pGlTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureSubImage2D");
			pGlTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureSubImage3D");
			pGlTextureSubImage1DEXT = (PFNGLTEXTURESUBIMAGE1DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureSubImage1DEXT");
			pGlTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureSubImage2DEXT");
			pGlTextureSubImage3DEXT = (PFNGLTEXTURESUBIMAGE3DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureSubImage3DEXT");
			pGlCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTexSubImage1D");
			pGlCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTexSubImage2D");
			pGlCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTexSubImage3D");
			pGlCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTextureSubImage1D");
			pGlCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTextureSubImage2D");
			pGlCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTextureSubImage3D");
			pGlCompressedTextureSubImage1DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTextureSubImage1DEXT");
			pGlCompressedTextureSubImage2DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTextureSubImage2DEXT");
			pGlCompressedTextureSubImage3DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompressedTextureSubImage3DEXT");
			pGlCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCopyImageSubData");
			pGlTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureParameterIuiv");
			pGlTextureParameterIuivEXT = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureParameterIuivEXT");
			pGlTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTexParameterIuiv");
			pGlGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenerateMipmap");
			pGlGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenerateTextureMipmap");
			pGlGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenerateTextureMipmapEXT");
			pGlClampColor = (PFNGLCLAMPCOLORPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClampColor");

			//samplers
			pGlCreateSamplers = (PFNGLCREATESAMPLERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateSamplers");
			pGlGenSamplers = (PFNGLGENSAMPLERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenSamplers");
			pGlDeleteSamplers = (PFNGLDELETESAMPLERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteSamplers");
			pGlBindSampler = (PFNGLBINDSAMPLERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindSampler");
			pGlBindSamplers = (PFNGLBINDSAMPLERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindSamplers");
			pGlSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glSamplerParameteri");
			pGlSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glSamplerParameterf");
			pGlSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glSamplerParameterfv");

			//
			pGlBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindImageTexture");
			pGlBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindImageTextures");

			//bindless texture
			//ARB
			pGlGetTextureHandleARB = (PFNGLGETTEXTUREHANDLEARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureHandleARB");
			pGlGetTextureSamplerHandleARB = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureSamplerHandleARB");
			pGlMakeTextureHandleResidentARB = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeTextureHandleResidentAR");
			pGlMakeTextureHandleNonResidentARB = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeTextureHandleNonResidentARB");
			pGlGetImageHandleARB = (PFNGLGETIMAGEHANDLEARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetImageHandleARB");
			pGlMakeImageHandleResidentARB = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeImageHandleResidentARB");
			pGlMakeImageHandleNonResidentARB = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeImageHandleNonResidentARB");
			pGlIsTextureHandleResidentARB = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsTextureHandleResidentARB");
			pGlIsImageHandleResidentARB = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsImageHandleResidentARB");
			//NV
			pGlGetTextureHandleNV = (PFNGLGETTEXTUREHANDLENVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureHandleNV");
			pGlGetTextureSamplerHandleNV = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetTextureSamplerHandleNV");
			pGlMakeTextureHandleResidentNV = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeTextureHandleResidentAR");
			pGlMakeTextureHandleNonResidentNV = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeTextureHandleNonResidentNV");
			pGlGetImageHandleNV = (PFNGLGETIMAGEHANDLENVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetImageHandleNV");
			pGlMakeImageHandleResidentNV = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeImageHandleResidentNV");
			pGlMakeImageHandleNonResidentNV = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMakeImageHandleNonResidentNV");
			pGlIsTextureHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsTextureHandleResidentNV");
			pGlIsImageHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsImageHandleResidentNV");

			//
			pGlBindBufferBase = (PFNGLBINDBUFFERBASEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindBufferBase");
			pGlBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindBufferRange");
			pGlBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindBuffersBase");
			pGlBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindBuffersRange");

			// get fragment and vertex program function pointers
			pGlCreateShader = (PFNGLCREATESHADERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateShader");
			pGlCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateShaderProgramv");
			pGlCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateProgramPipelines");
			pGlDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteProgramPipelines");
			pGlUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glUseProgramStages");
			pGlShaderSource = (PFNGLSHADERSOURCEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glShaderSource");
			pGlCompileShader = (PFNGLCOMPILESHADERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCompileShader");
			pGlCreateProgram = (PFNGLCREATEPROGRAMPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateProgram");
			pGlAttachShader = (PFNGLATTACHSHADERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glAttachShader");
			pGlTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTransformFeedbackVaryings");
			pGlLinkProgram = (PFNGLLINKPROGRAMPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glLinkProgram");
			pGlUseProgram = (PFNGLUSEPROGRAMPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glUseProgram");
			pGlDeleteProgram = (PFNGLDELETEPROGRAMPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteProgram");
			pGlDeleteShader = (PFNGLDELETESHADERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteShader");
			pGlGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetAttachedShaders");
			pGlGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetShaderInfoLog");
			pGlGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetProgramInfoLog");
			pGlGetShaderiv = (PFNGLGETSHADERIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetShaderiv");
			pGlGetProgramiv = (PFNGLGETPROGRAMIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetProgramiv");
			pGlGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetUniformLocation");
			pGlProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform1fv");
			pGlProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform2fv");
			pGlProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform3fv");
			pGlProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform4fv");
			pGlProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform1iv");
			pGlProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform2iv");
			pGlProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform3iv");
			pGlProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform4iv");
			pGlProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform1uiv");
			pGlProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform2uiv");
			pGlProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform3uiv");
			pGlProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniform4uiv");
			pGlProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix2fv");
			pGlProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix3fv");
			pGlProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix4fv");
			pGlProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix2x3fv");
			pGlProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix3x2fv");
			pGlProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix4x2fv");
			pGlProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix2x4fv");
			pGlProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix3x4fv");
			pGlProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramUniformMatrix4x3fv");
			pGlGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetActiveUniform");
			pGlBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindProgramPipeline");
			pGlGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetProgramBinary");
			pGlProgramBinary = (PFNGLPROGRAMBINARYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramBinary");

			//Criss
			pGlMemoryBarrier = (PFNGLMEMORYBARRIERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMemoryBarrier");
			pGlDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDispatchCompute");
			pGlDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDispatchComputeIndirect");

			// get point parameter extension
			pGlPointParameterf = (PFNGLPOINTPARAMETERFARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glPointParameterf");
			pGlPointParameterfv = (PFNGLPOINTPARAMETERFVARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glPointParameterfv");

			//ROP
			pGlBlendColor = (PFNGLBLENDCOLORPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendColor");
			pGlDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDepthRangeIndexed");
			pGlViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glViewportIndexedfv");
			pGlScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glScissorIndexedv");
			pGlSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glSampleCoverage");
			pGlSampleMaski = (PFNGLSAMPLEMASKIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glSampleMaski");
			pGlMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMinSampleShading");
			pGlBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendEquationSeparatei");
			pGlBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendFuncSeparatei");
			pGlColorMaski = (PFNGLCOLORMASKIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glColorMaski");
			pGlStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glStencilFuncSeparate");
			pGlStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glStencilOpSeparate");
			pGlStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glStencilMaskSeparate");

			// ARB FrameBufferObjects
			pGlBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlitNamedFramebuffer");
			pGlBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlitFramebuffer");
			pGlDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteFramebuffers");
			pGlCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateFramebuffers");
			pGlGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenFramebuffers");
			pGlBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindFramebuffer");
			pGlCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCheckFramebufferStatus");
			pGlCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCheckNamedFramebufferStatus");
			pGlCheckNamedFramebufferStatusEXT = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCheckNamedFramebufferStatusEXT");
			pGlFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFramebufferTexture");
			pGlNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferTexture");
			pGlNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferTextureEXT");
			pGlFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFramebufferTextureLayer");
			pGlNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferTextureLayer");
			pGlNamedFramebufferTextureLayerEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferTextureLayerEXT");
			pGlFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFramebufferTexture2D");
			pGlNamedFramebufferTexture2DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferTexture2DEXT");
			pGlDrawBuffers = (PFNGLDRAWBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawBuffers");
			pGlNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferDrawBuffers");
			pGlFramebufferDrawBuffersEXT = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFramebufferDrawBuffersEXT");
			pGlNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferDrawBuffer");
			pGlFramebufferDrawBufferEXT = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFramebufferDrawBufferEXT");
			pGlNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedFramebufferReadBuffer");
			pGlFramebufferReadBufferEXT = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFramebufferReadBufferEXT");
			pGlClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedFramebufferiv");
			pGlClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedFramebufferuiv");
			pGlClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedFramebufferfv");
			pGlClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedFramebufferfi");
			pGlClearBufferiv = (PFNGLCLEARBUFFERIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearBufferiv");
			pGlClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearBufferuiv");
			pGlClearBufferfv = (PFNGLCLEARBUFFERFVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearBufferfv");
			pGlClearBufferfi = (PFNGLCLEARBUFFERFIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearBufferfi");

			// get vertex buffer extension
			pGlGenBuffers = (PFNGLGENBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenBuffers");
			pGlCreateBuffers = (PFNGLCREATEBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateBuffers");
			pGlBindBuffer = (PFNGLBINDBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindBuffer");
			pGlDeleteBuffers = (PFNGLDELETEBUFFERSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteBuffers");
			pGlBufferStorage = (PFNGLBUFFERSTORAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBufferStorage");
			pGlNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedBufferStorage");
			pGlNamedBufferStorageEXT = (PFNGLNAMEDBUFFERSTORAGEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedBufferStorageEXT");
			pGlBufferSubData = (PFNGLBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBufferSubData");
			pGlNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedBufferSubData");
			pGlNamedBufferSubDataEXT = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedBufferSubDataEXT");
			pGlGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetBufferSubData");
			pGlGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetNamedBufferSubData");
			pGlGetNamedBufferSubDataEXT = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetNamedBufferSubDataEXT");
			pGlMapBuffer = (PFNGLMAPBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMapBuffer");
			pGlMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMapNamedBuffer");
			pGlMapNamedBufferEXT = (PFNGLMAPNAMEDBUFFEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMapNamedBufferEXT");
			pGlMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMapBufferRange");
			pGlMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMapNamedBufferRange");
			pGlMapNamedBufferRangeEXT = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMapNamedBufferRangeEXT");
			pGlFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFlushMappedBufferRange");
			pGlFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFlushMappedNamedBufferRange");
			pGlFlushMappedNamedBufferRangeEXT = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glFlushMappedNamedBufferRangeEXT");
			pGlUnmapBuffer = (PFNGLUNMAPBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glUnmapBuffer");
			pGlUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glUnmapNamedBuffer");
			pGlUnmapNamedBufferEXT = (PFNGLUNMAPNAMEDBUFFEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glUnmapNamedBufferEXT");
			pGlClearBufferData = (PFNGLCLEARBUFFERDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearBufferData");
			pGlClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedBufferData");
			pGlClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedBufferDataEXT");
			pGlClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearBufferSubData");
			pGlClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedBufferSubData");
			pGlClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glClearNamedBufferSubDataEXT");
			pGlCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCopyBufferSubData");
			pGlCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCopyNamedBufferSubData");
			pGlNamedCopyBufferSubDataEXT = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glNamedCopyBufferSubDataEXT");
			pGlIsBuffer = (PFNGLISBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsBuffer");
			pGlGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetNamedBufferParameteri64v");
			pGlGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetBufferParameteri64v");
			pGlGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetNamedBufferParameteriv");
			pGlGetNamedBufferParameterivEXT = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetNamedBufferParameterivEXT");
			pGlGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetBufferParameteriv");
			//vao
			pGlGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenVertexArrays");
			pGlCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateVertexArrays");
			pGlDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteVertexArrays");
			pGlBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindVertexArray");
			pGlVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayElementBuffer");
			pGlBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindVertexBuffer");
			pGlVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayVertexBuffer");
			pGlVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayBindVertexBufferEXT");
			pGlVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexAttribBinding");
			pGlVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayAttribBinding");
			pGlVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayVertexAttribBindingEXT");
			pGlEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEnableVertexAttribArray");
			pGlEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEnableVertexArrayAttrib");
			pGlEnableVertexArrayAttribEXT = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEnableVertexArrayAttribEXT");
			pGlDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDisableVertexAttribArray");
			pGlDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDisableVertexArrayAttrib");
			pGlDisableVertexArrayAttribEXT = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDisableVertexArrayAttribEXT");
			pGlVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexAttribFormat");
			pGlVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexAttribIFormat");
			pGlVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexAttribLFormat");
			pGlVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayAttribFormat");
			pGlVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayAttribIFormat");
			pGlVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayAttribLFormat");
			pGlVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayVertexAttribFormatEXT");
			pGlVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayVertexAttribIFormatEXT");
			pGlVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayVertexAttribLFormatEXT");
			pGlVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayBindingDivisor");
			pGlVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexArrayVertexBindingDivisorEXT");
			pGlVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glVertexBindingDivisor");
			//
			pGlPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glPrimitiveRestartIndex");
			pGlDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawArraysInstanced");
			pGlDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawArraysInstancedBaseInstance");
			pGlDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawElementsInstancedBaseVertex");
			pGlDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawElementsInstancedBaseVertexBaseInstance");
			pGlDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawTransformFeedback");
			pGlDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawTransformFeedbackInstanced");
			pGlDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawTransformFeedbackStream");
			pGlDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawTransformFeedbackStreamInstanced");
			pGlDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawArraysIndirect");
			pGlDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDrawElementsIndirect");
			pGlMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiDrawArraysIndirect");
			pGlMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiDrawElementsIndirect");
			if (Version >= 460)
			{
				pGlMultiDrawArrysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiDrawArraysIndirectCount");
				pGlMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiDrawElementsIndirectCount");
			}
			else if (FeatureAvailable[IRR_ARB_indirect_parameters])
			{
				pGlMultiDrawArrysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiDrawArraysIndirectCountARB");
				pGlMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glMultiDrawElementsIndirectCountARB");
			}
			//
			pGlCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateTransformFeedbacks");
			pGlGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenTransformFeedbacks");
			pGlDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteTransformFeedbacks");
			pGlBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBindTransformFeedback");
			pGlBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBeginTransformFeedback");
			pGlPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glPauseTransformFeedback");
			pGlResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glResumeTransformFeedback");
			pGlEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEndTransformFeedback");
			pGlTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTransformFeedbackBufferBase");
			pGlTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTransformFeedbackBufferRange");
			//
			pGlBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendFuncSeparate");
			pGlEnablei = (PFNGLENABLEIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEnablei");
			pGlDisablei = (PFNGLDISABLEIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDisablei");
			pGlBlendFuncIndexedAMD = (PFNGLBLENDFUNCINDEXEDAMDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendFuncIndexedAMD");
			pGlBlendFunciARB = (PFNGLBLENDFUNCIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendFunciARB");
			pGlBlendEquationIndexedAMD = (PFNGLBLENDEQUATIONINDEXEDAMDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendEquationIndexedAMD");
			pGlBlendEquationiARB = (PFNGLBLENDEQUATIONIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendEquationiARB");
			pGlProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glProgramParameteri");
			pGlPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glPatchParameterfv");
			pGlPatchParameteri = (PFNGLPATCHPARAMETERIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glPatchParameteri");

			// occlusion query
			pGlCreateQueries = (PFNGLCREATEQUERIESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glCreateQueries");
			pGlGenQueries = (PFNGLGENQUERIESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGenQueries");
			pGlDeleteQueries = (PFNGLDELETEQUERIESPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDeleteQueries");
			pGlIsQuery = (PFNGLISQUERYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glIsQuery");
			pGlBeginQuery = (PFNGLBEGINQUERYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBeginQuery");
			pGlEndQuery = (PFNGLENDQUERYPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEndQuery");
			pGlBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBeginQueryIndexed");
			pGlEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEndQueryIndexed");
			pGlGetQueryiv = (PFNGLGETQUERYIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetQueryiv");
			pGlGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetQueryObjectuiv");
			pGlGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetQueryObjectui64v");
			pGlGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetQueryBufferObjectuiv");
			pGlGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetQueryBufferObjectui64v");
			pGlQueryCounter = (PFNGLQUERYCOUNTERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glQueryCounter");
			pGlBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBeginConditionalRender");
			pGlEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glEndConditionalRender");

			if (FeatureAvailable[IRR_ARB_texture_barrier])
				pGlTextureBarrier = (PFNGLTEXTUREBARRIERPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureBarrier");
			else if (FeatureAvailable[IRR_NV_texture_barrier])
				pGlTextureBarrierNV = (PFNGLTEXTUREBARRIERNVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glTextureBarrierNV");


			pGlDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDebugMessageControl");
			pGlDebugMessageControlARB = (PFNGLDEBUGMESSAGECONTROLARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDebugMessageControlARB");
			pGlDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDebugMessageCallback");
			pGlDebugMessageCallbackARB = (PFNGLDEBUGMESSAGECALLBACKARBPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glDebugMessageCallbackARB");

			// blend equation
			pGlBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendEquationEXT");
			pGlBlendEquation = (PFNGLBLENDEQUATIONPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glBlendEquation");

			pGlGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetInternalformativ");
			pGlGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glGetInternalformati64v");

			// get vsync extension
#if defined(WGL_EXT_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			pWglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("wglSwapIntervalEXT");
#endif
#if defined(GLX_SGI_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			pGlxSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glXSwapIntervalSGI");
#endif
#if defined(GLX_EXT_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			pGlxSwapIntervalEXT = (PFNGLXSWAPINTERVALEXTPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glXSwapIntervalEXT");
#endif
#if defined(GLX_MESA_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			pGlxSwapIntervalMESA = (PFNGLXSWAPINTERVALMESAPROC)IRR_OGL_SDL_LOAD_FUNCTIONPTR("glXSwapIntervalMESA");
#endif

			functionsAlreadyLoaded = true;
		}


		bool COpenGLFunctionTable::isDeviceCompatibile(core::vector<std::string>* failedExtensions)
		{
			bool retval = true;

			if (Version < 430)
			{
				retval = false;
				std::string error = "OpenGL Version Lower Than 4.3\n";
				if (failedExtensions)
					failedExtensions->push_back(error);
				else
					os::Printer::log(error.c_str(), ELL_ERROR);
			}

			if (!(FeatureAvailable[IRR_EXT_texture_filter_anisotropic] || Version >= 460))
			{
				retval = false;
				std::string error = "No anisotropic filtering\n";
				if (failedExtensions)
					failedExtensions->push_back(error);
				else
					os::Printer::log(error.c_str(), ELL_ERROR);
			}

			if (!(FeatureAvailable[IRR_EXT_texture_compression_s3tc]))
			{
				retval = false;
				std::string error = "DXTn compression missing\n";
				if (failedExtensions)
					failedExtensions->push_back(error);
				else
					os::Printer::log(error.c_str(), ELL_ERROR);
			}

			if (!(FeatureAvailable[IRR_ARB_buffer_storage] || Version >= 440))
			{
				retval = false;
				std::string error = "GL_ARB_buffer_storage missing\n";
				if (failedExtensions)
					failedExtensions->push_back(error);
				else
					os::Printer::log(error.c_str(), ELL_ERROR);
			}

			if (!(FeatureAvailable[IRR_ARB_clip_control] || Version >= 450))
			{
				retval = false;
				std::string error = "GL_ARB_clip_control missing\n";
				if (failedExtensions)
					failedExtensions->push_back(error);
				else
					os::Printer::log(error.c_str(), ELL_ERROR);
			}

			if (!(FeatureAvailable[IRR_ARB_direct_state_access] || FeatureAvailable[IRR_EXT_direct_state_access] || Version >= 450))
			{
				retval = false;
				std::string error = "Direct State Access Extension missing\n";
				if (failedExtensions)
					failedExtensions->push_back(error);
				else
					os::Printer::log(error.c_str(), ELL_ERROR);
			}


			return retval;
		}

	}
}
//#endif