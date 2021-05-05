//the abstract class Expression is the root of the hierarchy for building expression tree
#pragma once
class Expression
{
public:
	//pure virtual function denoted by assigning value to 0
	virtual int evaluate() = 0;
};