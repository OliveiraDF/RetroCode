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

		class AFX_EXT_API CViewNode : public CNode
		{
		public:

			enum EBehavior : INT
			{
				EBehavior_None,
				EBehavior_Stretch,
				EBehavior_Fit,

				EBehavior_COUNT
			};

#pragma region Constructors

		public:

			DECLARE_SERIAL(CViewNode);

		protected:

			CViewNode();

		public:

			virtual ~CViewNode();

		private:

			CViewNode(const CViewNode& Node) = delete;
			void operator=(const CViewNode& Node) = delete;

#pragma endregion
#pragma region Attributes

		private:

			core::TVector2f		m_szInternal;

		private:

			EBehavior			m_eBehavior;
			core::TVector2f		m_ptCenter;
			core::TVector2f		m_szSize;
			FLOAT				m_fRotation;
			core::TFloatRect	m_rcViewport;

		public:

			void SetViewport(const core::TFloatRect& rcViewport);
			void SetCenter(FLOAT fX, FLOAT fY);
			void SetCenter(const core::TVector2f& ptCenter);
			void SetSize(FLOAT fWidth, FLOAT fHeight);
			void SetSize(const core::TVector2f& szSize);
			void SetRotation(FLOAT fAngle);
			void SetBehavior(EBehavior eBehavior);
			void Move(FLOAT fOffsetX, FLOAT fOffsetY);
			void Move(const core::TVector2f& vOffset);
			void Rotate(FLOAT fAngle);
			void Zoom(FLOAT fFactor);
			const core::TFloatRect& GetViewport() const;
			const core::TVector2f& GetCenter() const;
			const core::TVector2f& GetSize() const;
			FLOAT GetRotation() const;
			EBehavior GetBehavior() const;
			const core::TVector2f& GetInternalSize() const;

#pragma endregion
#pragma region Overridables

		public:

			gl::C3x3Matrix Get3x3Matrix() const override;
			CViewNode* GetWorldView() override;
			const CViewNode* GetWorldView() const override;
			void DoDraw(const CSceneView* pView) const override;
			void DoResize(const core::TVector2i& szSize) override;
			void Serialize(CArchive& ar) override;
#ifdef _DEBUG
			void Dump(CDumpContext& dc) const override;
			void AssertValid() const override;
#endif

#pragma endregion
#pragma region Implementations

		private:

			void SetInternalSize(FLOAT fWidth, FLOAT fHeight);
			void SetInternalSize(const core::TVector2f& szSize);

#pragma endregion

		};

	}
}