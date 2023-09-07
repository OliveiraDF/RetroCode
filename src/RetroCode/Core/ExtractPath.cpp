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

		HRESULT ExtractPath(LPCTSTR lpszPath, UINT uComp, CString& strResult)
		{
			if (!lpszPath)
			{
				return E_INVALIDARG;
			}

			UINT_PTR uPathLen = 0;
			HRESULT hr = StringCchLength(lpszPath, MAX_PATH, &uPathLen);
			if (FAILED(hr))
			{
				return hr;
			}

			LPCTSTR lpszDoubleDot = StrChr(lpszPath, _T(':'));
			LPCTSTR lpszLastSlash = StrRChr(lpszPath, NULL, _T('/'));
			LPCTSTR lpszLastAslash = StrRChr(lpszPath, NULL, _T('\\'));
			LPCTSTR lpszLastDot = StrRChr(lpszPath, NULL, _T('.'));

			LPCTSTR lpszRoot = NULL;
			LPCTSTR lpszDir = NULL;
			LPCTSTR lpszFile = NULL;
			LPCTSTR lpszExt = NULL;
			INT nRootLength = 0;
			INT nDirLength = 0;
			INT nFileNameLength = 0;
			INT nExtLength = 0;
			INT nPathDeb = 0;
			INT nPathFin = 0;

			if (lpszDoubleDot)
			{
				lpszRoot = lpszPath;
				nRootLength = static_cast<INT>(lpszDoubleDot - lpszPath) + 1;
				nPathDeb = nPathFin = nRootLength;
			}
			else if (uPathLen > 2 && ((lpszPath[0] == _T('\\') && lpszPath[1] == _T('\\')) || (lpszPath[0] == _T('/') && lpszPath[1] == _T('/'))))
			{
				LPCTSTR lpszFirstSlash = lpszPath + 2;

				while (lpszFirstSlash[0] != _T('\0'))
				{
					if (lpszFirstSlash[0] == _T('\\') || lpszFirstSlash[0] == _T('/'))
					{
						break;
					}
					lpszFirstSlash++;
				}
				lpszRoot = lpszPath;
				nRootLength = static_cast<INT>(lpszFirstSlash - lpszPath) + 1;
				nPathDeb = nPathFin = nRootLength;

				if (lpszLastSlash == (lpszPath + 1))
				{
					lpszLastSlash = NULL;
				}
				if (lpszLastAslash == (lpszPath + 1))
				{
					lpszLastAslash = NULL;
				}
			}

			if (lpszLastSlash || lpszLastAslash)
			{
				lpszFile = ((lpszLastSlash > lpszLastAslash) ? lpszLastSlash : lpszLastAslash) + 1;
			}
			else if (lpszDoubleDot)
			{
				lpszFile = lpszDoubleDot + 1;
			}
			else if (lpszLastDot != lpszPath)
			{
				lpszFile = lpszPath;
			}

			if (lpszFile)
			{
				if (lpszLastDot && lpszFile < lpszLastDot)
				{
					nFileNameLength = static_cast<INT>(lpszLastDot - lpszFile);
				}
				else
				{
					if (lpszLastDot)
					{
						lpszLastDot = NULL;
					}

					UINT_PTR uFileNameLen = 0;
					hr = StringCchLength(lpszFile, MAX_PATH, &uFileNameLen);
					if (FAILED(hr))
					{
						return hr;
					}
					nFileNameLength = static_cast<INT>(uFileNameLen);
				}
				nPathFin = static_cast<INT>(lpszFile - lpszPath);
			}

			if (lpszLastDot)
			{
				lpszExt = lpszLastDot;

				UINT_PTR uExtLen = 0;
				hr = StringCchLength(lpszExt, MAX_PATH, &uExtLen);
				if (FAILED(hr))
				{
					return hr;
				}
				nExtLength = static_cast<INT>(uExtLen);
			}

			if (nPathDeb != nPathFin)
			{
				lpszDir = lpszPath + nPathDeb;
				nDirLength = nPathFin - nPathDeb;
			}

			INT nTotalLength = 0;
			if ((uComp & EComponent_Drive) && nRootLength)
			{
				nTotalLength += nRootLength;
			}
			if ((uComp & EComponent_Dir) && nDirLength)
			{
				nTotalLength += nDirLength;
			}
			if ((uComp & EComponent_FileName) && nFileNameLength)
			{
				nTotalLength += nFileNameLength;
			}
			if ((uComp & EComponent_Ext) && nExtLength)
			{
				nTotalLength += nExtLength;
			}

			if (nTotalLength == 0)
			{
				strResult.Empty();
				return S_OK;
			}

			CString strDrive, strDirectory, strFileName, strExtension;

			if ((uComp & EComponent_Drive) && nRootLength)
			{
				strDrive.SetString(lpszRoot, nRootLength);
			}
			if ((uComp & EComponent_Dir) && nDirLength)
			{
				strDirectory.SetString(lpszDir, nDirLength);
			}
			if ((uComp & EComponent_FileName) && nFileNameLength)
			{
				strFileName.SetString(lpszFile, nFileNameLength);
			}
			if ((uComp & EComponent_Ext) && nExtLength)
			{
				strExtension.SetString(lpszExt, nExtLength);
			}
			
			strResult = strDrive + strDirectory + strFileName + strExtension;

			return S_OK;
		}

	}
}