#pragma once
#include "SubExpression.h"
//because the bodies of both member functions are inline, no corresponding .cpp file is required
class NotOp : public SubExpression
{
public:

	NotOp(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		// for negation, only left->evaluate() or right->evaluate()
		// is needed; both work correctly
		return !left->evaluate();
	}
};