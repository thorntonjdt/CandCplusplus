#include "abstractlinkedlist.hpp"

template <class LIT>
List<LIT>::List()
{
	head = new listNode
	head->next = NULL;
	size = 0;
}

template <class LIT>
listNode * List<LIT>::Find(listNode * place, int k)
{
	if(( k == 0) || ( place == NULL))
		return place;
	else
		return Find(k-1, place->next);
}

template <class LIT>
void List<LIT>::removeCurrent(listNode* curr)
{
	t = curr->next
	curr->data = t->data;
	curr->next = t->next;
	delete t;
}

/**********************************************************
**Adds a sentinel node that points to node before it
**Must have correct constructor set up
***********************************************************/

templace <class LIT>
void List<LIT>::insert(int loc, LIT e)
{
	listNode* t = new listNode(e);
	listNode* curr = Find(head, k - 1); //sets curr to the node before insertion point

	t->next = curr->next; //sets inserted nodes next to curr's next which points to the node currently in the insertion point
	curr->next = t; // sets curr's next to inserted node
			
			// ex want to insert B between A->C
			// A->C   B     | create B
			// A-> C <-B	| make B point to same node as A
			// A->B->C	| now make A point to B
}

/**********************************************************
**
** O(n) version of functions (not as good)
***********************************************************/

/*
template <clatt LIT>
void List<LIT>::insert(int loc, LIT e)
{
	listNode* t = new listNode(e);
	if(k == 1)
		insertAtFront(e);
	else
	{
		listNode* p = Find(head, k - 2);
		t->next = p->next;
		p->next = t;
	}
}


template <class LIT>
void List<LIT>::removeCurrent(listNode* curr)
{
	listNode* t = head;
	while(t->next != curr)
		t = t->next;
	t->next = curr->next;
	delete curr;
	size --;
}

*/
