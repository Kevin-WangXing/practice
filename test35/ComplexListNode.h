#pragma once

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

ComplexListNode* CreateComplexListNode(int value);
void ConnectComplexListNode(ComplexListNode* pNode1, ComplexListNode* pNode2, ComplexListNode* pSlibing);
void PrintComplexListNode(ComplexListNode* pHead);
void PrintComplexList(ComplexListNode* pHead);
void DestoryComplexList(ComplexListNode* pHead);
void PrintList(ComplexListNode* pHead);
