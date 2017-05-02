/* File Prolog
Name: Spencer Carter
Assignment: Project #1
Class: CS 1410 Section 003
Date: 08/29/2015

I declare that the following code was written by me, assisted with
by the lovely people in the drop in lab, and/or provided by the instructior
for this project. I understand that copying source code from any other
source constitutes cheating, and that I will recieve a zero on this
project if I am found in violation of this policy.
*/

#include <iostream>
#include <string>

using namespace std;

/*Function Prologue -----
Purpose: To ask the delivery speed in a menu system that is easily testable for errors
Parameters: takes none
Returns: an interger value that will be testable in the calcCost function
Pre-conditions: are reset to 0
Post-conditions: will either be a 1, 2, 3
-------------------------
*/
int askSpeed();

/*Function Prologue -----
Purpose: To ask the user where they are shipping it to in a menu system format that is easy to test for errors
Parameters: takes none
Returns: an interager value representative of that choice
Pre-conditions: reset to 0
Post-conditions: will either be a 1, 2, or 3
-------------------------
*/
int askPlace();

/*Function Prologue -----
Purpose: to ask the user how they will wish to pay for shipping per item or per weight
Parameters: takes none
Returns: an int so the calcCost function can determind how to calc the cost
Pre-conditions: reset to 0
Post-conditions: either a 1 or a 2
-------------------------
*/
int askMethod();

/*Function Prologue -----
Purpose: to be called on to validate a correct input for number of items (positive whole number > 0)
Parameters: takes none
Returns: an interager representative of the number of items the user is shipping
Pre-conditions: reset to 0
Post-conditions: correct user input
-------------------------
*/
int testItems();

/*Function Prologue -----
Purpose: to allow the user to enter a correct weight for their package/s (a positive number > 0)
Parameters: takes none
Returns: the users desired input
Pre-conditions: reset to 0.0
Post-conditions: the users desired weight
-------------------------
*/
double testWeight();

/*Function Prologue -----
Purpose: to take all the user inputs and calculate a cost
Parameters: takes the speed desired, the place its going to, and via which payment method they hace chosen
Returns: a double, representative of the dollar amount needed to be paid
Pre-conditions: both the package and surcharge are reset to 0.0
Post-conditions: returns a decimal value to be displayed in main
-------------------------
*/
double calcCost(int method, int place, int speed);

//Constants:
const int IGNORE_VALUE = 256; //For cin.ignore(256, '/n')
const int MAX_ITEMS = 1000000; //Good Practice it to set limits on what the user can enter
const double MAX_POUNDS = 1000000.00; //More limits for what the user can enter.
const double STAND_ITEMS = 3.00;
const double STAND_WEIGHT = 1.45;
const double STAND_SURCHARGE = 2.50;
const double EXPRE_ITEMS = 4.00;
const double EXPRE_WEIGHT = STAND_SURCHARGE; // $2.50 per lb
const double EXPRE_SURCHARGE = 5.00;
const double SAMED_ITEM = 5.50;
const double SAMED_WEIGHT = STAND_ITEMS; // $3.00 per lb
const double SAMED_SURCHARGE = 8.00;
const int MENU_OPTION_1 = 1; //For a menu system, switch statment, and to replace magic numbers
const int MENU_OPTION_2 = 2; //For a menu system, switch statment, and to replace magic numbers
const int MENU_OPTION_3 = 3; //For a menu system, switch statment, and to replace magic numbers

