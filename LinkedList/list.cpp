#include "list.hpp"
#include <iostream>

using namespace std;

/***********************************************************
** Inserts a new node and value at the front of the list	
***********************************************************/


void ListNode::insertAtFront(ListNode &curr, LIT e)
{
	ListNode *temp = new ListNode(e);
	temp->next = curr;
	curr = temp;
}


/************************************************************
** Recursively prints the list in reverse (from tail to head)
** run time: O(n) - scales linearly with length of list
************************************************************/

void ListNode::printReverse(ListNode *curr)
{
	if(curr != NULL)
	{
		printReverse(curr->next)
		cout << curr->data;
	}
}


