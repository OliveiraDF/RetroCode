#include "pch.h"
#include "Clock.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestClock);

CTestClock::CTestClock()
{

}

CTestClock::~CTestClock()
{

}

void CTestClock::TestDefaultConstructor()
{
	retro::core::CClock Clock;

	CPPUNIT_ASSERT(Clock.GetElapsedTime() != 0);
}

void CTestClock::TestGetElapsedTime()
{
	retro::core::CClock Clock;

	const ULONGLONG uBefore = Clock.GetElapsedTime();
	Sleep(1000);
	const ULONGLONG uAfter = Clock.GetElapsedTime();

	CPPUNIT_ASSERT_LESS(uAfter, uBefore);
	CPPUNIT_ASSERT_GREATEREQUAL(1000ull, uAfter - uBefore);
}

void CTestClock::TestRestart()
{
	retro::core::CClock Clock;

	const ULONGLONG uBefore = Clock.GetElapsedTime();
	const ULONGLONG uRestart = Clock.Restart();
	const ULONGLONG uAfter = Clock.GetElapsedTime();

	CPPUNIT_ASSERT_EQUAL(uBefore, uRestart);
	CPPUNIT_ASSERT_EQUAL(0ull, uAfter);
}