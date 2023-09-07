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
	namespace core
	{

		/**
		 * @ingroup core 
		 * @brief MS-DOS pattern like matching function
		 *
		 * The asterisk (*) and question mark (?) are used as wildcard
		 * characters, as they are in MS-DOS and Windows.
		 * The asterisk matches any sequence of characters, whereas
		 * the question mark matches any single character.
		 *
		 * @param lpszPattern	The pattern to match
		 * @param lpszString	The value that should match \a lpszPattern value
		 *
		 * @return S_OK if the string matches the pattern
		 *
		 */
		HRESULT AFX_EXT_API Matching(LPCTSTR lpszPattern, LPCTSTR lpszString);

	}
}