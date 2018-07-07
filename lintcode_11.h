
#include "lintcode_common.h"


class lintcode_11 {
public:
	/**
	* @param root: param root: The root of the binary search tree
	* @param k1: An integer
	* @param k2: An integer
	* @return: return: Return all keys that k1<=key<=k2 in ascending order
	*/
	vector<int> searchRange(TreeNode * root, int k1, int k2) {
		vector<int> vctOut;
		if (root)
		{
			if (root->val >= k1)
			{
				vector<int> vctTemp = searchRange(root->left, k1, min(k2, root->val));
				if (!vctTemp.empty())
					vctOut.insert(vctOut.end(), vctTemp.begin(), vctTemp.end());
			}
			if (root->val >= k1 && root->val <= k2)
				vctOut.push_back(root->val);
			if (root->val <= k2)
			{
				vector<int> vctTemp = searchRange(root->right, max(k1, root->val), k2);
				if (!vctTemp.empty())
					vctOut.insert(vctOut.end(), vctTemp.begin(), vctTemp.end());
			}
		}
		return vctOut;
	}
};