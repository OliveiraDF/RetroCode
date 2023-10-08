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

#pragma region Constructors

		IMPLEMENT_SERIAL(CLineNode, CDrawableNode, 1);

		CLineNode::CLineNode()
			: m_fThickness(1.f)
		{

		}

		CLineNode::~CLineNode()
		{

		}

#pragma endregion
#pragma region Attributes

		void CLineNode::SetStart(FLOAT fX, FLOAT fY)
		{
			m_ptStart.X = fX;
			m_ptStart.Y = fY;

			m_bNeedUpdateCache = TRUE;
		}

		void CLineNode::SetStart(const core::TVector2f& ptStart)
		{
			SetStart(ptStart.X, ptStart.Y);
		}

		void CLineNode::SetEnd(FLOAT fX, FLOAT fY)
		{
			m_ptEnd.X = fX;
			m_ptEnd.Y = fY;

			m_bNeedUpdateCache = TRUE;
		}

		void CLineNode::SetEnd(const core::TVector2f& ptEnd)
		{
			SetEnd(ptEnd.X, ptEnd.Y);
		}

		void CLineNode::SetThickness(FLOAT fThickness)
		{
			m_fThickness = fThickness;
		}

		const core::TVector2f& CLineNode::GetStart() const
		{
			return m_ptStart;
		}

		const core::TVector2f& CLineNode::GetEnd() const
		{
			return m_ptEnd;
		}

		FLOAT CLineNode::GetThickness() const
		{
			return m_fThickness;
		}

#pragma endregion
#pragma region Overridables

		void CLineNode::DoUpdate()
		{
			if (m_bNeedUpdateCache)
			{
				m_Cache.RemoveAll();

				TVertex Vertex;

				Vertex.clrColor = GetColor();
				Vertex.vPosition = m_ptStart;

				m_Cache.Add(Vertex);

				Vertex.vPosition = m_ptEnd;

				m_Cache.Add(Vertex);

				//LogInf(_T("Line \"%s\" successfully updated"), GetName());

				m_bNeedUpdateCache = FALSE;
			}
		}

		void CLineNode::DoDraw(const CSceneView* pView) const
		{
			ASSERT(pView);
			ASSERT_VALID(pView);

			pView->LineWidth(m_fThickness);
			pView->Draw(m_Cache.GetData(), m_Cache.GetSize(), gl::EPrimitiveType_Lines, 0, GetBlendMode(), 0);
			pView->LineWidth(1.f);
		}

		void CLineNode::Serialize(CArchive& ar)
		{
			CDrawableNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_ptStart.X << m_ptStart.Y << m_ptEnd.X << m_ptEnd.Y << m_fThickness;
			}
			else
			{
				ar >> m_ptStart.X >> m_ptStart.Y >> m_ptEnd.X >> m_ptEnd.Y >> m_fThickness;
			}
		}

#ifdef _DEBUG

		void CLineNode::Dump(CDumpContext& dc) const
		{
			CDrawableNode::Dump(dc);

			dc << _T("Center: (") << m_ptStart.X << _T(";") << m_ptStart.Y << _T(")");
			dc << _T("Center: (") << m_ptEnd.X << _T(";") << m_ptEnd.Y << _T(")");
			dc << _T("Thickness: ") << m_fThickness;
		}

		void CLineNode::AssertValid() const
		{
			CDrawableNode::AssertValid();

			ASSERT(m_fThickness >= 1.f);
		}

#endif

#pragma endregion

	}
}