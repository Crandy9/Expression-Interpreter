//this interpreter uses a symbol table that is implemented with an unsorted list defined by this class
class SymbolTable
{
public:
	SymbolTable() 
	{
		//in-line function
	}
	void insert(string variable, int value);

	int lookUp(string variable) const;
	void reset();

private:
	struct Symbol
	{
		Symbol(string variable, int value)
		{
			this->variable = variable;
			this->value = value;
		}
		string variable;
		int value;
	};
	vector <Symbol> elements;
};
