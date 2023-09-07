#pragma once

class CTestInterpolation : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestInterpolation);
			CPPUNIT_TEST(TestLinearInterpolate);
			CPPUNIT_TEST(TestBilinearInterpolate);
			CPPUNIT_TEST(TestLerp);
			CPPUNIT_TEST(TestInverseLerp);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestInterpolation();
		virtual ~CTestInterpolation();

	public:

		void TestLinearInterpolate();
		void TestBilinearInterpolate();
		void TestLerp();
		void TestInverseLerp();

};

