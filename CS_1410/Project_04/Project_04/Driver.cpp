/* File Prolog
Name: Spencer Carter
Assignment: Project 04
Class: CS 1410 Section 003
Date: 10/15/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include "Driver.h"			// the header file for this class

void main()
{
	cout << "Spencer Carter, Lab 07, CS 1410 Sec 03\n" << endl; //required for all assignments/

	// the following code was provided in the assignment description
	// Create a default vector 
	MyVector sam;
	// push some data into sam
	cout << "\nPushing three values into sam";
	sam.push_back(TEST_VALUE1);
	sam.push_back(TEST_VALUE2);
	sam.push_back(TEST_VALUE3);
	cout << "\nThe values in sam are: ";
	// test for out of bounds condition here
	// and test exception 
	for (int i = 0; i < sam.size() + 1; i++)
	{
		try
		{
			cout << sam.at(i) << " ";
		}
		catch (int badIndex)
		{
			cout << "\nOut of bounds at index " << badIndex << endl;
		}
	}
	cout << "\n--------------\n";
	// clear sam and display its size and capacity
	sam.clear();
	cout << "\nsam has been cleared.";
	cout << "\nSam's size is now " << sam.size();
	cout << "\nSam's capacity is now " << sam.capacity() << endl;
	cout << "---------------\n";
	// Push 12 values into the vector - it should grow
	cout << "\nPush 12 values into sam.";
	for (int i = 0; i < MAX; i++)
	{
		sam.push_back(i);
	}
	cout << "\nSam's size is now " << sam.size();
	cout << "\nSam's capcacity is now " << sam.capacity() << endl;
	cout << "---------------\n";
	cout << "\nTest to see if contents are correct...";
	// display the values in the vector
	for (int i = 0; i < sam.size(); i++)
	{
		cout << sam.at(i) << " ";
	}
	cout << "\n--------------\n";
	cout << "\n\nTest Complete..." << endl;

	system("Pause"); //required for all assignments
}