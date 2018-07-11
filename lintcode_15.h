#include "lintcode_common.h"

class lintcode_15 {
public:
	vector<vector<int>> permute(vector<int> &nums) {
		vector<vector<int>> vctOut;
		int n = nums.size();
		if (n <= 0)
			vctOut.push_back(vector<int>());
		else
		{
			vector<vector<int>> vctPre;
			vector<vector<int>> vctNext;
			vctPre.push_back(vector<int>(1, nums[0]));
			for (int i = 1; i < n; ++i)
			{
				int *p = new int[i + 1];
				for (size_t l = 0; l < vctPre.size(); ++l)
				{
					for (int j = 0; j <= i; ++j)
					{
						if (j > 0)
							memcpy(p, &vctPre[l][0], j*sizeof(int));

						p[j] = nums[i];

						if (i - j > 0)
							memcpy(p + j + 1, &vctPre[l][j], (i - j) * sizeof(int));

						vector<int> vct_temp;
						vct_temp.insert(vct_temp.end(), p, p + i + 1);
						vctNext.push_back(vct_temp);
					}
				}
				delete[]p;
				vctPre = vctNext;
				vctNext.clear();
			}
			return vctPre;
		}
		return vctOut;
	}
};