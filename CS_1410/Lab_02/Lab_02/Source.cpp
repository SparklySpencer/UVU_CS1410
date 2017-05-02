/* File Prolog
Name: Spencer Carter
Assignment: Lab 02
Class: CS 1410 Section 003
Date: 09/03/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

/* Psudocode
Declares a vector of doubles.
Declares an array big enough to hold 5 doubles.
Write a loop that prompts the user to enter in a decimal value, and uses the push_back function to add each number to the vector. Get and save 5 values.
Write a loop that copies each element of the vector into the array.
Write a function that sums the elements in the array. Pass the array as a parameter to the function.
Print the sum accurate to 2 decimal places.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Function Prologue -----
Purpose: to take an array, add the sum, and print out the values
Parameters: Takes a const double array
Returns: Void
Pre-conditions: none
Post-conditions: none
-------------------------
*/
void sumAndPrintArray(const double dValues[], int count);

const int PERCISION = 2;
const int ARRAY_SIZE = 5;
const int IGNORE_VALUE = 256;
const double MAX_VALUE = 1000000.00;
const double  MIN_VALUE = -1000000.00;

/*Function Prologue -----
Purpose: the default function in a c++ application
Parameters: Takes None
Returns: Void
Pre-conditions: ?
Post-conditions: ?
-------------------------
*/
void main()
{
	cout << "Spencer Carter, Lab 02, CS 1410 Sec 03" << endl; //Required for all assignments in this course
	vector <double> decimalVector; //Step 1: declare vector that holds doubles
	double decimalArray[ARRAY_SIZE]; //Step 2: delare an array that holds 5 doubles
	int count = 0; //always initialize variables (may or may not be needed)
	do
	{
		double userinput = 0.0; // Always initialize variables
		cout << "\nPlease enter a double value no less than -1M and no greater than 1M: "; //give instructions with limitations
		while ((!(cin >> userinput)) || userinput < MIN_VALUE || userinput > MAX_VALUE) //test for limitations
		{
			cout << "Invalid entry!\tEner a double between -1M - 1M: "; //restate what I am looking for
			cin.clear(); //clear the error flag
			cin.ignore(IGNORE_VALUE, '\n'); //get rid of the garbage the user entered
			userinput = 0.0; // reset the input
		}//End while loop
		decimalVector.push_back(userinput); //on good input, add the input to the vector
		count++; //increment count to prevent infinant loop
	} while (count < ARRAY_SIZE); //count being an index value, and ARRAY_SIZE being the limiting factor.
	for (unsigned int i = 0; i < decimalVector.size(); i++)//Step 4: copy the vector inputs into the array.
	{
		decimalArray[i] = decimalVector[i]; //indexes matching, it will coppy directly (assuming the array is the same size, which I limited prior).
	}//End for loop
	sumAndPrintArray(decimalArray, count); //Step 5: call sum function, and print to two decimal places
	system("pause");
}//End main()

void sumAndPrintArray(const double dValues[], int count)
{
	double sum = 0; //always initialize
	for (unsigned int i = 0; i < count; i++) //since we took the array in this assignment I decided to use the size to limit how far it could go
	{
		sum += dValues[i]; //+ = adds each element to sum
	}
	cout.precision(PERCISION); // aka 2
	cout << "\nThe sum of your inputs is: " << fixed << sum << endl;
}