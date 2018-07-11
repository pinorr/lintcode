#include "lintcode_common.h"

class lintcode_29 {
public:
	/**
	* @param s1: A string
	* @param s2: A string
	* @param s3: A string
	* @return: Determine whether s3 is formed by interleaving of s1 and s2
	*/
	bool isInterleave(string &s1, string &s2, string &s3) {
		const char * p1 = s1.c_str();
		const char * p2 = s2.c_str();
		const char * p3 = s3.c_str();
		int n1 = s1.length();
		int n2 = s2.length();
		int n3 = s3.length();
		int l = 0, r = 0;
		int rTemp = r;
		for (int i = 0; i < n3; ++i)
		{
			if (l < n1 && p1[l] == p3[i])
			{
				++l;
				if (rTemp < n2 && p2[rTemp] == p3[i])
					++rTemp;
				else
					rTemp = r;
			}
			else if (r < n2 && p2[r] == p3[i])
			{
				++r;
				rTemp = r;
			}
			else
			{
				if (rTemp < n2 && p2[rTemp] == p3[i])
				{
					l -= rTemp - r;
					r = ++rTemp;
				}
				else
					return false;
			}
		}
		return true;
	}
};