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

#include "Rectangle.h"

Rectangle::Rectangle()
{
	height = 0;
	width = 0;
}

Rectangle::Rectangle(int h, int w)
{
	height = h;
	width = w;
}

int Rectangle::getHeight() const
{
	return height;
}

int Rectangle::getWidth() const
{
	return width;
}

int Rectangle::getArea() const
{
	return (height * width);
}
