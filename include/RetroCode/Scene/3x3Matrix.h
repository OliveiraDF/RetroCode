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

        /**
         * @brief Class representing a 3x3 matrix for 2D transformations
         *
         * This class is used to store and manipulate 2D transformations, such as
         * translation, rotation and scaling.
         * It contains a 3x3 matrix of floating-point values, stored in column-major order.
         *
         */
        class AFX_EXT_API C3x3Matrix
        {
        public:

            /**
             * @brief Default constructor
             *
             */
            C3x3Matrix();

            /**
             * @brief Constructor with matrix elements
             *
             * @param a00 The element at row 0 and column 0 of the matrix
             * @param a01 The element at row 0 and column 1 of the matrix
             * @param a02 The element at row 0 and column 2 of the matrix
             * @param a10 The element at row 1 and column 0 of the matrix
             * @param a11 The element at row 1 and column 1 of the matrix
             * @param a12 The element at row 1 and column 2 of the matrix
             * @param a20 The element at row 2 and column 0 of the matrix
             * @param a21 The element at row 2 and column 1 of the matrix
             * @param a22 The element at row 2 and column 2 of the matrix
             *
             */
            C3x3Matrix(FLOAT a00, FLOAT a01, FLOAT a02,
                FLOAT a10, FLOAT a11, FLOAT a12,
                FLOAT a20, FLOAT a21, FLOAT a22);

        public:

            /** @brief Returns a pointer to the matrix elements
             *
             * @return A pointer to the first element of the matrix
             *
             */
            const FLOAT* GetMatrix() const;

            /** @brief Returns the inverse of the matrix
             *
             * @return A new matrix that is the inverse of the current one
             *
             */
            C3x3Matrix GetInverse() const;

            /** @brief Transforms a point by the matrix
             *
             * @param fX The x-coordinate of the point to transform
             * @param fY The y-coordinate of the point to transform
             *
             * @return A new point that is the result of applying the matrix transformation to the given point
             *
             */
            core::TVector2f TransformPoint(FLOAT fX, FLOAT fY) const;

            /** @brief Transforms a point by the matrix
             *
             * @param vPoint The point to transform
             *
             * @return A new point that is the result of applying the matrix transformation to the given point
             *
             */
            core::TVector2f TransformPoint(const core::TVector2f& vPoint) const;

            /** @brief Transforms a rectangle by the matrix
             *
             * @param rcRectangle The rectangle to transform
             *
             * @return A new rectangle that is the result of applying the matrix transformation to the given rectangle
             *
             */
            core::TFloatRect TransformRect(const core::TFloatRect& rcRectangle) const;

            /** @brief Combines the current matrix with another one
             *
             * The result is equivalent to applying this followed by mTransform.
             * For example, if this is a translation and mTransform is a rotation,
             * then this will be transformed into a translation followed by a rotation.
             * This operation is not commutative: combining A with B is not equivalent to combining B with A.
             * If you want to apply several transformations in order, you should combine them from left to right:
             * mFinal = mA.combine(mB).combine(mC); (the final transformation is mC followed by mB followed by mA).
             *
             * Example:
             * @code
             * mFinal *= mTransform; // equivalent to mFinal = mFinal.combine(mTransform);
             * @endcode
             *
             * @param mTransform The transform to combine with this one
             *
             * @return A reference to this after combining it with mTransform
             *
             * @note You can also use *= operator to combine matrices.
             *
             */
            C3x3Matrix& Combine(const C3x3Matrix& mTransform);

            /** @brief Applies a translation to the current matrix
             *
             * @param fX The x offset of the translation
             * @param fY The y offset of the translation
             *
             * @return A reference to this after applying the translation
             *
             */
            C3x3Matrix& Translate(FLOAT fX, FLOAT fY);

            /** @brief Applies a translation to the current matrix
             *
             * @param vOffset The offset of the translation
             *
             * @return A reference to this after applying the translation
             *
             */
            C3x3Matrix& Translate(const core::TVector2f& vOffset);

            /** @brief Applies a rotation to the current matrix
             *
             * @param fAngle The angle of the rotation
             *
             * @return A reference to this after applying the rotation
             *
             */
            C3x3Matrix& Rotate(FLOAT fAngle);

            /** @brief Applies a rotation to the current matrix around a center point
             *
             * @param fAngle The angle of the rotation
             * @param fCenterX The x-coordinate of the center of the rotation
             * @param fCenterY The y-coordinate of the center of the rotation
             *
             * @return A reference to this after applying the rotation
             *
             */
            C3x3Matrix& Rotate(FLOAT fAngle, FLOAT fCenterX, FLOAT fCenterY);

            /** @brief Applies a rotation to the current matrix around a center point
             *
             * @param fAngle  The angle of the rotation
             * @param vCenter The center of the rotation
             *
             * @return A reference to this after applying the rotation
             *
             */
            C3x3Matrix& Rotate(FLOAT fAngle, const core::TVector2f& vCenter);

            /** @brief Applies a scaling to the current matrix
             *
             * @param fScaleX The horizontal scale factor
             * @param fScaleY The vertical scale factor
             *
             * @return A reference to this after applying the scaling
             *
             */
            C3x3Matrix& Scale(FLOAT fScaleX, FLOAT fScaleY);

            /** @brief Applies a scaling to the current matrix
             *
             * @param fScaleX  The horizontal scale factor
             * @param fScaleY  The vertical scale factor
             * @param fCenterX The x-coordinate of the center of the scaling
             * @param fCenterY The y-coordinate of the center of the scaling
             *
             * @return A reference to this after applying the scaling
             *
             */
            C3x3Matrix& Scale(FLOAT fScaleX, FLOAT fScaleY, FLOAT fCenterX, FLOAT fCenterY);

            /** @brief Applies a scaling to the current matrix
             *
             * @param vFactors The scale factors
             *
             * @return A reference to this after applying the scaling
             *
             */
            C3x3Matrix& Scale(const core::TVector2f& vFactors);

            /** @brief Applies a scaling to the current matrix
             *
             * @param vFactors The scale factors
             * @param vCenter  The center of the scaling
             *
             * @return A reference to this after applying the scaling
             *
             */
            C3x3Matrix& Scale(const core::TVector2f& vFactors, const core::TVector2f& vCenter);

        private:

            /**
             * Member data
             */
            FLOAT m_Matrix[16];

        };

        /** @brief Overloaded binary * operator to combine two transforms
         *
         * @param mLeft  The left operand (a transform)
         * @param mRight The right operand (a transform)
         *
         * @return The combination of the two transforms
         *
         */
        AFX_EXT_API C3x3Matrix operator*(const C3x3Matrix& mLeft, const C3x3Matrix& mRight);

        /** @brief Overloaded binary *= operator to combine two transforms and assign the result to the left operand
         *
         * @param mLeft  The left operand (a transform)
         * @param mRight The right operand (a transform)
         *
         * @return A reference to the left operand after combining it with the right operand
         *
         */
        AFX_EXT_API C3x3Matrix& operator*=(C3x3Matrix& mLeft, const C3x3Matrix& mRight);

        /** @brief Overloaded binary * operator to transform a point by a transform
         *
         * @param mLeft  The left operand (a transform)
         * @param mRight The right operand (a transform)
         *
         * @return The transformed point
         *
         */
        AFX_EXT_API core::TVector2f operator*(const C3x3Matrix& mLeft, const core::TVector2f& vRight);

        /** @brief Overloaded binary == operator to compare two transforms
         *
         * @param mLeft  The left operand (a transform)
         * @param mRight The right operand (a transform)
         *
         * @return True if the two transforms are equal, false otherwise
         *
         */
        AFX_EXT_API BOOL operator==(const C3x3Matrix& mLeft, const C3x3Matrix& mRight);

        /** @brief Overloaded binary != operator to compare two transforms
         *
         * @param mLeft  The left operand (a transform)
         * @param mRight The right operand (a transform)
         *
         * @return True if the two transforms are different, false otherwise
         *
         */
        AFX_EXT_API BOOL operator!=(const C3x3Matrix& mLeft, const C3x3Matrix& mRight);

	}
}

#define C3x3Matrix_Identity	retro::scene::C3x3Matrix()