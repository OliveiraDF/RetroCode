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

		class AFX_EXT_API CDrawableNode : public CTransformableNode
		{
#pragma region Constructors

		public:

			DECLARE_SERIAL(CDrawableNode);

		protected:

			CDrawableNode();
			explicit CDrawableNode(EBlendMode eBlendMode);
			explicit CDrawableNode(const core::TColorRGBA& clrColor);
			explicit CDrawableNode(LPCTSTR lpszShader);
			CDrawableNode(EBlendMode eBlendMode, const core::TColorRGBA& clrColor, LPCTSTR lpszShader = NULL);

		public:

			virtual ~CDrawableNode();

		private:

			CDrawableNode(const CDrawableNode& Node) = delete;
			void operator=(const CDrawableNode& Node) = delete;

#pragma endregion Constructors
#pragma region Attributes

		protected:

			CArray<gl::TVertex>	m_Cache;
			BOOL				m_bNeedUpdateCache;

		private:

			BOOL				m_bVisible;
			EBlendMode			m_eBlendMode;
			core::TColorRGBA	m_clrColor;
			CString				m_strShader;

		public:

			void SetVisible(BOOL bVisible);
			void SetBlendMode(EBlendMode eBlendMode);
			EBlendMode GetBlendMode() const;
			void SetColor(const core::TColorRGBA& cColor);
			BOOL IsVisible() const;
			const core::TColorRGBA& GetColor() const;
			void SetAlpha(BYTE uAlpha);
			BYTE GetAlpha() const;
			void SetShader(LPCTSTR zShader);
			LPCTSTR GetShader() const;
			
#pragma endregion Attributes
#pragma region Overridables

		public:

			BOOL IsWorldVisible() const override;
			void OnDraw(const CSceneView* pView) const override;
			void Serialize(CArchive& ar) override;
#ifdef _DEBUG
			void Dump(CDumpContext& dc) const override;
			void AssertValid() const override;
#endif

#pragma endregion Overridables

		};

	}
}