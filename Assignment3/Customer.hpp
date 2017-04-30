/**********************************************************************
** Author: Jake Thornton
** Date: 11/1/2016
** Description: Header file for Line class
***********************************************************************/ 
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <vector>
#include "Product.hpp"

class Customer
{
private:
    std::vector<std::string> cart;
    std::string name;
    std::string accountID;
    bool premiumMember;
public:
   Customer(std::string n, std::string a, bool pm);
   std::string getAccountID();
   std::vector<std::string> getCart();
   void addProductToCart(std::string);
   bool isPremiumMember();
   void emptyCart();
};

#endif
