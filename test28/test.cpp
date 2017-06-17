#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stack>
#include "BinaryTree.h"

bool Symmerical(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
	if (pNode1 == NULL && pNode2 == NULL)
		return true;
	if (pNode1 == NULL || pNode2 == NULL)
		return false;
	if (pNode1->m_nValue != pNode2->m_nValue)
		return false;

	return Symmerical(pNode1->m_pLeft, pNode2->m_pRight)
		&& Symmerical(pNode1->m_pRight, pNode2->m_pLeft);
}

bool isSymmetrical(BinaryTreeNode* pNode)
{
	return Symmerical(pNode, pNode);
}

//            8
//        6      6
//       5 7    7 5
void Test1()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, pNode52);

	bool result = isSymmetrical(pNode8);
	printf("result = %d\n", result);

	DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode9);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode9, pNode72, pNode52);

	bool result = isSymmetrical(pNode8);
	printf("result = %d\n", result);

	DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, nullptr);

	bool result = isSymmetrical(pNode8);
	printf("result = %d\n", result);

	DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode31, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, pNode21, nullptr);
	ConnectTreeNodes(pNode42, nullptr, pNode22);
	ConnectTreeNodes(pNode21, pNode11, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode12);

	bool result = isSymmetrical(pNode5);
	printf("result = %d\n", result);

	DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode31, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, pNode6, nullptr);
	ConnectTreeNodes(pNode42, nullptr, pNode22);
	ConnectTreeNodes(pNode6, pNode11, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode12);

	bool result = isSymmetrical(pNode5);
	printf("result = %d\n", result);

	DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode31, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, pNode21, nullptr);
	ConnectTreeNodes(pNode42, nullptr, pNode22);
	ConnectTreeNodes(pNode21, nullptr, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode12);

	bool result = isSymmetrical(pNode5);
	printf("result = %d\n", result);

	DestroyTree(pNode5);
}

// 只有一个结点
void Test7()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	bool result = isSymmetrical(pNode1);
	printf("result = %d\n", result);

	DestroyTree(pNode1);
}

// 没有结点
void Test8()
{
	bool result = isSymmetrical(NULL);
	printf("result = %d\n", result);
}

// 所有结点都有相同的值，树对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode21, pNode22);
	ConnectTreeNodes(pNode21, pNode31, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, nullptr, nullptr);
	ConnectTreeNodes(pNode42, nullptr, nullptr);

	bool result = isSymmetrical(pNode1);
	printf("result = %d\n", result);

	DestroyTree(pNode1);
}

// 所有结点都有相同的值，树不对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode21, pNode22);
	ConnectTreeNodes(pNode21, pNode31, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, pNode42, nullptr);
	ConnectTreeNodes(pNode41, nullptr, nullptr);
	ConnectTreeNodes(pNode42, nullptr, nullptr);

	bool result = isSymmetrical(pNode1);
	printf("result = %d\n", result);

	DestroyTree(pNode1);
}

int main()
{
	Test6();
	system("pause");
	return 0;
}