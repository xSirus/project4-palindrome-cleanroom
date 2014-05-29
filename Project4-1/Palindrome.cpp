#include "Palindrome.h"

Palindrome::Palindrome()
{
	data_from_file = "";
	temp = "";
	upper = lower = 1;
}

Palindrome::~Palindrome()
{
	clear();
}

void Palindrome::find_palindrome(string myString)
{
	if(myString.length() == 1)//check to see if there is only one char in the input
		longest_palindrome = myString[0];
	else
	{
		//this for loop goes through each character in the string (except the char in index 0)
		for(int i = 1; i <= myString.length(); i++)
		{
			upper = lower = i;
			//starting at the current character position from the forr loop, increment the upper and
			//decrement the lower until you reach the bounds in the while declaration.
			//once the bounds have been reached, set the new longest palindrome if necessary
			while(lower >= 0 && upper <= myString.length() && myString[lower] == myString[upper])
			{
				if(lower == upper)
					temp = myString[lower];
				else
					temp = myString.substr(lower, upper - lower + 1);
				if(longest_palindrome.length() < temp.length())
					longest_palindrome = temp;

				lower -= 1;
				upper += 1;
			}
		}
	}
}

void Palindrome::clear()
{
	data_from_file = "";
	temp = "";
	upper = lower = NULL;
}

void Palindrome::print()
{
	cout << "\nLongest palindrome is: " << longest_palindrome << "\nat " << longest_palindrome.length() << " characters.\n";
}