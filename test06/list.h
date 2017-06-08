


struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pNode);
void DestroyList(ListNode* pHead);
void addToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);