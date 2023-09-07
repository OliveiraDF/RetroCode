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

namespace retro
{
	namespace core
	{

		HRESULT Matching(LPCTSTR lpszPattern, LPCTSTR lpszString)
		{
			if (!lpszPattern)
			{
				return E_INVALIDARG;
			}

			if (!lpszString)
			{
				return E_INVALIDARG;
			}

			for (; *lpszPattern != _T('\0'); ++lpszPattern)
			{
				switch (*lpszPattern)
				{
					case _T('?'):
						if (*lpszString == _T('\0'))
						{
							return RC_NOT_MATCHING;
						}
						++lpszString;
						break;
					case _T('*'):
					{
						if (lpszPattern[1] == _T('\0'))
						{
							return S_OK;
						}

						UINT_PTR uMax = 0;
						HRESULT hr = StringCchLength(lpszString, STRSAFE_MAX_CCH, &uMax);
						if (FAILED(hr))
						{
							return hr;
						}

						for (UINT_PTR i = 0; i < uMax; i++)
						{
							if (Matching(lpszPattern + 1, lpszString + i) == S_OK)
							{
								return S_OK;
							}
						}
						return RC_NOT_MATCHING;
					}
					default:
						if (*lpszString != *lpszPattern)
						{
							return RC_NOT_MATCHING;
						}
						++lpszString;
				}
			}

			return (*lpszString == _T('\0')) ? S_OK : RC_NOT_MATCHING;
		}

	}
}