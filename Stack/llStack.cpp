#include "llStack.hpp"

template <class T>
void llStack<T>::push(const T & e)
{
	stackNode* newNode = new stackNode(e);
	newNode->next = top;
	top = newNode;
	size++;
}

template <class T>
T llStack<T>::pop()
{
	T retval = 0;
	if(size != 0)
	{
		retval = top->data;
		stackNode* t = top->next;
		delete top;
		top = t;
		size--;
	}
	return 0;
}
