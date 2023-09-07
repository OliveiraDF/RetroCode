#pragma once

class CTestStack : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestStack);
			CPPUNIT_TEST(TestPushPop);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestStack();
		virtual ~CTestStack();

	public:
		
		void TestPushPop();

};

