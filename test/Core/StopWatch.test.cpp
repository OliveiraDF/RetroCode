#include "pch.h"
#include "StopWatch.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestStopWatch);

CTestStopWatch::CTestStopWatch()
{

}

CTestStopWatch::~CTestStopWatch()
{

}

void CTestStopWatch::TestDefaultConstructor()
{
	retro::core::CStopWatch StopWatch;

	CPPUNIT_ASSERT(!StopWatch.GetElapsedTime());
	CPPUNIT_ASSERT(!StopWatch.IsRunning());
}

void CTestStopWatch::TestGetElapsedTime()
{
	retro::core::CStopWatch StopWatch;

	StopWatch.Start();
	const ULONGLONG uBefore = StopWatch.GetElapsedTime();
	Sleep(1000);
	const ULONGLONG uAfter = StopWatch.GetElapsedTime();

	CPPUNIT_ASSERT_LESS(uAfter, uBefore);
	CPPUNIT_ASSERT_GREATEREQUAL(1000ull, uAfter - uBefore);
}

void CTestStopWatch::TestIsRunning()
{
	retro::core::CStopWatch StopWatch;

	const BOOL bBeforeStart = StopWatch.IsRunning();
	StopWatch.Start();
	const BOOL bAfterStart = StopWatch.IsRunning();
	StopWatch.Stop();
	const BOOL bAfterStop = StopWatch.IsRunning();

	CPPUNIT_ASSERT(!bBeforeStart);
	CPPUNIT_ASSERT(bAfterStart);
	CPPUNIT_ASSERT(!bAfterStop);
}

void CTestStopWatch::TestStart()
{
	retro::core::CStopWatch StopWatch;

	const ULONGLONG uBefore = StopWatch.GetElapsedTime();
	StopWatch.Start();
	Sleep(1000);
	const ULONGLONG uAfter = StopWatch.GetElapsedTime();

	CPPUNIT_ASSERT_LESS(uAfter, uBefore);
	CPPUNIT_ASSERT_GREATEREQUAL(1000ull, uAfter - uBefore);
}

void CTestStopWatch::TestStop()
{
	retro::core::CStopWatch StopWatch;

	StopWatch.Start();
	Sleep(1000);
	StopWatch.Stop();
	const ULONGLONG uAfter = StopWatch.GetElapsedTime();
	Sleep(1000);
	const ULONGLONG uLater = StopWatch.GetElapsedTime();

	CPPUNIT_ASSERT_GREATEREQUAL(1000ull, uAfter);
	CPPUNIT_ASSERT_GREATEREQUAL(uAfter, uLater);
}

void CTestStopWatch::TestReset()
{
	retro::core::CStopWatch StopWatch;

	StopWatch.Start();
	Sleep(1000);
	StopWatch.Reset();

	CPPUNIT_ASSERT(!StopWatch.GetElapsedTime());
	CPPUNIT_ASSERT(!StopWatch.IsRunning());
}

void CTestStopWatch::TestRestart()
{
	retro::core::CStopWatch StopWatch;

	StopWatch.Start();
	Sleep(1000);
	StopWatch.Restart();
	const ULONGLONG uAfterRestart = StopWatch.GetElapsedTime();
	const BOOL bIsRunningAfterRestart = StopWatch.IsRunning();
	Sleep(1000);
	const ULONGLONG uAfterSleeping = StopWatch.GetElapsedTime();

	CPPUNIT_ASSERT(!uAfterRestart);
	CPPUNIT_ASSERT(bIsRunningAfterRestart);
	CPPUNIT_ASSERT_GREATEREQUAL(1000ull, uAfterSleeping);
}