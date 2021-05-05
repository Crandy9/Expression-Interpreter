#pragma once
//this class defines the node of the binary arithmetic expression tree
class SubExpression : public Expression
{
public:
	SubExpression(Expression* left, Expression* right);
	static Expression* parse(stringstream& myStringStream);

//these fields can only be accessed by derived classes (subclasses)
//public keyword may be used as well for this project
protected:
	Expression* left;
	Expression* right;
};

