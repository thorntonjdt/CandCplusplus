/**********************************************************************
** Author: Jake Thornton
** Date: 1/11/2016
** Description: Customer class functions
***********************************************************************/ 

#include "Customer.hpp"

using namespace std;

/***********************************************************************
** Description: Customer constructor with name, ID, and membership status as parameters
**
************************************************************************/
Customer::Customer(string n, string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

/***********************************************************************
** Description: Retrieves customer ID
**
************************************************************************/
string Customer::getAccountID()
{
	return accountID;
}

/***********************************************************************
** Description: Retrieves customers cart
**
************************************************************************/
vector<string> Customer::getCart()
{
	return cart;
}

/***********************************************************************
** Description: Adds a product ID to customers cart
**
************************************************************************/
void Customer::addProductToCart(string str)
{
	cart.push_back(str);
}

/***********************************************************************
** Description: Checks if customer is a premium member
**
************************************************************************/
bool Customer::isPremiumMember()
{
	if(premiumMember)
		return true;
	else
		return false;
}

/***********************************************************************
** Description: Empties a customers cart
**
************************************************************************/
void Customer::emptyCart()
{
	cart.clear();
}
