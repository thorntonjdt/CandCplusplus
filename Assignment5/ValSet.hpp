/**********************************************************************
**Author: Jake Thornton
**Date: 12/2/16
**Description: Lets you add and removes values to a set and can also
** find the union, intersection, and symmetric difference of two sets
** also allows you to push the set into a vector.
** Compatible with int, char, and string sets.
***********************************************************************/

#ifndef VALSET_HPP
#define VALSET_HPP

#include <vector>
using namespace std;

template <class T>
class ValSet
{
    private:
	T *aptr;
	int s;     //Current array size
	int amount;
	void clear();
	void copyOther(const ValSet &);
    public:
	ValSet();
	ValSet(const ValSet &);
	~ValSet();
	ValSet<T> &operator =(const ValSet &);
	int size() const{ return amount;}
	bool isEmpty();
	bool contains(T) const;
	void add(const T &value);
	void remove(T);
	ValSet<T> unionWith(const ValSet &) const;
	ValSet<T> intersectWith(const ValSet &) const;
	ValSet<T> symmDiffWith(const ValSet &) const;
	vector<T> getAsVector();
};

#endif
