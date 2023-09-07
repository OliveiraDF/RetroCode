#pragma once

class CTestQueue : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestQueue);
			CPPUNIT_TEST(TestPushPop);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestQueue();
		virtual ~CTestQueue();

	public:

		void TestPushPop();

};

