#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stack>
#include "BinaryTree.h"


void MirrorRecursively(BinaryTreeNode* pHead)
{
	if (pHead == NULL)
		return;
	if (pHead->m_pLeft == NULL && pHead->m_pRight == NULL)
		return;

	BinaryTreeNode* pTemp = pHead->m_pLeft;
	pHead->m_pLeft = pHead->m_pRight;
	pHead->m_pRight = pTemp;

	if (pHead->m_pLeft)
		MirrorRecursively(pHead->m_pLeft);
	if (pHead->m_pRight)
		MirrorRecursively(pHead->m_pRight);
}

//循环
void MirrorIteratively(BinaryTreeNode* pHead)
{
	if (pHead == NULL)
		return;
	if (pHead->m_pLeft == NULL && pHead->m_pRight == NULL)
		return;
	std::stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pHead);

	while (!stackTreeNode.empty())
	{
		BinaryTreeNode* pNode = stackTreeNode.top();
		stackTreeNode.pop();

		BinaryTreeNode* pTemp = pNode->m_pLeft;
		pHead->m_pLeft = pNode->m_pRight;
		pHead->m_pRight = pTemp;

		if (pHead->m_pLeft)
			stackTreeNode.push(pNode->m_pLeft);
		if (pHead->m_pRight)
			stackTreeNode.push(pNode->m_pRight);
	}

}
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11

void Test1()
{
	printf("=====Test1 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	PrintTree(pNode8);

	MirrorRecursively(pNode8);

	PrintTree(pNode8);

	DestroyTree(pNode8);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}