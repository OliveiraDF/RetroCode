#include "pch.h"
#include "StaticArray.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestStaticArray);

CTestStaticArray::CTestStaticArray()
{
	
}

CTestStaticArray::~CTestStaticArray()
{

}

void CTestStaticArray::TestAt()
{
	retro::core::CStaticArray<INT, 5> Ints;

	Ints.SetAt(0, 1);
	Ints.SetAt(1, 2);
	Ints.SetAt(2, 3);
	Ints.SetAt(3, 4);
	Ints.SetAt(4, 5);
	
	const INT_PTR nUpperBound = Ints.GetUpperBound();
	const INT nAtLowerBound = Ints.GetAt(0);
	const INT nAtUpperBound = Ints.GetAt(nUpperBound);

	CPPUNIT_ASSERT_EQUAL((INT_PTR)4, nUpperBound);
	CPPUNIT_ASSERT_EQUAL(1, nAtLowerBound);
	CPPUNIT_ASSERT_EQUAL(5, nAtUpperBound);
}

void CTestStaticArray::TestData()
{
	retro::core::CStaticArray<INT, 5> Ints;

	Ints.SetAt(0, 1);
	Ints.SetAt(1, 2);
	Ints.SetAt(2, 3);
	Ints.SetAt(3, 4);
	Ints.SetAt(4, 5);

	const INT* pData = Ints.GetData();
	const INT nData = *Ints.GetData();

	CPPUNIT_ASSERT(pData);
	CPPUNIT_ASSERT_EQUAL(1, nData);
}