#include "pch.h"
#include "Interpolation.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestInterpolation);

CTestInterpolation::CTestInterpolation()
{

}

CTestInterpolation::~CTestInterpolation()
{

}

void CTestInterpolation::TestLinearInterpolate()
{
	struct
	{
		DOUBLE x1;
		DOUBLE y1;
		DOUBLE x2;
		DOUBLE y2;
		DOUBLE x;
		DOUBLE expected;
		DOUBLE actual;

	} TestCases[] =
	{
		{ 0., 0., 1., 1., 0., 0., 0. },
		{ 0., 0., 1., 1., 1., 1., 0. },
		{ 0., 0., 1., 1., 0.5, 0.5, 0. },
		{ 0., 0., 1., 1., -1., -1., 0. },
		{ 0., 0., 1., 1., 2., 2., 0. },
		{ -2., -3., 4., 5., -1., -2., 0. },
		{ -2., -3., 4., 5., 3., 4., 0. },
	};
	constexpr const UINT uTestCaseCount = ARRAYSIZE(TestCases);

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		TestCases[i].actual = retro::core::LinearInterpolate(TestCases[i].x1, TestCases[i].y1, TestCases[i].x2, TestCases[i].y2, TestCases[i].x);
	}

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		CPPUNIT_ASSERT_DOUBLES_EQUAL(TestCases[i].expected, TestCases[i].actual, 0.5);
	}
}

void CTestInterpolation::TestBilinearInterpolate()
{
	struct
	{
		DOUBLE x1;
		DOUBLE y1;
		DOUBLE x2;
		DOUBLE y2;
		DOUBLE q11;
		DOUBLE q12;
		DOUBLE q21;
		DOUBLE q22;
		DOUBLE x;
		DOUBLE y;
		DOUBLE expected;
		DOUBLE actual;

	} TestCases[] =
	{
		{ 0., 0., 1., 1., 0., 0.5, 0.5, 1., 0.5, 0.5, 0.5, 0. },
		{ 0., 0., 1., 1., -1., -2., -3., -4., -2., -2., 5., 0. },
		{ 0., 0., 1., 1., 10., 20., 30., 40., 2., 2., 70., 0. },
		{ -2., -2., 4., 4., -3., -2., -1., 0., 1., 3., -0.75, 0. }
	};
	constexpr const UINT uTestCaseCount = ARRAYSIZE(TestCases);

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		TestCases[i].actual = retro::core::BilinearInterpolate(TestCases[i].x1, TestCases[i].y1, TestCases[i].x2,
			TestCases[i].y2, TestCases[i].q11, TestCases[i].q12, TestCases[i].q21, TestCases[i].q22,
			TestCases[i].x, TestCases[i].y);
	}

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		CPPUNIT_ASSERT_DOUBLES_EQUAL(TestCases[i].expected, TestCases[i].actual, 0.5);
	}
}

void CTestInterpolation::TestLerp()
{
	struct
	{
		DOUBLE a;
		DOUBLE b;
		DOUBLE t;
		DOUBLE expected;
		DOUBLE actual;

	} TestCases[] =
	{
		{ 0., 10., 0.5, 5., 0. },
		{ -10., 10., 0.25, -5., 0. },
		{ -10., -10., 100., -10., 0. },
		{ -10., -10., -100., -10., 0. },
		{ -3.14, 6.28, 0.75, 3.85, 0. },
	};
	constexpr const UINT uTestCaseCount = ARRAYSIZE(TestCases);

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		TestCases[i].actual = retro::core::Lerp(TestCases[i].a, TestCases[i].b, TestCases[i].t);
	}

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		CPPUNIT_ASSERT_DOUBLES_EQUAL(TestCases[i].expected, TestCases[i].actual, 0.1);
	}
}

void CTestInterpolation::TestInverseLerp()
{
	struct
	{
		DOUBLE a;
		DOUBLE b;
		DOUBLE t;
		DOUBLE expected;
		DOUBLE actual;

	} TestCases[] =
	{
		{ 0., 10., 5., 0.5, 0. },
		{ -10., 10., -5., 0.25, 0. },
		{ -10., -10., -100., 0., 0. },
		{ -10., -10., 100., 0., 0. },
		{ -3.14, 6.28, 3.85, 0.75, 0. },
	};
	constexpr const UINT uTestCaseCount = ARRAYSIZE(TestCases);

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		TestCases[i].actual = retro::core::InverseLerp(TestCases[i].a, TestCases[i].b, TestCases[i].t);
	}

	for (UINT i = 0; i < uTestCaseCount; i++)
	{
		CPPUNIT_ASSERT_DOUBLES_EQUAL(TestCases[i].expected, TestCases[i].actual, 0.1);
	}
}