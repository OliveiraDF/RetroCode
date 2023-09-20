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

		IMPLEMENT_SERIAL(CDrawableNode, CTransformableNode, 1);

		CDrawableNode::CDrawableNode()
			: m_bNeedUpdateCache(TRUE)
			, m_bVisible(TRUE)
			, m_eBlendMode(gl::EBlendMode_Alpha)
		{

		}

		CDrawableNode::CDrawableNode(gl::EBlendMode eBlendMode)
			: m_bNeedUpdateCache(TRUE)
			, m_bVisible(TRUE)
			, m_eBlendMode(eBlendMode)
			, m_clrColor(ColorRGBA_Black)
		{

		}

		CDrawableNode::CDrawableNode(const core::TColorRGBA& clrColor)
			: m_bNeedUpdateCache(TRUE)
			, m_bVisible(TRUE)
			, m_eBlendMode(gl::EBlendMode_Alpha)
			, m_clrColor(clrColor)
		{

		}

		CDrawableNode::CDrawableNode(LPCTSTR lpszShader)
			: m_bNeedUpdateCache(TRUE)
			, m_bVisible(TRUE)
			, m_eBlendMode(gl::EBlendMode_Alpha)
			, m_clrColor(ColorRGBA_Black)
			, m_strShader(lpszShader)
		{

		}

		CDrawableNode::CDrawableNode(gl::EBlendMode eBlendMode, const core::TColorRGBA& clrColor, LPCTSTR lpszShader)
			: m_bNeedUpdateCache(TRUE)
			, m_bVisible(TRUE)
			, m_eBlendMode(eBlendMode)
			, m_clrColor(clrColor)
			, m_strShader(lpszShader)
		{

		}

		CDrawableNode::~CDrawableNode()
		{

		}

		void CDrawableNode::SetVisible(BOOL bVisible)
		{
			m_bVisible = bVisible;
			m_bNeedUpdateCache = TRUE;
		}

		void CDrawableNode::SetBlendMode(gl::EBlendMode eBlendMode)
		{
			m_eBlendMode = eBlendMode;
			m_bNeedUpdateCache = TRUE;
		}

		void CDrawableNode::SetColor(const core::TColorRGBA& cColor)
		{
			m_clrColor = cColor;
			m_bNeedUpdateCache = TRUE;
		}

		void CDrawableNode::SetAlpha(BYTE uAlpha)
		{
			m_clrColor.Alpha = uAlpha;
			m_bNeedUpdateCache = TRUE;
		}

		void CDrawableNode::SetShader(LPCTSTR zShader)
		{
			m_strShader = zShader;
			m_bNeedUpdateCache = TRUE;
		}

		BOOL CDrawableNode::IsVisible() const
		{
			return m_bVisible;
		}

		const core::TColorRGBA& CDrawableNode::GetColor() const
		{
			return m_clrColor;
		}

		uint8_t CDrawableNode::GetAlpha() const
		{
			return m_clrColor.Alpha;
		}

		gl::EBlendMode CDrawableNode::GetBlendMode() const
		{
			return m_eBlendMode;
		}

		LPCTSTR CDrawableNode::GetShader() const
		{
			return m_strShader.GetString();
		}

		BOOL CDrawableNode::IsWorldVisible() const
		{
			if (!IsVisible())
			{
				return FALSE;
			}

			return CNode::IsWorldVisible();
		}

		void CDrawableNode::OnDraw(const gl::CRenderView* pRenderView) const
		{
			ASSERT(pRenderView);
			ASSERT_VALID(pRenderView);

			if (!m_bVisible)
			{
				return;
			}

			CTransformableNode::OnDraw(pRenderView);
		}

		void CDrawableNode::Serialize(CArchive& ar)
		{
			CTransformableNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_bVisible << m_eBlendMode << m_clrColor.Red << m_clrColor.Green << m_clrColor.Blue << m_clrColor.Alpha << m_strShader;
			}
			else
			{
				INT nBlendMode = gl::EBlendMode_None;

				ar >> m_bVisible >> nBlendMode >> m_clrColor.Red >> m_clrColor.Green >> m_clrColor.Blue >> m_clrColor.Alpha >> m_strShader;

				m_eBlendMode = static_cast<gl::EBlendMode>(nBlendMode);
			}
		}

#ifdef _DEBUG

		void CDrawableNode::Dump(CDumpContext& dc) const
		{
			CTransformableNode::Dump(dc);

			dc << _T("Visible: ") << m_bVisible;
			dc << _T("BlendMode: ") << gl::BlendModeToString(m_eBlendMode);
			dc << _T("Color: (") << m_clrColor.Red << _T(";") << m_clrColor.Green << _T(";") << m_clrColor.Blue << _T(";") << m_clrColor.Alpha << _T(")");
			dc << _T("Shader: ") << m_strShader;
		}

		void CDrawableNode::AssertValid() const
		{
			CTransformableNode::AssertValid();

			ASSERT(m_eBlendMode >= 0);
			ASSERT(m_eBlendMode < gl::EBlendMode_COUNT);
		}

#endif

	}
}