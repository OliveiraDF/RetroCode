#pragma once

class CTestClock : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestClock);
			CPPUNIT_TEST(TestDefaultConstructor);
			CPPUNIT_TEST(TestGetElapsedTime);
			CPPUNIT_TEST(TestRestart);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestClock();
		virtual ~CTestClock();

	public:

		void TestDefaultConstructor();
		void TestGetElapsedTime();
		void TestRestart();

};

