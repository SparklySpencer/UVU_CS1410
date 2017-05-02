/* File Prolog
Name: Spencer Carter
Assignment: Lab 06
Class: CS 1410 Section 003
Date: 10/14/15

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include <iostream>			// std::cout
using namespace std;

/*Function Prologue -----
Purpose:
Parameters:
Returns:
Pre-conditions:
Post-conditions:
-------------------------
*/
void reverser(char*);

void main()
{
	cout << "Spencer Carter, Lab 06, CS 1410 Sec 03\n" << endl; //required for all assignments

	// declare a c-string to reverse
	char myString[] = "Hello world!";

	// call the reverser function
	reverser(myString);

	// output the result
	cout << myString << endl; // !dlrow olleH

	system("PAUSE");
}

/* Description:
In this program you will write a function that takes as its parameter a pointer to a C-string (a null terminated array of characters).
Your function will reverse the characters in the string.
You must reverse the characters in-line, that is, you cannot use another array while you do this work.
The function must be written so that it uses pointers only.
!!! --- No square brackets may be used inside of the function. --- !!!
*/
void reverser(char* cString)
{
	cout << cString << endl;
	cout << "Starting swap..." << endl << endl;
	// 1) Using a loop, determine the size of the string by counting characters until you encounter the null terminating character at the end of the string.
	int charCount = 0; // for the index value. When done should be 12
	char* tempPtr = cString; //just in case I want to use this later
	while (*tempPtr != '\0')       // loop till we find the null terminator
	{
		tempPtr++;
		charCount++;
	}

	// 2) Establish a pointer that points to the beginning character of the string.
	char* firstCharPtr = cString;

	// 3) Establish a pointer that points to the last character in the string, this is the character just before the null terminating character.
	char* lastCharPtr = tempPtr-1;

	// 6) Repeat this process until all of the characters have been swapped. The string should now be reversed.
	while (firstCharPtr < lastCharPtr)
	{
		// 4) Using the pointers, swap the first character in the string and the last character in the string.
		char swapChar = *firstCharPtr;
		*firstCharPtr = *lastCharPtr;
		*lastCharPtr = swapChar;

		// 5) Move the pointers so that the first pointer points to the 2nd character in the string and the second pointer points to the next to last character in the string. Swap these two characters.
		firstCharPtr++;
		lastCharPtr--;
	}
}