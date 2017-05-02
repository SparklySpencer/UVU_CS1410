/* File Prolog
Name: Spencer Carter
Assignment: Lab 03
Class: CS 1410 Section 003
Date: 09/10/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#pragma once
class Rectangle
{
private:
	int height;
	int width;

public:
	/*Function Prologue -----
	Purpose: The default constructor for this class
	Parameters: Takes none
	Returns: n/a
	Pre-conditions: 
	Post-conditions: Initializes the class variables to default values
	-------------------------
	*/
	Rectangle();

	/*Function Prologue -----
	Purpose: The paramaterized constructor for this class
	Parameters: takes in values for height and width to initalize the variables
	Returns: n/a
	Pre-conditions: 
	Post-conditions: Initializes the class variables to the paramaters
	-------------------------
	*/
	Rectangle(int h, int w);

	/*Function Prologue -----
	Purpose: A function to pass the height value
	Parameters: takes none
	Returns: the int value of the height
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	int getHeight() const;

	/*Function Prologue -----
	Purpose: A function to pass the width value
	Parameters: takes none
	Returns: the int value of the width
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	int getWidth() const;

	/*Function Prologue -----
	Purpose: a function to calculate the area of a rectangle
	Parameters: takes none
	Returns: the int value of the area
	Pre-conditions:
	Post-conditions:
	-------------------------
	*/
	int getArea() const;
};