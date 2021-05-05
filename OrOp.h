#pragma once
#include "SubExpression.h"
//because the bodies of both member functions are inline, no corresponding .cpp file is required
class OrOp : public SubExpression
{
public:

	OrOp(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() || right->evaluate();
	}
};