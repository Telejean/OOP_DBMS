#pragma once
#include <iostream>
#include "Table.h"
#include "Attribute.h"
using namespace std;



class Select {
	string variant;
	string identifier;
	int noParams;
	string* params;
	string conditionType;
	string conditionSpecifier;
	string conditionParam;

public:
	//Constructors
	Select();
	Select(string variant, string identifier, int noParams, string conditionType, string conditionSpecifier, string conditionParam, string* params);
	Select(Select& s);

	//Setters
	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setnoParams(int noParams);
	void setParams(string* params, int noParams);
	void setConditionType(string conditionType);
	void setConditionSpecifier(string conditionSpecifier);
	void setConditionParam(string conditionParam);

	//Getters
	string getVariant();
	string getIdentifier();
	int getnoParams();
	string* getParams();
	string getConditionType();
	string getConditionSpecifier();
	string getConditionParam();

	//Methods
	void parseUserInput(string userInput);
	void displayAll();
	void searchParams(Table t);
	Attribute searchInTableForColumns(Table t, string u);
	int searchInTableForPositions(Table t, string u);

	void searchConditionSpecifier(Table t);

	//Overloads
	void operator=(Select& s);
};