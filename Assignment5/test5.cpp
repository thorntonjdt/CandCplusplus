#include "ValSet.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ValSet<char> list;
	list.add('A');
	list.add('B');
	list.add('C');
	ValSet<char> list2;
	list2.add('D');
	list2.add('E');
	list2.add('F');
	list2.add('C');
	list2.add('H');
	list2.remove('H');
	
	cout << list2.size() << " " << list2.isEmpty() << " " << list2.contains('D') << " " << list2.contains('A') << endl;

	ValSet<char> list3;
	list3 = list.intersectWith(list2);

	vector<char> vec = list3.getAsVector();
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	list2 = list;
	cout << list2.size() << " " << list2.contains('A') << " " << list2.contains('D') << endl;
}
