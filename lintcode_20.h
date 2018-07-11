#include "lintcode_common.h"

class lintcode_20 {
public:
	map<int, double> getPer(int n)
	{
		map<int, double> mapOut;
		if (n == 1)
		{
			for (int i = 1; i <= 6; ++i)
				mapOut[i] = double(1.0);
		}
		else
		{
			map<int, double> mapTemp = getPer(n - 1);
			for (int i = 1; i <= 6; ++i)
			{
				auto iter = mapTemp.begin();
				for (; iter != mapTemp.end(); ++iter)
					mapOut[i + iter->first] += iter->second;
			}
		}
		return mapOut;
	}
	/**
	* @param n an integer
	* @return a list of pair<sum, probability>
	*/
	vector<pair<int, double>> dicesSum(int n) {
		vector<pair<int, double>> vctOut;
		if (n <= 0)
			return vctOut;
		map<int, double> mapOut = getPer(n);
		double all = pow(6, n);
		auto iter = mapOut.begin();
		for (; iter != mapOut.end(); ++iter)
			vctOut.push_back(make_pair(iter->first, iter->second/all));
		return vctOut;
	}
};