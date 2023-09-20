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
	namespace gl
	{

        C3x3Matrix::C3x3Matrix()
        {
            m_Matrix[0] = 1.f; m_Matrix[4] = 0.f; m_Matrix[8] = 0.f; m_Matrix[12] = 0.f;
            m_Matrix[1] = 0.f; m_Matrix[5] = 1.f; m_Matrix[9] = 0.f; m_Matrix[13] = 0.f;
            m_Matrix[2] = 0.f; m_Matrix[6] = 0.f; m_Matrix[10] = 1.f; m_Matrix[14] = 0.f;
            m_Matrix[3] = 0.f; m_Matrix[7] = 0.f; m_Matrix[11] = 0.f; m_Matrix[15] = 1.f;
        }

        C3x3Matrix::C3x3Matrix(FLOAT a00, FLOAT a01, FLOAT a02,
            FLOAT a10, FLOAT a11, FLOAT a12,
            FLOAT a20, FLOAT a21, FLOAT a22)
        {
            m_Matrix[0] = a00; m_Matrix[4] = a01; m_Matrix[8] = 0.f; m_Matrix[12] = a02;
            m_Matrix[1] = a10; m_Matrix[5] = a11; m_Matrix[9] = 0.f; m_Matrix[13] = a12;
            m_Matrix[2] = 0.f; m_Matrix[6] = 0.f; m_Matrix[10] = 1.f; m_Matrix[14] = 0.f;
            m_Matrix[3] = a20; m_Matrix[7] = a21; m_Matrix[11] = 0.f; m_Matrix[15] = a22;
        }

        const FLOAT* C3x3Matrix::GetMatrix() const
        {
            return m_Matrix;
        }

        C3x3Matrix C3x3Matrix::GetInverse() const
        {
            const FLOAT fDeterminant = m_Matrix[0] * (m_Matrix[15] * m_Matrix[5] - m_Matrix[7] * m_Matrix[13]) -
                m_Matrix[1] * (m_Matrix[15] * m_Matrix[4] - m_Matrix[7] * m_Matrix[12]) +
                m_Matrix[3] * (m_Matrix[13] * m_Matrix[4] - m_Matrix[5] * m_Matrix[12]);

            if (fDeterminant != 0.f)
            {
                return C3x3Matrix((m_Matrix[15] * m_Matrix[5] - m_Matrix[7] * m_Matrix[13]) / fDeterminant,
                    -(m_Matrix[15] * m_Matrix[4] - m_Matrix[7] * m_Matrix[12]) / fDeterminant,
                    (m_Matrix[13] * m_Matrix[4] - m_Matrix[5] * m_Matrix[12]) / fDeterminant,
                    -(m_Matrix[15] * m_Matrix[1] - m_Matrix[3] * m_Matrix[13]) / fDeterminant,
                    (m_Matrix[15] * m_Matrix[0] - m_Matrix[3] * m_Matrix[12]) / fDeterminant,
                    -(m_Matrix[13] * m_Matrix[0] - m_Matrix[1] * m_Matrix[12]) / fDeterminant,
                    (m_Matrix[7] * m_Matrix[1] - m_Matrix[3] * m_Matrix[5]) / fDeterminant,
                    -(m_Matrix[7] * m_Matrix[0] - m_Matrix[3] * m_Matrix[4]) / fDeterminant,
                    (m_Matrix[5] * m_Matrix[0] - m_Matrix[1] * m_Matrix[4]) / fDeterminant);
            }

            return C3x3Matrix_Identity;
        }

        core::TVector2f C3x3Matrix::TransformPoint(FLOAT fX, FLOAT fY) const
        {
            return core::TVector2f(m_Matrix[0] * fX + m_Matrix[4] * fY + m_Matrix[12], m_Matrix[1] * fX + m_Matrix[5] * fY + m_Matrix[13]);
        }

        core::TVector2f C3x3Matrix::TransformPoint(const core::TVector2f& vPoint) const
        {
            return TransformPoint(vPoint.X, vPoint.Y);
        }

        core::TFloatRect C3x3Matrix::TransformRect(const core::TFloatRect& rcRectangle) const
        {
            const core::TVector2f Points[] =
            {
                TransformPoint(rcRectangle.Left(), rcRectangle.Top()),
                TransformPoint(rcRectangle.Left(), rcRectangle.Bottom()),
                TransformPoint(rcRectangle.Right(), rcRectangle.Top()),
                TransformPoint(rcRectangle.Right(), rcRectangle.Bottom())
            };
            constexpr const UINT uPointCount = ARRAYSIZE(Points);

            FLOAT fLeft = Points[0].X;
            FLOAT fTop = Points[0].Y;
            FLOAT fRight = Points[0].X;
            FLOAT fbottom = Points[0].Y;

            for (UINT i = 1; i < uPointCount; i++)
            {
                if (Points[i].X < fLeft)
                {
                    fLeft = Points[i].X;
                }
                else if (Points[i].X > fRight)
                {
                    fRight = Points[i].X;
                }

                if (Points[i].Y < fTop)
                {
                    fTop = Points[i].Y;
                }
                else if (Points[i].Y > fbottom)
                {
                    fbottom = Points[i].Y;
                }
            }

            return core::TFloatRect(fLeft, fTop, fRight - fLeft, fbottom - fTop);
        }

        C3x3Matrix& C3x3Matrix::Combine(const C3x3Matrix& mTransform)
        {
            const FLOAT* a = m_Matrix;
            const FLOAT* b = mTransform.m_Matrix;

            *this = C3x3Matrix(a[0] * b[0] + a[4] * b[1] + a[12] * b[3],
                a[0] * b[4] + a[4] * b[5] + a[12] * b[7],
                a[0] * b[12] + a[4] * b[13] + a[12] * b[15],
                a[1] * b[0] + a[5] * b[1] + a[13] * b[3],
                a[1] * b[4] + a[5] * b[5] + a[13] * b[7],
                a[1] * b[12] + a[5] * b[13] + a[13] * b[15],
                a[3] * b[0] + a[7] * b[1] + a[15] * b[3],
                a[3] * b[4] + a[7] * b[5] + a[15] * b[7],
                a[3] * b[12] + a[7] * b[13] + a[15] * b[15]);

            return *this;
        }

        C3x3Matrix& C3x3Matrix::Translate(FLOAT fX, FLOAT fY)
        {
            C3x3Matrix mTranslation(1.f, 0.f, fX,
                0.f, 1.f, fY,
                0.f, 0.f, 1.f);

            return Combine(mTranslation);
        }

        C3x3Matrix& C3x3Matrix::Translate(const core::TVector2f& vOffset)
        {
            return Translate(vOffset.X, vOffset.Y);
        }

        C3x3Matrix& C3x3Matrix::Rotate(FLOAT fAngle)
        {
            const FLOAT fPI = static_cast<FLOAT>(M_PI);
            const FLOAT fRadian = fAngle * fPI / 180.f;
            const FLOAT fCosine = cosf(fRadian);
            const FLOAT fSine = sinf(fRadian);

            C3x3Matrix mRotation(fCosine, -fSine, 0.f,
                fSine, fCosine, 0.f,
                0.f, 0.f, 1.f);

            return Combine(mRotation);
        }

        C3x3Matrix& C3x3Matrix::Rotate(FLOAT fAngle, FLOAT fCenterX, FLOAT fCenterY)
        {
            const FLOAT fPI = static_cast<FLOAT>(M_PI);
            const FLOAT fRadian = fAngle * fPI / 180.f;
            const FLOAT fCosine = cosf(fRadian);
            const FLOAT fSine = sinf(fRadian);

            C3x3Matrix mRotation(fCosine, -fSine, fCenterX * (1.f - fCosine) + fCenterY * fSine,
                fSine, fCosine, fCenterY * (1.f - fCosine) - fCenterX * fSine,
                0.f, 0.f, 1.f);

            return Combine(mRotation);
        }

        C3x3Matrix& C3x3Matrix::Rotate(FLOAT fAngle, const core::TVector2f& vCenter)
        {
            return Rotate(fAngle, vCenter.X, vCenter.Y);
        }

        C3x3Matrix& C3x3Matrix::Scale(FLOAT fScaleX, FLOAT fScaleY)
        {
            C3x3Matrix mScaling(fScaleX, 0.f, 0.f,
                0.f, fScaleY, 0.f,
                0.f, 0.f, 1.f);

            return Combine(mScaling);
        }

        C3x3Matrix& C3x3Matrix::Scale(FLOAT fScaleX, FLOAT fScaleY, FLOAT fCenterX, FLOAT fCenterY)
        {
            C3x3Matrix mScaling(fScaleX, 0.f, fCenterX * (1.f - fScaleX),
                0.f, fScaleY, fCenterY * (1.f - fScaleY),
                0.f, 0.f, 1.f);

            return Combine(mScaling);
        }

        C3x3Matrix& C3x3Matrix::Scale(const core::TVector2f& vFactors)
        {
            return Scale(vFactors.X, vFactors.Y);
        }

        C3x3Matrix& C3x3Matrix::Scale(const core::TVector2f& vFactors, const core::TVector2f& vCenter)
        {
            return Scale(vFactors.X, vFactors.Y, vCenter.X, vCenter.Y);
        }

        C3x3Matrix operator*(const C3x3Matrix& mLeft, const C3x3Matrix& mRight)
        {
            return C3x3Matrix(mLeft).Combine(mRight);
        }

        C3x3Matrix& operator*=(C3x3Matrix& mLeft, const C3x3Matrix& mRight)
        {
            return mLeft.Combine(mRight);
        }

        core::TVector2f operator*(const C3x3Matrix& mLeft, const core::TVector2f& vRight)
        {
            return mLeft.TransformPoint(vRight);
        }

        BOOL operator==(const C3x3Matrix& mLeft, const C3x3Matrix& mRight)
        {
            const FLOAT* a = mLeft.GetMatrix();
            const FLOAT* b = mRight.GetMatrix();

            return ((a[0] == b[0]) && (a[1] == b[1]) && (a[3] == b[3]) &&
                (a[4] == b[4]) && (a[5] == b[5]) && (a[7] == b[7]) &&
                (a[12] == b[12]) && (a[13] == b[13]) && (a[15] == b[15]));
        }

        BOOL operator!=(const C3x3Matrix& mLeft, const C3x3Matrix& mRight)
        {
            return !(mLeft == mRight);
        }

	}
}