#include "pch.h"
#include "Queue.test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CTestQueue);

CTestQueue::CTestQueue()
{

}

CTestQueue::~CTestQueue()
{

}

void CTestQueue::TestPushPop()
{
	retro::core::CQueue<INT> Ints;

	Ints.Push(1);
	Ints.Push(2);

	{
		const INT_PTR nSize = Ints.GetSize();
		const INT nFront = Ints.Front();
		const INT nBack = Ints.Back();

		CPPUNIT_ASSERT_EQUAL((INT_PTR)2, nSize);
		CPPUNIT_ASSERT_EQUAL(1, nFront);
		CPPUNIT_ASSERT_EQUAL(2, nBack);
	}

	Ints.Pop();

	{
		const INT_PTR nSize = Ints.GetSize();
		const INT nFront = Ints.Front();
		const INT nBack = Ints.Back();

		CPPUNIT_ASSERT_EQUAL((INT_PTR)1, nSize);
		CPPUNIT_ASSERT_EQUAL(2, nFront);
		CPPUNIT_ASSERT_EQUAL(2, nBack);
	}

	Ints.Pop();

	{
		const BOOL bEmpty = Ints.IsEmpty();

		CPPUNIT_ASSERT(bEmpty);
	}
}