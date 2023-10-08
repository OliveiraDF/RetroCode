/**
 *
 * Retro Code
 *
 * MIT License
 *
 * Copyright(c) 2014-2023 Retro Technique
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "pch.h"
#include "glextPrototypes.h"

#define ENSURE_GLEXT_INITIALIZED if (!IsGLEXTPrototypesInitialized()) { return ; }

extern PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
extern PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
extern PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
extern PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
extern PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
extern PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
extern PFNGLGETATTACHEDOBJECTSARBPROC glGetInfoLogARB;
extern PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
extern PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
extern PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
extern PFNGLGETHANDLEARBPROC glGetHandleARB;
extern PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
extern PFNGLUNIFORM1FARBPROC glUniform1fARB;
extern PFNGLUNIFORM2FARBPROC glUniform2fARB;
extern PFNGLUNIFORM3FARBPROC glUniform3fARB;
extern PFNGLUNIFORM4FARBPROC glUniform4fARB;
extern PFNGLUNIFORM1IARBPROC glUniform1iARB;

namespace retro
{
	namespace gl
	{

		static inline UINT ToGL(EFeatureType eType)
		{
			static constexpr const UINT FEATURES[] =
			{
				GL_ALPHA_TEST,
				GL_BLEND,
				GL_CULL_FACE,
				GL_DEPTH_TEST,
				GL_LIGHTING,
				GL_LINE_SMOOTH,
				GL_POINT_SMOOTH,
				GL_TEXTURE_2D
			};
			static constexpr const UINT FEATURE_COUNT = ARRAYSIZE(FEATURES);
			C_ASSERT(FEATURE_COUNT == EFeatureType_COUNT);

			return FEATURES[eType];
		}

		static inline UINT ToGL(ECompilationMode eType)
		{
			static constexpr const UINT MODES[] =
			{
				GL_COMPILE,
				GL_COMPILE_AND_EXECUTE
			};
			static constexpr const UINT MODE_COUNT = ARRAYSIZE(MODES);
			C_ASSERT(MODE_COUNT == ECompilationMode_COUNT);

			return MODES[eType];
		}

		static inline UINT ToGL(EDataType eType)
		{
			static constexpr const UINT DATATYPES[] =
			{
				GL_BYTE,
				GL_UNSIGNED_BYTE,
				GL_SHORT,
				GL_UNSIGNED_SHORT,
				GL_INT,
				GL_UNSIGNED_INT,
				GL_FLOAT,
				GL_2_BYTES,
				GL_3_BYTES,
				GL_4_BYTES,
				GL_DOUBLE,
				GL_BITMAP
			};
			static constexpr const UINT DATATYPE_COUNT = ARRAYSIZE(DATATYPES);
			C_ASSERT(DATATYPE_COUNT == EDataType_COUNT);

			return DATATYPES[eType];
		}

		static inline UINT ToGL(EFormatType eType)
		{
			static constexpr const UINT FORMATTYPES[] =
			{
				GL_COLOR_INDEX,
				GL_RED,
				GL_GREEN,
				GL_BLUE,
				GL_ALPHA,
				GL_RGB,
				GL_RGBA,
				GL_BGR_EXT,
				GL_BGRA_EXT,
				GL_LUMINANCE,
				GL_LUMINANCE_ALPHA
			};
			static constexpr const UINT FORMATTYPE_COUNT = ARRAYSIZE(FORMATTYPES);
			C_ASSERT(FORMATTYPE_COUNT == EFormatType_COUNT);

			return FORMATTYPES[eType];
		}

		static inline UINT ToGL(EQueryString eQueryString)
		{
			static constexpr const UINT QUERIES[] =
			{
				GL_VENDOR,
				GL_RENDERER,
				GL_VERSION,
				GL_EXTENSIONS
			};
			static constexpr const UINT QUERY_COUNT = ARRAYSIZE(QUERIES);
			C_ASSERT(QUERY_COUNT == EQueryString_COUNT);

			return QUERIES[eQueryString];
		}

		static inline UINT ToGL(EMatrixMode eMatrixMode)
		{
			static constexpr const UINT MODES[] =
			{
				GL_MODELVIEW,
				GL_PROJECTION,
				GL_TEXTURE
			};
			static constexpr const UINT MODE_COUNT = ARRAYSIZE(MODES);
			C_ASSERT(MODE_COUNT == EMatrixMode_COUNT);

			return MODES[eMatrixMode];
		}

		static inline UINT ToGL(EBlendFactorSrc eSrcFactor)
		{
			static constexpr const UINT FACTORS[] =
			{
				GL_ZERO,
				GL_ONE,
				GL_DST_COLOR,
				GL_ONE_MINUS_DST_COLOR,
				GL_SRC_ALPHA_SATURATE,
				GL_SRC_ALPHA,
				GL_ONE_MINUS_SRC_ALPHA,
				GL_DST_ALPHA,
				GL_ONE_MINUS_DST_ALPHA
			};
			static constexpr const UINT FACTOR_COUNT = ARRAYSIZE(FACTORS);
			C_ASSERT(FACTOR_COUNT == EBlendFactorSrc_COUNT);

			return FACTORS[eSrcFactor];
		}

		static inline UINT ToGL(EBlendFactorDst eDstFactor)
		{
			static constexpr const UINT FACTORS[] =
			{
				GL_ZERO,
				GL_ONE,
				GL_SRC_COLOR,
				GL_ONE_MINUS_SRC_COLOR,
				GL_SRC_ALPHA,
				GL_ONE_MINUS_SRC_ALPHA,
				GL_DST_ALPHA,
				GL_ONE_MINUS_DST_ALPHA
			};
			static constexpr const UINT FACTOR_COUNT = ARRAYSIZE(FACTORS);
			C_ASSERT(FACTOR_COUNT == EBlendFactorDst_COUNT);

			return FACTORS[eDstFactor];
		}

		static inline UINT ToGL(EArrayType eType)
		{
			static constexpr const UINT ARRAYS[] =
			{
				GL_COLOR_ARRAY,
				GL_EDGE_FLAG_ARRAY,
				GL_INDEX_ARRAY,
				GL_NORMAL_ARRAY,
				GL_TEXTURE_COORD_ARRAY,
				GL_VERTEX_ARRAY
			};
			static constexpr const UINT ARRAY_COUNT = ARRAYSIZE(ARRAYS);
			C_ASSERT(ARRAY_COUNT == EArrayType_COUNT);
			
			return ARRAYS[eType];
		}

		static inline UINT ToGL(ETextureType eType)
		{
			static constexpr const UINT TEXTURES[] =
			{
				GL_TEXTURE_1D,
				GL_TEXTURE_2D
			};
			static constexpr const UINT TEXTURE_COUNT = ARRAYSIZE(TEXTURES);
			C_ASSERT(TEXTURE_COUNT == ETextureType_COUNT);

			return TEXTURES[eType];
		}

		static inline UINT ToGL(ETextureParameter eParam)
		{
			static constexpr const UINT PARAMETERS[] =
			{
				GL_TEXTURE_MIN_FILTER,
				GL_TEXTURE_MAG_FILTER,
				GL_TEXTURE_WRAP_S,
				GL_TEXTURE_WRAP_T
			};
			static constexpr const UINT PARAMETER_COUNT = ARRAYSIZE(PARAMETERS);
			C_ASSERT(PARAMETER_COUNT == ETextureParameter_COUNT);

			return PARAMETERS[eParam];
		}

#pragma region Constructors

		CRenderContext::CRenderContext()
			: m_hGLRC(NULL)
		{

		}

		CRenderContext::~CRenderContext()
		{

		}

#pragma endregion
#pragma region Operations

		HRESULT CRenderContext::CreateContext(CDC* pDC)
		{
			ASSERT(!m_hGLRC);
			ASSERT(pDC);
			ASSERT_VALID(pDC);

			PIXELFORMATDESCRIPTOR PixelFormatDescriptor;
			ZeroMemory(&PixelFormatDescriptor, sizeof(PIXELFORMATDESCRIPTOR));
			PixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			PixelFormatDescriptor.nVersion = 1;
			PixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
			PixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			PixelFormatDescriptor.cColorBits = 32;
			PixelFormatDescriptor.cAlphaBits = 8;
			PixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;
			PixelFormatDescriptor.cDepthBits = 24;
			PixelFormatDescriptor.cStencilBits = 8;

			HDC hDC = pDC->GetSafeHdc();

			const INT nPixelFormat = ChoosePixelFormat(hDC, &PixelFormatDescriptor);
			if (!nPixelFormat)
			{
				return GetLastError();
			}

			BOOL bRet = SetPixelFormat(hDC, nPixelFormat, &PixelFormatDescriptor);
			if (bRet == FALSE)
			{
				return GetLastError();
			}

			HGLRC hGLRC = wglCreateContext(hDC);
			if (!hGLRC)
			{
				return GetLastError();
			}

			m_hGLRC = hGLRC;

			return S_OK;
		}

		void CRenderContext::Begin(EPrimitiveType eType) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < EPrimitiveType_COUNT);

			glCheck(glBegin(eType));
		}

		void CRenderContext::BindTexture(ETextureType eType, UINT uTexture) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < ETextureType_COUNT);

			glCheck(glBindTexture(ToGL(eType), uTexture));
		}

		void CRenderContext::BlendFunc(EBlendFactorSrc eSrcFactor, EBlendFactorDst eDstFactor) const
		{
			ASSERT(eSrcFactor >= 0);
			ASSERT(eDstFactor >= 0);
			ASSERT(eSrcFactor < EBlendFactorSrc_COUNT);
			ASSERT(eDstFactor < EBlendFactorDst_COUNT);

			glCheck(glBlendFunc(ToGL(eSrcFactor), ToGL(eDstFactor)));
		}

		void CRenderContext::Build2DMipmaps(INT nComponents, core::TVector2i& vSize, EFormatType eFormat, EDataType eData, LPCVOID pData) const
		{
			ASSERT(nComponents >= 1);
			ASSERT(nComponents <= 4);
			ASSERT(vSize.X > 0);
			ASSERT(vSize.Y > 0);
			ASSERT(eFormat == EFormatType_Color_Index ||
				eFormat == EFormatType_Red ||
				eFormat == EFormatType_Green ||
				eFormat == EFormatType_Blue ||
				eFormat == EFormatType_Alpha ||
				eFormat == EFormatType_RGB ||
				eFormat == EFormatType_RGBA ||
				eFormat == EFormatType_BGR_Ext ||
				eFormat == EFormatType_BGRA_Ext ||
				eFormat == EFormatType_Luminance ||
				eFormat == EFormatType_Luminance_Alpha);
			ASSERT(eData == EDataType_Byte ||
				eData == EDataType_Unsigned_Byte ||
				eData == EDataType_Short ||
				eData == EDataType_Unsigned_Short ||
				eData == EDataType_Int ||
				eData == EDataType_Unsigned_Int ||
				eData == EDataType_Float ||
				eData == EDataType_Bitmap);
			ASSERT(pData);

			glCheck(gluBuild2DMipmaps(ToGL(ETextureType_2D), nComponents, vSize.X, vSize.Y, ToGL(eFormat), ToGL(eData), pData));
		}

		void CRenderContext::CallList(UINT uList) const
		{
			glCheck(glCallList(uList));
		}

		void CRenderContext::Clear(EClearMask eMask) const
		{
			glCheck(glClear(eMask));
		}

		void CRenderContext::ClearColor(const core::TColorRGBA& clrClear) const
		{
			glCheck(glClearColor(clrClear.Red / 255.f, clrClear.Green / 255.f, clrClear.Blue / 255.f, clrClear.Alpha / 255.f));
		}

		void CRenderContext::ColorPointer(INT nSize, EDataType eDataType, INT nStride, LPCVOID pPointer) const
		{
			ASSERT(eDataType == EDataType_Byte ||
				eDataType == EDataType_Unsigned_Byte ||
				eDataType == EDataType_Short ||
				eDataType == EDataType_Unsigned_Short ||
				eDataType == EDataType_Int ||
				eDataType == EDataType_Unsigned_Int ||
				eDataType == EDataType_Float ||
				eDataType == EDataType_Double);

			glCheck(glColorPointer(nSize, ToGL(eDataType), nStride, pPointer));
		}

		void CRenderContext::DeleteTextures(INT nCount, UINT* pTextures) const
		{
			ASSERT(nCount > 0);
			ASSERT(pTextures);

			glCheck(glDeleteTextures(nCount, pTextures));
		}

		void CRenderContext::DeleteContext()
		{
			if (m_hGLRC)
			{
				wglDeleteContext(m_hGLRC);
				m_hGLRC = NULL;
			}
		}

		void CRenderContext::Disable(EFeatureType eType) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < EFeatureType_COUNT);

			glCheck(glDisable(ToGL(eType)));
		}

		void CRenderContext::DrawArrays(EPrimitiveType eType, INT nFirst, INT nCount) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < EPrimitiveType_COUNT);

			glCheck(glDrawArrays(eType, nFirst, nCount));
		}

		void CRenderContext::Enable(EFeatureType eType) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < EFeatureType_COUNT);

			glCheck(glEnable(ToGL(eType)));
		}

		void CRenderContext::EnableClientState(EArrayType eType) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < EArrayType_COUNT);

			glCheck(glEnableClientState(ToGL(eType)));
		}

		void CRenderContext::End() const
		{
			glCheck(glEnd());
		}

		void CRenderContext::EndList() const
		{
			glCheck(glEndList());
		}

		void CRenderContext::Flush() const
		{
			glCheck(glFlush());
		}

		void CRenderContext::GenTextures(INT nCount, UINT* pTextures) const
		{
			ASSERT(nCount > 0);
			ASSERT(pTextures);
			
			glCheck(glGenTextures(nCount, pTextures));
		}

		CString CRenderContext::GetString(EQueryString eQueryString) const
		{
			ASSERT(eQueryString >= 0);
			ASSERT(eQueryString < EQueryString_COUNT);

			return CString(glGetString(ToGL(eQueryString)));
		}

		void CRenderContext::LineWidth(FLOAT fWidth) const
		{
			ASSERT(fWidth >= 1.f);

			glCheck(glLineWidth(fWidth));
		}

		void CRenderContext::LoadIdentity() const
		{
			glCheck(glLoadIdentity());
		}

		void CRenderContext::LoadMatrix(const FLOAT* pMatrix) const
		{
			ASSERT(pMatrix);

			glCheck(glLoadMatrixf(pMatrix));
		}

		void CRenderContext::MakeCurrent(CDC* pDC) const
		{
			ASSERT(pDC);
			ASSERT_VALID(pDC);

			wglCheck(wglMakeCurrent(pDC->GetSafeHdc(), m_hGLRC));
		}

		void CRenderContext::MatrixMode(EMatrixMode eMatrixMode) const
		{
			ASSERT(eMatrixMode >= 0);
			ASSERT(eMatrixMode < EMatrixMode_COUNT);

			glCheck(glMatrixMode(ToGL(eMatrixMode)));
		}

		void CRenderContext::MultMatrix(const FLOAT* pMatrix) const
		{
			ASSERT(pMatrix);

			glCheck(glMultMatrixf(pMatrix));
		}

		void CRenderContext::NewList(UINT uList, ECompilationMode eMode) const
		{
			ASSERT(eMode >= 0);
			ASSERT(eMode < ECompilationMode_COUNT);

			glCheck(glNewList(uList, ToGL(eMode)));
		}

		void CRenderContext::Ortho(const core::TIntRect& rcView, DOUBLE fNear, DOUBLE fFar) const
		{
			glCheck(glOrtho(rcView.Left(), rcView.Right(), rcView.Bottom(), rcView.Top(), fNear, fFar));
		}

		void CRenderContext::PushMatrix() const
		{
			glCheck(glPushMatrix());
		}

		void CRenderContext::PopMatrix() const
		{
			glCheck(glPopMatrix());
		}

		void CRenderContext::PointSize(FLOAT fSize) const
		{
			ASSERT(fSize >= 1.f);

			glCheck(glPointSize(fSize));
		}

		void CRenderContext::Rotate(FLOAT fAngle, FLOAT fX, FLOAT fY, FLOAT fZ) const
		{
			glCheck(glRotatef(fAngle, fX, fY, fZ));
		}

		void CRenderContext::Scale(FLOAT fX, FLOAT fY, FLOAT fZ) const
		{
			glCheck(glScalef(fX, fY, fZ));
		}

		void CRenderContext::TexCoord2(const core::TVector2f& vCoord) const
		{
			glCheck(glTexCoord2f(vCoord.X, vCoord.Y));
		}

		void CRenderContext::TexCoordPointer(INT nSize, EDataType eDataType, INT nStride, LPCVOID pPointer) const
		{
			ASSERT(eDataType == EDataType_Short ||
				eDataType == EDataType_Int ||
				eDataType == EDataType_Float ||
				eDataType == EDataType_Double);

			glCheck(glTexCoordPointer(nSize, ToGL(eDataType), nStride, pPointer));
		}

		void CRenderContext::TexImage2D(INT nLevels, INT nComponents, const core::TVector2i& vSize, INT nBorder, EFormatType eFormat, EDataType eData, LPCVOID pData) const
		{
			ASSERT(nLevels >= 0);
			ASSERT(nComponents >= 1);
			ASSERT(nComponents <= 4);
			ASSERT(vSize.X > 0);
			ASSERT(vSize.Y > 0);
			ASSERT(nBorder == 0 || nBorder == 1);
			ASSERT(eFormat == EFormatType_Color_Index ||
				eFormat == EFormatType_Red ||
				eFormat == EFormatType_Green ||
				eFormat == EFormatType_Blue ||
				eFormat == EFormatType_Alpha ||
				eFormat == EFormatType_RGB ||
				eFormat == EFormatType_RGBA ||
				eFormat == EFormatType_BGR_Ext ||
				eFormat == EFormatType_BGRA_Ext ||
				eFormat == EFormatType_Luminance ||
				eFormat == EFormatType_Luminance_Alpha);
			ASSERT(eData == EDataType_Byte ||
				eData == EDataType_Unsigned_Byte ||
				eData == EDataType_Short ||
				eData == EDataType_Unsigned_Short ||
				eData == EDataType_Int ||
				eData == EDataType_Unsigned_Int ||
				eData == EDataType_Float ||
				eData == EDataType_Bitmap);
			ASSERT(pData);

			glCheck(glTexImage2D(ToGL(ETextureType_2D), nLevels, nComponents, vSize.X, vSize.Y, nBorder, ToGL(eFormat), ToGL(eData), pData));
		}

		void CRenderContext::TexParameteri(ETextureType eType, ETextureParameter eParam, INT nParam) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < ETextureType_COUNT);
			ASSERT(eParam >= 0);
			ASSERT(eParam < ETextureParameter_COUNT);

			glCheck(glTexParameteri(ToGL(eType), ToGL(eParam), nParam));
		}

		void CRenderContext::TexParameterf(ETextureType eType, ETextureParameter eParam, FLOAT fParam) const
		{
			ASSERT(eType >= 0);
			ASSERT(eType < ETextureType_COUNT);
			ASSERT(eParam >= 0);
			ASSERT(eParam < ETextureParameter_COUNT);

			glCheck(glTexParameterf(ToGL(eType), ToGL(eParam), fParam));
		}

		void CRenderContext::TexSubImage2D(INT nLevels, const core::TVector2i& vOffset, const core::TVector2i& vSize, EFormatType eFormat, EDataType eData, LPCVOID pData) const
		{
			ASSERT(nLevels >= 0);
			ASSERT(vOffset.X >= 0);
			ASSERT(vOffset.Y >= 0);
			ASSERT(vSize.X > 0);
			ASSERT(vSize.Y > 0);
			ASSERT(eFormat == EFormatType_Color_Index ||
				eFormat == EFormatType_Red ||
				eFormat == EFormatType_Green ||
				eFormat == EFormatType_Blue ||
				eFormat == EFormatType_Alpha ||
				eFormat == EFormatType_RGB ||
				eFormat == EFormatType_RGBA ||
				eFormat == EFormatType_BGR_Ext ||
				eFormat == EFormatType_BGRA_Ext ||
				eFormat == EFormatType_Luminance ||
				eFormat == EFormatType_Luminance_Alpha);
			ASSERT(eData == EDataType_Byte ||
				eData == EDataType_Unsigned_Byte ||
				eData == EDataType_Short ||
				eData == EDataType_Unsigned_Short ||
				eData == EDataType_Int ||
				eData == EDataType_Unsigned_Int ||
				eData == EDataType_Float ||
				eData == EDataType_Bitmap);
			ASSERT(pData);

			glCheck(glTexSubImage2D(ToGL(ETextureType_2D), nLevels, vOffset.X, vOffset.Y, vSize.X, vSize.Y, ToGL(eFormat), ToGL(eData), pData));
		}

		void CRenderContext::Translate(FLOAT fX, FLOAT fY, FLOAT fZ) const
		{
			glCheck(glTranslatef(fX, fY, fZ));
		}

		void CRenderContext::Uniform1iARB(INT nLocation, INT nV0) const
		{
			ENSURE_GLEXT_INITIALIZED
				
			glCheck(glUniform1iARB(nLocation, nV0));
		}

		void CRenderContext::UnmakeCurrent() const
		{
			wglCheck(wglMakeCurrent(NULL, NULL));
		}

		void CRenderContext::UseProgramARB(UINT uHandleARB) const
		{
			ENSURE_GLEXT_INITIALIZED

			glCheck(glUseProgramObjectARB(uHandleARB));
		}

		void CRenderContext::Vertex2(const core::TVector2f& vVertex) const
		{
			glCheck(glVertex2f(vVertex.X, vVertex.Y));
		}

		void CRenderContext::VertexPointer(INT nSize, EDataType eDataType, INT nStride, LPCVOID pPointer) const
		{
			ASSERT(eDataType == EDataType_Short ||
				eDataType == EDataType_Int ||
				eDataType == EDataType_Float ||
				eDataType == EDataType_Double);

			glCheck(glVertexPointer(nSize, ToGL(eDataType), nStride, pPointer));
		}

		void CRenderContext::Viewport(const core::TIntRect& rcViewport) const
		{
			ASSERT(rcViewport.Size.X >= 0);
			ASSERT(rcViewport.Size.Y >= 0);

			glCheck(glViewport(rcViewport.Point.X, rcViewport.Point.Y, rcViewport.Size.X, rcViewport.Size.Y));
		}

#pragma endregion

	}
}