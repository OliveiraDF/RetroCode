#include "pch.h"
#include "Base64.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestBase64);

CTestBase64::CTestBase64()
{
	
}

CTestBase64::~CTestBase64()
{

}

void CTestBase64::TestEmptyString()
{
	const CString strInput;
	const CString strExpected(_T("AAA="));
	CString strEncoded;
	CString strDecoded;

	HRESULT hrEncoded = retro::core::Base64Encode(strInput.GetString(), strEncoded);
	const UINT_PTR uSize = retro::core::Base64QuerySize(strEncoded.GetString());
	LPTSTR lpczBuffer = strDecoded.GetBufferSetLength((INT)uSize);
	HRESULT hrDecoded = retro::core::Base64Decode(strEncoded.GetString(), lpczBuffer, uSize);
	strDecoded.ReleaseBuffer((INT)uSize);

	CPPUNIT_ASSERT_EQUAL(S_OK, hrEncoded);
	CPPUNIT_ASSERT(strExpected == strEncoded);
	CPPUNIT_ASSERT_EQUAL(S_OK, hrDecoded);
	CPPUNIT_ASSERT(strInput == strDecoded);
}

void CTestBase64::TestSimpleString()
{
	const CString strInput(_T("Hello world!"));
	const CString strExpected(_T("SABlAGwAbABvACAAdwBvAHIAbABkACEAAAA="));
	CString strEncoded;
	CString strDecoded;

	HRESULT hrEncoded = retro::core::Base64Encode(strInput.GetString(), strEncoded);
	const UINT_PTR uSize = retro::core::Base64QuerySize(strEncoded.GetString());
	LPTSTR lpczBuffer = strDecoded.GetBufferSetLength((INT)uSize);
	HRESULT hrDecoded = retro::core::Base64Decode(strEncoded.GetString(), lpczBuffer, uSize);
	strDecoded.ReleaseBuffer((INT)uSize);
	
	CPPUNIT_ASSERT_EQUAL(S_OK, hrEncoded);
	CPPUNIT_ASSERT(strExpected == strEncoded);
	CPPUNIT_ASSERT_EQUAL(S_OK, hrDecoded);
	CPPUNIT_ASSERT(strInput == strDecoded);
}