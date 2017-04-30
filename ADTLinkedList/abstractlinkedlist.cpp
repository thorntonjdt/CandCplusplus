#ifndef ABSTRACTLINKEDLIST_HPP
#define ABSTRACTLINKEDLIST_HPP

template <class LIT>
class List
{
    public:
	List():size(0), head(NULL){}
	~List();
	int getSize() const;
	void insert(int loc, LIT e);
	void remove(int loc);
	LIT const & getItem(int loc) const;
    private:
	listNode *head;
	int size;
	listNode *Find(listNode *place, int k);
	struct listNode
	{
		LIT data;
		listNode* next;
		listNode(LIT newData):data(newData), next(NULL);
	};
}

#ifndef
