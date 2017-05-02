#pragma once
#include <string>

using namespace std;

//should inclue a max valuw to test for

class Exception
{
private:
	int e;

public:
	/*Function Prologue -----
	Purpose: the parameterized constructor
	Parameters: user bs that is no good
	Returns: nothing
	Pre-conditions: non-existant
	Post-conditions: private data initalized to bs
	-------------------------
	*/
	Exception(int ex);
	/*Function Prologue -----
	Purpose: to display the bs data to the user
	Parameters: none
	Returns: the int value of the bs data
	Pre-conditions: none
	Post-conditions: none
	-------------------------
	*/
	int GetExcetion() const;
};

