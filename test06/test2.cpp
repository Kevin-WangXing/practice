/*

// 面试题5：链表添加结点
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "list.h"
#include <stack>

void PrintListReversing(ListNode* pHead)
{
	if (pHead == NULL)
		return;
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		nodes.pop();
		printf("%d\t", pNode->m_nValue);
	}
	printf("\n");
}

void Print_recursive(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
		{
			Print_recursive(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
	printf("\n");
}

void Test1()
{
	ListNode *phead1 = CreateListNode(2);
	ListNode* phead2 = CreateListNode(3);
	ListNode* phead3 = CreateListNode(4);
	ListNode* phead4 = CreateListNode(5);
	ListNode* phead5 = CreateListNode(6);
	ListNode* phead6 = CreateListNode(7);

	ConnectListNodes(phead1, phead2);
	ConnectListNodes(phead2, phead3);
	ConnectListNodes(phead3, phead4);
	ConnectListNodes(phead4, phead5);
	ConnectListNodes(phead5, phead6);
	//PrintListNode(phead1);
	PrintList(phead1);

	PrintListReversing(phead1);

	//Print_recursive(phead1);

	DestroyList(phead1);
}

void test2()
{
	ListNode *phead1 = CreateListNode(2);

	//PrintListNode(phead1);
	PrintList(phead1);

	PrintListReversing(phead1);

	//Print_recursive(phead1);

	DestroyList(phead1);
}

void Test3()
{
	ListNode *phead1 = NULL;

	//PrintListNode(phead1);
	PrintList(phead1);

	PrintListReversing(phead1);

	//Print_recursive(phead1);

	DestroyList(phead1);
}

int main(int arg, char *args[])
{
	
	Test1();
	test2();
	Test3();
	system("pause");
	return 0;
}