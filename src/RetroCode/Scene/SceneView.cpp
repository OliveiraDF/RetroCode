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
#include "resource.h"

namespace retro
{
	namespace scene
	{

#pragma region Constructors

		IMPLEMENT_DYNCREATE(CSceneView, gl::CRenderView)

		CSceneView::CSceneView()
		{

		}

		CSceneView::~CSceneView()
		{

		}

#pragma endregion

		BEGIN_MESSAGE_MAP(CSceneView, gl::CRenderView)
			ON_WM_CREATE()
			ON_WM_SIZE()
		END_MESSAGE_MAP()

#pragma region Attributes

#ifdef _DEBUG

		CSceneDocument* CSceneView::GetDocument() const
		{
			ASSERT_KINDOF(CSceneDocument, m_pDocument);
			return DYNAMIC_DOWNCAST(CSceneDocument, m_pDocument);
		}

#endif

#pragma endregion
#pragma region Overridables

		BOOL CSceneView::PreCreateWindow(CREATESTRUCT& cs)
		{
			cs.style &= ~WS_BORDER;

			return gl::CRenderView::PreCreateWindow(cs);
		}

		void CSceneView::OnInitialUpdate()
		{
			CNode* pRoot = GetRootDocument();

			pRoot->OnInitialUpdate();

			gl::CRenderView::OnInitialUpdate();
		}

		void CSceneView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
		{
			UNREFERENCED_PARAMETER(pSender);
			UNREFERENCED_PARAMETER(lHint);
			UNREFERENCED_PARAMETER(pHint);

			CNode* pRoot = GetRootDocument();

			pRoot->OnUpdate();
		}

		void CSceneView::OnDraw(CDC* pDC)
		{
			const CNode* pRoot = GetRootDocument();

			HRESULT hr;

			BeginDraw(pDC, ColorRGBA_Gray);

			pRoot->OnDraw(this);

			EndDraw(pDC);
		}

#ifdef _DEBUG

		void CSceneView::AssertValid() const
		{
			gl::CRenderView::AssertValid();
		}

#ifndef _WIN32_WCE

		void CSceneView::Dump(CDumpContext& dc) const
		{
			gl::CRenderView::Dump(dc);
		}

#endif
#endif

#pragma endregion
#pragma region Implementations

		CNode* CSceneView::GetRootDocument()
		{
			CSceneDocument* pDocument = GetDocument();
			ASSERT(pDocument);
			ASSERT_VALID(pDocument);

			/*
				CNode* pRoot = pDocument->GetRoot();
				ASSERT(pRoot);
				ASSERT_VALID(pRoot);

				return pRoot;
			*/

			return NULL;
		}

		const CNode* CSceneView::GetRootDocument() const
		{
			CSceneDocument* pDocument = GetDocument();
			ASSERT(pDocument);
			ASSERT_VALID(pDocument);

			/*
				const CNode* pRoot = pDocument->GetRoot();
				ASSERT(pRoot);
				ASSERT_VALID(pRoot);

				return pRoot;
			*/

			return NULL;
		}

#pragma endregion
#pragma region Messages

		int CSceneView::OnCreate(LPCREATESTRUCT lpCreateStruct)
		{
			if (gl::CRenderView::OnCreate(lpCreateStruct) == -1)
			{
				return -1;
			}

			return 0;
		}

		void CSceneView::OnSize(UINT uType, int cx, int cy)
		{
			gl::CRenderView::OnSize(uType, cx, cy);

			CNode* pRoot = GetRootDocument();

			pRoot->OnResize(core::TVector2i(cx, cy));
		}

#pragma endregion

	}
}