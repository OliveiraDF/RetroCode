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

namespace retro
{
	namespace gl
	{

		IMPLEMENT_DYNCREATE(CRenderView, CView)

		CRenderView::CRenderView()
			: m_hGLRC(NULL)
		{

		}

		CRenderView::~CRenderView()
		{

		}

		BEGIN_MESSAGE_MAP(CRenderView, CView)
			ON_WM_CREATE()
			ON_WM_DESTROY()
		END_MESSAGE_MAP()

		BOOL CRenderView::PreCreateWindow(CREATESTRUCT& cs)
		{
			cs.style &= ~WS_BORDER;

			return CView::PreCreateWindow(cs);
		}

		int CRenderView::OnCreate(LPCREATESTRUCT lpCreateStruct)
		{
			if (CView::OnCreate(lpCreateStruct) == -1)
			{
				return -1;
			}

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

			HDC hDC = GetDC()->GetSafeHdc();

			const INT nPixelFormat = ChoosePixelFormat(hDC, &PixelFormatDescriptor);
			if (!nPixelFormat)
			{
				return -1;
			}

			BOOL bRet = SetPixelFormat(hDC, nPixelFormat, &PixelFormatDescriptor);
			if (bRet == FALSE)
			{
				LogWinMsg(GetLastError(), _T("Unable to set pixel format"));
				return -1;
			}

			m_hGLRC = wglCreateContext(hDC);
			if (!m_hGLRC)
			{
				LogWinMsg(GetLastError(), _T("Unable to create OpenGL context"));
				return -1;
			}

			bRet = wglMakeCurrent(hDC, m_hGLRC);
			if (bRet == FALSE)
			{
				LogWinMsg(GetLastError(), _T("Unable to make current OpenGL context"));
				return -1;
			}

			LogInf(_T("OpenGL v%s video mode initialized"), GetString(EQueryString_Version).GetString());
			LogInf(_T("%s"), GetString(EQueryString_Renderer).GetString());

			glCheck(glEnable(GL_TEXTURE_2D));
			glCheck(glEnable(GL_BLEND));
			MatrixMode(EMatrixMode_ModelView);
			glCheck(glEnableClientState(GL_VERTEX_ARRAY));
			glCheck(glEnableClientState(GL_COLOR_ARRAY));
			glCheck(glEnableClientState(GL_TEXTURE_COORD_ARRAY));

			BOOL bInitialized = InitializeGLEXTPrototypes();
			if (bInitialized)
			{
				core::Log(_T("GLEXT prototypes initialized"), core::ELogLevel_Information);
			}
			else
			{
				core::Log(_T("Unable to load GLEXT prototypes"), core::ELogLevel_Warning);
			}

			return 0;
		}

		void CRenderView::OnDraw(CDC* pDC)
		{
			ASSERT(pDC);
			ASSERT_VALID(pDC);
		}

		void CRenderView::OnDestroy()
		{
			CView::OnDestroy();

			if (m_hGLRC)
			{
				wglDeleteContext(m_hGLRC);
				m_hGLRC = NULL;
			}
		}

#ifdef _DEBUG
		void CRenderView::AssertValid() const
		{
			CView::AssertValid();
		}

#ifndef _WIN32_WCE
		void CRenderView::Dump(CDumpContext& dc) const
		{
			CView::Dump(dc);

			dc << _T("GLRC: ") << m_hGLRC;
		}
#endif
#endif 

		void CRenderView::BeginDraw(CDC* pDC, const core::TColorRGBA& clrClear)
		{
			ASSERT(pDC);
			ASSERT_VALID(pDC);

			BOOL bRet = wglMakeCurrent(pDC->GetSafeHdc(), m_hGLRC);
			if (!bRet)
			{
				return;
			}

			ClearColor(clrClear);
			Clear();
		}

		void CRenderView::Draw(const TVertex* pVertices, INT nVertexCount, EPrimitiveType eType, UINT uTextureID, EBlendMode eBlendMode, UINT uShaderProgram) const
		{
			static constexpr const struct
			{
				GLenum uSrcFactor;
				GLenum uDstFactor;

			} BLENDMODES[] =
			{
				{ GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA },	/* EBlendMode_Alpha */
				{ GL_SRC_ALPHA, GL_ONE },					/* EBlendMode_Add */
				{ GL_DST_COLOR, GL_ZERO },					/* EBlendMode_Multiply */
				{ GL_ONE, GL_ZERO },						/* EBlendMode_None */
			};
			C_ASSERT(EBlendMode_COUNT == ARRAYSIZE(BLENDMODES));

			ASSERT(eBlendMode >= 0);
			ASSERT(eBlendMode < EBlendMode_COUNT);
			ASSERT(nVertexCount > 0);
			
			if (!pVertices)
			{
				return;
			}

			if (eBlendMode < 0)
			{
				return;
			}

			if (eBlendMode >= EBlendMode_COUNT)
			{
				return;
			}

			const BYTE* pData = reinterpret_cast<const BYTE*>(pVertices);

			glCheck(glBlendFunc(BLENDMODES[eBlendMode].uSrcFactor, BLENDMODES[eBlendMode].uDstFactor));
			glCheck(glBindTexture(GL_TEXTURE_2D, uTextureID));
			UseProgramARB(uShaderProgram);
			Uniform1iARB(uTextureID, 0);
			glCheck(glVertexPointer(2, GL_FLOAT, sizeof(TVertex), pData + 0));
			glCheck(glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(TVertex), pData + 8));
			glCheck(glTexCoordPointer(2, GL_FLOAT, sizeof(TVertex), pData + 12));
			
			glCheck(glDrawArrays(eType, 0, nVertexCount));
		}

		void CRenderView::EndDraw(CDC* pDC)
		{
			ASSERT(pDC);
			ASSERT_VALID(pDC);

			Flush();

			BOOL bRet = SwapBuffers(pDC->GetSafeHdc());
			if (!bRet)
			{
				return;
			}

			bRet = wglMakeCurrent(NULL, NULL);
			if (!bRet)
			{
				return;
			}
		}

	}
}