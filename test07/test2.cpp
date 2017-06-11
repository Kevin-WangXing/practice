/*

// 面试题5：链表添加结点
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "BinaryTree.h"
#include <stack>



BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int *startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int *startInorder, int* endInorder)
{
	//先根据前序遍历第一个找到跟节点
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	//根据中序遍历，找到左右字数的个数
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
	{
		//构建做字数
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		//构建右字数
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

void Test(char* testName, int *preorder, int *inorder, int length)
{
	printf("%s begin.\n", testName);

	for (int i = 0; i < length; i++)
		printf("%d  ", preorder[i]);

	printf("\n");
	for (int i = 0; i < length; i++)
		printf("%d  ", inorder[i]);
	printf("\n");
	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);
		DestoryTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

void Test1()
{
	int length = 8;
	int preorder[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	Test("Test1", preorder, inorder, length);
}

int main(int arg, char *args[])
{
	Test1();
	system("pause");
	return 0;
}