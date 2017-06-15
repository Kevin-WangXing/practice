#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "list.h"

//1   �ǲ����л�
//2   ���ж��ٽ��
//3   �ҽڵ�

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
		if (pFast != NULL)       //����ǲ����Ѿ���ĩβ��
			pFast = pFast->m_pNext;
	}

	return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);

	if (meetingNode == NULL)
		return NULL;
	//�õ����ĸ���

	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_pNext != meetingNode)
	{
		pNode1 = pNode1->m_pNext;
		nodesInLoop++;
	}

	//���ƶ�pNode1������Ϊ�����Ŀ
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

//���Բ���   ��   û��   �����һ��    һ������
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

	//DeletedListNode(pHead1);  �л��Ͳ�������ɾ����
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