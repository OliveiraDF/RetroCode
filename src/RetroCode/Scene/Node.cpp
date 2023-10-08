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

		IMPLEMENT_SERIAL(CNode, core::CObjectEx, 1);

		CNode::CNode()
			: m_pDocument(NULL)
			, m_pParent(NULL)
			, m_bActive(TRUE)
		{

		}

		CNode::~CNode()
		{
			RemoveChildren();
		}

#pragma endregion Constructors
#pragma region Attributes

		void CNode::SetName(LPCTSTR lpszName)
		{
			m_strName = lpszName;
		}

		LPCTSTR CNode::GetName() const
		{
			return m_strName.GetString();
		}

		void CNode::SetActive(BOOL bActive)
		{
			m_bActive = bActive;
		}

		BOOL CNode::IsActive() const
		{
			return m_bActive;
		}

		BOOL CNode::IsWorldActive() const
		{
			if (!IsActive())
			{
				return FALSE;
			}

			if (!m_pParent)
			{
				return TRUE;
			}

			return m_pParent->IsWorldActive();
		}

#pragma endregion Attributes
#pragma region Operations

		void CNode::AddChild(CNode* pChild)
		{
			if (pChild && (pChild != this))
			{
				pChild->AddRef();
				pChild->Detach();

				m_Children.AddTail(pChild);

				pChild->m_pParent = this;
			}
		}

		void CNode::RemoveChild(CNode* pChild)
		{
			POSITION pos = m_Children.Find(pChild);
			if (pos && pChild)
			{
				pChild->m_pParent = NULL;
				pChild->Release();
				m_Children.RemoveAt(pos);
			}
		}

		void CNode::RemoveChildren()
		{
			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				CObject* pObject = m_Children.GetNext(pos);
				ASSERT(pObject);
				ASSERT_KINDOF(CNode, pObject);
				CNode* pChild = STATIC_DOWNCAST(CNode, pObject);
				if (pChild)
				{
					pChild->m_pParent = NULL;
					pChild->Release();
				}
			}

			m_Children.RemoveAll();
		}

		void CNode::Detach()
		{
			if (m_pParent)
			{
				m_pParent->RemoveChild(this);
			}
		}

		const CNode* CNode::GetParent() const
		{
			return m_pParent;
		}

		CNode* CNode::GetParent()
		{
			return m_pParent;
		}

		const CNode* CNode::GetNodeFromName(LPCTSTR lpszName) const
		{
			if (!lpszName)
			{
				return NULL;
			}

			if (StrCmp(m_strName.GetString(), lpszName) == 0)
			{
				return this;
			}

			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				const CObject* pObject = m_Children.GetNext(pos);

				ASSERT(pObject);
				ASSERT_KINDOF(CNode, pObject);

				const CNode* pChild = DYNAMIC_DOWNCAST(CNode, pObject);
				const CNode* pNode = pChild->GetNodeFromName(lpszName);
				if (pNode)
				{
					return pNode;
				}
			}

			return NULL;
		}

		CNode* CNode::GetNodeFromName(LPCTSTR lpszName)
		{
			if (!lpszName)
			{
				return NULL;
			}

			if (StrCmp(m_strName.GetString(), lpszName) == 0)
			{
				return this;
			}

			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				CObject* pObject = m_Children.GetNext(pos);

				ASSERT(pObject);
				ASSERT_KINDOF(CNode, pObject);

				CNode* pChild = STATIC_DOWNCAST(CNode, pObject);
				CNode* pNode = pChild->GetNodeFromName(m_strName.GetString());
				if (pNode)
				{
					return pNode;
				}
			}

			return NULL;
		}

