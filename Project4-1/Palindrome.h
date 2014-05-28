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
	int upper, lower, len;//i will increment and decrement these and compare the data as i go
	int counter;//to keep track of the line number being read in
	string data_from_file;
	string longest_palindrome, filename, myString;
	ifstream myStream;
public:
	//default constructor
	Palindrome();

	//destructor
	~Palindrome();

	//reads in the file form the console
	void read();

	//finds the longest palindrome in a sequence of characters
	void find_palindrome();

	//clears the private data
	void clear();

	//Prints the longest palindrome found
	void print();
};