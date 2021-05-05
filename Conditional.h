#pragma once
#include "SubExpression.h"
//because the bodies of both member functions are inline, no corresponding .cpp file is required
class Conditional : public SubExpression
{
public:

	Conditional(Expression* left, Expression* right, Expression* conditionalOperand) :
		SubExpression(left, right)
	{
		this->conditionalOperand = conditionalOperand;
	}
	int evaluate()
	{
		return conditionalOperand->evaluate() ? left->evaluate() : right->evaluate();
	}
private:
	Expression* conditionalOperand;
};