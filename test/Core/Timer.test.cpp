#include "pch.h"
#include "Timer.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestTimer);

CTestTimer::CTestTimer()
{

}

CTestTimer::~CTestTimer()
{

}

void CTestTimer::TestDefaultConstructor()
{
	retro::core::CTimer Timer;

	CPPUNIT_ASSERT(!Timer.GetRemainingTime());
	CPPUNIT_ASSERT(!Timer.IsRunning());
}

void CTestTimer::TestGetRemainingTime()
{
	retro::core::CTimer Timer;

	Timer.Reset(2000);
	Timer.Start();
	const ULONGLONG uBefore = Timer.GetRemainingTime();
	Sleep(1000);
	const ULONGLONG uAfter = Timer.GetRemainingTime();

	CPPUNIT_ASSERT_LESS(uBefore, uAfter);
	CPPUNIT_ASSERT_GREATEREQUAL(1000ull, uBefore - uAfter);
}

void CTestTimer::TestIsRunning()
{
	retro::core::CTimer Timer;

	const BOOL bBeforeStart = Timer.IsRunning();
	Timer.Restart(2000);
	const BOOL bAfterStart = Timer.IsRunning();
	Timer.Stop();
	const BOOL bAfterStop = Timer.IsRunning();

	CPPUNIT_ASSERT(!bBeforeStart);
	CPPUNIT_ASSERT(bAfterStart);
	CPPUNIT_ASSERT(!bAfterStop);
}

void CTestTimer::TestIsExpired()
{
	retro::core::CTimer Timer;

	Timer.Reset(1000);
	Timer.Start();
	const BOOL bIsExpired = Timer.IsExpired();
	Sleep(2000);
	const BOOL bIsExpiredAfterSleeping = Timer.IsExpired();

	CPPUNIT_ASSERT(!bIsExpired);
	CPPUNIT_ASSERT(bIsExpiredAfterSleeping);
}

void CTestTimer::TestStart()
{
	retro::core::CTimer Timer;

	Timer.Stop();
	Timer.Restart(2000);
	const BOOL bIsRunning = Timer.IsRunning();
	Timer.Start();
	const BOOL bIsDoNothing = Timer.IsRunning();

	CPPUNIT_ASSERT(bIsRunning);
	CPPUNIT_ASSERT(bIsDoNothing);
}

void CTestTimer::TestStop()
{
	retro::core::CTimer Timer;

	Timer.Start();
	Timer.Stop();
	const BOOL bIsRunning = Timer.IsRunning();
	Timer.Stop();
	const BOOL bIsDoNothing = Timer.IsRunning();

	CPPUNIT_ASSERT(!bIsRunning);
	CPPUNIT_ASSERT(!bIsDoNothing);
}

void CTestTimer::TestReset()
{
	retro::core::CTimer Timer;

	Timer.Stop();
	Timer.Reset(5000);
	const ULONGLONG uFiveSec = Timer.GetRemainingTime();
	Timer.Start();
	Timer.Reset(15000);
	const BOOL bIsRunning = Timer.IsRunning();
	const ULONGLONG uFifteenSec = Timer.GetRemainingTime();

	CPPUNIT_ASSERT_GREATEREQUAL(5000ull, uFiveSec);
	CPPUNIT_ASSERT(!bIsRunning);
	CPPUNIT_ASSERT_GREATEREQUAL(15000ull, uFifteenSec);
}

void CTestTimer::TestRestart()
{
	retro::core::CTimer Timer;

	Timer.Stop();
	Timer.Restart(5000);
	const BOOL bIsRunningFive = Timer.IsRunning();
	const ULONGLONG uFiveSec = Timer.GetRemainingTime();
	Timer.Restart(15000);
	const BOOL bIsRunningFifteen = Timer.IsRunning();
	const ULONGLONG uFifteenSec = Timer.GetRemainingTime();

	CPPUNIT_ASSERT(bIsRunningFive);
	CPPUNIT_ASSERT_GREATEREQUAL(5000ull, uFiveSec);
	CPPUNIT_ASSERT(bIsRunningFifteen);
	CPPUNIT_ASSERT_GREATEREQUAL(15000ull, uFifteenSec);
}