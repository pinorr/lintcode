#include "lintcode_common.h"

class lintcode_24 {
public:
	int ncap;
	int num;

	map<int, pair<int, int>> mData;         //key->pair<value, freq>
	map<int, list<int>> mapFreq;            //freq->key
	/*
	* @param capacity: An integer
	*/
	lintcode_24(int capacity) {
		num = 0;
		ncap = capacity;
	}

	/*
	* @param key: An integer
	* @param value: An integer
	* @return: nothing
	*/
	void set(int key, int value) {
		if (ncap <= 0)
			return;
		auto iter = mData.find(key);
		if (iter != mData.end())
		{
			pair<int, int> &pData = iter->second;
			int nOldFreq = pData.second;
			pData.first = value;
			++pData.second;
			mapFreq[nOldFreq].remove(key);
			mapFreq[pData.second].push_back(key);
		}
		else
		{
			if (num >= ncap)	//清除最小的缓存
			{
				auto iterMin = mapFreq.begin();
				while (iterMin != mapFreq.end() && iterMin->second.size() == 0)
					++iterMin;
				if (iterMin == mapFreq.end())
					return;		//异常
				auto &lstDel = iterMin->second;
				auto iterDel = lstDel.begin();
				mData.erase(*iterDel);
				lstDel.remove(*iterDel);
				--num;
			}
			mData[key] = make_pair(value, 1);
			mapFreq[1].push_back(key);			
			++num;
		}
	}

	/*
	* @param key: An integer
	* @return: An integer
	*/
	int get(int key) {
		if (ncap <= 0)
			return -1;
		auto iter = mData.find(key);
		if (iter != mData.end())
		{
			pair<int, int> &pData = iter->second;
			int nOldFreq = pData.second;
			++pData.second;
			mapFreq[nOldFreq].remove(key);
			mapFreq[pData.second].push_back(key);
			return pData.first;
		}
		return -1;
	}
};