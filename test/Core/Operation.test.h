#pragma once

class CTestOperation : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestOperation);
			CPPUNIT_TEST(TestSwap);
			CPPUNIT_TEST(TestMin);
			CPPUNIT_TEST(TestMax);
			CPPUNIT_TEST(TestClamp);
			CPPUNIT_TEST(TestEuclidianDistance);
			CPPUNIT_TEST(TestManhattanDistance);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestOperation();
		virtual ~CTestOperation();

	public:

		void TestSwap();
		void TestMin();
		void TestMax();
		void TestClamp();
		void TestEuclidianDistance();
		void TestManhattanDistance();

};

