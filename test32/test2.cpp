#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "BinaryTree.h"
#include <deque>

void Print(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	std::deque<BinaryTreeNode*> DequeTreeNode;

	DequeTreeNode.push_back(pRoot);
	int toBePrint = 1;
	int NextLevel = 0;

	while (DequeTreeNode.size())
	{
		BinaryTreeNode* pNode = DequeTreeNode.front();
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pLeft)
		{
			DequeTreeNode.push_back(pNode->m_pLeft);
			NextLevel++;
		}
		if (pNode->m_pRight)
		{
			DequeTreeNode.push_back(pNode->m_pRight);
			NextLevel++;
		}

		DequeTreeNode.pop_front();
		--toBePrint;
		if (toBePrint == 0)
		{
			printf("\n");
			toBePrint = NextLevel;
			NextLevel = 0;
		}
	}
}

void Test(char* testName, BinaryTreeNode* pRoot)
{

	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);

	printf("The nodes from top to bottom, from left to right are: \n");
	Print(pRoot);

	printf("\n\n");
} 

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	Test("Test1", pNode10);

	DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode1, nullptr);

	Test("Test2", pNode5);

	DestroyTree(pNode5);
}

int main()
{
	Test2();
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	Test("Test3", pNode5);
	system("pause");
	return 0;
}