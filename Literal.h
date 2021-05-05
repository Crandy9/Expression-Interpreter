//The other subclass of Operand is Literal, which defines leaf nodes of the tree that contain literal values. 
#pragma once
class Literal : public Operand
{
public:
	Literal(int value)
	{
		this->value = value;
	}
	int evaluate()
	{
		return value;
	}
private:
		int value;
};