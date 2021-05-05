#pragma once
#include "Expression.h"
//defines the leaf nodes of the arithmetic expression tree
class Operand : public Expression
{
public:
	static Expression* parse(stringstream& myStringStream);
};

