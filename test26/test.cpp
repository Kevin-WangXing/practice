#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "BinaryTree.h"

//因为节点值类型为double类型，所以判断相等的时间不能直接用  =
bool Equal(double num1, double num2)
{
	if ((num1 - num2) < 0.0000001 && (num1 - num2) > -0.0000001)
		return true;
	else
		return false;
}

//判断是不是字数
bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;

	if (!Equal(pRoot1->m_nValue, pRoot2->m_nValue))
		return false;
	return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
		&& DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

//判断有没有字数
bool HasSubtree(BinaryTreeNode*pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (Equal(pRoot1->m_nValue, pRoot2->m_nValue))
			result = DoesTree1HasTree2(pRoot1, pRoot2);
		if (!result)
			result = DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2);
		if (!result)
			result = DoesTree1HasTree2(pRoot1->m_pRight, pRoot2);
	}

	return result;
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1()
{
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	bool result = HasSubtree(pNodeA1, pNodeB1);

	printf("result = %d.\n", result);

	DestoryTree(pNodeA1);
	DestoryTree(pNodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2()
{
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	bool result = HasSubtree(pNodeA1, pNodeB1);

	printf("result = %d.\n", result);

	DestoryTree(pNodeA1);
	DestoryTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void Test3()
{
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
	ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
	ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
	ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
	ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

	bool result = HasSubtree(pNodeA1, pNodeB1);

	printf("result = %d.\n", result);

	DestoryTree(pNodeA1);
	DestoryTree(pNodeB1);
}


int main()
{
	Test3();
	system("pause");
	return 0;
}