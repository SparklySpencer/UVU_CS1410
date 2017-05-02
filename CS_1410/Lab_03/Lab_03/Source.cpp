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

#include <iostream>
#include <string>

using namespace std;

#include "Rectangle.h"

void main()
{
	cout << "Spencer Carter, Lab 03, CS 1410 Sec 03" << endl; //Required for all assignments in this course
	const int h2 = 4;
	const int w2 = 7;
	Rectangle r2(h2, w2);
	cout << "The height of the rectangle is: " << r2.getHeight() << endl;
	cout << "The width of the rectangle is: " << r2.getWidth() << endl;
	cout << "The area of the rectangle is: " << r2.getArea() << endl;
	system("pause");
}