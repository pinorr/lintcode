#include "lintcode_common.h"

class lintcode_28 {
public:
	/**
	* @param matrix: matrix, a list of lists of integers
	* @param target: An integer
	* @return: a boolean, indicate whether matrix contains target
	*/
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		int n_line = matrix.size();
		int L = 0, R = n_line - 1;
		if (R < 0 || matrix[L][0] > target)
			return false;
		while (L + 1 < R)
		{
			int M = (L + R) / 2;
			if (matrix[M][0] == target)
				return true;
			else if (matrix[M][0] > target)
				R = M;
			else
				L = M;
		}
		int M = L;
		if (matrix[R][0] == target)
			return true;
		else if (matrix[R][0] < target)
			M = R;

		int l = 0, r = matrix[M].size() - 1;
		if (r < 0) return false;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (matrix[M][m] == target)
				return true;
			else if (matrix[M][m] > target)
				r = m;
			else
				l = m;
		}
		if (matrix[M][l] == target || matrix[M][r] == target)
			return true;
		return false;
	}
};