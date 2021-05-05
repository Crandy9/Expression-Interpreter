#pragma once
#include "SubExpression.h"
//because the bodies of both member functions are inline, no corresponding .cpp file is required
class EqualTo : public SubExpression
{
public:

	EqualTo(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() == right->evaluate();
	}
};