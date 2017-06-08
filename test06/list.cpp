#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;
	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == NULL)
	{
		printf("error to connrct two nodes.\n");
		exit(1);
	}
	pCurrent->m_pNext = pNext;
}
void PrintListNode(ListNode* pNode)
{
	if (pNode == NULL)
		printf("The Node is NULL.\n");
	else
		printf("The key in node is %d.\n", pNode->m_nValue);
}
void PrintList(ListNode* pNode)
{
	if (pNode == NULL)
		printf("The Node is NULL.\n");
	ListNode* pHead = pNode;
	while (pHead != NULL)
	{
		printf("%d\t", pHead->m_nValue);
		pHead = pHead->m_pNext;
	}
	printf("\n");
}
void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}
void addToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}
void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode* pDeleted = NULL;

	if ((*pHead)->m_nValue == value)
	{
		pDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pDeleted != NULL)
	{
		delete pDeleted;
		pDeleted = NULL;
	}
}