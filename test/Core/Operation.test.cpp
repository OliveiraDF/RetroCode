#include "pch.h"
#include "Operation.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestOperation);

CTestOperation::CTestOperation()
{

}

CTestOperation::~CTestOperation()
{

}

void CTestOperation::TestSwap()
{
	INT nA = 1;
	INT nB = 2;
	DOUBLE fC = 3.14;
	DOUBLE fD = 2.71;
	CString strE(_T("Hello"));
	CString strF(_T("World"));

	retro::core::Swap(nA, nB);
	retro::core::Swap(fC, fD);
	retro::core::Swap(strE, strF);

	CPPUNIT_ASSERT_EQUAL(2, nA);
	CPPUNIT_ASSERT_EQUAL(1, nB);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(2.71, fC, 0.01);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(3.141, fD, 0.01);
	CPPUNIT_ASSERT(CString(_T("World")) == strE);
	CPPUNIT_ASSERT(CString(_T("Hello")) == strF);
}

void CTestOperation::TestMin()
{
	const INT nA = 1;
	const INT nB = 2;
	const INT nC = -1;
	const INT nD = -2;
	const INT nE = 0;
	const DOUBLE fF = 3.14;
	const DOUBLE fG = -2.71;

	const INT nFirstRes = retro::core::Min(nA, nB);
	const INT nSecondRes = retro::core::Min(nC, nD);
	const INT nThirdRes = retro::core::Min(nE, nE);
	const DOUBLE fFourthRes = retro::core::Min(fF, fG);

	CPPUNIT_ASSERT_EQUAL(1, nFirstRes);
	CPPUNIT_ASSERT_EQUAL(-2, nSecondRes);
	CPPUNIT_ASSERT_EQUAL(0, nThirdRes);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.71, fFourthRes, 0.01);
}

void CTestOperation::TestMax()
{
	const INT nA = 1;
	const INT nB = 2;
	const INT nC = -1;
	const INT nD = -2;
	const INT nE = 0;
	const DOUBLE fF = 3.14;
	const DOUBLE fG = -2.71;

	const INT nFirstRes = retro::core::Max(nA, nB);
	const INT nSecondRes = retro::core::Max(nC, nD);
	const INT nThirdRes = retro::core::Max(nE, nE);
	const DOUBLE fFourthRes = retro::core::Max(fF, fG);

	CPPUNIT_ASSERT_EQUAL(2, nFirstRes);
	CPPUNIT_ASSERT_EQUAL(-1, nSecondRes);
	CPPUNIT_ASSERT_EQUAL(0, nThirdRes);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(3.14, fFourthRes, 0.01);
}

void CTestOperation::TestClamp()
{
	const INT nVal1 = 5;
	const INT nMin1 = 0;
	const INT nMax1 = 10;
	const INT nVal2 = -5;
	const INT nMin2 = 0;
	const INT nMax2 = 10;
	const INT nVal3 = 15;
	const INT nMin3 = 0;
	const INT nMax3 = 10;
	const INT nVal4 = 0;
	const INT nMin4 = 0;
	const INT nMax4 = 0;
	const DOUBLE fVal5 = 3.14;
	const DOUBLE fMin5 = -6.28;
	const DOUBLE fMax5 = 6.28;

 	const INT nClamp1 = retro::core::Clamp(nVal1, nMin1, nMax1);
	const INT nClamp2 = retro::core::Clamp(nVal2, nMin2, nMax2);
	const INT nClamp3 = retro::core::Clamp(nVal3, nMin3, nMax3);
	const INT nClamp4 = retro::core::Clamp(nVal4, nMin4, nMax4);
	const DOUBLE fClamp5 = retro::core::Clamp(fVal5, fMin5, fMax5);

	CPPUNIT_ASSERT_EQUAL(5, nClamp1);
	CPPUNIT_ASSERT_EQUAL(0, nClamp2);
	CPPUNIT_ASSERT_EQUAL(10, nClamp3);
	CPPUNIT_ASSERT_EQUAL(0, nClamp4);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(3.14, fClamp5, 0.01);
}

void CTestOperation::TestEuclidianDistance()
{
	struct
	{
		DOUBLE x1;
		DOUBLE y1;
		DOUBLE x2;
		DOUBLE y2;
		DOUBLE expected;
		DOUBLE actual;

	} TestCases[] =
	{
		{ 0.f, 0.f, 0.f, 0.f, 0.f, 0.f },
		{ 0.f, 0.f, 1.f, 0.f, 1.f, 0.f },
		{ 0.f, 0.f, 0.f, 1.f, 1.f, 0.f },
		{ 0.f, 0.f, 3.f, 4.f, 5.f, 0.f },
	};
	constexpr const UINT uTestCaseCount = ARRAYSIZE(TestCases);

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		TestCases[i].actual = retro::core::EuclidianDistance(TestCases[i].x1, TestCases[i].y1, TestCases[i].x2, TestCases[i].y2);
	}

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		CPPUNIT_ASSERT_DOUBLES_EQUAL(TestCases[i].expected, TestCases[i].actual, 0.001);
	}
}

void CTestOperation::TestManhattanDistance()
{
	struct
	{
		DOUBLE x1;
		DOUBLE y1;
		DOUBLE x2;
		DOUBLE y2;
		DOUBLE expected;
		DOUBLE actual;

	} TestCases[] =
	{
		{ 0.f, 0.f, 0.f, 0.f, 0.f, 0.f },
		{ 0.f, 0.f, 1.f, 0.f, 1.f, 0.f },
		{ 0.f, 0.f, 0.f, 1.f, 1.f, 0.f },
		{ 0.f, 0.f, 3.f, 4.f, 7.f, 0.f },
	};
	constexpr const UINT uTestCaseCount = ARRAYSIZE(TestCases);

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		TestCases[i].actual = retro::core::ManhattanDistance(TestCases[i].x1, TestCases[i].y1, TestCases[i].x2, TestCases[i].y2);
	}

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		CPPUNIT_ASSERT_DOUBLES_EQUAL(TestCases[i].expected, TestCases[i].actual, 0.001);
	}
}
