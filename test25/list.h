#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateListNode(int value);
void ConnectListNode(ListNode* pHead, ListNode* pNode);
void PrintListNode(ListNode* pHead);
void PrintList(ListNode* pNode);
void DeletedListNode(ListNode* pNode);
