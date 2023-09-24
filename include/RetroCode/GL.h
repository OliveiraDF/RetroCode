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

#pragma once

 /**
  * Headers
  */
#include "Core.h"

#include "GL/Check.h"
#include "GL/FeatureType.h"
#include "GL/ArrayType.h"
#include "GL/CompilationMode.h"
#include "GL/QueryString.h"
#include "GL/MatrixMode.h"
#include "GL/PrimitiveType.h"
#include "GL/FormatType.h"
#include "GL/DataType.h"
#include "GL/TextureParameter.h"
#include "GL/TextureType.h"
#include "GL/BlendFactor.h"
#include "GL/Vertex.h"
#include "GL/3x3Matrix.h"
#include "GL/RenderContext.h"
#include "GL/RenderWindow.h"
#include "GL/RenderView.h"

namespace retro
{
	namespace gl
	{

		/**
		 * @ingroup gl
		 * @brief Get Retro GL runtime version
		 *
		 * @return The version of Retro GL
		 *
		 */
		AFX_EXT_API CString GetVersion();

	}
}

/**
 * @defgroup gl GL module
 *
 * GL module of RetroCode, defining ready-to-use OpenGL context, view...
 *
 */