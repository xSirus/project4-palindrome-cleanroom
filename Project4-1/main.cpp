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
#include<string>
//#include<iostream>
//#include<iomanip>
#include<fstream>
const string YES = "y", NO = "n";

string yesNo, filename = "", data_from_file = "", myString = "";
ifstream myStream;

void clear();

int main()
{
	do
	{
		clear();
		Palindrome myPalidrome;

		cout << "Please enter the name of the file you would like to open\n(be sure it is in the same directory as the program): ";
		cin >> filename;
		myStream.open(filename);

		if (!myStream) //verify a file was opened successfully, throw error if fail
		cout << "\nFile did not open. Please check the name and location of the file\n\n";
		else
		{	
			//initialize the max and min to the first data point
			while (myStream >> data_from_file)//read the rest of the file
				myString += data_from_file;//add the new char to the end of the string

			myPalidrome.find_palindrome(myString);
			myPalidrome.print();
			myPalidrome.clear();

			if (!myStream.eof()) //<---- if the flag is not the eof
			{
				cout << "\nThe data failed to read at line " << myString.length() << ". ";
				cout << "Could be invalid data. \nCheck the data and try running the program again\n\n";
				system("PAUSE");
				exit (-1);
			}
		}	

		
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

	return 0;
}

// clear funciton
// resets the variables if the user wants to try more than one file
void clear()
{
	system("cls");
	filename = "";
	myStream.close();
	data_from_file = "";
	myString = "";
	yesNo = "";
}