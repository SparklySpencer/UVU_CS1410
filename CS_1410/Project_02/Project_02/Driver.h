/* File Prolog
Name: Spencer Carter
Assignment: Project 02-03
Class: CS 1410 Section 003
Date: 10/13/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#pragma once
#include "Account.h"		// Account header file so we can use the class
//#include "Exceptions.h"	not needed, in Person
//#include "Person.h"		not needed, in Account
//#include <iostream>		not needed, in Exceptions
//#include <string>			not needed, in Exceptions
#include <vector>;			// dynamic "arrays"

const string _name01 = "Frodo Baggins";
const string _name02 = "Clark Kent";
const string _name03 = "Joan Arc";
const string _addr01 = "Under Hill";
const string _addr02 = "Planet Krypton";
const string _addr03 = "Medieval Castle";
const int _acct01 = 1;
const int _acct02 = 3;
const int _acct03 = 5;
const double _ball01 = 500.00; //As required in Project 03 Spec
const double _ball02 = 1000.00; //As required in Project 03 Spec
const double _ball03 = 1200.00; //As required in Project 03 Spec
const int TWO = 2;

class Driver
{
public:
	/*Function Prologue -----
	Purpose: I assume this will work much like a print function: Output, account #'s, account names, account addresses, and account ballance
	Parameters: Takes an account object by const reference
	Returns: n/a
	Pre-conditions: ?
	Post-conditions: display the info
	-------------------------
	*/
	void displayAccounts(const vector<Account>& todisplay);
};
