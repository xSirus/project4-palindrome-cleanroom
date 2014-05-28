// Joel Harrison
// Project 4-1: Palindrome using Cleanroom approach
// 5/28/2014

// requirements for palindrome
/*
find longest palindrome in a sequence of letters
prompt for a file
read the file
output the longest palindrome found

palindrome will be odd in length
all uppercase
less than 1000 characters
text may be on multiple lines - treat them as one long sequence (ignore newlines and carriage returns
*/

// important cleanroom items
/*
design, design, design
do not compile until I am confident in my code
test the code and fix errors
they should be very simple errors
there should be very few errors, preferrably none
*/

#include "Palindrome.h"
const string YES = "y", NO = "n";

int main()
{
	string yesNo = "";
	do
	{
		yesNo = "";
		Palindrome myPalidrome;
		myPalidrome.find_palindrome();
		myPalidrome.print();
		myPalidrome.clear();
		// see if user wants to read in another text file
		cout << "\n\nWould you like to try another text file? (y or n): ";
		cin >> yesNo;
		if ((yesNo != NO)&&(yesNo != YES))
		{//check for correct input
			do
			{//keep asking for valid input until valid input is entered
				cout << "\nYou entered a wrong character.  Please enter 'y' for yes, or 'n' for no: ";
				cin >> yesNo;
			}while((yesNo != NO)&&(yesNo != YES));
		}
	}while(yesNo == YES);

	cout << "Press the \"ANY\" key to continue...";
	cin.get();
	return 0;
}