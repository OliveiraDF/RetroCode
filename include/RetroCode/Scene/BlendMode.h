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

namespace retro
{
	namespace scene
	{

		/**
		 * @ingroup scene 
		 * @brief Available blending modes for drawing
		 *
		 */
		enum EBlendMode : INT
		{
			EBlendMode_Alpha,		/**< Pixel = Source * Source.a + Dest * (1 - Source.a) */
			EBlendMode_Add,			/**< Pixel = Source + Dest */
			EBlendMode_Multiply,	/**< Pixel = Source * Dest */
			EBlendMode_None,		/**< Pixel = Source */

			EBlendMode_COUNT,		/**< Blend mode count */
			EBlendMode_INVALID = -1 /**< Invalid blend mode */
		};

		/**
		 * @ingroup gl
		 * @brief Converts a blend mode enum value to a string
		 *
		 * @param eBlendMode The blend mode to convert
		 *
		 * @return A pointer to a constant string representing the blend mode, or NULL if the blend mode is invalid
		 *
		 */
		LPCTSTR AFX_EXT_API BlendModeToString(EBlendMode eBlendMode);

		/**
		 * @ingroup gl
		 * @brief Converts a string to a blend mode enum value
		 *
		 * @param lpszBlendMode The string to convert
		 *
		 * @return The corresponding blend mode, or EBlendMode_INVALID if the string is not recognized
		 *
		 */
		EBlendMode AFX_EXT_API StringToBlendMode(LPCTSTR lpszBlendMode);

	}
}