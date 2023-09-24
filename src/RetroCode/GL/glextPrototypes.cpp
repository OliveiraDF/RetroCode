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

		static BOOL s_GLEXTInitialized = FALSE;

		HRESULT InitializeGLEXTPrototypes()
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

			s_GLEXTInitialized = TRUE;

			return S_OK;
		}

		BOOL IsGLEXTPrototypesInitialized()
		{
			return s_GLEXTInitialized;
		}

	}
}