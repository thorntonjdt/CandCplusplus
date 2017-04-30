/**********************************************************************
** Author: Jake Thornton
** Date: 1/11/2016
** Description: Store class functions
***********************************************************************/ 

#include "Store.hpp"
#include <string>
#include <iostream>

using namespace std;


/***********************************************************************
** Description: Adds products to store inventory
**
************************************************************************/
void Store::addProduct(Product* p)
{
	inventory.push_back(p);
}

/***********************************************************************
** Description: Adds customer to store member list
**
************************************************************************/
void Store::addMember(Customer* c)
{
	members.push_back(c);
}

/***********************************************************************
** Description: Looks for and returns a product from its ID code
**
************************************************************************/
Product* Store::getProductFromID(string str)
{
	//Looks through inventory for matching product ID
	for(int i = 0; i < inventory.size(); i++)
	{
		if(inventory[i]->getIdCode() == str)
			return inventory[i];
	}
	return NULL;
}

/***********************************************************************
** Description: Looks for and returns a member from their member ID
**
************************************************************************/
Customer* Store::getMemberFromID(string str)
{
	//Looks through member list for matching ID
	for(int i = 0; i < members.size(); i++)
	{
		if(members[i]->getAccountID() == str)
			return members[i];
	}
	return NULL;
}

/***********************************************************************
** Description: Searches through all product titles and descriptions for a user inputted keyword
**
************************************************************************/
void Store::productSearch(string str)
{
	//Looks through title and description of products in inventory for search terms
	for(int i = 0; i < inventory.size(); i++)
	{
		string title = inventory[i]->getTitle();
		string description = inventory[i]->getDescription();

		if(title.find(str) != string::npos || description.find(str) != string::npos)
		{
			cout << endl
			     << title << endl 
			     << "ID: " << inventory[i]->getIdCode() << endl
			     << "Price: $" << inventory[i]->getPrice() << endl
			     << "Description: " << inventory[i]->getDescription() << endl << endl;
		}
	}
}

/***********************************************************************
** Description: Adds a product to a members cart, using both the product and member IDs
**
************************************************************************/
void Store::addProductToMemberCart(string pID, string mID)
{
	Customer* pCustomer = this->getMemberFromID(mID);
	Product* pProduct = this->getProductFromID(pID);

	//If customer and product IDs are valid and the product is in stock the product is added to the customers cart
	if(pCustomer == NULL)
		cout << "Member #" << mID << " not found.\n";
	else if(pProduct == NULL)
		cout << "Product #" << pID << " not found.\n";
	else if(pProduct->getQuantityAvailable() == 0)
		cout << "Sorry, product #" << pID << " is currently out of stock.\n";
	else
		pCustomer->addProductToCart(pID);
}

/***********************************************************************
** Description: Checks out a member, totals the price of everything in their cart and adds a shipping price
**
************************************************************************/
void Store::checkOutMember(string mID)
{
	
	Customer* pCustomer = this->getMemberFromID(mID);

	//Checks if customer ID is valid
	if(pCustomer == NULL)
		cout << "Member #" << mID << " not found.\n";
	else
	{
		//Goes through every product in cart and calculates a subtotal
		vector<string> cart = pCustomer->getCart();
		double subtotal = 0;
		for(int i = 0; i < cart.size(); i++)
		{
			Product* pProduct = this->getProductFromID(cart[i]);
			if(pProduct->getQuantityAvailable() == 0)
				cout << "Sorry, product #" << pProduct->getIdCode() << ", " << pProduct->getTitle() << ", is no longer available.\n";
			else
			{
				cout << pProduct->getTitle() << endl
				     << "Price: $" << pProduct->getPrice() << endl << endl;
				pProduct->decreaseQuantity();
				subtotal += pProduct->getPrice();
			}
		}
		
		//Calculates shipping and prints out receipt
		double shipping, total;
		if(pCustomer->isPremiumMember())
			shipping = 0;
		else
			shipping = 0.07 * subtotal;
		cout << "Subtotal: $" << subtotal << endl
		     << "Shipping: $" << shipping << endl;
		total = subtotal + shipping;
		cout << "Total: $" << total << endl;
	
		pCustomer->emptyCart();
	}
}

