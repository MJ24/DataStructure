#include <iostream>
#include <string>
#include "TreeNode.h"
#include "BinaryTree.h"
#include <vector>
#include <algorithm>
using namespace std;


class CharTreeNode
{
public:
	CharTreeNode(char v) :val(v), left(nullptr), right(nullptr) {}
	char val;
	CharTreeNode *left;
	CharTreeNode *right;
};

CharTreeNode* build_tree(const string &preOrder, const string &inOrder)
{
	CharTreeNode *root = nullptr;
	if (preOrder.length() > 0)
	{
		root = new CharTreeNode(preOrder[0]);
		int index = inOrder.find(preOrder[0]);
		root->left = build_tree(preOrder.substr(1, index), inOrder.substr(0, index));
		root->right = build_tree(preOrder.substr(index + 1), inOrder.substr(index + 1));
	}
	return root;
}

CharTreeNode* build_tree_impl(const string &preOrder, int preStart, int preEnd, const string &inOrder, int inStart, int inEnd)
{
	CharTreeNode *root = nullptr;
	if (preStart <= preEnd)
	{
		root = new CharTreeNode(preOrder[preStart]);
		//理论上下面更好的方法是去inOrder的[inStart,inEnd]的区间找，不过那样会返回迭代器而不是下标
		int index = inOrder.find(preOrder[preStart]) - inStart;
		root->left = build_tree_impl(preOrder, preStart + 1, preStart + index, inOrder, inStart, inStart + index - 1);
		root->right = build_tree_impl(preOrder, preStart + index + 1, preEnd, inOrder, inStart + index + 1, inEnd);
	}
	return root;
}
CharTreeNode* build_tree_pro(const string &preOrder, const string &inOrder)
{
	return build_tree_impl(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
}

void printTreeImpl(CharTreeNode* n, bool left, std::string const& indent)
{
	if (n->right)
	{
		printTreeImpl(n->right, false, indent + (left ? "|     " : "      "));
	}
	std::cout << indent;
	std::cout << (left ? '\\' : '/');
	std::cout << "-----";
	std::cout << n->val << std::endl;
	if (n->left)
	{
		printTreeImpl(n->left, true, indent + (left ? "      " : "|     "));
	}
}
void printTree(CharTreeNode* root)
{
	if (root->right)
	{
		printTreeImpl(root->right, false, "");
	}
	std::cout << root->val << std::endl;
	if (root->left)
	{
		printTreeImpl(root->left, true, "");
	}
}
int main()
{
	/*BinaryTree bt;
	bt.traverseTree();
	BinaryTree bt("537619284");
	bt.traverseTree();*/
	CharTreeNode *root1 = build_tree("abcdefghij", "cbedahgijf");
	CharTreeNode *root2 = build_tree_pro("abcdefghij", "cbedahgijf");
	printTree(root1);
	cout << endl;
	printTree(root2);
	system("pause");
	return 0;
}