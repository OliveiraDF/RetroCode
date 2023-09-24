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

		IMPLEMENT_SERIAL(CRectangleNode, CDrawableNode, 1);

		CRectangleNode::CRectangleNode()
		{

		}

		CRectangleNode::~CRectangleNode()
		{

		}

#pragma endregion
#pragma region Attributes

		void CRectangleNode::SetRectangle(const core::TFloatRect& rcRectangle)
		{
			m_rcRectangle = rcRectangle;

			m_bNeedUpdateCache = TRUE;
		}

		const core::TFloatRect& CRectangleNode::GetRectangle() const
		{
			return m_rcRectangle;
		}

#pragma endregion
#pragma region Overridables

		void CRectangleNode::DoUpdate()
		{
			if (m_bNeedUpdateCache)
			{
				m_Cache.RemoveAll();

				const core::TVector2f POINTS[] =
				{
					core::TVector2f(m_rcRectangle.Point.X, m_rcRectangle.Point.Y),
					core::TVector2f(m_rcRectangle.Point.X + m_rcRectangle.Size.X, m_rcRectangle.Point.Y),
					core::TVector2f(m_rcRectangle.Point.X + m_rcRectangle.Size.X, m_rcRectangle.Point.Y + m_rcRectangle.Size.Y),
					core::TVector2f(m_rcRectangle.Point.X, m_rcRectangle.Point.Y + m_rcRectangle.Size.Y)
				};
				const UINT POINTCOUNT = ARRAYSIZE(POINTS);

				for (UINT i = 0; i < POINTCOUNT; i++)
				{
					gl::TVertex Vertex;
					Vertex.vPosition = POINTS[i];
					Vertex.clrColor = GetColor();

					m_Cache.Add(Vertex);
				}

				//LogInf(_T("Rectangle \"%s\" successfully updated"), GetName());

				m_bNeedUpdateCache = FALSE;
			}
		}

		void CRectangleNode::DoDraw(const CSceneView* pView) const
		{
			ASSERT(pView);
			ASSERT_VALID(pView);

			pView->Draw(m_Cache.GetData(), m_Cache.GetSize(), gl::EPrimitiveType_Quads, 0, GetBlendMode(), 0);
		}

		void CRectangleNode::Serialize(CArchive& ar)
		{
			CDrawableNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_rcRectangle.Point.X << m_rcRectangle.Point.Y << m_rcRectangle.Size.X << m_rcRectangle.Size.Y;
			}
			else
			{
				ar >> m_rcRectangle.Point.X >> m_rcRectangle.Point.Y >> m_rcRectangle.Size.X >> m_rcRectangle.Size.Y;
			}
		}

#ifdef _DEBUG

		void CRectangleNode::Dump(CDumpContext& dc) const
		{
			CDrawableNode::Dump(dc);

			dc << _T("Rectangle: (") << m_rcRectangle.Point.X << _T(";") << m_rcRectangle.Point.Y << _T(";") << m_rcRectangle.Size.X << _T(";") << m_rcRectangle.Size.Y << _T(")");
		}

		void CRectangleNode::AssertValid() const
		{
			CDrawableNode::AssertValid();
		}

#endif

#pragma endregion

	}
}