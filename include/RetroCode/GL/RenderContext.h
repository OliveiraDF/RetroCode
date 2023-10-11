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

		class AFX_EXT_API CRenderContext
		{
#pragma region Constructors

		public:

			CRenderContext();
			~CRenderContext();

#pragma endregion
#pragma region Attributes

		private:

			HGLRC	m_hGLRC;

#pragma endregion
#pragma region Operations

		public:

			HRESULT CreateContext(CDC* pDC);
			void Begin(EPrimitiveType eType) const;
			void BindTexture(ETextureType eTextureType, UINT uTexture) const;
			void BlendFunc(EBlendFactorSrc eSrcFactor, EBlendFactorDst eDstFactor) const;
			void Build2DMipmaps(INT nComponents, core::TVector2i& vSize, EFormatType eFormat, EDataType eData, LPCVOID pData) const;
			void CallList(UINT uList) const;
			void Clear(UINT uMask) const;
			void ClearColor(const core::TColorRGBA& clrClear) const;
			void ColorPointer(INT nSize, EDataType eDataType, INT nStride, LPCVOID pPointer) const;
			void DeleteContext();
			void DeleteTextures(INT nCount, UINT* pTextures) const;
			void Disable(EFeatureType eType) const;
			void DrawArrays(EPrimitiveType eType, INT nFirst, INT nCount) const;
			void Enable(EFeatureType eType) const;
			void EnableClientState(EArrayType eType) const;
			void End() const;
			void EndList() const;
			void Flush() const;
			void GenTextures(INT nCount, UINT* pTextures) const;
			CString GetString(EQueryString eQueryString) const;
			void LineWidth(FLOAT fWidth) const;
			void LoadIdentity() const;
			void LoadMatrix(const FLOAT* pMatrix) const;
			void MakeCurrent(CDC* pDC) const;
			void MatrixMode(EMatrixMode eMatrixMode) const;
			void MultMatrix(const FLOAT* pMatrix) const;
			void NewList(UINT uList, ECompilationMode eMode) const;
			void Ortho(const core::TIntRect& rcView, DOUBLE fNear, DOUBLE fFar) const;
			void PushMatrix() const;
			void PopMatrix() const;
			void PointSize(FLOAT fSize) const;
			void Rotate(FLOAT fAngle, FLOAT fX, FLOAT fY, FLOAT fZ) const;
			void Scale(FLOAT fX, FLOAT fY, FLOAT fZ) const;
			void TexCoord2(const core::TVector2f& vCoord) const;
			void TexEnv(ETextureEnv eTextureEnv) const;
			void TexCoordPointer(INT nSize, EDataType eDataType, INT nStride, LPCVOID pPointer) const;
			void TexImage2D(INT nLevels, INT nComponents, const core::TVector2i& vSize, INT nBorder, EFormatType eFormat, EDataType eData, LPCVOID pData) const;
			void TexParameter(ETextureType eType, ETextureParameter eParam, ETextureValue eValue) const;
			void TexSubImage2D(INT nLevels, const core::TVector2i& vOffset, const core::TVector2i& vSize, EFormatType eFormat, EDataType eData, LPCVOID pData) const;
			void Translate(FLOAT fX, FLOAT fY, FLOAT fZ) const;
			void Uniform1iARB(INT nLocation, INT nV0) const;
			void UnmakeCurrent() const;
			void UseProgramARB(UINT uHandleARB) const;
			void Vertex2(const core::TVector2f& vVertex) const;
			void VertexPointer(INT nSize, EDataType eDataType, INT nStride, LPCVOID pPointer) const;
			void Viewport(const core::TIntRect& rcViewport) const;

#pragma endregion

		};

	}
}