/* Psudocode Steps
							 -----Introduce the user to the program.
							 Ask the user if they want to ship a parcel.
							 Accept either "y" or "n" as input. If an invalid response is given, keep asking until you get a valid response.
							 Ask the user how they want the parcel shipped (standard, express, or same day).
							 Get the input and validate it. If an invalid response is given, keep asking until you get a valid response.
							 Ask the user if the parcel is being sent to Hawaii or Alaska.
							 Get the user's response. If an invalid response is given, keep asking until you get a valid response.
							 Ask the user to tell you if they want to ship by weight, or by number of items in the shipment.
							 Get the user's response. If an invalid response is given, keep asking until you get a valid response.
							 If the user elects to ship by weight, ask for the weight of the parcel.
							 Keep asking until the user enters positive non-zero value.
							 If the user elects to ship by number of items, ask for the number of items in the shipment.
							 Keep asking until the user enters positive non-zero value.
							 Based on the user's input, calculate the correct shipping cost and display the answer.
							 Ask the user if they want to ship another parcel.
							 Accept either "y" or "n" as input. Validate the input and re-do this step if the input is not valid.
							 If the user selects "y" start back at step 4. If the user selects "n" quit.
							 */

/*Function Prologue -----
Purpose: This function will serve as a menu system to guide the user through the shipping program, and will house the main loop that asks if the user wants to try again
Parameters: Takes none
Returns: Void
Pre-conditions: ?
Post-conditions: ?
-------------------------
*/
void main()
{
	cout << "Spencer Carter, Project 01, CS 1410 Sec 03" << endl;
	cout << "\nWelcome to Red Fern Shipping!" << endl;
	int menuSelection = 0; //Always initialize values
	do
	{
		cout << "\nWould you like to ship a parcel?\nPlease make a selection:\n\t1) Yes\n\t2) No\n\t\tEnter the selection number: ";
		while ((!(cin >> menuSelection)) || menuSelection < MENU_OPTION_1 || menuSelection > MENU_OPTION_2) //tests for strings, lower, and higher than I am looking for
		{
			cout << "Invaid menu selection!\tEnter selection: ";
			cin.clear();
			cin.ignore(IGNORE_VALUE, '\n');
		}//End nested while
		switch (menuSelection)
		{
		case MENU_OPTION_1: //Yes
			cout.precision(MENU_OPTION_2); // aka 2
			cout << '$' << fixed << calcCost(askMethod(), askPlace(), askSpeed()) << '\n' << endl; //do all the work in 1 go ;)
			system("pause");
			break;
		case MENU_OPTION_2: //No
			cout << "\nGoodbye :D\n" << endl;
			system("pause");
			return;
		}//End switch
	} while (true); //End doWhile
}//End main()

int askSpeed()
{
	int shipSpeed = 0; //Always initalize values
	while (shipSpeed == 0)
	{
		cout << "\nHow fast would you like your parcel delivered?\nPlease make a selection:\n\t1) Same Day\n\t2) Express\n\t3) Standard\n\t\tEnter the selection number: ";
		while ((!(cin >> shipSpeed)) || shipSpeed < MENU_OPTION_1 || shipSpeed > MENU_OPTION_3) //tests for strings, lower, and higher than I am looking for
		{
			cout << "Invaid menu selection!\tEnter selection: ";
			cin.clear();
			cin.ignore(IGNORE_VALUE, '\n');
			shipSpeed = 0; //To make sure the previous while loop is working correctly, reset shipspeed back to 0
		}//End nested while
		switch (shipSpeed)
		{
		case MENU_OPTION_1: //Same Day
			return shipSpeed;
		case MENU_OPTION_2: //Express
			return shipSpeed;
		case MENU_OPTION_3: //Standard
			return shipSpeed;
		}//End switch
	}//End while
}//End askSpeed()

int askPlace()
{
	int deliveryPlace = 0; //Always initalize values
	while (deliveryPlace == 0)
	{
		cout << "\nWhere would you like your parcel delivered?\nPlease make a selection:\n\t1) Continental USA\n\t2) Alaska\n\t3) Hawaii\n\t\tEnter the selection number: ";
		while ((!(cin >> deliveryPlace)) || deliveryPlace < MENU_OPTION_1 || deliveryPlace > MENU_OPTION_3) //tests for strings, lower, and higher than I am looking for
		{
			cout << "Invaid menu selection!\tEnter selection: ";
			cin.clear();
			cin.ignore(IGNORE_VALUE, '\n');
			deliveryPlace = 0; //To make sure the previous while loop is working correctly, reset deliveryPlace back to 0
		}//End nested wWhile
		switch (deliveryPlace)
		{
		case MENU_OPTION_1: //USA
			return deliveryPlace;
		case MENU_OPTION_2: //AK
			return deliveryPlace;
		case MENU_OPTION_3: //HW
			return deliveryPlace;
		}//End switch
	}//End while
}//End askPlace()

