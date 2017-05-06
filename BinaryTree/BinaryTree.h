#pragma once
#include "TreeNode.h"
#include <stack>
class BinaryTree
{
public:
	BinaryTree()
	{
		createSearchTree();
	}
	BinaryTree(TreeNode *n) :root(n) {}
	void createSearchTree()
	{
		std::cout << "请输入搜索二叉树的节点，"
			"以空格或回车间隔，以Ctrl+z并回车结束\n";
		for (int n; std::cin >> n;)
		{
			TreeNode** parent = &root;
			TreeNode* cur = root;
			while (cur)
			{
				if (n < cur->val)
				{
					parent = &cur->left;
					cur = cur->left;
				}
				else
				{
					parent = &cur->right;
					cur = cur->right;
				}
			}
			*parent = new TreeNode(n);
		}
	}
	void printTree() const
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
	void traverseTree() const
	{
		std::cout << "树的结构：\n";
		printTree();
		std::cout << "前序遍历（递归/非递归）：\n";
		preOrder(root);
		std::cout << "/";
		preOrderPro(root);
		std::cout << "\n";
		std::cout << "中序遍历（递归/非递归）：\n";
		inOrder(root);
		std::cout << "/";
		inOrderPro(root);
		std::cout << "\n";
		std::cout << "后序遍历（递归/非递归）：\n";
		postOrder(root);
		std::cout << "/";
		postOrderPro(root);
		std::cout << std::endl;
	}
private:
	TreeNode *root;
	void preOrder(TreeNode *r) const
	{
		if (!r)
			return;
		std::cout << r->val;
		preOrder(r->left);
		preOrder(r->right);
	}
	void preOrderPro(TreeNode *r) const
	{
		TreeNode *current = r;
		std::stack<TreeNode*> stk;
		while (current || !stk.empty())
		{
			while (current)
			{
				std::cout << current->val;
				stk.push(current);
				current = current->left;
			}
			if (!stk.empty())
			{
				current = stk.top()->right;
				stk.pop();
			}
		}
	}
	void inOrder(TreeNode *r) const
	{
		if (!r)
			return;
		inOrder(r->left);
		std::cout << r->val;
		inOrder(r->right);
	}
	void inOrderPro(TreeNode *r) const
	{
		TreeNode *current = r;
		std::stack<TreeNode *> stk;
		while (current || !stk.empty())
		{
			while (current)
			{
				stk.push(current);
				current = current->left;
			}
			if (!stk.empty())
			{
				std::cout << stk.top()->val;
				current = stk.top()->right;
				stk.pop();
			}
		}
	}
	void postOrder(TreeNode *r) const
	{
		if (!r)
			return;
		postOrder(r->left);
		postOrder(r->right);
		std::cout << r->val;
	}
	void postOrderPro(TreeNode *r) const
	{
		TreeNode *current = r;
		std::stack<TreeNode *> stk;
		std::stack<TreeNode *> stkPrint;
		while (current || !stk.empty())
		{
			while (current)
			{
				stkPrint.push(current);
				stk.push(current);
				current = current->right;
			}
			if (!stk.empty())
			{
				current = stk.top()->left;
				stk.pop();
			}
		}
		while (!stkPrint.empty())
		{
			std::cout << stkPrint.top()->val;
			stkPrint.pop();
		}
	}
	void printTreeImpl(TreeNode* n, bool left, std::string const& indent) const
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
};

