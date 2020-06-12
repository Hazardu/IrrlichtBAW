#ifndef __C_OPEN_GL_FUNCTION_TABLE_H_INCLUDED__
#define __C_OPEN_GL_FUNCTION_TABLE_H_INCLUDED__

#include "IrrCompileConfig.h"
#include "irr/core/core.h"
#include "irr/system/system.h"
//#ifdef _IRR_COMPILE_WITH_OPENGL

#include "COpenGLStateManager.h"
#ifdef _IRR_WINDOWS_API_
// include windows headers for HWND
#include "../src/3rdparty/GL/wglext.h"
#elif defined(_IRR_COMPILE_WITH_X11_)
#include "GL/glx.h"
#include "../src/3rdparty/GL/glxext.h"
#endif

#include "SDL2/include/SDL.h"
#include "os.h"
#include "irr/video/IGPUImageView.h"
#include <irr\system\DynamicFunctionCaller.h>
namespace irr { namespace video {
		
	class COpenGLFunctionTable
	{
	public:


		class OpenGLFunctionLoader final : system::FuncPtrLoader
		{
		public:
			OpenGLFunctionLoader() {}
			/*	OpenGLFunctionLoader(FUNC_PTR_TYPE _pGlGetProcAdress) : pGlGetProcAdress(_pGlGetProcAdress) {}*/
			OpenGLFunctionLoader(OpenGLFunctionLoader&& other) : OpenGLFunctionLoader()
			{
				operator=(std::move(other));
			}
			
			inline bool isLibraryLoaded() override final
			{
				//todo library loader - is sdl loaded
				return true;
			}

			inline void* loadFuncPtr(const char* funcname) override final
			{
				return SDL_GL_GetProcAddress(funcname);
			}
		};
		// im temporairly putting // after those which have a public inline function that uses them
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLsync, OpenGLFunctionLoader
			,glFenceSync
			,glDeleteSync,
			,glClientWaitSync
			,glWaitSync
			,glTextureBarrier
			,glTextureBarrierNV
			,glMemoryBarrier
			,glClientWaitSync	//
		);
		
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLframeBuffer, OpenGLFunctionLoader
			,glBlitNamedFramebuffer
			,glBlitFramebuffer
			,glDeleteFramebuffers
			,glCreateFramebuffers
			,glGenFramebuffers
			,glBindFramebuffer
			,glCheckFramebufferStatus
			,glCheckNamedFramebufferStatus
			,glCheckNamedFramebufferStatusEXT
			,glFramebufferTexture
			,glNamedFramebufferTexture
			,glNamedFramebufferTextureEXT
			,glFramebufferTextureLayer
			,glNamedFramebufferTextureLayer
			,glNamedFramebufferTextureLayerEXT
			,glFramebufferTexture2D
			,glNamedFramebufferTexture2DEXT
			,glNamedFramebufferDrawBuffers
			,glFramebufferDrawBuffersEXT
			,glNamedFramebufferDrawBuffer
			,glFramebufferDrawBufferEXT
			,glNamedFramebufferReadBuffer
			,glFramebufferReadBufferEXT
			,glClearNamedFramebufferiv
			,glClearNamedFramebufferuiv
			,glClearNamedFramebufferfv
			,glClearNamedFramebufferfi
			,glClearBufferiv
			,glClearBufferuiv
			,glClearBufferfv
			,glClearBufferfi
			,glDrawBuffers
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLbuffer, OpenGLFunctionLoader
			,glBindBufferBase
			,glBindBufferRange
			,glBindBuffersBase
			,glBindBuffersRange
			,glGenBuffers
			,glCreateBuffers
			,glBindBuffer
			,glDeleteBuffers
			,glBufferStorage
			,glNamedBufferStorage
			,glNamedBufferStorageEXT
			,glBufferSubData
			,glNamedBufferSubData
			,glNamedBufferSubDataEXT
			,glGetBufferSubData
			,glGetNamedBufferSubData
			,glGetNamedBufferSubDataEXT
			,glMapBuffer
			,glMapNamedBuffer
			,glMapNamedBufferEXT
			,glMapBufferRange
			,glMapNamedBufferRange
			,glMapNamedBufferRangeEXT
			,glFlushMappedBufferRange
			,glFlushMappedNamedBufferRange
			,glFlushMappedNamedBufferRangeEXT
			,glUnmapBuffer
			,glUnmapNamedBuffer
			,glUnmapNamedBufferEXT
			,glClearBufferData
			,glClearNamedBufferData
			,glClearNamedBufferDataEXT
			,glClearBufferSubData
			,glClearNamedBufferSubData
			,glClearNamedBufferSubDataEXT
			,glCopyBufferSubData
			,glCopyNamedBufferSubData
			,glNamedCopyBufferSubDataEXT
			,glIsBuffer
			,glGetNamedBufferParameteri64v
			,glGetBufferParameteri64v
			,glGetNamedBufferParameteriv
			,glGetNamedBufferParameterivEXT
			,glGetBufferParameteriv
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLtexture, OpenGLFunctionLoader
			,glActiveTexture
			,glBindTextures
			,glCreateTextures
			,glTexStorage1D
			,glTexStorage2D
			,glTexStorage3D
			,glTexStorage2DMultisample
			,glTexStorage3DMultisample
			,glTexBuffer
			,glTexBufferRange
			,glTextureStorage1D
			,glTextureStorage2D
			,glTextureStorage3D
			,glTextureStorage2DMultisample
			,glTextureStorage3DMultisample
			,glTextureBuffer
			,glTextureBufferRange
			,glTextureView
			,glTextureStorage1DEXT
			,glTextureStorage2DEXT
			,glTextureStorage3DEXT
			,glTextureBufferEXT
			,glTextureBufferRangeEXT
			,glTextureStorage2DMultisampleEXT
			,glTextureStorage3DMultisampleEXT
			,glGetTextureSubImage
			,glGetCompressedTextureSubImage
			,glGetTextureImage
			,glGetTextureImageEXT
			,glGetCompressedTextureImage
			,glGetCompressedTextureImageEXT
			,glGetCompressedTexImage
			,glTexSubImage3D
			,glMultiTexSubImage1DEXT
			,glMultiTexSubImage2DEXT
			,glMultiTexSubImage3DEXT
			,glTextureSubImage1D
			,glTextureSubImage2D
			,glTextureSubImage3D
			,glTextureSubImage1DEXT
			,glTextureSubImage2DEXT
			,glTextureSubImage3DEXT
			,glCompressedTexSubImage1D
			,glCompressedTexSubImage2D
			,glCompressedTexSubImage3D
			,glCompressedTextureSubImage1D
			,glCompressedTextureSubImage2D
			,glCompressedTextureSubImage3D
			,glCompressedTextureSubImage1DEXT
			,glCompressedTextureSubImage2DEXT
			,glCompressedTextureSubImage3DEXT
			,glCopyImageSubData
			,glTextureParameterIuiv
			,glTextureParameterIuivEXT
			,glTexParameterIuiv
			,glGenerateMipmap
			,glGenerateTextureMipmap
			,glGenerateTextureMipmapEXT
			,glClampColor
			,glCreateSamplers
			,glGenSamplers
			,glDeleteSamplers
			,glBindSampler
			,glBindSamplers
			,glSamplerParameteri
			,glSamplerParameterf
			,glSamplerParameterfv
			,glBindImageTexture
			,glBindImageTextures
			,glGetTextureHandleARB
			,glGetTextureSamplerHandleARB
			,glMakeTextureHandleResidentAR
			,glMakeTextureHandleNonResidentARB
			,glGetImageHandleARB
			,glMakeImageHandleResidentARB
			,glMakeImageHandleNonResidentARB
			,glIsTextureHandleResidentARB
			,glIsImageHandleResidentARB
			,glGetTextureHandleNV
			,glGetTextureSamplerHandleNV
			,glMakeTextureHandleResidentAR
			,glMakeTextureHandleNonResidentNV
			,glGetImageHandleNV
			,glMakeImageHandleResidentNV
			,glMakeImageHandleNonResidentNV
			,glIsTextureHandleResidentNV
			,glIsImageHandleResidentNV
			
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLshader, OpenGLFunctionLoader	
			,glCreateShader
			,glCreateShaderProgramv
			,glCreateProgramPipelines
			,glDeleteProgramPipelines
			,glUseProgramStages
			,glShaderSource
			,glCompileShader
			,glCreateProgram
			,glAttachShader
			,glTransformFeedbackVaryings
			,glLinkProgram
			,glUseProgram
			,glDeleteProgram
			,glDeleteShader
			,glGetAttachedShaders
			,glGetShaderInfoLog
			,glGetProgramInfoLog
			,glGetShaderiv
			,glGetProgramiv
			,glGetUniformLocation
			,glProgramUniform1fv
			,glProgramUniform2fv
			,glProgramUniform3fv
			,glProgramUniform4fv
			,glProgramUniform1iv
			,glProgramUniform2iv
			,glProgramUniform3iv
			,glProgramUniform4iv
			,glProgramUniform1uiv
			,glProgramUniform2uiv
			,glProgramUniform3uiv
			,glProgramUniform4uiv
			,glProgramUniformMatrix2fv
			,glProgramUniformMatrix3fv
			,glProgramUniformMatrix4fv
			,glProgramUniformMatrix2x3fv
			,glProgramUniformMatrix3x2fv
			,glProgramUniformMatrix4x2fv
			,glProgramUniformMatrix2x4fv
			,glProgramUniformMatrix3x4fv
			,glProgramUniformMatrix4x3fv
			,glGetActiveUniform
			,glBindProgramPipeline
			,glGetProgramBinary
			,glProgramBinary
			,glProgramParameteri
			,glPatchParameterfv
			,glPatchParameteri
			,glDepthMask
			,glPixelStorei
			,glPolygonOffset
			,glPointSize
			,glLineWidth
			,glDepthFunc
			,glHint

		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLfragment, OpenGLFunctionLoader
			,glPointParameterf
			,glPointParameterfv
			,glBlendEquationEXT
			,glBlendEquation
			,glBlendColor
			,glDepthRangeIndexed
			,glViewportIndexedfv
			,glScissorIndexedv
			,glSampleCoverage
			,glSampleMaski
			,glMinSampleShading
			,glBlendEquationSeparatei
			,glBlendFuncSeparatei
			,glColorMaski
			,glStencilFuncSeparate
			,glStencilOpSeparate
			,glStencilMaskSeparate
			,glBlendFuncIndexedAMD
			,glBlendFunciARB
			,glBlendEquationIndexedAMD
			,glBlendEquationiARB
			,glBlendFuncSeparate
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLvertex, OpenGLFunctionLoader
			,glGenVertexArrays
			,glCreateVertexArrays
			,glDeleteVertexArrays
			,glBindVertexArray
			,glVertexArrayElementBuffer
			,glBindVertexBuffer
			,glVertexArrayVertexBuffer
			,glVertexArrayBindVertexBufferEXT
			,glVertexAttribBinding
			,glVertexArrayAttribBinding
			,glVertexArrayVertexAttribBindingEXT
			,glEnableVertexAttribArray
			,glEnableVertexArrayAttrib
			,glEnableVertexArrayAttribEXT
			,glDisableVertexAttribArray
			,glDisableVertexArrayAttrib
			,glDisableVertexArrayAttribEXT
			,glVertexAttribFormat
			,glVertexAttribIFormat
			,glVertexAttribLFormat
			,glVertexArrayAttribFormat
			,glVertexArrayAttribIFormat
			,glVertexArrayAttribLFormat
			,glVertexArrayVertexAttribFormatEXT
			,glVertexArrayVertexAttribIFormatEXT
			,glVertexArrayVertexAttribLFormatEXT
			,glVertexArrayBindingDivisor
			,glVertexArrayVertexBindingDivisorEXT
			,glVertexBindingDivisor
			,glProvokingVertex
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLdrawing, OpenGLFunctionLoader
			,glPrimitiveRestartIndex
			,glDrawArraysInstanced
			,glDrawArraysInstancedBaseInstance
			,glDrawElementsInstancedBaseVertex
			,glDrawElementsInstancedBaseVertexBaseInstance
			,glDrawTransformFeedback
			,glDrawTransformFeedbackInstanced
			,glDrawTransformFeedbackStream
			,glDrawTransformFeedbackStreamInstanced
			,glDrawArraysIndirect
			,glDrawElementsIndirect
			,glMultiDrawArraysIndirect
			,glMultiDrawElementsIndirect
			,glMultiDrawArraysIndirectCount
			,glMultiDrawElementsIndirectCount
			,glMultiDrawArraysIndirectCountARB
			,glMultiDrawElementsIndirectCountARB
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLtransformFeedback, OpenGLFunctionLoader
			,glCreateTransformFeedbacks
			,glGenTransformFeedbacks
			,glDeleteTransformFeedbacks
			,glBindTransformFeedback
			,glBeginTransformFeedback
			,glPauseTransformFeedback
			,glResumeTransformFeedback
			,glEndTransformFeedback
			,glTransformFeedbackBufferBase
			,glTransformFeedbackBufferRange
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLquery, OpenGLFunctionLoader
			,glCreateQueries
			,glGenQueries
			,glDeleteQueries
			,glIsQuery
			,glBeginQuery
			,glEndQuery
			,glBeginQueryIndexed
			,glEndQueryIndexed
			,glGetQueryiv
			,glGetQueryObjectuiv
			,glGetQueryObjectui64v
			,glGetQueryBufferObjectuiv
			,glGetQueryBufferObjectui64v
			,glQueryCounter
			,glBeginConditionalRender
			,glEndConditionalRender
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLdebug, OpenGLFunctionLoader
			,glDebugMessageControl
			,glDebugMessageControlARB
			,glDebugMessageCallback
			,glDebugMessageCallbackARB
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLOS, OpenGLFunctionLoader
#if defined(WGL_EXT_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			,wglSwapIntervalEXT
#endif
#if defined(GLX_SGI_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			,glXSwapIntervalSGI
#endif
#if defined(GLX_EXT_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			,glXSwapIntervalEXT
#endif
#if defined(GLX_MESA_swap_control) && !defined(_IRR_COMPILE_WITH_SDL_DEVICE_)
			,glXSwapIntervalMESA
#endif
			,glxWin
			,glXMakeContextCurrent
			,glXMakeCurrent
			,glXDestroyContext
			,glXDestroyWindow
			,glXQueryExtension
			,glXChooseFBConfig
			,glXGetVisualFromFBConfig
			,glXGetFBConfigAttrib

		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLgeneral, OpenGLFunctionLoader
			,glEnablei	//
			,glDisablei	//
			,glEnable	//
			,glDisable	//
			,glGetIntegerv
			,glIsEnabledi	//
			,glLogicOp
			,glGetFloatv
			,glFlush
			,glGetBooleanv//
		);
		IRR_SYSTEM_DECLARE_DYNAMIC_FUNCTION_CALLER_CLASS(GLcompute, OpenGLFunctionLoader
			, glDispatchCompute
			, glDispatchComputeIndirect
		);


