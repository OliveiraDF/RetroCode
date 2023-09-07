#pragma once

class CTestObjectEx : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestObjectEx);
			CPPUNIT_TEST(TestReference);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestObjectEx();
		virtual ~CTestObjectEx();

	public:

		void TestReference();

};

