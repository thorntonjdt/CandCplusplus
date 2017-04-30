#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

template <class T>
class Queue
{
    public:
	Queue():capacity(8), size(0)
	{
		items = new T [capacity];
	}
	~Queue();
	bool empty() const;
	void enqueue(const &T);
	T dequeue();
    private:
	int capacity;
	int size;
	T* items;
	int rear;
	int front;
};
#endif
