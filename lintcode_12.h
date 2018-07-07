
#include "lintcode_common.h"

class lintcode_12 {
public:
	lintcode_12() {
		m_id = 0;
		m_min = 0;
		m_nCap = 16;
		m_pStack = new int[m_nCap];
	}

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number) {
		if (m_id == 0 || m_min > number)
			m_min = number;
		m_pStack[m_id++] = number;
		if (m_id == m_nCap)
		{
			m_nCap *= 2;
			int * pTemp = new int[m_nCap];
			memcpy(pTemp, m_pStack, m_id);
		}
	}

	/*
	* @return: An integer
	*/
	int pop() {
		if (m_id > 0)
		{
			--m_id;
			if (m_id >= 0)
			{
				m_min = *m_pStack;
				for (int i = 1; i<m_id; ++i)
					if (m_min > *(m_pStack + i)) m_min = *(m_pStack + i);

				return *(m_pStack + m_id);
			}
		}
		return -1;
	}

	/*
	* @return: An integer
	*/
	int min_val() {
		return m_min;
	}
public:
	int m_min;
	int m_id;
	int m_nCap;
	int *m_pStack;
};