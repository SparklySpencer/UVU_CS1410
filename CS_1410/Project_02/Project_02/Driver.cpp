/* File Prolog
Name: Spencer Carter
Assignment: Project 02-03
Class: CS 1410 Section 003
Date: 10/13/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include "Driver.h";			// Driver header file

void main()
{
	cout << "Spencer Carter, Project 03, CS 1410 Sec 03" << endl; //Required for all assignments in this course
	//Project 02 -- Step 01) Create an empty vector of Account objects.
	std::vector<Account> _stuffToTry;
	
	//Project 02 -- Step 02) Create three person objects.
	//Project 03 -- Step 01) Create three person objects.
	Person _defaultPerson01(_name01, _addr01);
	Person _defaultPerson02(_name02, _addr02);
	Person _defaultPerson03(_name03, _addr03);

	//Project 02 -- Step 03) Create three Account objects, where each account object contains one of your Person objects.
	//Project 03 -- Step 02) Create three Account object with the required ballances.
	Account _defaultAccount01(_defaultPerson01, _acct01, _ball01);
	Account _defaultAccount02(_defaultPerson02, _acct02, _ball02);
	Account _defaultAccount03(_defaultPerson03, _acct03, _ball03);

	//Project 02 -- Step 04) Push these Account objects into the vector.
	//Project 03 -- Step 03) Push these Account objects into the vector
	_stuffToTry.push_back(_defaultAccount01);
	_stuffToTry.push_back(_defaultAccount02);
	_stuffToTry.push_back(_defaultAccount03);

	//Project 03 -- Step 04) Create an ofstream object and open a file.
	// Hard code the file name in your program.
	// Pass the file name as the parameter to the open function of your ofstream object so that your program assumes the file to be in the same folder as your executable file.
	ofstream _fileToOpen;
	const string fileName = "testExample.txt";
	_fileToOpen.open(fileName);
	cout << "\nCreating File: " << fileName << endl;


	//Project 03 -- Step 05) using a loop, send messages to each of the three Account objects to write themselves out to the file.
	for (int i = 0; i < _stuffToTry.size(); i++)
	{
		_stuffToTry[i].writeData(_fileToOpen);
	}
	cout << "Writing data to file" << endl;


	//Project 03 -- Step 06) Close the file.
	_fileToOpen.close();
	cout << "Closing file" << endl;


	//Project 03 -- Step 07) Clear the vector.
	_stuffToTry.clear();

	//Project 03 -- Step 08) Open the file that you just saved.
	ifstream _fileToRead;
	_fileToRead.open(fileName);
	cout << "Opening file" << endl;

	if (_fileToRead.fail())
	{
		cout << "There was an issue opening, sorry..." << endl;
		system("pause");
		return;
	}

	//Project 03 -- Step 09) Create a loop that does the following:
	//Project 03 -- Step 10) creates an account object
	//Project 03 -- Step 11) asks the object to read itself in
	//Project 03 -- Step 12) if the read works, push object into the vector
	//Project 03 -- Step 13) if read fails, output error message
	//Project 03 -- Step 14) the loop runs until eof is discovered

	try
	{
		cout << "Trying to read file..." << endl;
		while (_fileToRead)
		{
			Account temp;
			temp.readData(_fileToRead);
			_stuffToTry.push_back(temp);
		}
	}
	catch (Exceptions e)
	{
		cout.precision(TWO);
		cout << e.getMsg() << endl;
	}

	//Project 02 -- Step 05) Using a for loop, add $25.00 to each account.
	//Project 03 -- Step 15) Using another loop, add $25.00 to each account.
	cout << "\nTry depositing $25.00 to each account..." << endl;
	const double testDeposit = 25.00;
	for (int i = 0; i < (_stuffToTry.size()); i++)
	{
		try
		{
			_stuffToTry[i].makeDeposit(testDeposit);
		}
		catch (Exceptions e)
		{
			cout.precision(TWO);
			cout << e.getMsg() << endl;
		}
	}//end for

	//Project 02 -- Step 06) Using a second for loop, withdraw $100.00 from each account.
	//Project 03 -- Step 16) Using another loop, withdraw $100.00 from each account.
	cout << "\nTry withdrawing $100.00 from each accout..." << endl;
	//const
	double testWithdraw = 100.00;
	for (int i = 0; i < (_stuffToTry.size()); i++)
	{
		try
		{
			_stuffToTry[i].makeWithdraw(testWithdraw);
		}
		catch (Exceptions e)
		{
			cout.precision(TWO);
			cout << fixed << e.getMsg() << endl;
		}
	}//end for

	//Project 02 -- Step 07) Finally, pass the vector to your displayAccounts function to display the account information for each Account object in the vector.
	//Project 03 -- Step 17) Finally, pass the vector to your displayAccounts() function to display the account information for each Account object in the vector.
	Driver _go; //a nonstatic member reference must be relative to a specific object
	_go.displayAccounts(_stuffToTry);

	//Finished: all Programs must pause.
	system("pause");
}//end main()

void Driver::displayAccounts(const vector<Account>& todisplay)
{
	cout.precision(TWO);
	cout << "\nAccount\t\tName\t\tAddress\t\t\tBallance" << endl;
	for (int i = 0; i < (todisplay.size()); i++)
	{
		cout << todisplay[i].getActNumber() << "\t\t" << todisplay[i].getPerson().getName() << "\t" << todisplay[i].getPerson().getAddress() << "\t\t" << "$" << fixed << todisplay[i].getBallance() << endl;
	}
	cout << endl; //add another line for better readability
}//end displayAccounts()
