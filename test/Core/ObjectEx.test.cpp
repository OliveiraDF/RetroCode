#include "pch.h"
#include "ObjectEx.test.h"

class CMyObject : public retro::core::CObjectEx
{
	private:

		DECLARE_DYNCREATE(CMyObject);

	protected:

		CMyObject() {}

	public:
		
		virtual ~CMyObject() {}

	private:

		CMyObject(const CMyObject& Object) = delete;
		void operator=(const CMyObject& Object) = delete;

};

IMPLEMENT_DYNCREATE(CMyObject, retro::core::CObjectEx);

CPPUNIT_TEST_SUITE_REGISTRATION(CTestObjectEx);

CTestObjectEx::CTestObjectEx()
{

}

CTestObjectEx::~CTestObjectEx()
{

}

void CTestObjectEx::TestReference()
{
	CMyObject* pObject = DYNAMIC_DOWNCAST(CMyObject, CMyObject::CreateObject());
	if (pObject)
	{
		const INT nFirstRef = static_cast<INT>(pObject->GetReferenceCounter());
		pObject->AddRef();
		const INT nSecondRef = static_cast<INT>(pObject->GetReferenceCounter());
		const BOOL bIsReleasedAfterSecond = pObject->Release();
		const INT nThirdRef = static_cast<INT>(pObject->GetReferenceCounter());
		const BOOL bIsReleasedAfterThird = pObject->Release();

		CPPUNIT_ASSERT_EQUAL(1, nFirstRef);
		CPPUNIT_ASSERT_EQUAL(2, nSecondRef);
		CPPUNIT_ASSERT_EQUAL(FALSE, bIsReleasedAfterSecond);
		CPPUNIT_ASSERT_EQUAL(1, nThirdRef);
		CPPUNIT_ASSERT_EQUAL(TRUE, bIsReleasedAfterThird);
	}
}