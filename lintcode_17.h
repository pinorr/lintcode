#include "lintcode_common.h"

class lintcode_17 {
public:
	vector<vector<int>> subsets(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int all = 1 << n;
		vector<vector<int>> vctOut;
		for (int i = 0; i < all; ++i)
		{
			vector<int> vctTemp;
			for (int j = 0; j < n; ++j)
			{
				if ((i & (1 << j)) != 0)
					vctTemp.push_back(nums[j]);
			}
			vctOut.push_back(vctTemp);
		}
		return vctOut;
	}
};