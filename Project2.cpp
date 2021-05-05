/*
Project2.cpp : This file contains the 'main' function. Reads in an input.txt file
the main function reads in the.txt file,
calls the static function parse() of the SubExpression class to parse it
and builds an arithmetic tree.
it then calls subordinate function parseAssignments() to parse the assignmnets and
enters them into the symbol table; finally, it evaluates expression and displays result
Author: Linden Crandall
Class: CMSC 330 Advanced Programming languages
Date: May 12, 2021
Professor: Vladimir Gubanov
*/

//including all of the needed headers/source headers
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

//function definition. Implementation below after main function
void parseAssignments(stringstream& myStringStream);
//SymbolTable object
SymbolTable symbolTable;

int main()

{ 
	string getFile;
	cout << "Enter .txt file name (Example: TestCase4.txt)" << endl << "Ensure that .txt file path is located in Project directory" << endl;
	cin >> getFile;
	cout<< endl;
	//reading data from file
	ifstream myFile(getFile);

	//if file is not found close the program and check file path
	if (!myFile.is_open())
	{
		cout << "File not found. Check file name and/or file path and re-execute program" << endl;
		exit(EXIT_FAILURE);
	}


	char parenthesis, comma;

	//this string is going to hold the .txt contents
	string fileString;

	//while file still has items to be read
	//gets line from .txt file myFile into the string fileString
	//can also add delimitters as a third parameter that will read up
	//to that delimitter i.e. ':'
	while (getline(myFile, fileString))
	{

		//stringstream allows a string to be treated as a stream
		//this allows extraction/insertion operations to be perfomed on the string
		//i.e. converting strings to int, double, etc.
		//first parameter is the string fileString, the second parameter ios::in 
		//is an openmode flag used for reading from a file
		stringstream myStream(fileString, ios::in);

		//the first token will be a left side parenthesis, so place that in the parenthesis variable to 
		//go on to the next token which should either be a literal or a variable or another left side parenthesis
		myStream >> parenthesis;

		//printing out the string from .txt file
		cout << "Expression: " << fileString << " " << endl;

		//pointer of type Expression
		//Expression is an abstract class and cannot be instantiated, so a work around is to use pointers
		Expression* expression = SubExpression::parse(myStream);
			
		myStream >> comma;

		parseAssignments(myStream);

		if (!myFile)
		{
			break;
		}
		//printing out evaluated expression
		cout << "Value = " << expression->evaluate() << endl;
		
		//reset symbolTable to accomodate same variable names
		symbolTable.reset();
	}

	//closing input
	myFile.close();
	return 0;
}

void parseAssignments(stringstream& myStringStream)
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName(myStringStream);
		myStringStream >> ws >> assignop >> value >> delimiter;

		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}