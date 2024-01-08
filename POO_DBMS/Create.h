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
	char commandName[20] = "";

public:
	//Constructors
	Create();
	Create(string variant, string identifier, string condition, int noColumns, CreateParams* params, const char commandName[20]);
	Create(Create& c);

	//Setters
	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setNoColumns(int noColumns);
	void setParams(CreateParams* params, int noColumns);
	void setCondition(string condition);
	void setCommandName(const char[20]);

	//Getters
	string getVariant();
	string getIdentifier();
	string getCondition();
	int getNoColumns();
	CreateParams* getParams();
	const char getCommandName();

	//Methods
	void parseUserInput(string userInput);
	void displayAll();

	//Deconstructor
	~Create();

	//Overloads
	void operator=(Create& create);
	friend void operator<<(ostream& console, Create create);
	friend void operator>>(istream& console, Create create);
	//int operator[](int counter);
	//void operator+();
};