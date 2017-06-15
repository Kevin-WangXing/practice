

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"

void DeleteNode_2(ListNode** pListNode, ListNode* pToBeDeleted)
{
	if (pListNode == NULL || pToBeDeleted == NULL)
	{
		printf("the invalid iuput.\n");
		return;
	}

	if (pToBeDeleted->m_pNext != NULL)//不是尾结点
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	else if (*pListNode == pToBeDeleted)//是尾结点同时也只有一个元素
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListNode = NULL;
	}
	else//链表有多个节点，删除尾结点
	{
		ListNode* pNode = *pListNode;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}


void Test()
{
	ListNode *pNode1 = CreateListNode(1);
	ListNode *pNode2 = CreateListNode(2);
	ListNode *pNode3 = CreateListNode(3);
	ListNode *pNode4 = CreateListNode(4);
	ListNode *pNode5 = CreateListNode(5);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);

	PrintList(pNode1);

	DeleteNode_2(&pNode1, pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);
}

int main2(int arg, char* args[])
{
	Test();
	system("pause");
	return 0;
}