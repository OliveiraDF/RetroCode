#pragma once

class CTestTimer : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestTimer);
			CPPUNIT_TEST(TestDefaultConstructor);
			CPPUNIT_TEST(TestGetRemainingTime);
			CPPUNIT_TEST(TestIsRunning);
			CPPUNIT_TEST(TestIsExpired);
			CPPUNIT_TEST(TestStart);
			CPPUNIT_TEST(TestStop);
			CPPUNIT_TEST(TestReset);
			CPPUNIT_TEST(TestRestart);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestTimer();
		virtual ~CTestTimer();

	public:

		void TestDefaultConstructor();
		void TestGetRemainingTime();
		void TestIsRunning();
		void TestIsExpired();
		void TestStart();
		void TestStop();
		void TestReset();
		void TestRestart();

};

