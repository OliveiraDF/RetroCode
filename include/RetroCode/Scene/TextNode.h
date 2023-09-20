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

		class AFX_EXT_API CTextNode : public CDrawableNode
		{
#pragma region Constructors

		public:

			DECLARE_SERIAL(CTextNode);

		protected:

			CTextNode();

		public:

			virtual ~CTextNode();

		private:

			CTextNode(const CTextNode& Node) = delete;
			void operator=(const CTextNode& Node) = delete;

#pragma endregion
#pragma region Attributes

		private:

			CString				m_strText;
			LOGFONT				m_LogFont;
			core::TColorRGBA	m_clrBackground;
			core::TColorRGBA	m_clrForeground;

#pragma endregion
#pragma region Overridables

		public:

			void Serialize(CArchive& ar) override;
#ifdef _DEBUG
			void Dump(CDumpContext& dc) const override;
			void AssertValid() const override;
#endif

#pragma endregion
#pragma region Implementations

		private:

			HRESULT UpdateBitmap(CDC* pDC);

#pragma endregion

		};

	}
}