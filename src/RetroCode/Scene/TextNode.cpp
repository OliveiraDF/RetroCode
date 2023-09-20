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
	namespace scene
	{

		IMPLEMENT_SERIAL(CTextNode, CDrawableNode, 1);

		CTextNode::CTextNode()
			: CDrawableNode(ColorRGBA_White)
			, m_LogFont { 0 }
			, m_clrBackground(ColorRGBA_Black)
			, m_clrForeground(ColorRGBA_White)
		{
	
		}

		CTextNode::~CTextNode()
		{

		}

		void CTextNode::Serialize(CArchive& ar)
		{
			CDrawableNode::Serialize(ar);
		}

#ifdef _DEBUG

		void CTextNode::Dump(CDumpContext& dc) const
		{
			CDrawableNode::Dump(dc);
		}

		void CTextNode::AssertValid() const
		{
			CDrawableNode::AssertValid();
		}

#endif

		HRESULT CTextNode::UpdateBitmap(CDC* pDC)
		{
			ASSERT(pDC);
			ASSERT_VALID(pDC);

			CFont Font;
			BOOL bRet = Font.CreateFontIndirect(&m_LogFont);
			if (!bRet)
			{
				return E_FAIL;
			}

			pDC->SelectObject(Font);

			CSize szText;
			bRet = GetTextExtentPoint32(pDC->GetSafeHdc(), m_strText.GetString(), m_strText.GetLength(), &szText);
			if (!bRet)
			{
				return E_FAIL;
			}

			CBitmap Bitmap;
			bRet = Bitmap.CreateCompatibleBitmap(pDC, szText.cx, szText.cy);
			if (!bRet)
			{
				return E_FAIL;
			}

			pDC->SelectObject(Bitmap);

			CBrush Brush(m_clrBackground.ToCOLORREF());
			const CRect rcText = { 0, 0, szText.cx, szText.cy };

			pDC->FillRect(rcText, &Brush);
			pDC->SetTextColor(m_clrForeground.ToCOLORREF()); 
			pDC->SetBkMode(TRANSPARENT);
			pDC->TextOut(0, 0, m_strText.GetString(), m_strText.GetLength());

			Brush.DeleteObject();
			Bitmap.DeleteObject();
			Font.DeleteObject();

			return S_OK;
		}

	}
}