		inline bool GlIsEnabledi(GLenum cap, GLuint index)
		{
			return glGeneral.pglIsEnabledi(cap, index);
		}

		inline void GlEnablei(GLenum cap, GLuint index)
		{
			glGeneral.pglEnable(cap, index);
		}

		inline void GlEnable(GLenum cap, GLuint index)
		{
			glGeneral.pglEnable(cap, index);
		}

		inline void GlDisablei(GLenum cap, GLuint index)
		{
			glGeneral.pglDisablei(cap, index);
		}

		inline void GlDisable(GLenum cap, GLuint index)
		{
			glGeneral.pglDisable(cap, index);
		}

		inline void GlGetBooleani_v(GLenum pname, GLuint index, GLboolean* data)
		{
			glGeneral.glGetBooleanv(pname, index, data);
		}

		inline void extGlGetFloati_v(GLenum pname, GLuint index, float* data)
		{
			glGeneral.pGlGetFloati_v(pname, index, data);
		}

		inline void COpenGLFunctionTable::extGlGetInteger64v(GLenum pname, GLint64* data)
		{
			glGeneral.pGlGetInteger64v(pname, data);
		}
		inline void COpenGLFunctionTable::extGlGetIntegeri_v(GLenum pname, GLuint index, GLint* data)
		{
			pGlGetIntegeri_v(pname, index, data);
		}
		inline void COpenGLFunctionTable::extGlProvokingVertex(GLenum provokeMode)
		{
			pGlProvokingVertex(provokeMode);
		}
		inline void COpenGLFunctionTable::extGlClipControl(GLenum origin, GLenum depth)
		{
			pGlClipControl(origin, depth);
		}
			
			
			
		inline GLsync COpenGLFunctionTable::extGlFenceSync(GLenum condition, GLbitfield flags)
		{
			return pGlFenceSync(condition, flags);
		}
			
		inline void COpenGLFunctionTable::extGlDeleteSync(GLsync sync)
		{
			pGlDeleteSync(sync);
		}
			
		inline GLenum extGlClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
		{
			return pGlClientWaitSync(sync, flags, timeout);
		}
			
		inline void COpenGLFunctionTable::extGlWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
		{
			pGlWaitSync(sync, flags, timeout);
		}
			
		inline void COpenGLFunctionTable::extGlActiveTexture(GLenum target) // kill this function in favour of multibind (but need to upgrade OpenGL tracker)
		{
			pGlActiveTexture(target);
		}
			
