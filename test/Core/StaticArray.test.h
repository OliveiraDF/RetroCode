#pragma once

class CTestStaticArray : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestStaticArray);
			CPPUNIT_TEST(TestAt);
			CPPUNIT_TEST(TestData);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestStaticArray();
		virtual ~CTestStaticArray();

	public:

		void TestAt();
		void TestData();

};

