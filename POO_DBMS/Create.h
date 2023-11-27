#pragma once
#include <iostream>
#include "CreateParams.h"
using namespace std;



class Create {
	string variant;
	string identifier;
	string condition;
	int noColumns;
	CreateParams* params;

public:
	//Constructors
	Create();
	Create(string variant, string identifier, string condition, int noColumns, CreateParams* params);
	Create(Create& c);

	//Setters
	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setNoColumns(int noColumns);
	void setParams(CreateParams* params, int noColumns);
	void setCondition(string condition);

	//Getters
	string getVariant();
	string getIdentifier();
	string getCondition();
	int getNoColumns();
	CreateParams* getParams();

	//Methods
	void parseUserInput(string userInput);
	void displayAll();

	//Deconstructor
	~Create();

	//Overloads
	void operator=(Create& create);
	friend void operator<<(ostream& console, Create create);
	friend void operator>>(ifstream& console, Create create);
	CreateParams operator[](int counter);
	void operator+()
};