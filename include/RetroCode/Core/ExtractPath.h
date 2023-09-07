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
		 * @brief Enumeration of the filename components
		 *
		 */
		enum EComponent : UINT
		{
			EComponent_Empty = 0x00,	/**< Empty component */
			EComponent_Drive = 0x01,	/**< Drive component */
			EComponent_Dir = 0x02,		/**< Directory component */
			EComponent_FileName = 0x04,	/**< Filename component */
			EComponent_Ext = 0x08,		/**< Extension component */

			EComponent_COUNT = 5		/**! Component count */
		};

		/**
		 * @ingroup core
		 * @brief Extracting path function
		 *
		 * @param lpszPath	The original path
		 * @param uComp		The combination of components
		 * @param strResult	The resulting extraction
		 *
		 * @return S_OK if the extraction was successful
		 *
		 */
		HRESULT AFX_EXT_API ExtractPath(LPCTSTR lpszPath, UINT uComp, CString& strResult);

	}
}