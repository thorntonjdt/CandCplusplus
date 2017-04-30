#include "Store.hpp"
#include <iostream>

using namespace std;

int main()
{
	Store s1;

	Product* pApple;
	Product Apple("001", "Apple", "Yummy honeycrisp apples", 1.00, 5);
	pApple = &Apple;
	s1.addProduct(pApple);
	s1.productSearch("Apple");

	Customer* pCustomer;
	Customer Jake("Jake", "001", false);
	pCustomer = &Jake;
	s1.addMember(pCustomer);

	s1.getProductFromID("001");
	s1.getMemberFromID("001");

	s1.addProductToMemberCart("001", "001");

	s1.checkOutMember("001");
}

