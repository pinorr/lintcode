#include "lintcode_common.h"

//KMP
class lintcode_13 {
public:
	bool getNext(const char target[], int n, vector<int> &vctNext)
	{
		if (n > 0 && target != nullptr)
		{
			int * pNext = new int[n];
			memset(pNext, 0, sizeof(int)*n);
			pNext[0] = -1;
			pNext[1] = 0;
			for (int i = 2; i < n; ++i)
			{
				pNext[i] = pNext[i - 1];
				if (target[i - 1] == target[pNext[i - 1]])
					++pNext[i];
				else
					pNext[i] = 0;
			}
			vctNext.insert(vctNext.end(), pNext, pNext + n);
			delete[]pNext;
			return true;
		}
		return false;
	}
	/*
	* @param source: source string to be scanned.
	* @param target: target string containing the sequence of characters to match
	* @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
	*/
	int strStr(const char *source, const char *target) {
		if (source == nullptr || target == nullptr)
			return -1;
		int nSrc = 0;
		while (source[nSrc] != 0) ++nSrc;
		int nTag = 0;
		while (target[nTag] != 0) ++nTag;

		vector<int> vctNext;
		getNext(target, nTag, vctNext);
		if (nTag == 0)
			return 0;

		int l = 0, r = 0;
		while (l < nSrc)
		{
			if (source[l] == target[r])
			{
				++l;
				++r;
				if (r == nTag)
					return l - r;
			}
			else if (vctNext[r] < 0)
				++l;
			else
				r = vctNext[r];
		}
		return -1;
	}
};