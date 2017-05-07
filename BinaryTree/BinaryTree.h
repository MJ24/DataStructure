#pragma once
#include "TreeNode.h"
#include <stack>
#include <queue>
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
		std::cout << "�����������������Ľڵ㣬"
			"�Կո��س��������Ctrl+z���س�����\n";
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
		std::cout << "���Ľṹ��\n";
		printTree();
		std::cout << "ǰ��������ݹ�/�ǵݹ飩��\n";
		preOrder(root);
		std::cout << "/";
		preOrderPro(root);
		std::cout << "\n";
		std::cout << "����������ݹ�/�ǵݹ飩��\n";
		inOrder(root);
		std::cout << "/";
		inOrderPro(root);
		std::cout << "\n";
		std::cout << "����������ݹ�/�ǵݹ飩��\n";
		postOrder(root);
		std::cout << "/";
		postOrderPro(root);
		std::cout << "\n";
		std::cout << "���������\n";
		levelOrder(root);
		std::cout << "\n";
		printLevelInfo(root);
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
	void levelOrder(TreeNode *r) const
	{
		if (!r)
			return;
		std::queue<TreeNode*> que;
		que.push(r);
		while (!que.empty())
		{
			TreeNode *cur = que.front();
			std::cout << cur->val;
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
			que.pop();
		}
	}
	void printLevelInfo(TreeNode *r) const
	{
		if (!r)
			return;
		std::queue<TreeNode*> que;
		que.push(r);
		int levelCount = 0; //����
		int levelWidth = 0; //��ǰ��node����
		while (!que.empty())
		{
			++levelCount;
			levelWidth = que.size();
			std::cout << "��ǰΪ��" << levelCount << "��, �����"
				<< levelWidth << "��node��" << std::endl;
			// ������ǰ�㣬���δ�ӡ��ǰ������нڵ㲢�����ǵ����Ҷ������
			for (int i = 0; i < levelWidth; i++)
			{
				TreeNode * cur = que.front();
				que.pop();
				std::cout << cur->val;
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			std::cout << "\n"; // ��ǰ��������
		}
		std::cout << "��" << levelCount << "���ӡ��ϡ�" << std::endl;
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