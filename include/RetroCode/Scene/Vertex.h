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
		 * @brief Structure that represents a vertex with position, color and texture
		 * coordinates
		 *
		 * This structure is used to store attributes of a vertex in 2D graphics.
		 * In contains a position vector, a color value and a texture coordinate vector.
		 *
		 */
		struct AFX_EXT_API TVertex
		{
			/**
			 * @brief Default constructor
			 *
			 */
			TVertex();

			/**
			 * @brief Constructor with position
			 *
			 * @param vPosition Position of the vertex in 2D space
			 *
			 */
			explicit TVertex(const core::TVector2f& vPosition);

			/**
			 * @brief Constructor with position and color
			 *
			 * @param vPosition Position of the vertex in 2D space
			 * @param clrColor	Color of the vertex
			 *
			 */
			TVertex(const core::TVector2f& vPosition, const core::TColorRGBA& clrColor);

			/**
			 * @brief Constructor with position and texture coordinates
			 *
			 * @param vPosition		Position of the vertex in 2D space
			 * @param vTexCoords	Texture coordinates of the vertex
			 *
			 */
			TVertex(const core::TVector2f& vPosition, const core::TVector2f& vTexCoords);

			/**
			 * @brief Constructor with position, color and texture coordinates
			 *
			 * @param vPosition		Position of the vertex in 2D space
			 * @param clrColor		Color of the vertex
			 * @param vTexCoords	Texture coordinates of the vertex
			 *
			 */
			TVertex(const core::TVector2f& vPosition, const core::TColorRGBA& clrColor, const core::TVector2f& vTexCoords);

			core::TVector2f		vPosition;		/**< Position of the vertex in 2D space */
			core::TColorRGBA	clrColor;		/**< Color of the vertex */
			core::TVector2f		vTexCoords;		/**< Texture coordinates of the vertex */

		};

	}
}