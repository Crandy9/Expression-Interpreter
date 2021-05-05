#pragma once
#include "SubExpression.h"

class Multiply : public SubExpression
{
public:
	Multiply(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() * right->evaluate();
	}
};