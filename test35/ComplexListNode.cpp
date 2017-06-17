#include <stdio.h>
#include <stdlib.h>

#include "ComplexListNode.h"

ComplexListNode* CreateComplexListNode(int value)
{
	ComplexListNode* pNode = new ComplexListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;
	pNode->m_pSibling = NULL;
	return pNode;
}

void ConnectComplexListNode(ComplexListNode* pNode1, ComplexListNode* pNode2, ComplexListNode* pSlibing)
{
	if (pNode1 == NULL)
		return;
	pNode1->m_pNext = pNode2;
	pNode1->m_pSibling = pSlibing;
}
void PrintComplexListNode(ComplexListNode* pHead)
{
	if (pHead == NULL)
	{
		printf("The ComplexlistNode is NULL");
		return;
	}
	else
	{
		printf("The value of Head is: %d \n", pHead->m_nValue);
		if (pHead->m_pNext)
			printf("The Next value is: %d \n", pHead->m_pNext->m_nValue);
		if (pHead->m_pSibling)
			printf("The Sibling value is: %d \n", pHead->m_pSibling->m_nValue);
		printf("\n");
	}
}
void PrintComplexList(ComplexListNode* pHead)
{
	PrintComplexListNode(pHead);
	if (pHead != NULL)
	{
		if (pHead->m_pNext)
			PrintComplexList(pHead->m_pNext);
	}
}

void PrintList(ComplexListNode* pHead)
{
	if (pHead == NULL)
	{
		printf("The ComplexlistNode is NULL");
		return;
	}

	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		printf("The value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pSibling != NULL)
		{
			printf("The value of its sibling is: %d\n", pNode->m_pSibling->m_nValue);

		}
		else
			printf("This node does have a sibling.\n");

		printf("\n");

		pNode = pNode->m_pNext;
	}
}
