/* File Prolog
Name: Spencer Carter
Assignment: Lab 07
Class: CS 1410 Section 003
Date: 10/15/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#pragma once
class MyVector
{
private:
	int* data;
	int size;
	int capacity;

public:
	/*Function Prologue -----
	Purpose: A default constructor that creates a vector that is empty.
	Its size will be zero and its capacity will be two.
	Remember that size refers to the number of elements currently stored in the vector.
	Parameters: Default constructor, takes none
	Returns: Constructors do not return
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	MyVector();

	/*Function Prologue -----
	Purpose: A parameterized constructor that creates a vector of capacity n.
	Its size will initially be zero.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	MyVector(int);

	/*Function Prologue -----
	Purpose: A destructor that deletes any dynamically allocated storage.
	The destructor should prevent your program from having memory leaks.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	~MyVector();

	/*Function Prologue -----
	Purpose: A function size( ) that returns the size of your vector.
	The size is defined as the number of integer values that have been stored in the vector.
	The size will change as integer values are added.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	int size() const;

	/*Function Prologue -----
	Purpose: A function capacity( ) that returns the capacity of the vector.
	The capacity is defined as the number of integer values that can be stored in the vector.
	The capacity changes when the vector grows.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	int capacity() const;

	/*Function Prologue -----
	Purpose: A function clear( ) that deletes all of the elements from the vector and resets its size to zero and its capacity to two.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	void clear();

	/*Function Prologue -----
	Purpose: A function push_back(int n) that adds the integer value n to the end of the vector.
	If the vector is not large enough to hold this additional value, you must make the vector grow.
	Your grow algorithm should double the current capacity of the vector.
	Be sure to consider the special case when the vector is initially empty.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	void push_back(int n);

	/*Function Prologue -----
	Purpose: A function at(int n) that returns the value of the integer stored at index n of the vector.
	If the index outside the range of the vector (no element at that index), this function should throw an exception.
	Instead of creating an exception class for this case, just throw an integer value that represents the index parameter passed to the function.
	Parameters:
	Returns:
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	int at(int) const;
};