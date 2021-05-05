//bodies of member functions of SubExpression class (SubExpression.h)
#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "GreaterThan.h"
#include "LessThan.h"
#include "EqualTo.h"
#include "AndOp.h"
#include "NotOp.h"
#include "OrOp.h"
#include "Conditional.h"


char operation, paren;

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}


//myStringStream parameter holds the next character to be parsed
//should be a variable, left side parenthesis or an int
Expression* SubExpression::parse(stringstream& myStringStream)
{

	char operation, paren;

	Expression* leftOperand;
	Expression* rightOperand;
	Expression* conditionalOperand;

	leftOperand = Operand::parse(myStringStream);
	myStringStream >> operation;


	//check if operation char is conditional :
	//if so, follow this grammar '(' <operand> ':' <operand> '?' <operand> ')'
	if (operation == ':')
	{
		//next is the right operand
		rightOperand = Operand::parse(myStringStream);

		//get next token
		myStringStream >> paren;

		//next should be Conditional 
		conditionalOperand = Operand::parse(myStringStream);

		//next token
		myStringStream >> paren;
		return new Conditional(leftOperand, rightOperand, conditionalOperand);
	}

	rightOperand = Operand::parse(myStringStream);
	myStringStream >> paren;

	switch (operation)
	{
	case '+':
		return new Plus(leftOperand, rightOperand);
	case '-':
		return new Minus(leftOperand, rightOperand);
	case '*':
		return new Multiply(leftOperand, rightOperand);
	case '/':
		return new Divide(leftOperand, rightOperand);
	case '>':
		return new GreaterThan(leftOperand, rightOperand);
	case '<':
		return new LessThan(leftOperand, rightOperand);
	case '=':
		return new EqualTo(leftOperand, rightOperand);
	case '&':
		return new AndOp(leftOperand, rightOperand);
	case '|':
		return new OrOp(leftOperand, rightOperand);
	case '!':
		return new NotOp(leftOperand, rightOperand);
	}
	return 0;
}