#include "pch.h"
#include "Stack.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestStack);

CTestStack::CTestStack()
{

}

CTestStack::~CTestStack()
{

}

void CTestStack::TestPushPop()
{
	retro::core::CStack<INT> Ints;

	Ints.Push(1);
	Ints.Push(2);

	{
		const INT_PTR nSize = Ints.GetSize();
		const INT nTop = Ints.Top();

		CPPUNIT_ASSERT_EQUAL((INT_PTR)2, nSize);
		CPPUNIT_ASSERT_EQUAL(2, nTop);
	}

	Ints.Pop();

	{
		const INT_PTR nSize = Ints.GetSize();
		const INT nTop = Ints.Top();

		CPPUNIT_ASSERT_EQUAL((INT_PTR)1, nSize);
		CPPUNIT_ASSERT_EQUAL(1, nTop);
	}

	Ints.Pop();

	{
		const BOOL bEmpty = Ints.IsEmpty();

		CPPUNIT_ASSERT(bEmpty);
	}
}