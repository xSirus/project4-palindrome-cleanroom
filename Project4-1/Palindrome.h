#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

const int ARRAY_SIZE = 1000;

class Palindrome
{
private:
	int upper, lower;//i will increment and decrement these and compare the data as i go
	string data_from_file, temp;
	string longest_palindrome;
	ifstream myStream;
public:
	//default constructor
	//initializes the data in the object
	Palindrome();

	//destructor
	//uses the clear function to destroy any data
	~Palindrome();

	//finds the longest palindrome in a sequence of characters
	//goes through each character of a string one by one to find the longest palindrome
	//parameters: a string is passed in containing the whole string that was input
	//returns: none
	void find_palindrome(string);

	//clear function
	//clears the private data
	void clear();

	//print function
	//Prints the longest palindrome found
	void print();
};