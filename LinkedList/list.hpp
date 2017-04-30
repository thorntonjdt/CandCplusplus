#ifndef LIST.HPP
#define LIST.HPP

struct ListNode {
	LIT data;
	listNode *next;
	listNode(LIT newData):data(newData), next(NULL){}
	void insertAtFront(ListNode &curr, LIT e);
	void printReverse(ListNode *curr);
};

#endif
