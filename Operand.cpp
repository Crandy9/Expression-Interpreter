//body of subclass Operand member function
#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h";
#include "OrOp.h"
#include "AndOp.h"
#include "EqualTo.h"
#include "GreaterThan.h"
#include "LessThan.h"
#include "NotOp.h"
#include "Conditional.h"
//includes the utility function parseName 
#include "parse.h"

Expression* Operand::parse(stringstream& myStringStream)
{
	char paren;
	int value;

	//ignores or gets rid of whitespace
	myStringStream >> ws;

	//if the next token is a a decimal digit character, set value to that digit
	//peek function looks at the next character without operating on it
	if (isdigit(myStringStream.peek()))
	{
		myStringStream >> value;
		Expression* literal = new Literal(value);
		return literal;
	}

	//else if the next token is a left side parenthesis, add it to the paren variable and go to the next token
	if (myStringStream.peek() == '(')
	{
		myStringStream >> paren;
		return SubExpression::parse(myStringStream);
	}

	else
		//else if the next token is neither a digit nor a left side parenthesis, it must be a variable
		//argument is the result of parseName method found in parse.cpp
		return new Variable(parseName(myStringStream));
	return 0;
}