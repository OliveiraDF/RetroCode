#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RetroCoreTest
{
	TEST_CLASS(MatchingTest)
	{
	public:
		
		TEST_METHOD(TestQuestionMark)
		{
			HRESULT hr = retro::core::Matching(_T("l?racr?ft"), _T("laracroft"));

			Assert::IsTrue(SUCCEEDED(hr));
		}

		TEST_METHOD(TestAsterisk)
		{
			HRESULT hr = retro::core::Matching(_T("amber*"), _T("amber torrelson"));

			Assert::IsTrue(SUCCEEDED(hr));
		}

		TEST_METHOD(TestNegativeQuestionMark)
		{
			HRESULT hr = retro::core::Matching(_T("minoko???molenski"), _T("minoko_molenski"));

			Assert::AreEqual(RC_NOT_MATCHING, hr);
		}

		TEST_METHOD(TestNegativeAsterisk)
		{
			HRESULT hr = retro::core::Matching(_T("c*tir"), _T("carter"));

			Assert::AreEqual(RC_NOT_MATCHING, hr);
		}

		TEST_METHOD(TestMiddleAsterisk)
		{
			HRESULT hr = retro::core::Matching(_T("a*re"), _T("andre"));

			Assert::IsTrue(SUCCEEDED(hr));
		}

	};
}
