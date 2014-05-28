#include "Palindrome.h"

Palindrome::Palindrome()
{
	data_from_file = "";
	len = 0;
	upper = lower = 1;
	counter = 0;
	cout << "Please enter the name of the file you would like to open\n(be sure it is in the same directory as the program): ";
	cin >> filename;
	myStream.open(filename);
}

Palindrome::~Palindrome()
{
	clear();
}

void Palindrome::read()
{
	if (!myStream) //verify a file was opened successfully, throw error if fail
		cout << "\nFile did not open. Please check the name and location of the file\n\n";
	else
	{	
		//initialize the max and min to the first data point
		while (myStream >> data_from_file)//read the rest of the file
			myString += data_from_file;//add the new char to the end of the string

		if (!myStream.eof()) //<---- if the flag is not the eof
		{
			cout << "\nThe data failed to read at line " << counter << ". ";
			cout << "Could be invalid data. \nCheck the data and try running the program again\n\n";
			system("PAUSE");
			exit (-1);
		}
	}	
}

void Palindrome::find_palindrome()
{
	//check if the data read in was only one char
	if(data_from_file.length == 1)
		longest_palindrome = myString;
	else//if more than one char
	{
		while(lower >= 0 && upper < myString.length && myString[lower] == myString[upper])
		{//increment upper and decrement lower
			lower -= 1;
			upper += 1;
			len++;
		}
		for(int i = lower; i < len; i++)
			longest_palindrome += myString[i];
	}
}

void Palindrome::clear()
{
	data_from_file = "";
	filename = "";
	upper = lower = NULL;
	counter = 0;
	myStream.close();
}

void Palindrome::print()
{
	cout << "Longest palindrome is: " << longest_palindrome << " at " << longest_palindrome.length << " characters.\n";
}