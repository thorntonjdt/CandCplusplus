/**********************************************************************
** Author: Jake Thornton
** Date: 1/11/2016
** Description: Product class functions
***********************************************************************/ 
#include "Product.hpp"

using namespace std;

/***********************************************************************
** Description: Product constructor, uses id, title, description, price, and quantity for parameters
**
************************************************************************/
Product::Product(string id, string t, string d, double p, int qa)
{
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

/***********************************************************************
** Description: Retrieves a products ID code
**
************************************************************************/
string Product::getIdCode()
{
	return idCode;
}

/***********************************************************************
** Description: Returns a products title
**
************************************************************************/
string Product::getTitle()
{
	return title;
}

/***********************************************************************
** Description: Returns a products description
**
************************************************************************/
string Product::getDescription()
{
	return description;
}

/***********************************************************************
** Description: Returns product price
**
************************************************************************/
double Product::getPrice()
{
	return price;
}

/***********************************************************************
** Description: Returns product quantity
**
************************************************************************/
int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

/***********************************************************************
** Description: Decreases product quantity by one
**
************************************************************************/
void Product::decreaseQuantity()
{
	quantityAvailable--;
}
