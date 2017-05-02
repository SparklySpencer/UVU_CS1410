/* File Prolog
Name: Spencer Carter
Assignment: Lab 04
Class: CS 1410 Section 003
Date: 09/18/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include <iostream>			// std::cout
#include <string>			// std::string, std::stod
#include <vector>
#include <fstream>			// reading and writing from a file

using namespace std;

/*Psudocode / Spec
1) Your program declares an array of double values. You will use this array to hold voltages. The array should hold up to 100 voltage values.
2) Your program should then open a file containing a set of voltage values. You can use the sample file below. Name the file "voltages.txt". Your program should work for any number of values in the file, up to 100. Your program should verify that the file opened successfully. Assume that the file is in the same folder as your executable.
3) Your program will now read the voltage values from the file and store them in the array. Test the state of the stream after each read operation to make sure that it worked. Keep reading until you reach the end of the file.
4) Calculate the average voltage value and display it.
*/

const int MAX_ASIZE = 100; //The spec says that there can only be 100 values passed into the array
ifstream _readMe; //Instanciate a stream object

void main()
{
	cout << "Spencer Carter, Lab 04, CS 1410 Sec 03\n" << endl; //Required for all assignments
	double _voltageArray[MAX_ASIZE]; // not sure if this is correct, but could not think of a way to set up a size that is based on something else
	double _sum = 0.0; //always initalize values
	int _count = 0; //always initalize values
	double _average = 0.0; //always initalize values
	_readMe.open("voltages.txt"); //Per spec, named as requested
	if (_readMe.fail()) //test to make sure the file exists
	{
		cout << "\nCould not open the file ... check to see if it exists" << endl;
		system("Pause");
		return;
	}//end if condition
	while (!(_readMe.eof()) && _voltageArray[_count] < MAX_ASIZE) //a test to make sure there is data to be read in the file
	{
		string stringText = ""; //temp var to hold the string value of the voltage
		getline(_readMe, stringText); //get line delimits on a return
		if (!(stringText == ""))
		{
			_voltageArray[_count] = std::stod(stringText); //found @ http://www.cplusplus.com/reference/string/stod/
			//This seems okay, but also failes to help when a naughty user decides to give me bad data.... I would like help here
			cout << "The following voltage was added to your calculation: " << _voltageArray[_count] << endl;
			_sum += _voltageArray[_count];
			_count++;
		}//end if
	}//end while ~ should read the file
	_readMe.close(); //always close the stream
	_average = _sum / _count;
	cout << "\nThe following is the average voltage: " << _average << endl;
	system("Pause"); //required for all assignments
}//end main()