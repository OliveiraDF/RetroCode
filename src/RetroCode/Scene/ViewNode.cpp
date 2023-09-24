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

		IMPLEMENT_SERIAL(CViewNode, CNode, 1);

		CViewNode::CViewNode()
			: m_eBehavior(EBehavior_None)
			, m_fRotation(0.f)
		{

		}

		CViewNode::~CViewNode()
		{

		}

#pragma endregion
#pragma region Attributes

		void CViewNode::SetViewport(const core::TFloatRect& rcViewport)
		{
			m_rcViewport = rcViewport;
		}

		void CViewNode::SetCenter(FLOAT fX, FLOAT fY)
		{
			m_ptCenter.X = fX;
			m_ptCenter.Y = fY;
		}

		void CViewNode::SetCenter(const core::TVector2f& vCenter)
		{
			SetCenter(vCenter.X, vCenter.Y);
		}

		void CViewNode::SetSize(FLOAT fWidth, FLOAT fHeight)
		{
			m_szSize.X = fWidth;
			m_szSize.Y = fHeight;
		}

		void CViewNode::SetSize(const core::TVector2f& vSize)
		{
			SetSize(vSize.X, vSize.Y);
		}

		void CViewNode::SetRotation(FLOAT fAngle)
		{
			m_fRotation = fmodf(fAngle, 360.f);
			if (m_fRotation < 0)
			{
				m_fRotation = 360.f;
			}
		}

		void CViewNode::SetBehavior(EBehavior eBehavior)
		{
			m_eBehavior = eBehavior;
		}

		void CViewNode::Move(FLOAT fOffsetX, FLOAT fOffsetY)
		{
			SetCenter(m_ptCenter.X + fOffsetX, m_ptCenter.Y + fOffsetY);
		}

		void CViewNode::Move(const core::TVector2f& vOffset)
		{
			Move(vOffset.X, vOffset.Y);
		}

		void CViewNode::Rotate(FLOAT fAngle)
		{
			SetRotation(m_fRotation + fAngle);
		}

		void CViewNode::Zoom(FLOAT fFactor)
		{
			SetSize(m_szSize.X * fFactor, m_szSize.Y * fFactor);
		}

		const core::TFloatRect& CViewNode::GetViewport() const
		{
			return m_rcViewport;
		}

		const core::TVector2f& CViewNode::GetCenter() const
		{
			return m_ptCenter;
		}

		const core::TVector2f& CViewNode::GetSize() const
		{
			return m_szSize;
		}

		FLOAT CViewNode::GetRotation() const
		{
			return m_fRotation;
		}

		CViewNode::EBehavior CViewNode::GetBehavior() const
		{
			return m_eBehavior;
		}

		const core::TVector2f& CViewNode::GetInternalSize() const
		{
			return m_szInternal;
		}

