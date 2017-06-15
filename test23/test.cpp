#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"

//1   是不是有环
//2   环有多少结点
//3   找节点

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ListNode* pSlow = pHead;
	ListNode* pFast = pSlow->m_pNext;
	if (pFast == NULL)
		return NULL;

	while (pFast != NULL && pSlow != NULL)
	{
		if (pFast == pSlow)
			return pFast;

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast != NULL)       //检测是不是已经到末尾了
			pFast = pFast->m_pNext;
	}

	return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);

	if (meetingNode == NULL)
		return NULL;
	//得到环的个数

	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_pNext != meetingNode)
	{
		pNode1 = pNode1->m_pNext;
		nodesInLoop++;
	}

	//先移动pNode1，次数为结点数目
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; i++)
		pNode1 = pNode1->m_pNext;

	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
}

//可以测试   空   没环   环结点一个    一个正环
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
	ConnectListNode(pHead5, pHead1);

	ListNode* result = EntryNodeOfLoop(pHead1);

	PrintListNode(result);

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


int main()
{
	Test1();
	system("pause");
	return 0;
}