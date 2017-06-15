#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//此程序删除头结点出错，为什么？

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;
	return pNode;
}
void ConnectListNode(ListNode* pHead, ListNode* pNode)
{
	if (pNode != NULL || pHead != NULL)
	pHead->m_pNext = pNode;
}
void PrintListNode(ListNode* pHead)
{
	if (pHead != NULL)
		printf("The Head of the list is: %d\n", pHead->m_nValue);
	else
		printf("The head of the list is NULL\n");
	
}
void PrintList(ListNode* pNode)
{
	printf("PrintList begin.\n");
	while (pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}

	printf("\nPrintList end.\n");
}
void DeletedListNode(ListNode* pNode)
{

	
		ListNode* pNext = pNode;
		while (pNext != NULL)
		{
			pNode = pNode->m_pNext;
			delete pNext;
			pNext = pNode;
		}
	
}