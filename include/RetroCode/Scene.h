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
#include "MFC.h"
#include "GL.h"

#include "Scene/BlendMode.h"
#include "Scene/SceneDocument.h"
#include "Scene/SceneView.h"
#include "Scene/Node.h"
#include "Scene/ViewNode.h"
#include "Scene/TransformableNode.h"
#include "Scene/DrawableNode.h"
#include "Scene/PointNode.h"
#include "Scene/LineNode.h"
#include "Scene/RectangleNode.h"
#include "Scene/SpriteNode.h"
#include "Scene/TextNode.h"

namespace retro
{
	namespace scene
	{

		/**
		 * @ingroup scene
		 * @brief Get Retro Scene runtime version
		 *
		 * @return The version of Retro Scene
		 *
		 */
		AFX_EXT_API CString GetVersion();

	}
}

/**
 * @defgroup scene Scene module
 *
 * Scene module of RetroCode, defining ready-to-use 2D scene rendering
 *
 */