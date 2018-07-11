#include "lintcode_common.h"

class lintcode_57 {
public:
	struct stData
	{
		int val;
		int num;
		stData(int v, int n)
		{
			val = v;
			num = n;
		}
	};
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		vector<vector<int>> vctOut;
		sort(numbers.begin(), numbers.end());
		vector<stData> vctNote;
		int nNote = 0;
		int num = numbers.size();
		for (int i = 0; i<num; ++i)
		{
			if (nNote > 0 && vctNote[nNote - 1].val == numbers[i])
				++vctNote[nNote - 1].num;
			else
			{
				++nNote;
				vctNote.push_back(stData(numbers[i], 1));
			}
		}
		num = vctNote.size();
		unordered_map<int, int> mapKey;
		for (int i = 0; i<num; ++i)
			mapKey[vctNote[i].val] = i;

		for (int i = 0; i<num; ++i)
		{
			--vctNote[i].num;
			for (int j = i; j<num; ++j)
			{
				if (vctNote[j].num <= 0) continue;
				--vctNote[j].num;
				int nDesVal = 0 - vctNote[i].val - vctNote[j].val;
				if (nDesVal >= vctNote[j].val)
				{
					auto iter = mapKey.find(nDesVal);
					if (iter != mapKey.end() && iter->second >= j && vctNote[iter->second].num > 0)
					{
						int temp[3] = { vctNote[i].val, vctNote[j].val, nDesVal };
						vector<int> vct(temp, temp + 3);
						vctOut.push_back(vct);
					}
				}
				++vctNote[j].num;
			}
			++vctNote[i].num;
		}
		return vctOut;
	}
};