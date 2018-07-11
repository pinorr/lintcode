#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <map>
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

class ListNode {
	public:
		int val;
		ListNode *next;
		ListNode(int val) {
			this->val = val;
			this->next = NULL;			
		}		
};