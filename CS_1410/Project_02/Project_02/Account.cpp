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

#include "Account.h"			// Account header file

Account::Account()
{
	owner = Person::Person(); //set the default person object to the default constructor's info.
	const int START_ACT = 7736237; //NoMagicThings
	actNumber = START_ACT;
	ballance = 0;
}

Account::Account(const Person& passedOwner, int passedNumber, double passedBallance)
{

	if (passedBallance < 0)
	{
		throw Exceptions(("\n$" + to_string(passedBallance) + ", is not an acceptable starting ballance."));
	}
	else
	{
		owner = passedOwner;
		actNumber = passedNumber;
		ballance = passedBallance;
	}
}

Person Account::getPerson() const
{
	return owner;
}

int Account::getActNumber() const
{
	return actNumber;
}

double Account::getBallance() const
{
	return ballance;
}

void Account::makeDeposit(double deposit)
{
	if (deposit > 0) //Prevents negative deposits
	{
		cout.precision(TWO);
		ballance += deposit;
		cout << "Added the following to your account: $" << fixed << deposit << " Your new ballance is: $" << fixed << ballance << endl;
	}
	else
	{
		throw Exceptions(("\n$" + to_string(deposit) + ", You may not withdraw a negative or zero amount!"));
	}
}

double Account::makeWithdraw(double& withdrawl)
{
	if (withdrawl < ballance) //Prevents overdraw
	{
		cout.precision(TWO);
		ballance -= withdrawl;
		cout << "Withdrew the following from your account: $" << fixed << withdrawl << ". Your new ballance is: $" << fixed << ballance << endl;
	}
	else
	{
		throw Exceptions(("A withdraw of $" + to_string(withdrawl) + " will exceed the available funds of: $" + to_string(ballance)));
	}
	return withdrawl;
}

void Account::readData(ifstream& reader)
{
	owner.readData(reader);
	reader >> actNumber;
	
	if (reader.fail())
	{
		throw Exceptions("Read Account: Account Number failed to read in.");
	}
	reader >> ballance;
	
	if (reader.fail())
	{
		throw Exceptions("Read Account: Account Balance failed to read in.");
	}
	if (reader.eof())
	{
		throw Exceptions("You have reached End of File.");
	}
	reader.ignore();
}

void Account::writeData(ofstream& writer)
{
	owner.writeData(writer);
	writer << actNumber << endl << ballance << endl;
}
