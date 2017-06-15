

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"


void DeleteDuplication(ListNode** pHead)
{
	if (pHead == NULL || *pHead == NULL)
	{
		printf("invalid input.\n");
		return;
	}

	ListNode* pPreNode = NULL;
	ListNode* pNode = *pHead;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != NULL && pNode->m_nValue == pNext->m_nValue)
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != NULL && pToBeDel->m_nValue == value)
			{
				pNext = pToBeDel->m_pNext;
				delete pToBeDel;
				pToBeDel = NULL;
				pToBeDel = pNext;
			}

			if (pPreNode == NULL)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}
//部分节点重复
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(4);
	ListNode* pNode7 = CreateListNode(5);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

//没有重复节点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

//除了一个结点其他都重复
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(1);
	ListNode* pNode6 = CreateListNode(1);
	ListNode* pNode7 = CreateListNode(2);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

// 所有结点的值都相同
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(1);
	ListNode* pNode6 = CreateListNode(1);
	ListNode* pNode7 = CreateListNode(1);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

// 所有结点都成对出现
void Test5()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(2);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(3);
	ListNode* pNode7 = CreateListNode(4);
	ListNode* pNode8 = CreateListNode(4);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);
	ConnectListNode(pNode7, pNode8);
PrintList(pNode1);

DeleteDuplication(&pNode1);

PrintList(pNode1);

DeletedListNode(pNode1);
}


// 除了两个结点之外其他结点都成对出现
void Test6()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(4);
	ListNode* pNode7 = CreateListNode(5);
	ListNode* pNode8 = CreateListNode(5);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);
	ConnectListNode(pNode7, pNode8);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

// 链表中只有两个不重复的结点
void Test7()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);

	ConnectListNode(pNode1, pNode2);
PrintList(pNode1);

DeleteDuplication(&pNode1);

PrintList(pNode1);

DeletedListNode(pNode1);
}

// 结点中只有一个结点
void Test8()
{
	ListNode* pNode1 = CreateListNode(1);

	ConnectListNode(pNode1, nullptr);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

// 结点中只有两个重复的结点
void Test9()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);

	ConnectListNode(pNode1, pNode2);

	PrintList(pNode1);

	DeleteDuplication(&pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}
int main(int arg, char* args[])
{
	Test9();
	system("pause");
	return 0;
}