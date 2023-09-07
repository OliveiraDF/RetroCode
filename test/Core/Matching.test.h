#pragma once

class CTestMatching : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestMatching);
			CPPUNIT_TEST(MatchingFirst);
			CPPUNIT_TEST(MatchingSecond);
			CPPUNIT_TEST(MatchingThird);
			CPPUNIT_TEST(MatchingFourth);
			CPPUNIT_TEST(MatchingFifth);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestMatching();
		virtual ~CTestMatching();

	public:

		void MatchingFirst();
		void MatchingSecond();
		void MatchingThird();
		void MatchingFourth();
		void MatchingFifth();

};

