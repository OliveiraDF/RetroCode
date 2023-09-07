#include "pch.h"
#include "Circular.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestCircular);

CTestCircular::CTestCircular()
{

}

CTestCircular::~CTestCircular()
{

}

void CTestCircular::TestConstructor()
{
	retro::core::CCircular<INT> Ints;

	const BOOL bEmpty = Ints.IsEmpty();
	const INT_PTR nSize = Ints.GetSize();
	const INT_PTR nCount = Ints.GetCount();

	CPPUNIT_ASSERT_EQUAL(TRUE, bEmpty);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)0, nSize);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)0, nCount);
}

void CTestCircular::TestCapacity()
{
	retro::core::CCircular<INT> Ints;

	Ints.SetSize(5);

	const BOOL bEmpty = Ints.IsEmpty();
	const INT_PTR nSize = Ints.GetSize();
	const INT_PTR nCount = Ints.GetCount();

	CPPUNIT_ASSERT_EQUAL(TRUE, bEmpty);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)5, nSize);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)0, nCount);
}

void CTestCircular::TestPush()
{
	retro::core::CCircular<INT> Ints;

	Ints.SetSize(5);

	Ints.Push(1);
	Ints.Push(2);
	Ints.Push(3);

	const BOOL bEmpty = Ints.IsEmpty();
	const INT_PTR nSize = Ints.GetSize();
	const INT_PTR nCount = Ints.GetCount();
	const INT nAt0 = Ints.GetAt(0);
	const INT nAt1 = Ints.GetAt(1);
	const INT nAt2 = Ints.GetAt(2);
	const INT nAt3 = Ints.GetAt(3);
	const INT nAt4 = Ints.GetAt(4);

	CPPUNIT_ASSERT_EQUAL(FALSE, bEmpty);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)5, nSize);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)3, nCount);
	CPPUNIT_ASSERT_EQUAL(0, nAt0);
	CPPUNIT_ASSERT_EQUAL(0, nAt1);
	CPPUNIT_ASSERT_EQUAL(1, nAt2);
	CPPUNIT_ASSERT_EQUAL(2, nAt3);
	CPPUNIT_ASSERT_EQUAL(3, nAt4);
}

void CTestCircular::TestClear()
{
	retro::core::CCircular<INT> Ints;

	Ints.SetSize(5);

	Ints.Push(1);
	Ints.Push(2);
	Ints.Push(3);

	Ints.RemoveAll();

	const BOOL bEmpty = Ints.IsEmpty();
	const INT_PTR nSize = Ints.GetSize();
	const INT_PTR nCount = Ints.GetCount();

	CPPUNIT_ASSERT_EQUAL(TRUE, bEmpty);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)0, nSize);
	CPPUNIT_ASSERT_EQUAL((INT_PTR)0, nCount);
}