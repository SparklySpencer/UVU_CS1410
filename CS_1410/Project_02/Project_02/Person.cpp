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

#include "Person.h"			// Person header file

Person::Person()
{
	name = "Spencer Carter";
	address = "1216 West 1250 South, Orem, Utah 84058, United States of America, North America, Earth";
}

Person::Person(string passedName, string passedAddr)
{
	if (!(passedName == "\n" || passedName == ""))
	{
		name = passedName;
	}
	else
	{
		throw Exceptions("\nYou did not enter any data for a Name");
	}
	if (!(passedAddr == "\n"|| passedAddr == ""))
	{
		address = passedAddr;
	}
	else
	{
		throw Exceptions("\nYou did not enter any data for an Address");
	}
	
}

string Person::getName() const
{
	return name;
}

string Person::getAddress() const
{
	return address;
}

void Person::readData(ifstream& reader)
{
	getline(reader, name);
	
	if (reader.fail())
	{
		throw Exceptions("Read Person: Name failed to read in.");
	}
	getline(reader, address);
	
	if (reader.fail())
	{
		throw Exceptions("Read Person: Address failed to read in.");
	}
	if (reader.eof())
	{
		throw Exceptions("You have reached End of File");
	}
}

void Person::writeData(ofstream& writer)
{
	writer << name << endl << address << endl;
}
