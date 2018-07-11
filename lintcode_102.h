#include "lintcode_common.h"

class lintcode_102 {
public:
	/*
	* @param head: The first node of linked list.
	* @return: True if it has a cycle, or false
	*/
	bool hasCycle(ListNode * head) {
		ListNode *fast = head;
		ListNode *slow = head;
		while (slow && fast)
		{
			fast = fast->next;
			if (fast == nullptr)
				return false;
			else if (fast == slow)
				return true;
			fast = fast->next;
			slow = slow->next;
		}
		return false;
	}
};