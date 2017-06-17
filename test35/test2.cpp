#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "ComplexListNode.h"

/*struct ComplexListNode{
    int val;
    ComplexListNode* pNext;
    ComplexListNode* pSibling;
    ComplexListNode():val(0),pNext(NULL),pSibling(NULL){};
};
 
typedef std::map<ComplexListNode*,ComplexListNode*> MAP;
 
ComplexListNode* CloneNodes(ComplexListNode* pHead,MAP &hashNode){
    ComplexListNode* pNode=new ComplexListNode();
    ComplexListNode* p=pNode;
    ComplexListNode* tmp;
 
    while(pHead!=NULL){
        tmp=new ComplexListNode();
        tmp->val=pHead->val;
        p->pNext=tmp;
        hashNode[pHead]=tmp;
        pHead=pHead->pNext;
        p=p->pNext;
    }
    return pNode->pNext;
}
 
void SetSiblings(ComplexListNode* pHead,ComplexListNode* pCopy,MAP &hashNode){
    while(pCopy!=NULL){
        pCopy->pSibling=hashNode[pHead->pSibling];
        pCopy=pCopy->pNext;
        pHead=pHead->pNext;
    }
}
 
ComplexListNode* ComplexListCopy(ComplexListNode* pHead){
    ComplexListNode* pCopy;
    MAP hashNode;
    pCopy=CloneNodes(pHead,hashNode);
    SetSiblings(pHead,pCopy,hashNode);
    return pCopy;
}*/
void ClonepNodes(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return;
	ComplexListNode* pNode = pHead;
	while (pNode)
	{
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

void CloneSibling(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pHead->m_pSibling != NULL)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;

		}
		pNode = pCloned->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;

	if (pNode != NULL)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}


	return pClonedHead;
}



ComplexListNode* Clone(ComplexListNode* pHead)
{
	ClonepNodes(pHead);
	CloneSibling(pHead);
	return ReconnectNodes(pHead);
}

void Test(char *testName, ComplexListNode* pHead)
{
	if (testName != NULL)
		printf("%s is begin:\n", testName);

	printf("The original list is: \n");
	PrintList(pHead);

	ComplexListNode* result = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pHead);
}

void Test11()
{
	ComplexListNode* pNode1 = CreateComplexListNode(1);
	ComplexListNode* pNode2 = CreateComplexListNode(2);
	ComplexListNode* pNode3 = CreateComplexListNode(3);
	ComplexListNode* pNode4 = CreateComplexListNode(4);
	ComplexListNode* pNode5 = CreateComplexListNode(5);

	ConnectComplexListNode(pNode1, pNode2, pNode3);
	ConnectComplexListNode(pNode2, pNode3, pNode5);
	ConnectComplexListNode(pNode3, pNode4, NULL);
	ConnectComplexListNode(pNode4, pNode5, pNode2);

	Test("test1", pNode1);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
	ComplexListNode* pNode1 = CreateComplexListNode(1);
	ComplexListNode* pNode2 = CreateComplexListNode(2);
	ComplexListNode* pNode3 = CreateComplexListNode(3);
	ComplexListNode* pNode4 = CreateComplexListNode(4);
	ComplexListNode* pNode5 = CreateComplexListNode(5);

	ConnectComplexListNode(pNode1, pNode2, pNode3);
	ConnectComplexListNode(pNode2, pNode3, pNode5);
	ConnectComplexListNode(pNode3, pNode4, nullptr);
	ConnectComplexListNode(pNode4, pNode5, pNode2);

	Test("Test1", pNode1);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}