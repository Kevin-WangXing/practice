#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* pMergeList = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergeList = pHead1;
		pMergeList->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergeList = pHead2;
		pMergeList->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}

	return pMergeList;
}

//两个正常链表
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNode(pNode1, pNode3);
	ConnectListNode(pNode3, pNode5);

	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNode(pNode2, pNode4);
	ConnectListNode(pNode4, pNode6);

	ListNode* pNode = Merge(pNode1, pNode2);

	PrintList(pNode);
}

//一个空
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNode(pNode1, pNode3);
	ConnectListNode(pNode3, pNode5);


	ListNode* pNode = Merge(pNode1, NULL);

	PrintList(pNode);
}

//有相同节点值
void Test3()

{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNode(pNode1, pNode3);
	ConnectListNode(pNode3, pNode5);

	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(5);

	ConnectListNode(pNode2, pNode4);
	ConnectListNode(pNode4, pNode6);

	ListNode* pNode = Merge(pNode1, pNode2);

	PrintList(pNode);
}
int main()
{
	

	Test3();
	system("pause");
	return 0;
}