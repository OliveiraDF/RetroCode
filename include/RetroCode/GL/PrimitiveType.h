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
	namespace gl
	{

		/**
		 * @ingroup gl
		 * @brief Type of primitives
		 *
		 */
		enum EPrimitiveType : UINT
		{
			EPrimitiveType_Points,			/**< Treats each vertex as a single point. Vertex n defines point n. N points are drawn */
			EPrimitiveType_Lines,			/**< Treats each pair of vertices as an independent line segment. Vertices 2n - 1 and 2n define line n. N/2 lines are drawn */
			EPrimitiveType_LineLoop,		/**< Draws a connected group of line segments from the first vertex to the last. Vertices n and n+1 define line n. N - 1 lines are drawn */
			EPrimitiveType_LineStrip,		/**< Draws a connected group of line segments from the first vertex to the last, then back to the first. Vertices n and n + 1 define line n. The last line, however, is defined by vertices N and 1. N lines are drawn */
			EPrimitiveType_Triangles,		/**< Treats each triplet of vertices as an independent triangle. Vertices 3n - 2, 3n - 1, and 3n define triangle n. N/3 triangles are drawn */
			EPrimitiveType_TriangleStrip,	/**< Draws a connected group of triangles. One triangle is defined for each vertex presented after the first two vertices. For odd n, vertices n, n + 1, and n + 2 define triangle n. For even n, vertices n + 1, n, and n + 2 define triangle n. N - 2 triangles are drawn */
			EPrimitiveType_TriangleFan,		/**< Draws a connected group of triangles. one triangle is defined for each vertex presented after the first two vertices. Vertices 1, n + 1, n + 2 define triangle n. N - 2 triangles are drawn */
			EPrimitiveType_Quads,			/**< Treats each group of four vertices as an independent quadrilateral. Vertices 4n - 3, 4n - 2, 4n - 1, and 4n define quadrilateral n. N/4 quadrilaterals are drawn */
			EPrimitiveType_QuadStrip,		/**< Draws a connected group of quadrilaterals. One quadrilateral is defined for each pair of vertices presented after the first pair. Vertices 2n - 1, 2n, 2n + 2, and 2n + 1 define quadrilateral n. N/2 - 1 quadrilaterals are drawn. Note that the order in which vertices are used to construct a quadrilateral from strip data is different from that used with independent data */
			EPrimitiveType_Polygon,			/**< Draws a single, convex polygon. Vertices 1 through N define this polygon */

			EPrimitiveType_COUNT			/**< Primitive type count */
		};

	}
}