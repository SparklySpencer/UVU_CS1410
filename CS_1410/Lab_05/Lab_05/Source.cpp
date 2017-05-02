/* File Prolog
Name: Spencer Carter
Assignment: Lab 05
Class: CS 1410 Section 003
Date: 09/24/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include <iostream>			// std::cout
#include <string>			// std::string
#include <vector>			// better than arrays
#include <fstream>			// reading and writing from a file

#include "Exception.h"		// the exception class we wrote for this assignment

using namespace std;


/* Psudocode
1) Declare an integer value to store the user's input.
2) Prompt the user to enter a positive, non-zero integer value.
3) Pass this value to a function named calculateSquare.
This function will only work on positive, non-zero values.
Since the function has no idea where the data came from it has no way to recover if the parameter it receives is invalid.
If the value passed is zero or negative the function will throw an exception that (1) indicates what the error was, and (2) what the value of the offending parameter is.
If the parameter is okay, it calculates and returns the square of the number.
*/

/*Function Prologue -----
Purpose: to square an integer value pass=ed by the user
Parameters: takes the user value
Returns: an integer representsative of the squared value
Pre-conditions: ?
Post-conditions: stores an int in the return
-------------------------
*/
int calculateSquare(int validateThisShit);

void main() // should throw in loop so it can be done more than once, but I cant type much with a messed up hand
{
	cout << "Spencer Carter, Lab 05, CS 1410 Sec 03\n" << endl; //required for all assignments
	int _storeInput = 0; //#1 always initalize variables
	cout << "Please enter a positive number, greater than zero: "; //#2
	cin >> _storeInput;
	try
	{
		//cout the good input
		cout << _storeInput << " squared is: " << calculateSquare(_storeInput) << endl;
	}
	catch (Exception& ex)
	{
		//cout the exception
		cout << "The following is an invalid value: " << ex.GetExcetion() << endl;
	}
	system("Pause"); //required for all assignments
}

int calculateSquare(int validateThisShit)
{
	if (validateThisShit <= 0) //test for negative and 0
	{
		throw Exception(validateThisShit);
	}
	else //square the number
	{
		return (validateThisShit * validateThisShit);
	}
}