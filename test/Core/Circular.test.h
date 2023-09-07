#pragma once

class CTestCircular : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestCircular);
			CPPUNIT_TEST(TestConstructor);
			CPPUNIT_TEST(TestCapacity);
			CPPUNIT_TEST(TestPush);
			CPPUNIT_TEST(TestClear);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestCircular();
		virtual ~CTestCircular();

	public:

		void TestConstructor();
		void TestCapacity();
		void TestPush();
		void TestClear();


};

