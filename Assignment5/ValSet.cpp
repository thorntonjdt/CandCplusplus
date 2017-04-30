/**********************************************************************
**Author: Jake Thornton
**Date: 12/2/16
**Description: Lets you add and removes values to a set and can also
** find the union, intersection, and symmetric difference of two sets
** also allows you to push the set into a vector.
** Compatible with int, char, and string sets.
***********************************************************************/

#include "ValSet.hpp"
#include <vector>
#include <string>

using namespace std;

/*****************************************************************
**Description: Used when deallocating the aptr array that holds
**	       the value set
*****************************************************************/ 
template <class T>
void ValSet<T>::clear()
{
	delete [] aptr;
}

/*****************************************************************
**Description: Copies one objects values into another
**
*****************************************************************/ 
template <class T>
void ValSet<T>::copyOther(const ValSet &other)
{	
	s = other.s;
	amount = other.amount;
	aptr = new T[s];
	for(int i = 0; i < amount; i++)
		aptr[i] = other.aptr[i];
}

/*****************************************************************
**Description: Default constructor; sets amount to 0, size to 10,
**	       and allocates the aptr array with size 10
*****************************************************************/ 
template <class T>
ValSet<T>::ValSet()
{
	amount = 0;
	s = 10;
	aptr = new T [s];
}

/*****************************************************************
**Description: Copy constructor
**
*****************************************************************/ 
template <class T>
ValSet<T>::ValSet(const ValSet &other)
{
	copyOther(other);
}

/*****************************************************************
**Description: Destructor
**
*****************************************************************/ 
template <class T>
ValSet<T>::~ValSet()
{
	if(s > 0)
		clear();
}

/*****************************************************************
**Description: Overloaded = operator
**
*****************************************************************/ 
template <class T>
ValSet<T> & ValSet<T>::operator=(const ValSet &other)
{
	if(this != &other)
	{
		clear();
		copyOther(other);
	}
	return *this;
}

/*****************************************************************
**Description: Checks if ValSet is empty, returns true if 
**	       amount = 0 and false if not.
*****************************************************************/ 
template <class T>
bool ValSet<T>::isEmpty()
{
	if(amount == 0)
		return true;
	else
		return false;
}

/*****************************************************************
**Description: Checks if ValSet contains user inputted value
**
*****************************************************************/ 
template <class T>
bool ValSet<T>::contains(T value) const
{
	for(int i = 0; i < amount; i++)
	{
		if(aptr[i] == value)
			return true;
	}
	return false;
}

/*****************************************************************
**Description: Adds a value to the ValSet, if the ValSet is full
**	       it creates a new array twice the size
*****************************************************************/ 
template <class T>
void ValSet<T>::add(const T &value)
{
	if(amount >= s)
	{
		s = s*2;
		T* array = new T[s];
		for(int i = 0; i < amount; i++)
			array[i] = aptr[i];
		delete [] aptr;
		aptr = array;
	}
	aptr[amount] = value;
	amount++;
}

/*****************************************************************
**Description: Removes a value from the ValSet
**
*****************************************************************/ 
template <class T>
void ValSet<T>::remove(T value)
{
	for(int i = 0; i < amount; i++)
	{
		if(aptr[i] == value)
		{
			amount--;
			for(int j = i; j < amount; j++)
				aptr[j] = aptr[j+1];
			break;
		}
	}
}

/*****************************************************************
**Description: Returns a new ValSet with the union of two specified
**	       ValSets
*****************************************************************/ 
template <class T>
ValSet<T> ValSet<T>::unionWith(const ValSet &other) const
{
	ValSet<T> unionset;
	for(int i = 0; i < amount; i++)
		unionset.add(aptr[i]);
	for(int i = 0; i < other.amount; i++)
	{
		if(!unionset.contains(other.aptr[i]))
			unionset.add(other.aptr[i]);
	}
	return unionset;
}

/*****************************************************************
**Description: Returns a new ValSet with the intersection of two
**	       specified ValSets
*****************************************************************/ 
template <class T>
ValSet<T> ValSet<T>::intersectWith(const ValSet &other) const
{
	ValSet<T> intersect;
	for(int i = 0; i < amount; i++)
	{
		for(int j = 0; j < other.amount; j++)
		{
			if(aptr[i] == other.aptr[j])
				intersect.add(aptr[i]);
		}
	}
	return intersect;
}

/*****************************************************************
**Description: Returns a new ValSet with the symmetric difference
**	       of two specified ValSets
*****************************************************************/ 
template <class T>
ValSet<T> ValSet<T>::symmDiffWith(const ValSet &other) const
{
	ValSet<T> symmdiff;
	ValSet<T> intersect;
	symmdiff = unionWith(other);
	intersect = intersectWith(other);
	for(int i = 0; i < intersect.amount; i++)
	{
		if(symmdiff.contains(intersect.aptr[i]))
			symmdiff.remove(intersect.aptr[i]);
	}
	return symmdiff;
}

/*****************************************************************
**Description: Pushes the ValSet onto a vector and returns the vector
**
*****************************************************************/ 
template <class T>
vector<T> ValSet<T>::getAsVector()
{
	vector<T> thevec;
	for(int i = 0; i < amount; i++)
	{
		thevec.push_back(aptr[i]);
	}
	return thevec;
}

template class ValSet<int>;
template class ValSet<char>;
template class ValSet<string>;	
