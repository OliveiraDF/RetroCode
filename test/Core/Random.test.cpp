#include "pch.h"
#include "Random.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestRandom);

CTestRandom::CTestRandom()
{

}

CTestRandom::~CTestRandom()
{

}

void CTestRandom::TestNextInteger()
{
	retro::core::CRandom Random;

	const INT nRandom = Random.NextInteger();

	CPPUNIT_ASSERT_GREATEREQUAL(0, nRandom);
	CPPUNIT_ASSERT_LESSEQUAL(32767, nRandom);
}

void CTestRandom::TestNextIntegerWithMax()
{
	retro::core::CRandom Random;
	const INT nMax = 10;

	const INT nRandom = Random.NextInteger(nMax);

	CPPUNIT_ASSERT_GREATEREQUAL(0, nRandom);
	CPPUNIT_ASSERT_LESS(nMax, nRandom);
}

void CTestRandom::TestNextIntegerWithMinAndMax()
{
	retro::core::CRandom Random;
	const INT nMin = 5;
	const INT nMax = 15;

	const INT nRandom = Random.NextInteger(nMin, nMax);

	CPPUNIT_ASSERT_GREATEREQUAL(nMin, nRandom);
	CPPUNIT_ASSERT_LESS(nMax, nRandom);
}

void CTestRandom::TestNextFloat()
{
	retro::core::CRandom Random;

	const FLOAT fRandom = Random.NextFloat();

	CPPUNIT_ASSERT_GREATEREQUAL(0.f, fRandom);
	CPPUNIT_ASSERT_LESSEQUAL(1.f, fRandom);
}

void CTestRandom::TestNextDouble()
{
	retro::core::CRandom Random;

	const DOUBLE fRandom = Random.NextDouble();

	CPPUNIT_ASSERT_GREATEREQUAL(0., fRandom);
	CPPUNIT_ASSERT_LESSEQUAL(1., fRandom);
}

void CTestRandom::TestNextBytes()
{
	retro::core::CRandom Random;
	const UCHAR uLowerBound = 0;
	const UCHAR hHigherBound = 255;
	const UINT uByteCount = 10;
	UCHAR* pBytes = new UCHAR[uByteCount];
	if (!pBytes)
	{
		return;
	}

	Random.NextBytes(pBytes, uByteCount);

	for (UINT i = 0; i < uByteCount; i++)
	{
		CPPUNIT_ASSERT_GREATEREQUAL(uLowerBound, pBytes[i]);
		CPPUNIT_ASSERT_LESSEQUAL(hHigherBound, pBytes[i]);
	}

	delete[] pBytes;
}

void CTestRandom::TestNextBoolean()
{
	retro::core::CRandom Random;

	const BOOL bRandom = Random.NextBoolean();

	CPPUNIT_ASSERT(bRandom == TRUE || bRandom == FALSE);
}