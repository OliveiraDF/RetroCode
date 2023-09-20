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

		IMPLEMENT_SERIAL(CPointNode, CDrawableNode, 1);

		CPointNode::CPointNode()
			: m_fSize(1.f)
		{

		}

		CPointNode::~CPointNode()
		{

		}

#pragma endregion
#pragma region Attributes

		void CPointNode::SetPoint(FLOAT fX, FLOAT fY)
		{
			m_ptPoint.X = fX;
			m_ptPoint.Y = fY;

			m_bNeedUpdateCache = TRUE;
		}

		void CPointNode::SetPoint(const core::TVector2f& ptPoint)
		{
			SetPoint(ptPoint.X, ptPoint.Y);
		}

		void CPointNode::SetSize(FLOAT fSize)
		{
			m_fSize = fSize;
		}

		const core::TVector2f& CPointNode::GetPoint() const
		{
			return m_ptPoint;
		}

		FLOAT CPointNode::GetSize() const
		{
			return m_fSize;
		}

#pragma endregion
#pragma region Overridables

		void CPointNode::DoUpdate()
		{
			if (m_bNeedUpdateCache)
			{
				m_Cache.RemoveAll();

				gl::TVertex Vertex;
				Vertex.vPosition = m_ptPoint;
				Vertex.clrColor = GetColor();

				m_Cache.Add(Vertex);

				//LogInf(_T("Point \"%s\" successfully updated"), GetName());

				m_bNeedUpdateCache = FALSE;
			}
		}

		void CPointNode::DoDraw(const gl::CRenderView* pRenderView) const
		{
			ASSERT(pRenderView);
			ASSERT_VALID(pRenderView);

			pRenderView->PointSize(m_fSize);
			pRenderView->Draw(m_Cache.GetData(), m_Cache.GetSize(), gl::EPrimitiveType_Points, 0, GetBlendMode(), 0);
			pRenderView->PointSize(1.f);
		}

		void CPointNode::Serialize(CArchive& ar)
		{
			CDrawableNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_ptPoint.X << m_ptPoint.Y << m_fSize;
			}
			else
			{
				ar >> m_ptPoint.X >> m_ptPoint.Y >> m_fSize;
			}
		}

#ifdef _DEBUG

		void CPointNode::Dump(CDumpContext& dc) const
		{
			CDrawableNode::Dump(dc);

			dc << _T("Point: (") << m_ptPoint.X << _T(";") << m_ptPoint.Y << _T(")");
			dc << _T("Size: ") << m_fSize;
		}

		void CPointNode::AssertValid() const
		{
			CDrawableNode::AssertValid();

			ASSERT(m_fSize >= 1.f);
		}

#endif

#pragma endregion

	}
}