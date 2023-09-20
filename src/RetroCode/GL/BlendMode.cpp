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
	namespace gl
	{

		static constexpr LPCTSTR BLENDMODES[] =
		{
			_T("Alpha"),
			_T("Add"),
			_T("Multiply"),
			_T("None")
		};
		C_ASSERT(EBlendMode_COUNT == ARRAYSIZE(BLENDMODES));

		LPCTSTR BlendModeToString(EBlendMode eBlendMode)
		{
			ASSERT(eBlendMode >= 0);
			ASSERT(eBlendMode < EBlendMode_COUNT);

			if (eBlendMode < 0)
			{
				return NULL;
			}

			if (eBlendMode >= EBlendMode_COUNT)
			{
				return NULL;
			}

			return BLENDMODES[eBlendMode];
		}

		EBlendMode StringToBlendMode(LPCTSTR lpszBlendMode)
		{
			for (INT i = 0; i < EBlendMode_COUNT; i++)
			{
				if (StrCmp(BLENDMODES[i], lpszBlendMode) == 0)
				{
					return static_cast<EBlendMode>(i);
				}
			}

			ASSERT(FALSE);

			return EBlendMode_INVALID;
		}

	}
}