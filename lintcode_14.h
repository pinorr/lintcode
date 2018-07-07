#include "lintcode_common.h"

class lintcode_14 {
public:
	/**
	* @param nums: The integer array.
	* @param target: Target to find.
	* @return: The first position of target. Position starts from 0.
	*/
	int binarySearch(vector<int> &nums, int target) {
		int l = 0;
		int r = nums.size();
		int mid = (l + r) / 2;
		while (nums[l] != target && l + 1 < r)
		{
			mid = (l + r) / 2;
			if (nums[mid] < target)
				l = mid;
			else if (nums[mid] >= target)
				r = mid;
		}
		if (l < r)
		{
			if (nums[l] == target)
				return l;
			else if (nums[r] == target)
				return r;
		}
		return -1;
	}
};