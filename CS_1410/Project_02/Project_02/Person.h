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
#include "Exceptions.h"		// Exceptions header file so I can tell the user how bad they fucked up
//#include <string>			Not needed, in Exceptions
#include <fstream>			// reading and writing from a file

class Person
{
private:
	string name;
	string address;
	

public:
	/*Function Prologue -----
	Purpose: The default constructor for this class to initialize all the variables
	Parameters: Takes none
	Returns:  n/a
	Pre-conditions: 
	Post-conditions: Initializes the fields to default values
	-------------------------
	*/
	Person();

	/*Function Prologue -----
	Purpose: The paramaterized constructor for this class
	Parameters: takes a name and an address
	Returns: n/a
	Pre-conditions:
	Post-conditions: Initializes fields to the values passed in
	-------------------------
	*/
	Person(string passedName, string passedAddr);

	/*Function Prologue -----
	Purpose: A function to grab the persons name without changing it
	Parameters: Takes none
	Returns: The sting value of the persons name
	Pre-conditions: 
	Post-conditions: The value of ther person's name is stored in the return
	-------------------------
	*/
	string getName() const;

	/*Function Prologue -----
	Purpose: A function to grab the address without changing it
	Parameters: Takes none
	Returns: The string value of the address
	Pre-conditions:
	Post-conditions: The value of the address is stored in the return
	-------------------------
	*/
	string getAddress() const;

	/*Function Prologue -----
	Purpose: To read data in from a file to create a person object
	Parameters: takes the input file stream by reference
	Returns: a person object
	Pre-conditions: ?
	Post-conditions: Creates a new person object and promices not to change the data
	-------------------------
	*/
	void readData(ifstream& reader);

	/*Function Prologue -----
	Purpose: to write out a person object to a file
	Parameters: takes the output file stream by reference
	Returns: a bool (t or f) -- I am hoping this will help with error checking
	Pre-conditions: ?
	Post-conditions: if it can write to a file, it will return true and be happy
	-------------------------
	*/
	void writeData(ofstream& writer);
};