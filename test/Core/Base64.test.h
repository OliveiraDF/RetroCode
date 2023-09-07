#pragma once

class CTestBase64 : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestBase64);
			CPPUNIT_TEST(TestEmptyString);
			CPPUNIT_TEST(TestSimpleString);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestBase64();
		virtual ~CTestBase64();

	public:

		void TestEmptyString();
		void TestSimpleString();

};

