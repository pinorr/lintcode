#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};