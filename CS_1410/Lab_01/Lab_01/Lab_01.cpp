/* File Prolog
Name: Spencer Carter
Assignment: Lab #1
Class: CS 1410 Section 003
Date: 08/26/2015 & 01/05/16

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include "stdafx.h" //needed this damn thing or "Unexpected EOF while looking for precompiled header"
#include <iostream> //needed this damn thing to use cout and cin
#include <string> //needed this damn thing to make the << and >> work

using namespace std; //a namespace with tools to use for this project (like cout and cin)

void main() //the standard method that is prebuilt for our applications. I changed it to void, because int and return 0 did not make sense for this app.
{
	string userName = ""; //a var to store the name of the person
	cout << "Spencer Carter, Lab 06, CS 1410 Sec 03\n" << endl; //required for all assignments
	cout << "Hello, my name is Hal, what is your name?\n"; //a cute little intro message about our little assignment
	getline(cin, userName); //storing the name
	cout << "Welcome to C++ " << userName << ", let the adventure begin!\n"; //a cute little message to show that we can gather and use data
	system("PAUSE"); //Learned today in class to keep the console window open
}