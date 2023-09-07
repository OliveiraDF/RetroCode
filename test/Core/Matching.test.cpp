#include "pch.h"
#include "Matching.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestMatching);

CTestMatching::CTestMatching()
{

}

CTestMatching::~CTestMatching()
{

}

void CTestMatching::MatchingFirst()
{
	HRESULT hr = retro::core::Matching(_T("l?racr?ft"), _T("laracroft"));

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
}

void CTestMatching::MatchingSecond()
{
	HRESULT hr = retro::core::Matching(_T("amber*"), _T("amber torrelson"));

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
}

void CTestMatching::MatchingThird()
{
	HRESULT hr = retro::core::Matching(_T("minoko???molenski"), _T("minoko_molenski"));

	CPPUNIT_ASSERT_EQUAL(RC_NOT_MATCHING, hr);
}

void CTestMatching::MatchingFourth()
{
	HRESULT hr = retro::core::Matching(_T("c*tir"), _T("carter"));

	CPPUNIT_ASSERT_EQUAL(RC_NOT_MATCHING, hr);
}

void CTestMatching::MatchingFifth()
{
	HRESULT hr = retro::core::Matching(_T("a*re"), _T("andre"));

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
}