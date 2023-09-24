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

		class AFX_EXT_API CRectangleNode : public CDrawableNode
		{
#pragma region Constructors

		public:

			DECLARE_SERIAL(CRectangleNode);

		protected:

			CRectangleNode();

		public:

			virtual ~CRectangleNode();

		private:

			CRectangleNode(const CRectangleNode& Node) = delete;
			void operator=(const CRectangleNode& Node) = delete;

#pragma endregion
#pragma region Attributes

		private:

			core::TFloatRect	m_rcRectangle;

		public:

			void SetRectangle(const core::TFloatRect& rcRectangle);
			const core::TFloatRect& GetRectangle() const;

#pragma endregion
#pragma region Overridables

		public:

			void DoUpdate() override;
			void DoDraw(const CSceneView* pView) const override;
			void Serialize(CArchive& ar) override;
#ifdef _DEBUG
			void Dump(CDumpContext& dc) const override;
			void AssertValid() const override;
#endif

#pragma endregion

		};

	}
}