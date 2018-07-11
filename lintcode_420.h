#include "lintcode_common.h"

class lintcode_420 {
public:
	string vctDataToString(vector<pair<int, int>> &vct)
	{
		string strOut;
		for (size_t n = 0; n < vct.size(); ++n)
		{
			strOut += to_string(vct[n].first);
			strOut += to_string(vct[n].second);
		}
		return strOut;
	}
	/**
	* @param n: the nth
	* @return: the nth sequence
	*/
	string countAndSay(int n) {
		if (n <= 0)
			return "";
		else if (n == 1)
			return "1";
		else
		{
			vector<pair<int, int>> vct;
			vct.push_back(make_pair(1, 1));
			for (int i = 3; i <= n; ++i)
			{
				int cur = -1;
				vector<pair<int, int>> vctNext;
				for (size_t n = 0; n < vct.size(); ++n)
				{
					if (cur >= 0 && vctNext[cur].second == vct[n].first)
						++vctNext[cur].first;
					else
					{
						vctNext.push_back(make_pair(1, vct[n].first));
						++cur;
					}
					if (cur >= 0 && vctNext[cur].second == vct[n].second)
						++vctNext[cur].first;
					else
					{
						vctNext.push_back(make_pair(1, vct[n].second));
						++cur;
					}
				}
				vct = vctNext;
			}
			return vctDataToString(vct);
		}
	}
};