#pragma endregion Operations
#pragma region Overridables

		C3x3Matrix CNode::Get3x3Matrix() const
		{
			return C3x3Matrix_Identity;
		}

		CViewNode* CNode::GetWorldView()
		{
			CNode* pParent = GetParent();
			if (pParent)
			{
				return pParent->GetWorldView();
			}

			return NULL;
		}

		const CViewNode* CNode::GetWorldView() const
		{
			return GetWorldView();
		}

		void CNode::DoInitialUpdate()
		{

		}

		void CNode::DoUpdate()
		{

		}

		void CNode::DoDraw(const CSceneView* pView) const
		{
			UNREFERENCED_PARAMETER(pView);
		}

		void CNode::DoResize(const core::TVector2i& vSize)
		{
			UNREFERENCED_PARAMETER(vSize);
		}

		BOOL CNode::IsWorldVisible() const
		{
			const CNode* pParent = GetParent();
			if (!pParent)
			{
				return TRUE;
			}

			return pParent->IsWorldVisible();
		}

		void CNode::OnInitialUpdate()
		{
			DoInitialUpdate();

			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				CObject* pObject = m_Children.GetNext(pos);
				ASSERT_KINDOF(CNode, pObject);
				CNode* pChild = STATIC_DOWNCAST(CNode, pObject);
				if (pChild)
				{
					pChild->OnInitialUpdate();
				}
			}
		}

		void CNode::OnUpdate()
		{
			if (!m_bActive)
			{
				return;
			}

			DoUpdate();

			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				CObject* pObject = m_Children.GetNext(pos);
				ASSERT_KINDOF(CNode, pObject);
				CNode* pChild = STATIC_DOWNCAST(CNode, pObject);
				if (pChild)
				{
					pChild->OnInitialUpdate();
				}
			}
		}

		void CNode::OnDraw(const CSceneView* pView) const
		{
			ASSERT(pView);
			ASSERT_VALID(pView);

			if (!m_bActive)
			{
				return;
			}

			DoDraw(pView);

			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				const CObject* pObject = m_Children.GetNext(pos);
				ASSERT_KINDOF(CNode, pObject);
				const CNode* pChild = DYNAMIC_DOWNCAST(CNode, pObject);
				if (pChild)
				{
					pChild->OnDraw(pView);
				}
			}
		}

		void CNode::OnResize(const core::TVector2i& vSize)
		{
			DoResize(vSize);

			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				CObject* pObject = m_Children.GetNext(pos);
				ASSERT_KINDOF(CNode, pObject);
				CNode* pChild = STATIC_DOWNCAST(CNode, pObject);
				if (pChild)
				{
					pChild->OnResize(vSize);
				}
			}
		}

		void CNode::Serialize(CArchive& ar)
		{
			CObject::Serialize(ar);

			if (ar.IsStoring())
			{
				ar << m_strName << m_bActive;
			}
			else
			{
				ar >> m_strName >> m_bActive;
			}

			m_Children.Serialize(ar);

			if (!ar.IsStoring())
			{
				RebuildingConnections();
			}
		}

#ifdef _DEBUG

		void CNode::Dump(CDumpContext& dc) const
		{
			CObjectEx::Dump(dc);

			dc << _T("Name: ") << m_strName;
			dc << _T("Active: ") << m_bActive;

			m_Children.Dump(dc);
		}

		void CNode::AssertValid() const
		{
			CObjectEx::AssertValid();

			m_Children.AssertValid();
		}

#endif

#pragma endregion Overridables
#pragma region Implementations

		void CNode::SetDocument(CSceneDocument* pDocument)
		{
			ASSERT(pDocument);
			ASSERT_VALID(pDocument);

			m_pDocument = pDocument;
		}

		void CNode::RebuildingConnections()
		{
			POSITION pos = m_Children.GetHeadPosition();
			while (pos)
			{
				CObject* pObject = m_Children.GetNext(pos);
				ASSERT_KINDOF(CNode, pObject);
				CNode* pChild = STATIC_DOWNCAST(CNode, pObject);
				if (pChild)
				{
					pChild->m_pParent = this;
				}
			}
		}

#pragma endregion Implementations

	}
}