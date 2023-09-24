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

		IMPLEMENT_SERIAL(CSpriteNode, CDrawableNode, 1);

		CSpriteNode::CSpriteNode()
			: CDrawableNode(ColorRGBA_White)
			, m_bUseSource(FALSE)
		{

		}

		CSpriteNode::~CSpriteNode()
		{

		}

		void CSpriteNode::SetTexture(LPCTSTR lpszTexture)
		{
			m_strTexture = lpszTexture;

			m_bNeedUpdateCache = TRUE;
		}

		void CSpriteNode::SetUseSource(BOOL bUseSource)
		{
			m_bUseSource = bUseSource;

			m_bNeedUpdateCache = TRUE;
		}

		void CSpriteNode::SetSource(const core::TIntRect& rcSource)
		{
			m_rcSource = rcSource;

			m_bNeedUpdateCache = TRUE;
		}

		LPCTSTR CSpriteNode::GetTexture() const
		{
			return m_strTexture.GetString();
		}

		BOOL CSpriteNode::IsUseSource() const
		{
			return m_bUseSource;
		}

		const core::TIntRect& CSpriteNode::GetSource() const
		{
			return m_rcSource;
		}

		void CSpriteNode::DoUpdate()
		{
			if (m_bNeedUpdateCache)
			{
				/* 
				
				CSceneDocument* pDocument = GetDocument();
			 	CResource* pResource = pDocument->GetResource(m_strTexture.GetString());
				if (!Resource)
				{
					return; //not found
				}

				if (!pResource->IsKindOf(RUNTIME_CLASS(CTextureResource))
				{
					return; //not a texture
				}

				CTextureResource* pTexture = STATIC_DOWNCAST(CTextureResource, pResource);
				
				const TVector2u szTexture = pTexture->GetSize();

				*/

				const FLOAT fWidth = 0.f;
				const FLOAT fHeight = 0.f;

				core::TIntRect rcSource(core::TFloatRect(0, 0, fWidth, fHeight));

				if (m_bUseSource)
				{
					rcSource = m_rcSource;
				}

				const FLOAT fMinU = static_cast<FLOAT>(rcSource.Point.X) / fWidth;
				const FLOAT fMaxU = (rcSource.Point.X + rcSource.Size.X) / fWidth;
				const FLOAT fMinV = static_cast<FLOAT>(rcSource.Point.Y) / fHeight;
				const FLOAT fMaxV = (rcSource.Point.Y + rcSource.Size.Y) / fHeight;

				m_Cache.RemoveAll();

				gl::TVertex Vertex;

				Vertex.vPosition = core::TVector2f(0.f, 0.f);
				Vertex.clrColor = GetColor();
				Vertex.vTexCoords = core::TVector2f(fMinU, 1.f - fMinV);

				m_Cache.Add(Vertex);

				Vertex.vPosition = core::TVector2f(0.f, static_cast<FLOAT>(rcSource.Size.Y));
				Vertex.clrColor = GetColor();
				Vertex.vTexCoords = core::TVector2f(fMinU, 1.f - fMaxV);

				m_Cache.Add(Vertex);

				Vertex.vPosition = core::TVector2f(static_cast<FLOAT>(rcSource.Size.X), static_cast<FLOAT>(rcSource.Size.Y));
				Vertex.clrColor = GetColor();
				Vertex.vTexCoords = core::TVector2f(fMaxU, 1.f - fMaxV);

				m_Cache.Add(Vertex);

				Vertex.vPosition = core::TVector2f(static_cast<FLOAT>(rcSource.Size.X), 0.f);
				Vertex.clrColor = GetColor();
				Vertex.vTexCoords = core::TVector2f(fMaxU, 1.f - fMinV);

				m_Cache.Add(Vertex);

				//LogInf(_T("Sprite \"%s\" successfully updated"), GetName());

				m_bNeedUpdateCache = FALSE;
			}
		}

		void CSpriteNode::DoDraw(const CSceneView* pView) const
		{
			ASSERT(pView);
			ASSERT_VALID(pView);

			const UINT uID = 0;
			const UINT uShaderProgram = 0;

			pView->Draw(m_Cache.GetData(), m_Cache.GetSize(), gl::EPrimitiveType_Quads, uID, GetBlendMode(), uShaderProgram);
		}

		void CSpriteNode::Serialize(CArchive& ar)
		{
			CDrawableNode::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_strTexture << m_bUseSource << m_rcSource.Point.X << m_rcSource.Point.Y << m_rcSource.Size.X << m_rcSource.Size.Y;
			}
			else
			{
				ar >> m_strTexture >> m_bUseSource >> m_rcSource.Point.X >> m_rcSource.Point.Y >> m_rcSource.Size.X >> m_rcSource.Size.Y;
			}
		}

#ifdef _DEBUG

		void CSpriteNode::Dump(CDumpContext& dc) const
		{
			CDrawableNode::Dump(dc);

			dc << _T("Texture: ") << m_strTexture;
			dc << _T("UseSource: ") << m_bUseSource;
			dc << _T("Source: (") << m_rcSource.Point.X << _T(";") << m_rcSource.Point.Y << _T(";") << m_rcSource.Size.X << _T(";") << m_rcSource.Size.Y << _T(")");
		}

		void CSpriteNode::AssertValid() const
		{
			CDrawableNode::AssertValid();

			ASSERT(m_rcSource.Point.X >= 0.f);
			ASSERT(m_rcSource.Point.Y >= 0.f);
			ASSERT(m_rcSource.Size.X >= 0.f);
			ASSERT(m_rcSource.Size.Y >= 0.f);
		}

#endif

	}
}