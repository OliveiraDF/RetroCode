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

		class AFX_EXT_API CTransformableNode : public CNode
		{
#pragma region Constructors

		public:

			DECLARE_SERIAL(CTransformableNode);

		protected:

			CTransformableNode();

		public:

			virtual ~CTransformableNode();

		private:

			CTransformableNode(const CTransformableNode& Node) = delete;
			void operator=(const CTransformableNode& Node) = delete;

#pragma endregion
#pragma region Attributes

		private:

			core::TVector2f	m_vOrigin;
			core::TVector2f	m_vPosition;
			FLOAT			m_fRotation;
			core::TVector2f	m_vScale;

		public:

			void SetPosition(FLOAT fX, FLOAT fY);
			void SetPosition(const core::TVector2f& vPosition);
			void SetRotation(FLOAT fAngle);
			void SetScale(FLOAT fFactorX, FLOAT fFactorY);
			void SetScale(const core::TVector2f& vFactor);
			void SetOrigin(FLOAT fX, FLOAT fY);
			void SetOrigin(const core::TVector2f& vOrigin);
			void Move(FLOAT fOffsetX, FLOAT fOffsetY);
			void Move(const core::TVector2f& vOffset);
			void Rotate(FLOAT fAngle);
			void Scale(FLOAT fFactorX, FLOAT fFactorY);
			void Scale(const core::TVector2f& vFactor);
			const core::TVector2f& GetPosition() const;
			core::TVector2f GetWorldPosition() const;
			FLOAT GetRotation() const;
			const core::TVector2f& GetScale() const;
			const core::TVector2f& GetOrigin() const;
			C3x3Matrix GetWorld3x3Matrix() const;

#pragma endregion
#pragma region Overridables

		public:

			C3x3Matrix Get3x3Matrix() const override;
			void OnDraw(const CSceneView* pView) const override;
			void Serialize(CArchive& ar) override;
#ifdef _DEBUG
			void Dump(CDumpContext& dc) const override;
			void AssertValid() const override;
#endif

#pragma endregion
			
		};

	}
}