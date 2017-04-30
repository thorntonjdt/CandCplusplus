#ifndef QUEUE_HPP
#define QUEUE_HPP

template <class T>
class Queue
{
    public:
	bool empty() const;
	void enqueue(const T &e);	// O(n)
	T dequeue();			// also O(n)
    private:
	struct queueNode
	{
		T data;
		queueNode* next;
	}
	queueNode *entry;
	queueNode *exit;
	int size;
}

#endif
