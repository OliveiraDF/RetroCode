#include "pch.h"
#include "ExtractPath.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestExtractPath);

CTestExtractPath::CTestExtractPath()
{

}

CTestExtractPath::~CTestExtractPath()
{

}

void CTestExtractPath::TestDrive()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T("W:"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Drive, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestDir()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T("\\Games\\The Park\\"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Dir, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestExt()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T(".txt"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Ext, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestFileName()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T("Manifest_DebugFiles"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_FileName, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestEmpty()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T(""));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Empty, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestDriveDir()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T("W:\\Games\\The Park\\"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Drive | retro::core::EComponent_Dir, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestDirFileNameExt()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T("\\Games\\The Park\\Manifest_DebugFiles.txt"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Dir | retro::core::EComponent_FileName | retro::core::EComponent_Ext, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}

void CTestExtractPath::TestDriveExt()
{
	LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
	const CString strExpected(_T("W:.txt"));
	CString strResult;

	HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Drive | retro::core::EComponent_Ext, strResult);

	CPPUNIT_ASSERT_EQUAL(S_OK, hr);
	CPPUNIT_ASSERT(strExpected == strResult);
}