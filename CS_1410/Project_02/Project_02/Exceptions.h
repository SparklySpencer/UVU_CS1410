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
#include <iostream>			// std::cout
#include <string>			// std::string
#include <iomanip>			// other manipulations

using namespace std;

class Exceptions
{
private:
	bool _test;
	string _errorMsg;
	double _errorMoney;

public:
	/*Function Prologue -----
	Purpose: the default constructor for this class
	Parameters: takes none, default
	Returns: n/a
	Pre-conditions: ?
	Post-conditions: initalizes all class vars
	-------------------------
	*/
	Exceptions(string); //Exceptions.cpp

	string getMsg() const;
};

