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
#include "Person.h"			// Person header file to be used in this class
//#include "Exceptions.h"	not needed, in Person
//#include <iostream>		not needed, in Exceptions
//#include <string>			not needed, in Exceptions
//#include <fstream>		not needed, in Person
#include <sstream>			//used to make my error messages pretty eventually

class Account
{
private:
	Person owner;
	int actNumber;
	double ballance;
	const int TWO = 2;
	

public:
	/*Function Prologue -----
	Purpose: The default constructor for this class to initialize all the variables
	Parameters: Takes none
	Returns:  n/a
	Pre-conditions:
	Post-conditions: Initializes the fields to default values
	-------------------------
	*/
	Account();

	/*Function Prologue -----
	Purpose: The paramaterized constructor to initialize the fields to the passed values
	Parameters: takes a person object, an account number, and the starting ballance
	Returns: n/a
	Pre-conditions:
	Post-conditions: initializes the fields
	-------------------------
	*/
	Account(const Person& passedOwner, int passedNumber, double passedBallance);

	/*Function Prologue -----
	Purpose: to get the information from the owner and return it into the function without altering anything
	Parameters: takes none
	Returns: returns a person object to the function
	Pre-conditions:
	Post-conditions: stores a person object in the function
	-------------------------
	*/
	Person getPerson() const;

	/*Function Prologue -----
	Purpose: to get the account number and return it into the function without alteration
	Parameters: takes none
	Returns: the int value of the account number into the function
	Pre-conditions:
	Post-conditions: stores the acount number into the function 
	-------------------------
	*/
	int getActNumber() const;

	/*Function Prologue -----
	Purpose: to the the current acount balance and return it to the function without alteration
	Parameters: takes none
	Returns: a double value representative of the available funds
	Pre-conditions:
	Post-conditions: stores the account ballance into the function
	-------------------------
	*/
	double getBallance() const;

	/*Function Prologue -----
	Purpose: to add money into the account of the person
	Parameters: the passed (from another function) deposit amount into the function to do some addition, ballance will be class level available
	Returns: n/a
	Pre-conditions: the "current" ballance
	Post-conditions: the ballance + the deposit (if deposit is a non negative number)
	-------------------------
	*/
	void makeDeposit(double deposit);

	/*Function Prologue -----
	Purpose: to withdraw money from the account of the person
	Parameters: the passed (from another function) withdraw amount to the function to do some subtraction, ballance will be class level available
	Returns: n/a
	Pre-conditions: the "current" ballance
	Post-conditions: if withdrawl does not exceed the current ballance, ballance - withdraw
	-------------------------
	*/
	double makeWithdraw(double& withdrawl);

	/*Function Prologue -----
	Purpose: To read data in from a file to create an account object
	Parameters: takes the input file stream by reference
	Returns: a person object
	Pre-conditions: ?
	Post-conditions: Creates a new person object and promices not to change the data
	-------------------------
	*/
	void readData(ifstream& reader);

	/*Function Prologue -----
	Purpose: to write out an account object to a file
	Parameters: takes the output file stream by reference
	Returns: a bool (t or f) -- I am hoping this will help with error checking
	Pre-conditions: ?
	Post-conditions: if it can write to a file, it will return true and be happy
	-------------------------
	*/
	void writeData(ofstream& writer);
};

class Savings : public Account
{

};

class Checking : public Account
{

};