int askMethod()
{
	int itemVsLbs = 0; //Always initalize values
	while (itemVsLbs == 0)
	{
		cout << "\nWhich rate would you like to pay?\nPlease make a selection:\n\t1) Pay per Item\n\t2) Pay per Weight\n\t\tEnter the selection number: ";
		while ((!(cin >> itemVsLbs)) || itemVsLbs < MENU_OPTION_1 || itemVsLbs > MENU_OPTION_2) //tests for strings, lower, and higher than I am looking for
		{
			cout << "Invaid menu selection!\tEnter selection: ";
			cin.clear();
			cin.ignore(IGNORE_VALUE, '\n');
			itemVsLbs = 0; //To make sure the previous while loop is working correctly, reset itemVsLbs back to 0
		}//End nested wWhile
		switch (itemVsLbs)
		{
		case MENU_OPTION_1: //Per Item
			return itemVsLbs;
		case MENU_OPTION_2: //Per pound
			return itemVsLbs;
		}//End switch
	}//End while
}//End askMethod()

int testItems()
{
	int userinput = 0; // Always initialize variables
	cout << "\nWe cannot ship more than a million items, please enter the number of items you wish to ship: ";
	while ((!(cin >> userinput)) || userinput < 0 || userinput > MAX_ITEMS)
	{
		cout << "Invalid entry!\tEner Items: ";
		cin.clear();
		cin.ignore(IGNORE_VALUE, '\n');
		userinput = 0;
	}
	return userinput;
}//End testItems()

double testWeight()
{
	double userinput = 0.0; //Always initialize values
	cout << "\nWe cannot ship more than a million pounds, please enter the package's weight that you wish to ship: ";
	while ((!(cin >> userinput)) || userinput < 0 || userinput > MAX_POUNDS)
	{
		cout << "Invalid entry!\tEner Weight: ";
		cin.clear();
		cin.ignore(IGNORE_VALUE, '\n');
		userinput = 0;
	}
	return userinput;
}//End testWeigt()

double calcCost(int method, int place, int speed)
{
	double surcharge = 0.0;
	double package = 0.0;
	if (speed == MENU_OPTION_1) //Same Day
	{
		if (place == MENU_OPTION_2 || place == MENU_OPTION_3) //AK or HW
		{
			surcharge = SAMED_SURCHARGE;
		}
		if (method == MENU_OPTION_1)
		{
			package = (testItems() * SAMED_ITEM);
		}
		else if (method == MENU_OPTION_2)
		{
			package = (testWeight() * SAMED_WEIGHT);
		}
	}//End Same Day
	else if (speed == MENU_OPTION_2) //Express
	{
		if (place == MENU_OPTION_2 || place == MENU_OPTION_3) //AK or HW
		{
			surcharge = EXPRE_SURCHARGE;
		}
		if (method == MENU_OPTION_1)
		{
			package = (testItems() * EXPRE_ITEMS);
		}
		else if (method == MENU_OPTION_2)
		{
			package = (testWeight() * EXPRE_WEIGHT);
		}
	}//End Express
	else if (speed == MENU_OPTION_3) //Standard
	{
		if (place == MENU_OPTION_2 || place == MENU_OPTION_3) //AK or HW
		{
			surcharge = STAND_SURCHARGE;
		}
		if (method == MENU_OPTION_1)
		{
			package = (testItems() * STAND_ITEMS);
		}
		else if (method == MENU_OPTION_2)
		{
			package = (testWeight() * STAND_WEIGHT);
		}
	}//End Standard
	return (package + surcharge); //The total cost for the package
}//End calcCost();