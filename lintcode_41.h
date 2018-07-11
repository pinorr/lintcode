#include "lintcode_common.h"

class lintcode_41 {
public:
	int maxSubArray(vector<int> &nums) {
		int n = nums.size();
		int ans = -99999999;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			if (sum > ans)
				ans = sum;
			if (sum < 0)
				sum = 0;   //子串和为负数，丢掉
		}
		return ans;
	}
};