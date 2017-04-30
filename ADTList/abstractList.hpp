#ifndef ABSTRACTLIST_HPP
#define ABSTRACTLIST_HPP 

template <class LIT>

class List
{
    public:
	List():size(0){}
	~List();
	int getSize() const;
	void insert(int loc, LIT e);
	void remove(int loc);
	LIT const & getItem(int loc) const;

    private:
	LIT items[8];
	int size;
};

#endif
