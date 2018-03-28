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
	BinaryTree(const std::string &nodeVals)
	{
		createSearchTree(nodeVals);
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
	void createSearchTree(const std::string &nodeVals)
	{
		for (char nodeValChar : nodeVals)
		{
			int nodeVal = nodeValChar - '0';
			TreeNode **parent = &root;
			TreeNode *cur = root;
			while (cur)
			{
				if (nodeVal < cur->val)
				{
					parent = &(cur->left);
					cur = cur->left;
				}
				else
				{
					parent = &(cur->right);
					cur = cur->right;
				}
			}
			*parent = new TreeNode(nodeVal);
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
		std::cout << "\n";
		std::cout << "层序遍历：\n";
		levelOrder(root);
		std::cout << "\n";
		printLevelInfo(root);
		std::cout << "\n";

		int preArr[] = { 5,3,1,2,4,7,6,9,8 };
		std::cout << "根据搜索二叉树的前序遍历结果构建二叉树并输出后序遍历结果：\n";
		getPostByPre(preArr, 9);
		std::cout << std::endl;
	}
	TreeNode* findNode(const int nodeVal, TreeNode *root) const
	{
		if (!root)
			return nullptr;
		if (nodeVal < root->val)
			findNode(nodeVal, root->left);
		else if (nodeVal > root->val)
			findNode(nodeVal, root->right);
		else
			return root;
	}
	TreeNode* findNode(const int nodeVal) const
	{
		TreeNode *cur = root;
		while (cur)
		{
			if (nodeVal < cur->val)
				cur = cur->left;
			else if (nodeVal > cur->val)
				cur = cur->right;
			else
				return cur;
		}
		return nullptr;
	}
private:
	TreeNode * root;
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
		int levelCount = 0; //层数
		int levelWidth = 0; //当前层node个数
		while (!que.empty())
		{
			++levelCount;
			levelWidth = que.size();
			std::cout << "当前为第" << levelCount << "层, 这层有"
				<< levelWidth << "个node：" << std::endl;
			// 遍历当前层，依次打印当前层的所有节点并将它们的左右儿子入队
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
			std::cout << "\n"; // 当前层遍历完毕
		}
		std::cout << "共" << levelCount << "层打印完毕。" << std::endl;
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
	//从前序遍历的结果数组arr构建二叉树，思想是先找到第一个大于arr[start]的下标rightChild
	//那么[start+1, rightChild-1]是arr[start]的左子树，[rightChild, end]是其右子树
	//对这两个区间递归调用此方法构造再下层的子树即可
	void buidTreeByPreOrder(int *arr, int start, int end, TreeNode *root) const
	{
		if (start < end)
		{
			int rightChild = start + 1;
			while (rightChild <= end && arr[rightChild] <= arr[start])
				++rightChild;
			if (rightChild > start + 1) // has left child
			{
				root->left = new TreeNode(arr[start + 1]);
				buidTreeByPreOrder(arr, start + 1, rightChild - 1, root->left);
			}
			if (rightChild <= end) // has right child
			{
				root->right = new TreeNode(arr[rightChild]);
				buidTreeByPreOrder(arr, rightChild, end, root->right);
			}
		}
	}
	void getPostByPre(int *preArr, int len) const
	{
		TreeNode* root = new TreeNode(preArr[0]);
		buidTreeByPreOrder(preArr, 0, len - 1, root);
		postOrderPro(root);
		std::cout << "\n";
	}
};