#ifndef LLSTACK_HPP
#define LLSTACK_HPP

template <class T>
class llStack
{
    public:
	llStack();
	~llStack();
	bool empty() const;
	void push(const T & e);
	T pop();
    private:
	struct stackNode
	{
		T data;
		stackNode* next;
	}
	stackNode* top;
	int size;
};
#endif
