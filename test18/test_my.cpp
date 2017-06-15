/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

#include "list.h"


void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted)
{
	if (pListHead == NULL || pToBeDeleted == NULL)
	{
		printf("THe iuput is invaild.\n");
		return;
	}

	if (pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		pListHead = NULL;
		return;
	}

	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pTemp = pListHead;
		while (pTemp->m_pNext != pToBeDeleted)
		{
			pTemp = pTemp->m_pNext;

		}
		pTemp->m_pNext = pToBeDeleted->m_pNext;
		pToBeDeleted = pTemp;

	}
	else//ÊÇÎ²½áµã
	{
		ListNode* pNode = pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}


int main1(int arg, char *args[])
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

	DeleteNode(pNode1, pNode1);

	PrintList(pNode1);

	DeletedListNode(pNode1);

	system("pause");
	return 0;
}