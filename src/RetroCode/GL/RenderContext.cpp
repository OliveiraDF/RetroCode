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
#include "glext/glext.h"

PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
PFNGLGETATTACHEDOBJECTSARBPROC glGetInfoLogARB;
PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
PFNGLGETHANDLEARBPROC glGetHandleARB;
PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
PFNGLUNIFORM1FARBPROC glUniform1fARB;
PFNGLUNIFORM2FARBPROC glUniform2fARB;
PFNGLUNIFORM3FARBPROC glUniform3fARB;
PFNGLUNIFORM4FARBPROC glUniform4fARB;
PFNGLUNIFORM1IARBPROC glUniform1iARB;

namespace retro
{
	namespace gl
	{

#pragma region Constructors

		CRenderContext::CRenderContext()
			: m_bGLEXTInitialized(FALSE)
		{

		}

		CRenderContext::~CRenderContext()
		{

		}

#pragma endregion
#pragma region Attributes

		BOOL CRenderContext::IsGLEXTPrototypesInitialized() const
		{
			return m_bGLEXTInitialized;
		}

#pragma endregion
#pragma region Operations

		HRESULT CRenderContext::InitializeGLEXTPrototypes()
		{
			glCreateProgramObjectARB = reinterpret_cast<PFNGLCREATEPROGRAMOBJECTARBPROC>(wglGetProcAddress("glCreateProgramObjectARB"));
			glDeleteObjectARB = reinterpret_cast<PFNGLDELETEOBJECTARBPROC>(wglGetProcAddress("glDeleteObjectARB"));
			glCreateShaderObjectARB = reinterpret_cast<PFNGLCREATESHADEROBJECTARBPROC>(wglGetProcAddress("glCreateShaderObjectARB"));
			glShaderSourceARB = reinterpret_cast<PFNGLSHADERSOURCEARBPROC>(wglGetProcAddress("glShaderSourceARB"));
			glCompileShaderARB = reinterpret_cast<PFNGLCOMPILESHADERARBPROC>(wglGetProcAddress("glCompileShaderARB"));
			glGetObjectParameterivARB = reinterpret_cast<PFNGLGETOBJECTPARAMETERIVARBPROC>(wglGetProcAddress("glGetObjectParameterivARB"));
			glGetInfoLogARB = reinterpret_cast<PFNGLGETATTACHEDOBJECTSARBPROC>(wglGetProcAddress("glGetInfoLogARB"));
			glAttachObjectARB = reinterpret_cast<PFNGLATTACHOBJECTARBPROC>(wglGetProcAddress("glAttachObjectARB"));
			glLinkProgramARB = reinterpret_cast<PFNGLLINKPROGRAMARBPROC>(wglGetProcAddress("glLinkProgramARB"));
			glUseProgramObjectARB = reinterpret_cast<PFNGLUSEPROGRAMOBJECTARBPROC>(wglGetProcAddress("glUseProgramObjectARB"));
			glGetHandleARB = reinterpret_cast<PFNGLGETHANDLEARBPROC>(wglGetProcAddress("glGetHandleARB"));
			glGetUniformLocationARB = reinterpret_cast<PFNGLGETUNIFORMLOCATIONARBPROC>(wglGetProcAddress("glGetUniformLocationARB"));
			glUniform1fARB = reinterpret_cast<PFNGLUNIFORM1FARBPROC>(wglGetProcAddress("glUniform1fARB"));
			glUniform2fARB = reinterpret_cast<PFNGLUNIFORM2FARBPROC>(wglGetProcAddress("glUniform2fARB"));
			glUniform3fARB = reinterpret_cast<PFNGLUNIFORM3FARBPROC>(wglGetProcAddress("glUniform3fARB"));
			glUniform4fARB = reinterpret_cast<PFNGLUNIFORM4FARBPROC>(wglGetProcAddress("glUniform4fARB"));
			glUniform1iARB = reinterpret_cast<PFNGLUNIFORM1IARBPROC>(wglGetProcAddress("glUniform1iARB"));

			if (!glCreateProgramObjectARB ||
				!glDeleteObjectARB ||
				!glCreateShaderObjectARB ||
				!glShaderSourceARB ||
				!glCompileShaderARB ||
				!glGetObjectParameterivARB ||
				!glGetInfoLogARB ||
				!glAttachObjectARB ||
				!glLinkProgramARB ||
				!glUseProgramObjectARB ||
				!glGetHandleARB ||
				!glGetUniformLocationARB ||
				!glUniform1fARB ||
				!glUniform2fARB ||
				!glUniform3fARB ||
				!glUniform4fARB ||
				!glUniform1iARB)
			{
				return RC_GLEXT_NOTINITIALIZED;
			}

			m_bGLEXTInitialized = TRUE;
			
			return S_OK;
		}

		CString CRenderContext::GetString(EQueryString eQueryString) const
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

			ASSERT(eQueryString >= 0);
			ASSERT(eQueryString < EQueryString_COUNT);

			return CString(glGetString(QUERIES[eQueryString]));
		}

		void CRenderContext::Clear() const
		{
			glCheck(glClear(GL_COLOR_BUFFER_BIT));
		}

		void CRenderContext::ClearColor(const core::TColorRGBA& clrClear) const
		{
			glCheck(glClearColor(clrClear.Red / 255.f, clrClear.Green / 255.f, clrClear.Blue / 255.f, clrClear.Alpha / 255.f));
		}

		void CRenderContext::Flush() const
		{
			glCheck(glFlush());
		}

		void CRenderContext::Viewport(const core::TIntRect& rcViewport) const
		{
			glCheck(glViewport(rcViewport.Point.X, rcViewport.Point.Y, rcViewport.Size.X, rcViewport.Size.Y));
		}

		void CRenderContext::MatrixMode(EMatrixMode eMatrixMode) const
		{
			static constexpr const UINT MODES[] =
			{
				GL_MODELVIEW,
				GL_PROJECTION,
				GL_TEXTURE
			};
			static constexpr const UINT MODE_COUNT = ARRAYSIZE(MODES);
			C_ASSERT(MODE_COUNT == EMatrixMode_COUNT);

			ASSERT(eMatrixMode >= 0);
			ASSERT(eMatrixMode < EMatrixMode_COUNT);

			glCheck(glMatrixMode(MODES[eMatrixMode]));
		}

		void CRenderContext::LoadIdentity() const
		{
			glCheck(glLoadIdentity());
		}

		void CRenderContext::LoadMatrix(const C3x3Matrix& mMatrix) const
		{
			glCheck(glLoadMatrixf(mMatrix.GetMatrix()));
		}

		void CRenderContext::PushMatrix() const
		{
			glCheck(glPushMatrix());
		}

		void CRenderContext::MultMatrix(const C3x3Matrix& mMatrix) const
		{
			glCheck(glMultMatrixf(mMatrix.GetMatrix()));
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

		void CRenderContext::LineWidth(FLOAT fWidth) const
		{
			ASSERT(fWidth >= 1.f);

			glCheck(glLineWidth(fWidth));
		}

#define ENSURE_GLEXT_INITIALIZED if (!m_bGLEXTInitialized) { return ; }

		void CRenderContext::UseProgramARB(UINT uHandleARB) const
		{
			ENSURE_GLEXT_INITIALIZED

			glCheck(glUseProgramObjectARB(uHandleARB));
		}

		void CRenderContext::Uniform1iARB(INT nLocation, INT nV0) const
		{
			ENSURE_GLEXT_INITIALIZED

			glCheck(glUniform1iARB(nLocation, nV0));
		}

#pragma endregion

	}
}