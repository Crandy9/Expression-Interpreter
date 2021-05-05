//defines leaf nodes of the tree that contains variables
#pragma once
class Variable : public Operand
{
public:
    Variable(string name)
    {
        this->name = name;
    }
    int evaluate();
private:
    string name;
};