#pragma once

class CTestStopWatch : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestStopWatch);
			CPPUNIT_TEST(TestDefaultConstructor);
			CPPUNIT_TEST(TestGetElapsedTime);
			CPPUNIT_TEST(TestIsRunning);
			CPPUNIT_TEST(TestStart);
			CPPUNIT_TEST(TestStop);
			CPPUNIT_TEST(TestReset);
			CPPUNIT_TEST(TestRestart);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestStopWatch();
		virtual ~CTestStopWatch();

	public:		

		void TestDefaultConstructor();
		void TestGetElapsedTime();
		void TestIsRunning();
		void TestStart();
		void TestStop();
		void TestReset();
		void TestRestart();

};