	protected:
		// constructor
		COpenGLFunctionTable() 
		{
			if(SDL_VideoInit()<0)
				//log error
			if(SDL_GL_LoadLibrary(nullptr) < 0) //nullptr to load the default OpenGL library
				//log error
		}
	private:
		GLsync glSync;
		GLframeBuffer glFrameBuffer;
		GLbuffer glBuffer;
		GLtexture glTexture;
		GLshader glShader;
		GLfragment glFragment;
		GLvertex glVertex;
		GLdrawing glDrawing;
		GLtransformFeedback glTransformFeedback;
		GLquery glQuery;
		GLdebug glDebug;
		GLOS glOS;
		GLgeneral glGeneral;
		GLcompute glCompute;

	}	// end of class COpenGLFunctionTable
	

	//#pragma region Inline Implementations
	//		//TODO use khronos.org to add params & add ptr null checks


	//		
	//		inline void COpenGLFunctionTable::extGlBindTextures(const GLuint& first, const GLsizei& count, const GLuint* textures, const GLenum* targets)
	//		{
	//			const GLenum supportedTargets[] = { GL_TEXTURE_1D,GL_TEXTURE_2D, // GL 1.x
	//												GL_TEXTURE_3D,GL_TEXTURE_RECTANGLE,GL_TEXTURE_CUBE_MAP, // GL 2.x
	//												GL_TEXTURE_1D_ARRAY,GL_TEXTURE_2D_ARRAY,GL_TEXTURE_BUFFER, // GL 3.x
	//												GL_TEXTURE_CUBE_MAP_ARRAY,GL_TEXTURE_2D_MULTISAMPLE,GL_TEXTURE_2D_MULTISAMPLE_ARRAY }; // GL 4.x
	//
	//			if (Version >= 440 || FeatureAvailable[IRR_ARB_multi_bind])
	//				pGlBindTextures(first, count, textures);
	//			else
	//			{
	//				int32_t activeTex = 0;
	//				glGetIntegerv(GL_ACTIVE_TEXTURE, &activeTex);
	//
	//				for (GLsizei i = 0; i < count; i++)
	//				{
	//					GLuint texture = textures ? textures[i] : 0;
	//
	//					GLuint unit = first + i;
	//					pGlActiveTexture(GL_TEXTURE0 + unit);
	//
	//					if (texture)
	//						glBindTexture(targets[i], texture);
	//					else
	//					{
	//						for (size_t j = 0; j < sizeof(supportedTargets) / sizeof(GLenum); j++)
	//							glBindTexture(supportedTargets[j], 0);
	//					}
	//				}
	//
	//				pGlActiveTexture(activeTex);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCreateTextures(GLenum target, GLsizei n, GLuint* textures)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlCreateTextures(target, n, textures);
	//			else
	//				glGenTextures(n, textures);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureBuffer(texture, internalformat, buffer);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureBufferEXT(texture, GL_TEXTURE_BUFFER, internalformat, buffer);
	//			else
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_TEXTURE_BINDING_BUFFER, &bound);
	//				glBindTexture(GL_TEXTURE_BUFFER, texture);
	//				pGlTexBuffer(GL_TEXTURE_BUFFER, internalformat, buffer);
	//				glBindTexture(GL_TEXTURE_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizei length)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//
	//				if (pGlTextureBufferRange)
	//					pGlTextureBufferRange(texture, internalformat, buffer, offset, length);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlTextureBufferRangeEXT)
	//					pGlTextureBufferRangeEXT(texture, GL_TEXTURE_BUFFER, internalformat, buffer, offset, length);
	//			}
	//			else
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_TEXTURE_BINDING_BUFFER, &bound);
	//				glBindTexture(GL_TEXTURE_BUFFER, texture);
	//				if (pGlTexBufferRange)
	//					pGlTexBufferRange(GL_TEXTURE_BUFFER, internalformat, buffer, offset, length);
	//				glBindTexture(GL_TEXTURE_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureStorage1D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlTextureStorage1D)
	//					pGlTextureStorage1D(texture, levels, internalformat, width);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlTextureStorage1DEXT)
	//					pGlTextureStorage1DEXT(texture, target, levels, internalformat, width);
	//			}
	//			else if (pGlTexStorage1D)
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlTexStorage1D(target, levels, internalformat, width);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlTextureStorage2D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlTextureStorage2D)
	//					pGlTextureStorage2D(texture, levels, internalformat, width, height);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlTextureStorage2DEXT)
	//					pGlTextureStorage2DEXT(texture, target, levels, internalformat, width, height);
	//			}
	//			else if (pGlTexStorage2D)
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_RECTANGLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlTexStorage2D(target, levels, internalformat, width, height);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlTextureStorage3D(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureStorage3D(texture, levels, internalformat, width, height, depth);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureStorage3DEXT(texture, target, levels, internalformat, width, height, depth);
	//			else
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlTexStorage3D(target, levels, internalformat, width, height, depth);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureStorage2DMultisample(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureStorage2DMultisampleEXT(texture, target, samples, internalformat, width, height, fixedsamplelocations);
	//			else
	//			{
	//				GLint bound;
	//				if (target != GL_TEXTURE_2D_MULTISAMPLE)
	//				{
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				else
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE, &bound);
	//				glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture);
	//				pGlTexStorage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, internalformat, width, height, fixedsamplelocations);
	//				glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlTextureStorage3DMultisample(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureStorage3DMultisampleEXT(texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
	//			else
	//			{
	//				GLint bound;
	//				if (target != GL_TEXTURE_2D_MULTISAMPLE_ARRAY)
	//				{
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				else
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &bound);
	//				glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, texture);
	//				pGlTexStorage3DMultisample(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, samples, internalformat, width, height, depth, fixedsamplelocations);
	//				glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
	//		{
	//			pGlTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_get_texture_sub_image])
	//				pGlGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
	//#ifdef _IRR_DEBUG
	//			else
	//				os::Printer::log("EDF_GET_TEXTURE_SUB_IMAGE Not Available! Tell DevSH to implement!\n", ELL_ERROR);
	//#endif // _IRR_DEBUG
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_get_texture_sub_image])
	//				extGlGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
	//#ifdef _IRR_DEBUG
	//			else
	//				os::Printer::log("EDF_GET_TEXTURE_SUB_IMAGE Not Available! Tell DevSH to implement!\n", ELL_ERROR);
	//#endif // _IRR_DEBUG
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetTextureImage(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSizeHint, void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlGetTextureImage(texture, level, format, type, bufSizeHint, pixels);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlGetTextureImageEXT(texture, target, level, format, type, pixels);
	//			else
	//			{
	//				GLint bound = 0;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_RECTANGLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
	//					break;
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				default:
	//					break;
	//				}
	//				glBindTexture(target, texture);
	//				glGetTexImage(target, level, format, type, pixels);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetCompressedTextureImage(GLuint texture, GLenum target, GLint level, GLsizei bufSizeHint, void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlGetCompressedTextureImage(texture, level, bufSizeHint, pixels);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlGetCompressedTextureImageEXT(texture, target, level, pixels);
	//			else
	//			{
	//				GLint bound = 0;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_RECTANGLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
	//					break;
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				default:
	//					break;
	//				}
	//				glBindTexture(target, texture);
	//				pGlGetCompressedTexImage(target, level, pixels);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureSubImage1D(texture, level, xoffset, width, format, type, pixels);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureSubImage1DEXT(texture, target, level, xoffset, width, format, type, pixels);
	//			else
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureSubImage2DEXT(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
	//			else
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_2D_MULTISAMPLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_RECTANGLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureSubImage3DEXT(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	//			else
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlCompressedTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCompressedTextureSubImage1D)
	//					pGlCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlCompressedTextureSubImage1DEXT)
	//					pGlCompressedTextureSubImage1DEXT(texture, target, level, xoffset, width, format, imageSize, data);
	//			}
	//			else if (pGlCompressedTexSubImage1D)
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlCompressedTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCompressedTextureSubImage2D)
	//					pGlCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlCompressedTextureSubImage2DEXT)
	//					pGlCompressedTextureSubImage2DEXT(texture, target, level, xoffset, yoffset, width, height, format, imageSize, data);
	//			}
	//			else if (pGlCompressedTexSubImage2D)
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
	//				case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//		inline void COpenGLFunctionTable::extGlCompressedTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCompressedTextureSubImage3D)
	//					pGlCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlCompressedTextureSubImage3DEXT)
	//					pGlCompressedTextureSubImage3DEXT(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
	//			}
	//			else if (pGlCompressedTexSubImage3D)
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
	//		{
	//			pGlCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGenerateTextureMipmap(GLuint texture, GLenum target)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlGenerateTextureMipmap)
	//					pGlGenerateTextureMipmap(texture);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlGenerateTextureMipmapEXT)
	//					pGlGenerateTextureMipmapEXT(texture, target);
	//			}
	//			else
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D_MULTISAMPLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE, &bound);
	//					break;
	//				case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				case GL_TEXTURE_BUFFER:
	//					glGetIntegerv(GL_TEXTURE_BINDING_BUFFER, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_RECTANGLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlGenerateMipmap(target);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTextureParameterIuiv(GLuint texture, GLenum target, GLenum pname, const GLuint* params)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				pGlTextureParameterIuiv(texture, pname, params);
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				pGlTextureParameterIuivEXT(texture, target, pname, params);
	//			else
	//			{
	//				GLint bound;
	//				switch (target)
	//				{
	//				case GL_TEXTURE_1D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D, &bound);
	//					break;
	//				case GL_TEXTURE_1D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_1D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound);
	//					break;
	//				case GL_TEXTURE_2D_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_2D_MULTISAMPLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE, &bound);
	//					break;
	//				case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_3D:
	//					glGetIntegerv(GL_TEXTURE_BINDING_3D, &bound);
	//					break;
	//				case GL_TEXTURE_BUFFER:
	//					glGetIntegerv(GL_TEXTURE_BINDING_BUFFER, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bound);
	//					break;
	//				case GL_TEXTURE_CUBE_MAP_ARRAY:
	//					glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, &bound);
	//					break;
	//				case GL_TEXTURE_RECTANGLE:
	//					glGetIntegerv(GL_TEXTURE_BINDING_RECTANGLE, &bound);
	//					break;
	//				default:
	//					os::Printer::log("DevSH would like to ask you what are you doing!!??\n", ELL_ERROR);
	//					return;
	//				}
	//				glBindTexture(target, texture);
	//				pGlTexParameterIuiv(target, pname, params);
	//				glBindTexture(target, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClampColor(GLenum target, GLenum clamp)
	//		{
	//			if (pGlClampColor)
	//				pGlClampColor(GL_CLAMP_READ_COLOR, clamp);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCreateSamplers(GLsizei n, GLuint* samplers)
	//		{
	//			if (pGlCreateSamplers)
	//				pGlCreateSamplers(n, samplers);
	//			else if (pGlGenSamplers)
	//				pGlGenSamplers(n, samplers);
	//			else memset(samplers, 0, 4 * n);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteSamplers(GLsizei n, GLuint* samplers)
	//		{
	//			if (pGlDeleteSamplers)
	//				pGlDeleteSamplers(n, samplers);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindSamplers(const GLuint& first, const GLsizei& count, const GLuint* samplers)
	//		{
	//			if (Version >= 440 || FeatureAvailable[IRR_ARB_multi_bind])
	//			{
	//				if (pGlBindSamplers)
	//					pGlBindSamplers(first, count, samplers);
	//			}
	//			else
	//			{
	//				for (GLsizei i = 0; i < count; i++)
	//				{
	//					GLuint unit = first + i;
	//					if (samplers)
	//					{
	//						if (pGlBindSampler)
	//							pGlBindSampler(unit, samplers[i]);
	//					}
	//					else
	//					{
	//						if (pGlBindSampler)
	//							pGlBindSampler(unit, 0);
	//					}
	//				}
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
	//		{
	//			if (pGlSamplerParameteri)
	//				pGlSamplerParameteri(sampler, pname, param);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
	//		{
	//			if (pGlSamplerParameterf)
	//				pGlSamplerParameterf(sampler, pname, param);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* params)
	//		{
	//			if (pGlSamplerParameterfv)
	//				pGlSamplerParameterfv(sampler, pname, params);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlBindImageTexture(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
	//		{
	//			if (pGlBindImageTexture)
	//				pGlBindImageTexture(index, texture, level, layered, layer, access, format);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlBindImageTextures(GLuint first, GLsizei count, const GLuint* textures, const GLenum* formats)
	//		{
	//			if (pGlBindImageTextures)
	//				pGlBindImageTextures(first, count, textures);
	//			else
	//			{
	//				for (GLsizei i = 0; i < count; i++)
	//				{
	//					if (!textures || textures[i] == 0u)
	//						extGlBindImageTexture(first + i, 0u, 0u, GL_FALSE, 0, GL_READ_WRITE, GL_R8);
	//					else
	//						extGlBindImageTexture(first + i, textures[i], 0, GL_TRUE, 0, GL_READ_WRITE, formats[i]);
	//				}
	//			}
	//		}
	//
	//		inline GLuint64 COpenGLFunctionTable::extGlGetTextureHandle(GLuint texture)
	//		{
	//			if (pGlGetTextureHandleARB)
	//				return pGlGetTextureHandleARB(texture);
	//			else if (pGlGetTextureHandleNV)
	//				return pGlGetTextureHandleNV(texture);
	//			return 0ull;
	//		}
	//
	//		inline GLuint64 COpenGLFunctionTable::extGlGetTextureSamplerHandle(GLuint texture, GLuint sampler)
	//		{
	//			if (pGlGetTextureSamplerHandleARB)
	//				return pGlGetTextureSamplerHandleARB(texture, sampler);
	//			else if (pGlGetTextureSamplerHandleNV)
	//				return pGlGetTextureSamplerHandleNV(texture, sampler);
	//			return 0ull;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMakeTextureHandleResident(GLuint64 handle)
	//		{
	//			if (pGlMakeTextureHandleResidentARB)
	//				return pGlMakeTextureHandleResidentARB(handle);
	//			else if (pGlMakeTextureHandleResidentNV)
	//				return pGlMakeTextureHandleResidentNV(handle);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMakeTextureHandleNonResident(GLuint64 handle)
	//		{
	//			if (pGlMakeTextureHandleNonResidentARB)
	//				return pGlMakeTextureHandleNonResidentARB(handle);
	//			else if (pGlMakeTextureHandleNonResidentNV)
	//				return pGlMakeTextureHandleNonResidentNV(handle);
	//		}
	//
	//		inline GLuint64 COpenGLFunctionTable::extGlGetImageHandle(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
	//		{
	//			if (pGlGetImageHandleARB)
	//				return pGlGetImageHandleARB(texture, level, layered, layer, format);
	//			else if (pGlGetImageHandleNV)
	//				return pGlGetImageHandleNV(texture, level, layered, layer, format);
	//			return 0ull;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMakeImageHandleResident(GLuint64 handle, GLenum access)
	//		{
	//			if (pGlMakeImageHandleResidentARB)
	//				return pGlMakeImageHandleResidentARB(handle, access);
	//			else if (pGlMakeImageHandleResidentNV)
	//				return pGlMakeImageHandleResidentNV(handle, access);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMakeImageHandleNonResident(GLuint64 handle)
	//		{
	//			if (pGlMakeImageHandleNonResidentARB)
	//				return pGlMakeImageHandleNonResidentARB(handle);
	//			else if (pGlMakeImageHandleNonResidentNV)
	//				return pGlMakeImageHandleNonResidentNV(handle);
	//		}
	//
	//		inline GLboolean COpenGLFunctionTable::extGlIsTextureHandleResident(GLuint64 handle)
	//		{
	//			if (pGlIsTextureHandleResidentARB)
	//				return pGlIsTextureHandleResidentARB(handle);
	//			else if (pGlIsTextureHandleResidentNV)
	//				return pGlIsTextureHandleResidentNV(handle);
	//			return false;
	//		}
	//
	//		inline GLboolean COpenGLFunctionTable::extGlIsImageHandleResident(GLuint64 handle)
	//		{
	//			if (pGlIsTextureHandleResidentARB)
	//				return pGlIsTextureHandleResidentARB(handle);
	//			else if (pGlIsTextureHandleResidentNV)
	//				return pGlIsTextureHandleResidentNV(handle);
	//			return false;
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlCreateProgramPipelines(GLsizei n, GLuint* pipelines)
	//		{
	//			if (pGlCreateProgramPipelines)
	//				pGlCreateProgramPipelines(n, pipelines);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteProgramPipelines(GLsizei n, const GLuint* pipelines)
	//		{
	//			if (pGlDeleteProgramPipelines)
	//				pGlDeleteProgramPipelines(n, pipelines);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
	//		{
	//			if (pGlUseProgramStages)
	//				pGlUseProgramStages(pipeline, stages, program);
	//		}
	//
	//		inline GLuint COpenGLFunctionTable::extGlCreateShader(GLenum shaderType)
	//		{
	//			if (pGlCreateShader)
	//				return pGlCreateShader(shaderType);
	//			return 0;
	//		}
	//
	//		inline GLuint COpenGLFunctionTable::extGlCreateShaderProgramv(GLenum shaderType, GLsizei count, const char** strings)
	//		{
	//			if (pGlCreateShaderProgramv)
	//				return pGlCreateShaderProgramv(shaderType, count, strings);
	//			return 0;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlShaderSource(GLuint shader, GLsizei numOfStrings, const char** strings, const GLint* lenOfStrings)
	//		{
	//			if (pGlShaderSource)
	//				pGlShaderSource(shader, numOfStrings, strings, lenOfStrings);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCompileShader(GLuint shader)
	//		{
	//			if (pGlCompileShader)
	//				pGlCompileShader(shader);
	//		}
	//
	//		inline GLuint COpenGLFunctionTable::extGlCreateProgram(void)
	//		{
	//			if (pGlCreateProgram)
	//				return pGlCreateProgram();
	//			return 0;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlAttachShader(GLuint program, GLuint shader)
	//		{
	//			if (pGlAttachShader)
	//				pGlAttachShader(program, shader);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlLinkProgram(GLuint program)
	//		{
	//			if (pGlLinkProgram)
	//				pGlLinkProgram(program);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTransformFeedbackVaryings(GLuint program, GLsizei count, const char** varyings, GLenum bufferMode)
	//		{
	//			if (pGlTransformFeedbackVaryings)
	//				pGlTransformFeedbackVaryings(program, count, varyings, bufferMode);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlUseProgram(GLuint prog)
	//		{
	//			if (pGlUseProgram)
	//				pGlUseProgram(prog);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteProgram(GLuint object)
	//		{
	//			if (pGlDeleteProgram)
	//				pGlDeleteProgram(object);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteShader(GLuint shader)
	//		{
	//			if (pGlDeleteShader)
	//				pGlDeleteShader(shader);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
	//		{
	//			if (count)
	//				*count = 0;
	//			if (pGlGetAttachedShaders)
	//				pGlGetAttachedShaders(program, maxcount, count, shaders);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog)
	//		{
	//			if (length)
	//				*length = 0;
	//			if (pGlGetShaderInfoLog)
	//				pGlGetShaderInfoLog(shader, maxLength, length, infoLog);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei* length, GLchar* infoLog)
	//		{
	//			if (length)
	//				*length = 0;
	//			if (pGlGetProgramInfoLog)
	//				pGlGetProgramInfoLog(program, maxLength, length, infoLog);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlGetShaderiv(GLuint shader, GLenum type, GLint* param)
	//		{
	//			if (pGlGetShaderiv)
	//				pGlGetShaderiv(shader, type, param);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetProgramiv(GLuint program, GLenum type, GLint* param)
	//		{
	//			if (pGlGetProgramiv)
	//				pGlGetProgramiv(program, type, param);
	//		}
	//
	//		inline GLint COpenGLFunctionTable::extGlGetUniformLocation(GLuint program, const char* name)
	//		{
	//			if (pGlGetUniformLocation)
	//				return pGlGetUniformLocation(program, name);
	//			return -1;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform1fv(GLuint program, GLint loc, GLsizei count, const GLfloat* v)
	//		{
	//			if (pGlProgramUniform1fv)
	//				pGlProgramUniform1fv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform2fv(GLuint program, GLint loc, GLsizei count, const GLfloat* v)
	//		{
	//			if (pGlProgramUniform2fv)
	//				pGlProgramUniform2fv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform3fv(GLuint program, GLint loc, GLsizei count, const GLfloat* v)
	//		{
	//			if (pGlProgramUniform3fv)
	//				pGlProgramUniform3fv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform4fv(GLuint program, GLint loc, GLsizei count, const GLfloat* v)
	//		{
	//			if (pGlProgramUniform4fv)
	//				pGlProgramUniform4fv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform1iv(GLuint program, GLint loc, GLsizei count, const GLint* v)
	//		{
	//			if (pGlProgramUniform1iv)
	//				pGlProgramUniform1iv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform2iv(GLuint program, GLint loc, GLsizei count, const GLint* v)
	//		{
	//			if (pGlProgramUniform2iv)
	//				pGlProgramUniform2iv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform3iv(GLuint program, GLint loc, GLsizei count, const GLint* v)
	//		{
	//			if (pGlProgramUniform3iv)
	//				pGlProgramUniform3iv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform4iv(GLuint program, GLint loc, GLsizei count, const GLint* v)
	//		{
	//			if (pGlProgramUniform4iv)
	//				pGlProgramUniform4iv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform1uiv(GLuint program, GLint loc, GLsizei count, const GLuint* v)
	//		{
	//			if (pGlProgramUniform1uiv)
	//				pGlProgramUniform1uiv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform2uiv(GLuint program, GLint loc, GLsizei count, const GLuint* v)
	//		{
	//			if (pGlProgramUniform2uiv)
	//				pGlProgramUniform2uiv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform3uiv(GLuint program, GLint loc, GLsizei count, const GLuint* v)
	//		{
	//			if (pGlProgramUniform3uiv)
	//				pGlProgramUniform3uiv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniform4uiv(GLuint program, GLint loc, GLsizei count, const GLuint* v)
	//		{
	//			if (pGlProgramUniform4uiv)
	//				pGlProgramUniform4uiv(program, loc, count, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix2fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix2fv)
	//				pGlProgramUniformMatrix2fv(program, loc, count, transpose, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix3fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix3fv)
	//				pGlProgramUniformMatrix3fv(program, loc, count, transpose, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix4fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix4fv)
	//				pGlProgramUniformMatrix4fv(program, loc, count, transpose, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix2x3fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix2x3fv)
	//				pGlProgramUniformMatrix2x3fv(program, loc, count, transpose, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix2x4fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix2x4fv)
	//				pGlProgramUniformMatrix2x4fv(program, loc, count, transpose, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix3x2fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix3x2fv)
	//				pGlProgramUniformMatrix3x2fv(program, loc, count, transpose, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix3x4fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix3x4fv)
	//				pGlProgramUniformMatrix3x4fv(program, loc, count, transpose, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix4x2fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix4x2fv)
	//				pGlProgramUniformMatrix4x2fv(program, loc, count, transpose, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlProgramUniformMatrix4x3fv(GLuint program, GLint loc, GLsizei count, GLboolean transpose, const GLfloat* v)
	//		{
	//			if (pGlProgramUniformMatrix4x3fv)
	//				pGlProgramUniformMatrix4x3fv(program, loc, count, transpose, v);
	//		}
	//
	//
	//
	//		inline void COpenGLFunctionTable::extGlGetActiveUniform(GLuint program,
	//			GLuint index, GLsizei maxlength, GLsizei* length,
	//			GLint* size, GLenum* type, GLchar* name)
	//		{
	//			if (length)
	//				*length = 0;
	//			if (pGlGetActiveUniform)
	//				pGlGetActiveUniform(program, index, maxlength, length, size, type, name);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindProgramPipeline(GLuint pipeline)
	//		{
	//			if (pGlBindProgramPipeline)
	//				pGlBindProgramPipeline(pipeline);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary)
	//		{
	//			if (pGlGetProgramBinary)
	//				pGlGetProgramBinary(program, bufSize, length, binaryFormat, binary);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length)
	//		{
	//			if (pGlProgramBinary)
	//				pGlProgramBinary(program, binaryFormat, binary, length);
	//		}
	//
	//
	//
	//		inline void COpenGLFunctionTable::extGlMemoryBarrier(GLbitfield barriers)
	//		{
	//			if (pGlMemoryBarrier)
	//				pGlMemoryBarrier(barriers);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
	//		{
	//			if (pGlDispatchCompute)
	//				pGlDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDispatchComputeIndirect(GLintptr indirect)
	//		{
	//			if (pGlDispatchComputeIndirect)
	//				pGlDispatchComputeIndirect(indirect);
	//		}
	//
	//
	//
	//
	//		inline void COpenGLFunctionTable::extGlPointParameterf(GLint loc, GLfloat f)
	//		{
	//			if (pGlPointParameterf)
	//				pGlPointParameterf(loc, f);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlPointParameterfv(GLint loc, const GLfloat* v)
	//		{
	//			if (pGlPointParameterfv)
	//				pGlPointParameterfv(loc, v);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
	//		{
	//			pGlStencilFuncSeparate(face, func, ref, mask);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
	//		{
	//			pGlStencilOpSeparate(face, fail, zfail, zpass);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlStencilMaskSeparate(GLenum face, GLuint mask)
	//		{
	//			pGlStencilMaskSeparate(face, mask);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlBindFramebuffer(GLenum target, GLuint framebuffer)
	//		{
	//			pGlBindFramebuffer(target, framebuffer);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
	//		{
	//			pGlDeleteFramebuffers(n, framebuffers);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCreateFramebuffers(GLsizei n, GLuint* framebuffers)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlCreateFramebuffers(n, framebuffers);
	//					return;
	//				}
	//			}
	//
	//			pGlGenFramebuffers(n, framebuffers);
	//		}
	//
	//		inline GLenum COpenGLFunctionTable::extGlCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//					return pGlCheckNamedFramebufferStatus(framebuffer, target);
	//				else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//					return pGlCheckNamedFramebufferStatusEXT(framebuffer, target);
	//			}
	//
	//			GLenum retval;
	//			GLuint bound;
	//			glGetIntegerv(target == GL_READ_FRAMEBUFFER ? GL_READ_FRAMEBUFFER_BINDING : GL_DRAW_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&bound));
	//
	//			if (bound != framebuffer)
	//				pGlBindFramebuffer(target, framebuffer);
	//			retval = pGlCheckFramebufferStatus(target);
	//			if (bound != framebuffer)
	//				pGlBindFramebuffer(target, bound);
	//
	//			return retval;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlNamedFramebufferTexture(framebuffer, attachment, texture, level);
	//					return;
	//				}
	//				else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				{
	//					pGlNamedFramebufferTextureEXT(framebuffer, attachment, texture, level);
	//					return;
	//				}
	//			}
	//
	//			GLuint bound;
	//			glGetIntegerv(GL_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&bound));
	//
	//			if (bound != framebuffer)
	//				pGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//			pGlFramebufferTexture(GL_FRAMEBUFFER, attachment, texture, level);
	//			if (bound != framebuffer)
	//				pGlBindFramebuffer(GL_FRAMEBUFFER, bound);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLenum textureType, GLint level, GLint layer)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
	//					return;
	//				}
	//			}
	//
	//			if (textureType != GL_TEXTURE_CUBE_MAP)
	//			{
	//				if (!needsDSAFramebufferHack && FeatureAvailable[IRR_EXT_direct_state_access])
	//				{
	//					pGlNamedFramebufferTextureLayerEXT(framebuffer, attachment, texture, level, layer);
	//				}
	//				else
	//				{
	//					GLuint bound;
	//					glGetIntegerv(GL_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&bound));
	//
	//					if (bound != framebuffer)
	//						pGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//					pGlFramebufferTextureLayer(GL_FRAMEBUFFER, attachment, texture, level, layer);
	//					if (bound != framebuffer)
	//						pGlBindFramebuffer(GL_FRAMEBUFFER, bound);
	//				}
	//			}
	//			else
	//			{
	//				constexpr GLenum CubeMapFaceToCubeMapFaceGLenum[IGPUImageView::ECMF_COUNT] = {
	//					GL_TEXTURE_CUBE_MAP_POSITIVE_X,GL_TEXTURE_CUBE_MAP_NEGATIVE_X,GL_TEXTURE_CUBE_MAP_POSITIVE_Y,GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,GL_TEXTURE_CUBE_MAP_POSITIVE_Z,GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	//				};
	//
	//				if (!needsDSAFramebufferHack && FeatureAvailable[IRR_EXT_direct_state_access])
	//				{
	//					pGlNamedFramebufferTexture2DEXT(framebuffer, attachment, CubeMapFaceToCubeMapFaceGLenum[layer], texture, level);
	//				}
	//				else
	//				{
	//					GLuint bound;
	//					glGetIntegerv(GL_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&bound));
	//
	//					if (bound != framebuffer)
	//						pGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//					pGlFramebufferTexture2D(GL_FRAMEBUFFER, attachment, CubeMapFaceToCubeMapFaceGLenum[layer], texture, level);
	//					if (bound != framebuffer)
	//						pGlBindFramebuffer(GL_FRAMEBUFFER, bound);
	//				}
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	//					return;
	//				}
	//			}
	//
	//			GLint boundReadFBO = -1;
	//			GLint boundDrawFBO = -1;
	//			glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &boundReadFBO);
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundDrawFBO);
	//
	//			if (static_cast<GLint>(readFramebuffer) != boundReadFBO)
	//				extGlBindFramebuffer(GL_READ_FRAMEBUFFER, readFramebuffer);
	//			if (static_cast<GLint>(drawFramebuffer) != boundDrawFBO)
	//				extGlBindFramebuffer(GL_DRAW_FRAMEBUFFER, drawFramebuffer);
	//
	//			pGlBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	//
	//			if (static_cast<GLint>(readFramebuffer) != boundReadFBO)
	//				extGlBindFramebuffer(GL_READ_FRAMEBUFFER, boundReadFBO);
	//			if (static_cast<GLint>(drawFramebuffer) != boundDrawFBO)
	//				extGlBindFramebuffer(GL_DRAW_FRAMEBUFFER, boundDrawFBO);
	//		}
	//
	//		//! there should be a GL 3.1 thing for this
	//		inline void COpenGLFunctionTable::extGlActiveStencilFace(GLenum face)
	//		{
	//			pGlActiveStencilFaceEXT(face);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlNamedFramebufferReadBuffer(framebuffer, mode);
	//					return;
	//				}
	//				else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				{
	//					pGlFramebufferReadBufferEXT(framebuffer, mode);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO;
	//			glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &boundFBO);
	//
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				pGlBindFramebuffer(GL_READ_FRAMEBUFFER, framebuffer);
	//			glReadBuffer(mode);
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				pGlBindFramebuffer(GL_READ_FRAMEBUFFER, boundFBO);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlNamedFramebufferDrawBuffer(framebuffer, buf);
	//					return;
	//				}
	//				else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				{
	//					pGlFramebufferDrawBufferEXT(framebuffer, buf);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO;
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundFBO);
	//
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				pGlBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
	//			glDrawBuffer(buf);
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				pGlBindFramebuffer(GL_DRAW_FRAMEBUFFER, boundFBO);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlNamedFramebufferDrawBuffers(framebuffer, n, bufs);
	//					return;
	//				}
	//				else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//				{
	//					pGlFramebufferDrawBuffersEXT(framebuffer, n, bufs);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO;
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundFBO);
	//
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				pGlBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
	//			pGlDrawBuffers(n, bufs);
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				pGlBindFramebuffer(GL_DRAW_FRAMEBUFFER, boundFBO);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO = -1;
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundFBO);
	//			if (boundFBO < 0)
	//				return;
	//
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				extGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//			pGlClearBufferiv(buffer, drawbuffer, value);
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				extGlBindFramebuffer(GL_FRAMEBUFFER, boundFBO);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO = -1;
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundFBO);
	//			if (boundFBO < 0)
	//				return;
	//
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				extGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//			pGlClearBufferuiv(buffer, drawbuffer, value);
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				extGlBindFramebuffer(GL_FRAMEBUFFER, boundFBO);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO = -1;
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundFBO);
	//			if (boundFBO < 0)
	//				return;
	//
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				extGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//			pGlClearBufferfv(buffer, drawbuffer, value);
	//			if (static_cast<GLuint>(boundFBO) != framebuffer)
	//				extGlBindFramebuffer(GL_FRAMEBUFFER, boundFBO);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
	//		{
	//			if (!needsDSAFramebufferHack)
	//			{
	//				if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//				{
	//					pGlClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil);
	//					return;
	//				}
	//			}
	//
	//			GLint boundFBO = -1;
	//			glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &boundFBO);
	//			if (boundFBO < 0)
	//				return;
	//			extGlBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	//			pGlClearBufferfi(buffer, drawbuffer, depth, stencil);
	//			extGlBindFramebuffer(GL_FRAMEBUFFER, boundFBO);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlCreateBuffers(GLsizei n, GLuint* buffers)
	//		{
	//#ifdef OPENGL_LEAK_DEBUG
	//			for (size_t i = 0; i < n; i++)
	//				COpenGLFunctionTable::bufferLeaker.registerObj(buffers);
	//#endif // OPENGL_LEAK_DEBUG
	//
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCreateBuffers)
	//					pGlCreateBuffers(n, buffers);
	//				else if (buffers)
	//					memset(buffers, 0, n * sizeof(GLuint));
	//			}
	//			else
	//			{
	//				if (pGlGenBuffers)
	//					pGlGenBuffers(n, buffers);
	//				else if (buffers)
	//					memset(buffers, 0, n * sizeof(GLuint));
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteBuffers(GLsizei n, const GLuint* buffers)
	//		{
	//#ifdef OPENGL_LEAK_DEBUG
	//			for (size_t i = 0; i < n; i++)
	//				COpenGLFunctionTable::bufferLeaker.deregisterObj(buffers);
	//#endif // OPENGL_LEAK_DEBUG
	//
	//			if (pGlDeleteBuffers)
	//				pGlDeleteBuffers(n, buffers);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindBuffer(const GLenum& target, const GLuint& buffer)
	//		{
	//			if (pGlBindBuffer)
	//				pGlBindBuffer(target, buffer);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindBuffersBase(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuint* buffers)
	//		{
	//			if (Version >= 440 || FeatureAvailable[IRR_ARB_multi_bind])
	//			{
	//				if (pGlBindBuffersBase)
	//					pGlBindBuffersBase(target, first, count, buffers);
	//			}
	//			else
	//			{
	//				for (GLsizei i = 0; i < count; i++)
	//				{
	//					if (pGlBindBufferBase)
	//						pGlBindBufferBase(target, first + i, buffers ? buffers[i] : 0);
	//				}
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindBuffersRange(const GLenum& target, const GLuint& first, const GLsizei& count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes)
	//		{
	//			if (Version >= 440 || FeatureAvailable[IRR_ARB_multi_bind])
	//			{
	//				if (pGlBindBuffersRange)
	//					pGlBindBuffersRange(target, first, count, buffers, offsets, sizes);
	//			}
	//			else
	//			{
	//				for (GLsizei i = 0; i < count; i++)
	//				{
	//					if (buffers)
	//					{
	//						if (pGlBindBufferRange)
	//							pGlBindBufferRange(target, first + i, buffers[i], offsets[i], sizes[i]);
	//					}
	//					else
	//					{
	//						if (pGlBindBufferBase)
	//							pGlBindBufferBase(target, first + i, 0);
	//					}
	//				}
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlNamedBufferStorage)
	//					pGlNamedBufferStorage(buffer, size, data, flags);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlNamedBufferStorageEXT)
	//					pGlNamedBufferStorageEXT(buffer, size, data, flags);
	//			}
	//			else if (pGlBufferStorage && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlBufferStorage(GL_ARRAY_BUFFER, size, data, flags);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlNamedBufferSubData)
	//					pGlNamedBufferSubData(buffer, offset, size, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlNamedBufferSubDataEXT)
	//					pGlNamedBufferSubDataEXT(buffer, offset, size, data);
	//			}
	//			else if (pGlBufferSubData && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlGetNamedBufferSubData)
	//					pGlGetNamedBufferSubData(buffer, offset, size, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlGetNamedBufferSubDataEXT)
	//					pGlGetNamedBufferSubDataEXT(buffer, offset, size, data);
	//			}
	//			else if (pGlGetBufferSubData && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlGetBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void* COpenGLFunctionTable::extGlMapNamedBuffer(GLuint buffer, GLbitfield access)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlMapNamedBuffer)
	//					return pGlMapNamedBuffer(buffer, access);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlMapNamedBufferEXT)
	//					return pGlMapNamedBufferEXT(buffer, access);
	//			}
	//			else if (pGlMapBuffer && pGlBindBuffer)
	//			{
	//				GLvoid* retval;
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				retval = pGlMapBuffer(GL_ARRAY_BUFFER, access);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//				return retval;
	//			}
	//			return NULL;
	//		}
	//
	//		inline void* COpenGLFunctionTable::extGlMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlMapNamedBufferRange)
	//					return pGlMapNamedBufferRange(buffer, offset, length, access);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlMapNamedBufferRangeEXT)
	//					return pGlMapNamedBufferRangeEXT(buffer, offset, length, access);
	//			}
	//			else if (pGlMapBufferRange && pGlBindBuffer)
	//			{
	//				GLvoid* retval;
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				retval = pGlMapBufferRange(GL_ARRAY_BUFFER, offset, length, access);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//				return retval;
	//			}
	//			return NULL;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlFlushMappedNamedBufferRange)
	//					pGlFlushMappedNamedBufferRange(buffer, offset, length);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlFlushMappedNamedBufferRangeEXT)
	//					pGlFlushMappedNamedBufferRangeEXT(buffer, offset, length);
	//			}
	//			else if (pGlFlushMappedBufferRange && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlFlushMappedBufferRange(GL_ARRAY_BUFFER, offset, length);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline GLboolean COpenGLFunctionTable::extGlUnmapNamedBuffer(GLuint buffer)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlUnmapNamedBuffer)
	//					return pGlUnmapNamedBuffer(buffer);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlUnmapNamedBufferEXT)
	//					return pGlUnmapNamedBufferEXT(buffer);
	//			}
	//			else if (pGlUnmapBuffer && pGlBindBuffer)
	//			{
	//				GLboolean retval;
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				retval = pGlUnmapBuffer(GL_ARRAY_BUFFER);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//				return retval;
	//			}
	//			return false;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlClearNamedBufferData)
	//					pGlClearNamedBufferData(buffer, internalformat, format, type, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlClearNamedBufferDataEXT)
	//					pGlClearNamedBufferDataEXT(buffer, internalformat, format, type, data);
	//			}
	//			else if (pGlClearBufferData && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlClearBufferData(GL_ARRAY_BUFFER, internalformat, format, type, data);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlClearNamedBufferSubData)
	//					pGlClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlClearNamedBufferSubDataEXT)
	//					pGlClearNamedBufferSubDataEXT(buffer, internalformat, offset, size, format, type, data);
	//			}
	//			else if (pGlClearBufferSubData && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlClearBufferSubData(GL_ARRAY_BUFFER, internalformat, offset, size, format, type, data);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCopyNamedBufferSubData)
	//					pGlCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlNamedCopyBufferSubDataEXT)
	//					pGlNamedCopyBufferSubDataEXT(readBuffer, writeBuffer, readOffset, writeOffset, size);
	//			}
	//			else if (pGlCopyBufferSubData && pGlBindBuffer)
	//			{
	//				GLint boundRead, boundWrite;
	//				glGetIntegerv(GL_COPY_READ_BUFFER_BINDING, &boundRead);
	//				glGetIntegerv(GL_COPY_WRITE_BUFFER_BINDING, &boundWrite);
	//				pGlBindBuffer(GL_COPY_READ_BUFFER, readBuffer);
	//				pGlBindBuffer(GL_COPY_WRITE_BUFFER, writeBuffer);
	//				pGlCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, readOffset, writeOffset, size);
	//				pGlBindBuffer(GL_COPY_READ_BUFFER, boundRead);
	//				pGlBindBuffer(GL_COPY_WRITE_BUFFER, boundWrite);
	//			}
	//		}
	//
	//		inline GLboolean COpenGLFunctionTable::extGlIsBuffer(GLuint buffer)
	//		{
	//			if (pGlIsBuffer)
	//				return pGlIsBuffer(buffer);
	//			return false;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetNamedBufferParameteriv(const GLuint& buffer, const GLenum& value, GLint* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlGetNamedBufferParameteriv)
	//					pGlGetNamedBufferParameteriv(buffer, value, data);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlGetNamedBufferParameterivEXT)
	//					pGlGetNamedBufferParameterivEXT(buffer, value, data);
	//			}
	//			else if (pGlGetBufferParameteriv && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlGetBufferParameteriv(GL_ARRAY_BUFFER, value, data);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetNamedBufferParameteri64v(const GLuint& buffer, const GLenum& value, GLint64* data)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlGetNamedBufferParameteri64v)
	//					pGlGetNamedBufferParameteri64v(buffer, value, data);
	//			}
	//			else if (pGlGetBufferParameteri64v && pGlBindBuffer)
	//			{
	//				GLint bound;
	//				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bound);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, buffer);
	//				pGlGetBufferParameteri64v(GL_ARRAY_BUFFER, value, data);
	//				pGlBindBuffer(GL_ARRAY_BUFFER, bound);
	//			}
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlCreateVertexArrays(GLsizei n, GLuint* arrays)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCreateVertexArrays)
	//					pGlCreateVertexArrays(n, arrays);
	//			}
	//			else
	//			{
	//				if (pGlGenVertexArrays)
	//					pGlGenVertexArrays(n, arrays);
	//				else
	//					memset(arrays, 0, sizeof(GLuint) * n);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteVertexArrays(GLsizei n, GLuint* arrays)
	//		{
	//			if (pGlDeleteVertexArrays)
	//				pGlDeleteVertexArrays(n, arrays);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindVertexArray(GLuint vaobj)
	//		{
	//			if (pGlBindVertexArray)
	//				pGlBindVertexArray(vaobj);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayElementBuffer(GLuint vaobj, GLuint buffer)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayElementBuffer)
	//					pGlVertexArrayElementBuffer(vaobj, buffer);
	//			}
	//			else if (pGlBindBuffer && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayVertexBuffer)
	//					pGlVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlVertexArrayBindVertexBufferEXT)
	//					pGlVertexArrayBindVertexBufferEXT(vaobj, bindingindex, buffer, offset, stride);
	//			}
	//			else if (pGlBindVertexBuffer && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlBindVertexBuffer(bindingindex, buffer, offset, stride);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayAttribBinding)
	//					pGlVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlVertexArrayVertexAttribBindingEXT)
	//					pGlVertexArrayVertexAttribBindingEXT(vaobj, attribindex, bindingindex);
	//			}
	//			else if (pGlVertexAttribBinding && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlVertexAttribBinding(attribindex, bindingindex);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlEnableVertexArrayAttrib(GLuint vaobj, GLuint index)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlEnableVertexArrayAttrib)
	//					pGlEnableVertexArrayAttrib(vaobj, index);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlEnableVertexArrayAttribEXT)
	//					pGlEnableVertexArrayAttribEXT(vaobj, index);
	//			}
	//			else if (pGlEnableVertexAttribArray && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlEnableVertexAttribArray(index);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDisableVertexArrayAttrib(GLuint vaobj, GLuint index)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlDisableVertexArrayAttrib)
	//					pGlDisableVertexArrayAttrib(vaobj, index);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlDisableVertexArrayAttribEXT)
	//					pGlDisableVertexArrayAttribEXT(vaobj, index);
	//			}
	//			else if (pGlDisableVertexAttribArray && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlDisableVertexAttribArray(index);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayAttribFormat)
	//					pGlVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
	//			}
	//			else if (!IsIntelGPU && FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlVertexArrayVertexAttribFormatEXT)
	//					pGlVertexArrayVertexAttribFormatEXT(vaobj, attribindex, size, type, normalized, relativeoffset);
	//			}
	//			else if (pGlVertexAttribFormat && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayAttribIFormat)
	//					pGlVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
	//			}
	//			else if (!IsIntelGPU && FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlVertexArrayVertexAttribIFormatEXT)
	//					pGlVertexArrayVertexAttribIFormatEXT(vaobj, attribindex, size, type, relativeoffset);
	//			}
	//			else if (pGlVertexAttribIFormat && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlVertexAttribIFormat(attribindex, size, type, relativeoffset);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayAttribLFormat)
	//					pGlVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
	//			}
	//			else if (!IsIntelGPU && FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlVertexArrayVertexAttribLFormatEXT)
	//					pGlVertexArrayVertexAttribLFormatEXT(vaobj, attribindex, size, type, relativeoffset);
	//			}
	//			else if (pGlVertexAttribLFormat && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlVertexAttribLFormat(attribindex, size, type, relativeoffset);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlVertexArrayBindingDivisor)
	//					pGlVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
	//			}
	//			else if (FeatureAvailable[IRR_EXT_direct_state_access])
	//			{
	//				if (pGlVertexArrayVertexBindingDivisorEXT)
	//					pGlVertexArrayVertexBindingDivisorEXT(vaobj, bindingindex, divisor);
	//			}
	//			else if (pGlVertexBindingDivisor && pGlBindVertexArray)
	//			{
	//				// Save the previous bound vertex array
	//				GLint restoreVertexArray;
	//				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &restoreVertexArray);
	//				pGlBindVertexArray(vaobj);
	//				pGlVertexBindingDivisor(bindingindex, divisor);
	//				pGlBindVertexArray(restoreVertexArray);
	//			}
	//		}
	//
	//
	//
	//		inline void COpenGLFunctionTable::extGlCreateTransformFeedbacks(GLsizei n, GLuint* ids)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCreateTransformFeedbacks)
	//					pGlCreateTransformFeedbacks(n, ids);
	//			}
	//			else
	//			{
	//				if (pGlGenTransformFeedbacks)
	//					pGlGenTransformFeedbacks(n, ids);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteTransformFeedbacks(GLsizei n, const GLuint* ids)
	//		{
	//			if (pGlDeleteTransformFeedbacks)
	//				pGlDeleteTransformFeedbacks(n, ids);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBindTransformFeedback(GLenum target, GLuint id)
	//		{
	//			if (pGlBindTransformFeedback)
	//				pGlBindTransformFeedback(target, id);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBeginTransformFeedback(GLenum primitiveMode)
	//		{
	//			if (pGlBeginTransformFeedback)
	//				pGlBeginTransformFeedback(primitiveMode);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlPauseTransformFeedback()
	//		{
	//			if (pGlPauseTransformFeedback)
	//				pGlPauseTransformFeedback();
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlResumeTransformFeedback()
	//		{
	//			if (pGlResumeTransformFeedback)
	//				pGlResumeTransformFeedback();
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlEndTransformFeedback()
	//		{
	//			if (pGlEndTransformFeedback)
	//				pGlEndTransformFeedback();
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlTransformFeedbackBufferBase)
	//					pGlTransformFeedbackBufferBase(xfb, index, buffer);
	//			}
	//			else
	//			{
	//				GLint restoreXFormFeedback;
	//				glGetIntegerv(GL_TRANSFORM_FEEDBACK_BINDING, &restoreXFormFeedback);
	//				extGlBindTransformFeedback(GL_TRANSFORM_FEEDBACK, xfb);
	//				extGlBindBuffersBase(GL_TRANSFORM_FEEDBACK_BUFFER, index, 1, &buffer);
	//				extGlBindTransformFeedback(GL_TRANSFORM_FEEDBACK, restoreXFormFeedback);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlTransformFeedbackBufferRange)
	//					pGlTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
	//			}
	//			else
	//			{
	//				GLint restoreXFormFeedback;
	//				glGetIntegerv(GL_TRANSFORM_FEEDBACK_BINDING, &restoreXFormFeedback);
	//				extGlBindTransformFeedback(GL_TRANSFORM_FEEDBACK, xfb);
	//				extGlBindBuffersRange(GL_TRANSFORM_FEEDBACK_BUFFER, index, 1, &buffer, &offset, &size);
	//				extGlBindTransformFeedback(GL_TRANSFORM_FEEDBACK, restoreXFormFeedback);
	//			}
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlPrimitiveRestartIndex(GLuint index)
	//		{
	//			if (pGlPrimitiveRestartIndex)
	//				pGlPrimitiveRestartIndex(index);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
	//		{
	//			if (pGlDrawArraysInstanced)
	//				pGlDrawArraysInstanced(mode, first, count, instancecount);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
	//		{
	//			if (pGlDrawArraysInstancedBaseInstance)
	//				pGlDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex)
	//		{
	//			if (pGlDrawElementsInstancedBaseVertex)
	//				pGlDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
	//		{
	//			if (pGlDrawElementsInstancedBaseVertexBaseInstance)
	//				pGlDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawTransformFeedback(GLenum mode, GLuint id)
	//		{
	//			if (pGlDrawTransformFeedback)
	//				pGlDrawTransformFeedback(mode, id);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount)
	//		{
	//			if (pGlDrawTransformFeedbackInstanced)
	//				pGlDrawTransformFeedbackInstanced(mode, id, instancecount);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
	//		{
	//			if (pGlDrawTransformFeedbackStream)
	//				pGlDrawTransformFeedbackStream(mode, id, stream);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)
	//		{
	//			if (pGlDrawTransformFeedbackStreamInstanced)
	//				pGlDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawArraysIndirect(GLenum mode, const void* indirect)
	//		{
	//			if (pGlDrawArraysIndirect)
	//				pGlDrawArraysIndirect(mode, indirect);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect)
	//		{
	//			if (pGlDrawElementsIndirect)
	//				pGlDrawElementsIndirect(mode, type, indirect);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride)
	//		{
	//			if (pGlMultiDrawArraysIndirect)
	//				pGlMultiDrawArraysIndirect(mode, indirect, drawcount, stride);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride)
	//		{
	//			if (pGlMultiDrawElementsIndirect)
	//				pGlMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride)
	//		{
	//			if (pGlMultiDrawArrysIndirectCount)
	//				pGlMultiDrawArrysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride)
	//		{
	//			if (pGlMultiDrawElementsIndirectCount)
	//				pGlMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride);
	//		}
	//
	//
	//
	//		// ROP
	//		inline void COpenGLFunctionTable::extGlBlendColor(float red, float green, float blue, float alpha)
	//		{
	//			if (pGlBlendColor)
	//				pGlBlendColor(red, green, blue, alpha);
	//		}
	//		inline void COpenGLFunctionTable::extGlDepthRangeIndexed(GLuint index, GLdouble nearVal, GLdouble farVal)
	//		{
	//			if (pGlDepthRangeIndexed)
	//				pGlDepthRangeIndexed(index, nearVal, farVal);
	//		}
	//		inline void COpenGLFunctionTable::extGlViewportIndexedfv(GLuint index, const GLfloat* v)
	//		{
	//			if (pGlViewportIndexedfv)
	//				pGlViewportIndexedfv(index, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlScissorIndexedv(GLuint index, const GLint* v)
	//		{
	//			if (pGlScissorIndexedv)
	//				pGlScissorIndexedv(index, v);
	//		}
	//		inline void COpenGLFunctionTable::extGlSampleCoverage(float value, bool invert)
	//		{
	//			if (pGlSampleCoverage)
	//				pGlSampleCoverage(value, invert);
	//		}
	//		inline void COpenGLFunctionTable::extGlSampleMaski(GLuint maskNumber, GLbitfield mask)
	//		{
	//			if (pGlSampleMaski)
	//				pGlSampleMaski(maskNumber, mask);
	//		}
	//		inline void COpenGLFunctionTable::extGlMinSampleShading(float value)
	//		{
	//			if (pGlMinSampleShading)
	//				pGlMinSampleShading(value);
	//		}
	//		inline void COpenGLFunctionTable::extGlBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
	//		{
	//			if (pGlBlendEquationSeparatei)
	//				pGlBlendEquationSeparatei(buf, modeRGB, modeAlpha);
	//		}
	//		inline void COpenGLFunctionTable::extGlBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
	//		{
	//			if (pGlBlendFuncSeparatei)
	//				pGlBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
	//		}
	//		inline void COpenGLFunctionTable::extGlColorMaski(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
	//		{
	//			if (pGlColorMaski)
	//				pGlColorMaski(buf, red, green, blue, alpha);
	//		}
	//
	//
	//
	//		inline void COpenGLFunctionTable::extGlBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
	//		{
	//			if (pGlBlendFuncSeparate)
	//				pGlBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlColorMaskIndexed(GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
	//		{
	//			if (pGlColorMaski)
	//				pGlColorMaski(buf, r, g, b, a);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlEnableIndexed(GLenum target, GLuint index)
	//		{
	//			if (pGlEnablei)
	//				pGlEnablei(target, index);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDisableIndexed(GLenum target, GLuint index)
	//		{
	//			if (pGlDisablei)
	//				pGlDisablei(target, index);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBlendFuncIndexed(GLuint buf, GLenum src, GLenum dst)
	//		{
	//			pGlBlendFunciARB(buf, src, dst);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBlendEquationIndexed(GLuint buf, GLenum mode)
	//		{
	//			pGlBlendEquationiARB(buf, mode);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlPatchParameterfv(GLenum pname, const float* values)
	//		{
	//			pGlPatchParameterfv(pname, values);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlPatchParameteri(GLenum pname, GLuint value)
	//		{
	//			pGlPatchParameteri(pname, value);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlProgramParameteri(GLuint program, GLenum pname, GLint value)
	//		{
	//			pGlProgramParameteri(program, pname, value);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlCreateQueries(GLenum target, GLsizei n, GLuint* ids)
	//		{
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlCreateQueries)
	//					pGlCreateQueries(target, n, ids);
	//			}
	//			else
	//			{
	//				if (pGlGenQueries)
	//					pGlGenQueries(n, ids);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlDeleteQueries(GLsizei n, const GLuint* ids)
	//		{
	//			if (pGlDeleteQueries)
	//				pGlDeleteQueries(n, ids);
	//		}
	//
	//		inline GLboolean COpenGLFunctionTable::extGlIsQuery(GLuint id)
	//		{
	//			if (pGlIsQuery)
	//				return pGlIsQuery(id);
	//			return false;
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBeginQuery(GLenum target, GLuint id)
	//		{
	//			if (pGlBeginQuery)
	//				pGlBeginQuery(target, id);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlEndQuery(GLenum target)
	//		{
	//			if (pGlEndQuery)
	//				pGlEndQuery(target);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
	//		{
	//			if (pGlBeginQueryIndexed)
	//				pGlBeginQueryIndexed(target, index, id);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlEndQueryIndexed(GLenum target, GLuint index)
	//		{
	//			if (pGlEndQueryIndexed)
	//				pGlEndQueryIndexed(target, index);
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params)
	//		{
	//			if (pGlGetQueryObjectuiv)
	//				pGlGetQueryObjectuiv(id, pname, params);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params)
	//		{
	//			if (pGlGetQueryObjectui64v)
	//				pGlGetQueryObjectui64v(id, pname, params);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
	//		{
	//			if (Version < 440 && !FeatureAvailable[IRR_ARB_query_buffer_object])
	//			{
	//#ifdef _DEBuG
	//				os::Printer::log("GL_ARB_query_buffer_object unsupported!\n
	//#endif // _DEBuG
	//					return;
	//			}
	//
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlGetQueryBufferObjectuiv)
	//					pGlGetQueryBufferObjectuiv(id, buffer, pname, offset);
	//			}
	//			else
	//			{
	//				GLint restoreQueryBuffer;
	//				glGetIntegerv(GL_QUERY_BUFFER_BINDING, &restoreQueryBuffer);
	//				pGlBindBuffer(GL_QUERY_BUFFER, id);
	//				if (pGlGetQueryObjectuiv)
	//					pGlGetQueryObjectuiv(id, pname, reinterpret_cast<GLuint*>(offset));
	//				pGlBindBuffer(GL_QUERY_BUFFER, restoreQueryBuffer);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
	//		{
	//			if (Version < 440 && !FeatureAvailable[IRR_ARB_query_buffer_object])
	//			{
	//#ifdef _DEBuG
	//				os::Printer::log("GL_ARB_query_buffer_object unsupported!\n
	//#endif // _DEBuG
	//					return;
	//			}
	//
	//			if (Version >= 450 || FeatureAvailable[IRR_ARB_direct_state_access])
	//			{
	//				if (pGlGetQueryBufferObjectui64v)
	//					pGlGetQueryBufferObjectui64v(id, buffer, pname, offset);
	//			}
	//			else
	//			{
	//				GLint restoreQueryBuffer;
	//				glGetIntegerv(GL_QUERY_BUFFER_BINDING, &restoreQueryBuffer);
	//				pGlBindBuffer(GL_QUERY_BUFFER, id);
	//				if (pGlGetQueryObjectui64v)
	//					pGlGetQueryObjectui64v(id, pname, reinterpret_cast<GLuint64*>(offset));
	//				pGlBindBuffer(GL_QUERY_BUFFER, restoreQueryBuffer);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlQueryCounter(GLuint id, GLenum target)
	//		{
	//			if (pGlQueryCounter)
	//				pGlQueryCounter(id, target);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBeginConditionalRender(GLuint id, GLenum mode)
	//		{
	//			if (pGlBeginConditionalRender)
	//				pGlBeginConditionalRender(id, mode);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlEndConditionalRender()
	//		{
	//			if (pGlEndConditionalRender)
	//				pGlEndConditionalRender();
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlTextureBarrier()
	//		{
	//			if (FeatureAvailable[IRR_ARB_texture_barrier])
	//				pGlTextureBarrier();
	//			else if (FeatureAvailable[IRR_NV_texture_barrier])
	//				pGlTextureBarrierNV();
	//#ifdef _IRR_DEBUG
	//			else
	//				os::Printer::log("EDF_TEXTURE_BARRIER Not Available!\n", ELL_ERROR);
	//#endif // _IRR_DEBUG
	//		}
	//
	//
	//		inline void COpenGLFunctionTable::extGlSwapInterval(int interval)
	//		{
	//			// we have wglext, so try to use that
	//#if defined(_IRR_WINDOWS_API_) && defined(_IRR_COMPILE_WITH_WINDOWS_DEVICE_)
	//#ifdef WGL_EXT_swap_control
	//			if (pWglSwapIntervalEXT)
	//				pWglSwapIntervalEXT(interval);
	//#endif
	//#endif
	//#ifdef _IRR_COMPILE_WITH_X11_DEVICE_
	//			//TODO: Check GLX_EXT_swap_control and GLX_MESA_swap_control
	//#ifdef GLX_SGI_swap_control
	//	// does not work with interval==0
	//			if (interval && pGlxSwapIntervalSGI)
	//				pGlxSwapIntervalSGI(interval);
	//#elif defined(GLX_EXT_swap_control)
	//			Display* dpy = glXGetCurrentDisplay();
	//			GLXDrawable drawable = glXGetCurrentDrawable();
	//
	//			if (pGlxSwapIntervalEXT)
	//				pGlxSwapIntervalEXT(dpy, drawable, interval);
	//#elif defined(GLX_MESA_swap_control)
	//			if (pGlxSwapIntervalMESA)
	//				pGlxSwapIntervalMESA(interval);
	//#endif
	//#endif
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlBlendEquation(GLenum mode)
	//		{
	//			pGlBlendEquation(mode);
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params)
	//		{
	//			if (Version >= 460 || FeatureAvailable[IRR_ARB_internalformat_query])
	//			{
	//				if (pGlGetInternalformativ)
	//					pGlGetInternalformativ(target, internalformat, pname, bufSize, params);
	//			}
	//		}
	//
	//		inline void COpenGLFunctionTable::extGlGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params)
	//		{
	//			if (Version >= 460 || FeatureAvailable[IRR_ARB_internalformat_query])
	//			{
	//				if (pGlGetInternalformati64v)
	//					pGlGetInternalformati64v(target, internalformat, pname, bufSize, params);
	//			}
	//		}
	//#pragma endregion

}		//namespace video
}		//namespace irr
#endif
