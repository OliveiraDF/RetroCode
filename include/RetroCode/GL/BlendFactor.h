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

		/**
		 * @ingroup gl
		 * @brief Specifies how the red, green, blue, and alpha source-blending factors are computed
		 *
		 */
		enum EBlendFactorSrc : UINT
		{
			EBlendFactorSrc_Zero,					/**< (0,0,0,0) */
			EBlendFactorSrc_One,					/**< (1,1,1,1) */
			EBlendFactorSrc_Dst_Color,				/**< (Rd / kR , Gd / kG , Bd / kB , Ad / kA ) */
			EBlendFactorSrc_One_Minus_Dst_Color,	/**< (1,1,1,1) - (Rd / kR , Gd / kG , Bd / kB , Ad / kA ) */
			EBlendFactorSrc_Src_Alpha_Saturate,		/**< (i,i,i,1) */
			EBlendFactorSrc_Src_Alpha,				/**< (A? / kA , A? / kA , A? / kA , A? / kA ) */
			EBlendFactorSrc_One_Minus_Src_Alpha,	/**< (1,1,1,1) - (A? / kA , A? / kA , A? / kA , A? / kA ) */
			EBlendFactorSrc_Dst_Alpha,				/**< (Ad / kA , Ad / kA , Ad / kA , Ad / kA ) */
			EBlendFactorSrc_One_Minus_Dst_Alpha,	/**< (1,1,1,1) - (Ad / kA , Ad / kA , Ad / kA , Ad / kA ) */

			EBlendFactorSrc_COUNT					/**< Blend factor source count */
		};

		/**
		 * @ingroup gl
		 * @brief Specifies how the red, green, blue, and alpha destination-blending factors are computed
		 *
		 */
		enum EBlendFactorDst : UINT
		{
			EBlendFactorDst_Zero,					/**< (0,0,0,0) */
			EBlendFactorDst_One,					/**< (1,1,1,1) */
			EBlendFactorDst_Src_Color,				/**< (R? / kR , G? / kG , B? / kB , A? / kA ) */
			EBlendFactorDst_One_Minus_Src_Color,	/**< (1,1,1,1) - (R? / kR , G? / kG , B? / kB , A? / kA ) */
			EBlendFactorDst_Src_Alpha,				/**< (A? / kA , A? / kA , A? / kA , A? / kA ) */
			EBlendFactorDst_One_Minus_Src_Alpha,	/**< (1,1,1,1) - (A? / kA , A? / kA , A? / kA , A? / kA ) */
			EBlendFactorDst_Dst_Alpha,				/**< (Ad / kA , Ad / kA , Ad / kA , Ad / kA ) */
			EBlendFactorDst_One_Minus_Dst_Alpha,	/**< (1,1,1,1) - (Ad / kA , Ad / kA , Ad / kA , Ad / kA ) */

			EBlendFactorDst_COUNT					/**< Blend factor destination count */
		};

	}
}