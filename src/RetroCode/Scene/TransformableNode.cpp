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

		IMPLEMENT_SERIAL(CTransformableNode, CNode, 1);

		CTransformableNode::CTransformableNode()
			: m_fRotation(0.f)
			, m_vScale{ 1.f, 1.f }
		{

		}

		CTransformableNode::~CTransformableNode()
		{

		}

		void CTransformableNode::SetPosition(FLOAT fX, FLOAT fY)
		{
			m_vPosition.X = fX;
			m_vPosition.Y = fY;
		}

		void CTransformableNode::SetPosition(const core::TVector2f& vPosition)
		{
			SetPosition(vPosition.X, vPosition.Y);
		}

		void CTransformableNode::SetRotation(FLOAT fAngle)
		{
			m_fRotation = fmodf(fAngle, 360.f);
			if (m_fRotation < 0)
			{
				m_fRotation += 360.f;
			}
		}

		void CTransformableNode::SetScale(FLOAT fFactorX, FLOAT fFactorY)
		{
			m_vScale.X = fFactorX;
			m_vScale.Y = fFactorY;
		}

		void CTransformableNode::SetScale(const core::TVector2f& vFactor)
		{
			SetScale(vFactor.X, vFactor.Y);
		}

		void CTransformableNode::SetOrigin(FLOAT fX, FLOAT fY)
		{
			m_vOrigin.X = fX;
			m_vOrigin.Y = fY;
		}

		void CTransformableNode::SetOrigin(const core::TVector2f& vOrigin)
		{
			SetOrigin(vOrigin.X, vOrigin.Y);
		}

		void CTransformableNode::Move(FLOAT fOffsetX, FLOAT fOffsetY)
		{
			SetPosition(m_vPosition.X + fOffsetX, m_vPosition.Y + fOffsetY);
		}

		void CTransformableNode::Move(const core::TVector2f& vOffset)
		{
			Move(vOffset.X, vOffset.Y);
		}

		void CTransformableNode::Rotate(FLOAT fAngle)
		{
			SetRotation(m_fRotation + fAngle);
		}

		void CTransformableNode::Scale(FLOAT fFactorX, FLOAT fFactorY)
		{
			SetScale(m_vScale.X * fFactorX, m_vScale.Y * fFactorY);
		}

		void CTransformableNode::Scale(const core::TVector2f& vFactor)
		{
			SetScale(m_vScale.X * vFactor.X, m_vScale.Y * vFactor.Y);
		}

		const core::TVector2f& CTransformableNode::GetPosition() const
		{
			return m_vPosition;
		}

		core::TVector2f CTransformableNode::GetWorldPosition() const
		{
			return GetWorld3x3Matrix() * core::TVector2f();
		}

		FLOAT CTransformableNode::GetRotation() const
		{
			return m_fRotation;
		}

		const core::TVector2f& CTransformableNode::GetScale() const
		{
			return m_vScale;
		}

		const core::TVector2f& CTransformableNode::GetOrigin() const
		{
			return m_vOrigin;
		}

		gl::C3x3Matrix CTransformableNode::Get3x3Matrix() const
		{
			const FLOAT fPI = static_cast<FLOAT>(M_PI);
			const FLOAT fAngle = -m_fRotation * fPI / 180.f;
			const FLOAT fCosine = cosf(fAngle);
			const FLOAT fSine = sinf(fAngle);
			const FLOAT fSxc = m_vScale.X * fCosine;
			const FLOAT fSyc = m_vScale.Y * fCosine;
			const FLOAT fSxs = m_vScale.X * fSine;
			const FLOAT fSys = m_vScale.Y * fSine;
			const FLOAT fTx = -m_vOrigin.X * fSxc - m_vOrigin.Y * fSys + m_vPosition.X;
			const FLOAT fTy = m_vOrigin.X * fSxs - m_vOrigin.Y * fSyc + m_vPosition.Y;

			return gl::C3x3Matrix(fSxc, fSys, fTx,
				-fSxs, fSyc, fTy,
				0.f, 0.f, 1.f);
		}

		gl::C3x3Matrix CTransformableNode::GetWorld3x3Matrix() const
		{
			gl::C3x3Matrix mMatrix = C3x3Matrix_Identity;
			
			for (const CNode* pNode = this; pNode != NULL; pNode = pNode->GetParent())
			{
				mMatrix = pNode->Get3x3Matrix() * mMatrix;
			}

			return mMatrix;
		}

		void CTransformableNode::OnDraw(const gl::CRenderView* pRenderView) const
		{
			ASSERT(pRenderView);
			ASSERT_VALID(pRenderView);

			pRenderView->PushMatrix();
			pRenderView->MultMatrix(Get3x3Matrix());

			CNode::OnDraw(pRenderView);

			pRenderView->PopMatrix();
		}

		void CTransformableNode::Serialize(CArchive& ar)
		{
			CNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_vPosition.X << m_vPosition.Y << m_fRotation << m_vScale.X << m_vScale.Y << m_vOrigin.X << m_vOrigin.Y;
			}
			else
			{
				ar >> m_vPosition.X >> m_vPosition.Y >> m_fRotation >> m_vScale.X >> m_vScale.Y >> m_vOrigin.X >> m_vOrigin.Y;
			}
		}

#ifdef _DEBUG

		void CTransformableNode::Dump(CDumpContext& dc) const
		{
			CNode::Dump(dc);

			dc << _T("Position: (") << m_vPosition.X << _T(";") << m_vPosition.Y << _T(")");
			dc << _T("Rotation: ") << m_fRotation;
			dc << _T("Scale: (") << m_vScale.X << _T(";") << m_vScale.Y << _T(")");
			dc << _T("Origin: (") << m_vOrigin.X << _T(";") << m_vOrigin.Y << _T(")");
		}

		void CTransformableNode::AssertValid() const
		{
			CNode::AssertValid();

			ASSERT(m_fRotation >= 0.f);
			ASSERT(m_fRotation <= 360.f);
		}

#endif

	}
}