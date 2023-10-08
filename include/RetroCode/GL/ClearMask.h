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
		 * @brief Bitwise OR operators of masks that indicate the buffers to be cleared
		 *
		 */
		enum EClearMask : UINT
		{
			EClearMask_Depth_Buffer_Bit = 0x00000100,	/**< The depth buffer */
			EClearMask_Accum_Buffer_Bit = 0x00000200,	/**< The accumulation buffer */
			EClearMask_Stencil_Buffer_Bit = 0x00000400,	/**< The accumulation buffer */
			EClearMask_Color_Buffer_Bit = 0x00004000	/**< The buffers currently enabled for color writing */
		};

	}
}