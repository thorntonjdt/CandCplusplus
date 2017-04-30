template <class LIT>
int List<LIT>::getSize() const
{
	return size;
}

template <class LIT>
void List<LIT>::insert(int loc, LIT e)
{
	if((size + 1) < 8)
	{
		LIT go = e;
		int it = loc - 1;
		while(it < size+1)
		{
			LIT temp = items[it];
			items[it] = go;
			go = temp;
			it++;
		{
		size++;
	}
}

/*************************************************************************
** Removes a value at specified location and shifts all items behind it in
** the list over.
** runtime: O(n) - linear (time is proportional to the size of the list)
**************************************************************************/
template <class LIT>
void List<LIT>::remove(int loc)
{
	if(size > 0)
	{
		int it = loc - 1;
		while(it < size)
		{
			items[it] = items[it + 1];
			it ++;
		}
		size--;
	}
}

template <class LIT>
LIT const & List<LIT>::getItem(int loc) const
{
	return items[loc - 1];
}
