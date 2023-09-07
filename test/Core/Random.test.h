#pragma once

class CTestRandom : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestRandom);
			CPPUNIT_TEST(TestNextInteger);
			CPPUNIT_TEST(TestNextIntegerWithMax);
			CPPUNIT_TEST(TestNextIntegerWithMinAndMax);
			CPPUNIT_TEST(TestNextFloat);
			CPPUNIT_TEST(TestNextDouble);
			CPPUNIT_TEST(TestNextBytes);
			CPPUNIT_TEST(TestNextBoolean);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestRandom();
		virtual ~CTestRandom();

	public:

		void TestNextInteger();
		void TestNextIntegerWithMax();
		void TestNextIntegerWithMinAndMax();
		void TestNextFloat();
		void TestNextDouble();
		void TestNextBytes();
		void TestNextBoolean();

};

