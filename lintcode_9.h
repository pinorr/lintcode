#include "lintcode_common.h"

class lintcode_9 {
public:
	/**
	* @param n: An integer
	* @return: A list of strings.
	*/
	vector<string> fizzBuzz(int n) {
		static string str3 = "fizz";
		static string str5 = "buzz";
		static string str35 = "fizz buzz";
		vector<string> vctOut;
		for (int i = 1; i <= n; ++i)
		{
			string str = to_string(i);
			if (i % 15 == 0)
				str = str35;
			else if (i % 3 == 0)
				str = str3;
			else if (i % 5 == 0)
				str = str5;

			vctOut.push_back(str);
		}
		return vctOut;
	}
};