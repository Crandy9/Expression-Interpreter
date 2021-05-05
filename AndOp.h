#pragma once
#include "SubExpression.h"
//because the bodies of both member functions are inline, no corresponding .cpp file is required
class AndOp : public SubExpression
{
public:

	AndOp(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() && right->evaluate();
	}
};