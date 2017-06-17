#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include "BinaryTree.h"

void FindPath(BinaryTreeNode* pRoot, int expectedsum, int currentsum, std::vector<int>&path)
{
	currentsum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//�ж��ǲ���Ҷ�ӽڵ�
	bool isLeaf = (pRoot->m_pLeft == NULL) && (pRoot->m_pRight == NULL);

	if (currentsum == expectedsum && isLeaf)
	{
		printf("Find Path.\n");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); iter++)
			printf("%d\t", *iter);

		printf("\n");
	}

	//�������Ҷ�ӽڵ㣬�����ӽڵ�
	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedsum, currentsum, path);
	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedsum, currentsum, path);

	//���ظ��ڵ㣬����Ҫɾ����ǰ���
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedsum)
{
	if (pRoot == NULL)
		return;
	int currentsum = 0;
	std::vector<int> path;
	FindPath(pRoot, expectedsum, currentsum, path);
}

// ====================���Դ���====================
void Test(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	FindPath(pRoot, expectedSum);

	printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// ������·���ϵĽ���Ϊ22
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("Two paths should be found in Test1.\n");
	Test("Test1", pNode10, 22);

	DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// û��·���ϵĽ���Ϊ15
void Test2()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("No paths should be found in Test2.\n");
	Test("Test2", pNode10, 15);

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
// ��һ��·������Ľ���Ϊ15
void Test3()
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

	printf("One path should be found in Test3.\n");
	Test("Test3", pNode5, 15);

	DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// û��·������Ľ���Ϊ16
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	printf("No paths should be found in Test4.\n");
	Test("Test4", pNode1, 16);

	DestroyTree(pNode1);
}

// ����ֻ��1�����
void Test5()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	printf("One path should be found in Test5.\n");
	Test("Test5", pNode1, 1);

	DestroyTree(pNode1);
}

// ����û�н��
void Test6()
{
	printf("No paths should be found in Test6.\n");
	Test("Test6", nullptr, 0);
}


int main()
{
	Test5();
	system("pause");
	return 0;
}