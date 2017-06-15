#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"

ListNode* FindNthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
		return NULL;

	ListNode* pBegin = pListHead;
	ListNode* pBehind = NULL;

	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pBegin->m_pNext != NULL)
			pBegin = pBegin->m_pNext;
		else
			return NULL;
	}

	pBehind = pListHead;
	while (pBegin->m_pNext != NULL)
	{
		pBegin = pBegin->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}


void Test1()
{
	ListNode* pHead1 = CreateListNode(1);
	ListNode* pHead2 = CreateListNode(2);
	ListNode* pHead3 = CreateListNode(3);
	ListNode* pHead4 = CreateListNode(4);
	ListNode* pHead5 = CreateListNode(5);

	ConnectListNode(pHead1, pHead2);
	ConnectListNode(pHead2, pHead3);
	ConnectListNode(pHead3, pHead4);
	ConnectListNode(pHead4, pHead5);

	ListNode* result = FindNthToTail(pHead1, 7);

	PrintListNode(result);

}


int main()
{
	Test1();
	system("pause");
	return 0;
}