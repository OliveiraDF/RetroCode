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
	namespace gl
	{

		class AFX_EXT_API CRenderView : public CView, public CRenderContext
		{

#pragma region Constructors

			/**
			 * @brief Enables objects of CView-derived classes to be created dynamically at run time
			 *
			 */
			DECLARE_DYNCREATE(CRenderView)

		protected:

			/**
			* @brief Default constructor
			*
			*/
			CRenderView();

			/**
			 * @brief Destructor
			 *
			 */
			virtual ~CRenderView();

#pragma endregion
#pragma region Overridables

		public:

			/**
			 * @brief Called by the framework before the creation of the Windows window attached to this CWnd object
			 *
			 * @param cs Called by the framework before the creation of the Windows window attached to this CWnd object
			 * 
			 * @return Nonzero if the window creation should continue; 0 to indicate creation failure
			 *
			 */
			BOOL PreCreateWindow(CREATESTRUCT& cs) override;

			/**
			 * @brief Called by the framework to render an image of the document
			 * 
			 * @param pDC Points to the device context to be used for rendering an image of the document
			 *
			 */
			void OnDraw(CDC* pDC) override;   

#pragma endregion
#pragma region Messages

		protected:

			/**
			 * @brief Declares that a message map will be used in a class to map messages to functions
			 *
			 */
			DECLARE_MESSAGE_MAP()

		public:

			/**
			 * @brief Called as a part of window creation
			 * 
			 * @param lpCreateStruct Points to a CREATESTRUCT structure that contains information about the CWnd object being created
			 * 
			 * @return 0 to continue the creation of the CWnd object
			 *
			 */
			afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

			/**
			 * @brief Called when CWnd is being destroyed
			 *
			 */
			afx_msg void OnDestroy();

#pragma endregion

		};

	}

}



