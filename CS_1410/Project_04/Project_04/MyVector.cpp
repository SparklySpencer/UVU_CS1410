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

#include "MyVector.h"

MyVector::MyVector()
{
	/*	Purpose: A default constructor that creates a vector that is empty.
	Its size will be zero and its capacity will be two.
	Remember that size refers to the number of elements currently stored in the vector.*/
	_size = 0;
	_capacity = TWO;
	_dataPtr = new int [_capacity];
}

MyVector::MyVector(int n)
{
	/*	Purpose: A parameterized constructor that creates a vector of capacity n.
	Its size will initially be zero.*/
	if (n > 0) //Good data
	{
		_size = 0;
		_capacity = n;
		_dataPtr = new int[_capacity];
	}
	else //Bad data, just throw, no exception class in this assignment
	{
		throw n;
	}
}

MyVector::~MyVector()
{
	/*	Purpose: A destructor that deletes any dynamically allocated storage.
	The destructor should prevent your program from having memory leaks.*/
	if (_dataPtr != nullptr)
	{
		delete[] _dataPtr;
		_dataPtr = nullptr;
	}
}

int MyVector::size() const
{
	/*	Purpose: A function size( ) that returns the size of your vector.
	The size is defined as the number of integer values that have been stored in the vector.
	The size will change as integer values are added.*/
	return _size;
}

int MyVector::capacity() const
{
	/*	Purpose: A function capacity( ) that returns the capacity of the vector.
	The capacity is defined as the number of integer values that can be stored in the vector.
	The capacity changes when the vector grows.*/
	return _capacity;
}

void MyVector::clear() //Is this working right? Probably not
{
	/*	Purpose: A function clear( ) that deletes all of the elements from the vector and resets its size to zero and its capacity to two.*/
	if (_dataPtr != nullptr)
	{
		delete[] _dataPtr;
		_dataPtr = nullptr;
	}
	_size = 0;
	_capacity = TWO;
	_dataPtr = new int[_capacity];
}

void MyVector::push_back(int n)
{
	/*	Purpose: A function push_back(int n) that adds the integer value n to the end of the vector.
	If the vector is not large enough to hold this additional value, you must make the vector grow.
	Your grow algorithm should double the current capacity of the vector.
	Be sure to consider the special case when the vector is initially empty.*/
	if (_capacity > 0)
	{
		if (_size < _capacity)
		{
			_dataPtr[_size] = n; // this is not working, it is doing odd things
			// it shouls put the value of n in the address of the dataptr, but it putting junk there.
			_size++;
		}
		else
		{
			//grow: make new array x2 capacity, copy elements over, move pointer to new array, delete old array, add numer to new array
			_capacity = (_capacity * TWO);
			int* _tempPtr = new int[_capacity];
			for (int i = 0; i < _size; i++)
			{
				//copy from one arry to next
				_tempPtr[i] = _dataPtr[i];
			}
			//get rid of old array?
			delete[] _dataPtr;
			_dataPtr = nullptr;
			//move pointer to new array
			_dataPtr = _tempPtr;
			_tempPtr = nullptr;
			//add new number to array
			_dataPtr[_size] = n;
			_size++;
		}
	}
	else
	{
		//for now just throw it, and don't deal.
		throw _capacity;
	}
}

int MyVector::at(int n) const
{
	/*	Purpose: A function at(int n) that returns the value of the integer stored at index n of the vector.
	If the index outside the range of the vector (no element at that index), this function should throw an exception.
	Instead of creating an exception class for this case, just throw an integer value that represents the index parameter passed to the function.*/
	
	if (n >= 0 && n < _capacity) //only if the index is grater than 0 and less than the capacity (4, but index is 3)
	{
		return (_dataPtr[n]);
	}
	else
	{
		throw n;
	}
}