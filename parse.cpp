#include <cctype> 
#include <iostream> 
#include <sstream>
#include <string> 
using namespace std;

#include "parse.h"
string parseName(stringstream& myStringStream)
{
    char alnum;
    string name = "";

    myStringStream >> ws;

    //isalnum method is a very useful flag. It checks whether
    //the character is a decimal digit or an upper/lowercase letter character
    while (isalnum(myStringStream.peek()))
    {
        myStringStream >> alnum;

        //set sting to alnum character(s)
        name += alnum;
    }
    //go back to Operand.cpp
    return name;
}