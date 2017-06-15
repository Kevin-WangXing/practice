


struct BinaryTreeNode
{
	double m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(double value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void DestoryTree(BinaryTreeNode* pRoot);