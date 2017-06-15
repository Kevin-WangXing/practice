#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = NULL;
	ListNode* pPre = NULL;
	ListNode* pNode = pHead;

	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL)
			pReverseHead = pNode;

		pNode->m_pNext = pPre;
		pPre = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}
//测试一个链表
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
	//ConnectListNode(pHead5, pHead1);

	ListNode* result = ReverseList(pHead1);

	PrintListNode(result);
	PrintList(result);

	//DeletedListNode(pHead1);  有环就不能这样删除了
	delete pHead1;
	pHead1 = NULL;
	delete pHead2;
	pHead2 = NULL;
	delete pHead3;
	pHead3 = NULL;
	delete pHead4;
	pHead4 = NULL;
	delete pHead5;
	pHead5 = NULL;


}
//测试一个结点
void Test2()
{
	ListNode* pHead1 = CreateListNode(1);



	ConnectListNode(pHead1, NULL);
	//ConnectListNode(pHead5, pHead1);

	ListNode* result = ReverseList(pHead1);

	//PrintListNode(result);
	PrintList(result);

	//DeletedListNode(pHead1);  有环就不能这样删除了
	delete pHead1;
	pHead1 = NULL;



}

//测试空
void Test3()
{


	ListNode* result = ReverseList(NULL);

	//PrintListNode(result);
	PrintList(result);

	//DeletedListNode(pHead1);  有环就不能这样删除了




}
int main()
{
	Test3();
	system("pause");
	return 0;
}