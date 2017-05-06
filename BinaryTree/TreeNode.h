#pragma once
#include <iostream>
#include <string>
class TreeNode
{
public:
	TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r) :val(v), left(l), right(r) {}
	int val;
	TreeNode *left;
	TreeNode *right;
};