#pragma endregion
#pragma region Overridables

		gl::C3x3Matrix CViewNode::Get3x3Matrix() const
		{
			const FLOAT fPI = static_cast<FLOAT>(M_PI);
			const FLOAT fAngle = m_fRotation * fPI / 180.f;
			const FLOAT fCosine = cosf(fAngle);
			const FLOAT fSine = sinf(fAngle);
			const FLOAT fTx = -m_ptCenter.X * fCosine - m_ptCenter.Y * fSine + m_ptCenter.X;
			const FLOAT fTy = m_ptCenter.X * fSine - m_ptCenter.Y * fCosine + m_ptCenter.Y;

			const FLOAT a = 2.f / m_szInternal.X;
			const FLOAT b = -2.f / m_szInternal.Y;
			const FLOAT c = -a * m_ptCenter.X;
			const FLOAT d = -b * m_ptCenter.Y;

			return gl::C3x3Matrix(a * fCosine, a * fSine, a * fTx + c,
				-b * fSine, b * fCosine, b * fTy + d,
				0.f, 0.f, 1.f);
		}

		CViewNode* CViewNode::GetWorldView()
		{
			return this;
		}

		const CViewNode* CViewNode::GetWorldView() const
		{
			return GetWorldView();
		}

		void CViewNode::DoDraw(const CSceneView* pView) const
		{
			CNode::DoDraw(pView);

			CRect rcWnd;
			pView->GetClientRect(rcWnd);

			const FLOAT fWindowWidth = static_cast<FLOAT>(rcWnd.Width());
			const FLOAT fWindowHeight = static_cast<FLOAT>(rcWnd.Height());

			core::TIntRect rcViewport;
			rcViewport.Point.X = static_cast<int32_t>(0.5f + fWindowWidth * m_rcViewport.Point.X);
			rcViewport.Point.Y = static_cast<int32_t>(0.5f + fWindowHeight * m_rcViewport.Point.Y);
			rcViewport.Size.X = static_cast<int32_t>(fWindowWidth * m_rcViewport.Size.X);
			rcViewport.Size.Y = static_cast<int32_t>(fWindowHeight * m_rcViewport.Size.Y);

			rcViewport.Point.Y = static_cast<int32_t>(fWindowHeight) - (rcViewport.Point.Y + rcViewport.Size.Y);
			
			pView->Viewport(rcViewport);

			pView->MatrixMode(gl::EMatrixMode_Projection);
			pView->LoadIdentity();
			pView->LoadMatrix(Get3x3Matrix().GetMatrix());

			pView->MatrixMode(gl::EMatrixMode_ModelView);
			pView->LoadIdentity();
		}

		void CViewNode::DoResize(const core::TVector2i& szSize)
		{
			CNode::DoResize(szSize);

			switch (m_eBehavior)
			{
			case EBehavior_None:
				SetInternalSize(core::TVector2f(core::TVector2i(szSize.X, szSize.Y)));
				break;
			case EBehavior_Fit:
			{
				const FLOAT fAspectDesired = m_szSize.X / m_szSize.Y;
				const FLOAT fAspectWindow = static_cast<FLOAT>(szSize.X) / static_cast<FLOAT>(szSize.Y);

				if (fAspectWindow < fAspectDesired)
				{
					const FLOAT fRatio = m_szSize.X / static_cast<FLOAT>(szSize.X);
					SetInternalSize(core::TVector2f(m_szSize.X, szSize.Y * fRatio));
				}
				else
				{
					const FLOAT fRatio = m_szSize.Y / static_cast<FLOAT>(szSize.Y);
					SetInternalSize(core::TVector2f(szSize.X * fRatio, m_szSize.Y));
				}
			}
			break;
			case EBehavior_Stretch:
				[[fallthrough]];
			default:
				SetInternalSize(m_szSize);
				break;
			}
		}

		void CViewNode::Serialize(CArchive& ar)
		{
			CNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_fRotation << m_eBehavior;
			}
			else
			{
				INT nBehavior = 0;

				ar >> m_fRotation >> nBehavior;

				m_eBehavior = static_cast<EBehavior>(nBehavior);
			}

			m_ptCenter.Serialize(ar);
			m_szSize.Serialize(ar);
			m_rcViewport.Serialize(ar);
		}

#ifdef _DEBUG

		void CViewNode::Dump(CDumpContext& dc) const
		{
			CNode::Dump(dc);

			dc << _T("Center: (") << m_ptCenter.X << _T(";") << m_ptCenter.Y << _T(")");
			dc << _T("Size: ") << m_szSize.X << _T(";") << m_szSize.Y << _T(")");
			dc << _T("Rotation: (") << m_fRotation;
			dc << _T("Viewport: (") << m_rcViewport.Point.X << _T(";") << m_rcViewport.Point.Y << _T(";") << m_rcViewport.Size.X << _T(";") << m_rcViewport.Size.Y << _T(")");
			dc << _T("Behavior: ") << m_eBehavior;
		}

		void CViewNode::AssertValid() const
		{
			CNode::AssertValid();

			ASSERT(m_szSize.X >= 0.f);
			ASSERT(m_szSize.Y >= 0.f);
			ASSERT(m_fRotation >= 0.f);
			ASSERT(m_fRotation <= 360.f);
			ASSERT(m_rcViewport.Point.X >= 0.f);
			ASSERT(m_rcViewport.Point.Y >= 0.f);
			ASSERT(m_rcViewport.Size.X >= 0.f);
			ASSERT(m_rcViewport.Size.Y >= 0.f);
		}

#endif

#pragma endregion
#pragma region Implementations

		void CViewNode::SetInternalSize(FLOAT fWidth, FLOAT fHeight)
		{
			m_szInternal.X = fWidth;
			m_szInternal.Y = fHeight;
		}

		void CViewNode::SetInternalSize(const core::TVector2f& szSize)
		{
			SetInternalSize(szSize.X, szSize.Y);
		}

#pragma endregion

	}
}