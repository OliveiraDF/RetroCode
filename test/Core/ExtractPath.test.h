#pragma once

class CTestExtractPath : public CPPUNIT_NS::TestFixture
{
	private:

		CPPUNIT_TEST_SUITE(CTestExtractPath);
			CPPUNIT_TEST(TestDrive);
			CPPUNIT_TEST(TestDir);
			CPPUNIT_TEST(TestExt);
			CPPUNIT_TEST(TestFileName);
			CPPUNIT_TEST(TestEmpty);
			CPPUNIT_TEST(TestDriveDir);
			CPPUNIT_TEST(TestDirFileNameExt);
			CPPUNIT_TEST(TestDriveExt);
		CPPUNIT_TEST_SUITE_END();

	public:

		CTestExtractPath();
		virtual ~CTestExtractPath();

	public:

		void TestDrive();
		void TestDir();
		void TestExt();
		void TestFileName();
		void TestEmpty();
		void TestDriveDir();
		void TestDirFileNameExt();
		void TestDriveExt();

};

