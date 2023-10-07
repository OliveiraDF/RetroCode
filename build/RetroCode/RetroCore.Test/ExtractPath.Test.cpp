#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RetroCoreTest
{
	TEST_CLASS(ExtractPathTest)
	{
	public:
		
		ExtractPathTest()
		{
			Logger::WriteMessage("Tests ExtractPath...");
		}
		TEST_METHOD(TestDrive)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T("W:"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Drive, strResult);

			BOOL bRet = strExpected == strResult;

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestDir)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T("\\Games\\The Park\\"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Dir, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestExt)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T(".txt"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Ext, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestFileName)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T("Manifest_DebugFiles"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_FileName, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestEmpty)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T(""));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Empty, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestDriveDir)
		{
			PCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T("W:\\Games\\The Park\\"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Drive | retro::core::EComponent_Dir, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestDirFileNameExt)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T("\\Games\\The Park\\Manifest_DebugFiles.txt"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Dir | retro::core::EComponent_FileName | retro::core::EComponent_Ext, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

		TEST_METHOD(TestDriveExt)
		{
			LPCTSTR lpszFile = _T("W:\\Games\\The Park\\Manifest_DebugFiles.txt");
			const CString strExpected(_T("W:.txt"));
			CString strResult;

			HRESULT hr = retro::core::ExtractPath(lpszFile, retro::core::EComponent_Drive | retro::core::EComponent_Ext, strResult);

			Assert::AreSame(S_OK, hr);
			Assert::AreEqual(strExpected.GetString(), strResult.GetString());
		}

	};
}
