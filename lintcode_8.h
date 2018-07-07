#include "lintcode_common.h"

class lintcode_8 {
public:
	/**
	* @param str: An array of char
	* @param offset: An integer
	* @return: nothing
	*/
	void rotateString(string &str, int offset) {		
		int len = str.length();
		if (offset >= 0 && offset <= len)
		{
			char * pTemp = new char[len + 1];
			memcpy(pTemp, str.c_str() + len - offset , offset);
			memcpy(pTemp + offset, str.c_str(), len - offset);
			pTemp[len] = '\0';
			str = pTemp;
			delete[]pTemp;
		}
	}
};