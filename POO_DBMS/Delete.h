#pragma once
#include <iostream>
#include "Table.h"
#include "Attribute.h"
using namespace std;

//Instruction  Variant Identifier          Condition   

class Delete{
	string variant;
	string identifier;
	string conditionType;
	string conditionSpecifier;
	string conditionParam;
	char commandName[20];

public:
	Delete();
	Delete(string variant, string identifier, string conditionType, string conditionSpecifier, string conditionParam);
	Delete(Delete& d);

	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setConditionType(string conditionType);
	void setConditionSpecifier(string conditionSpecifier);
	void setConditionParam(string conditionParam);
	void setCommandName(const char name[20]);

	string getVariant();
	string getIdentifier();
	string getConditionType();
	string getConditionSpecifier();
	string getConditionParam();
	const char* getCommandName();

	void parseUserInput(string userInput);
	void displayAll();
	void deleteRow(Table t);
	Attribute searchInTableForColumn(Table t, string u);

	void operator=(Delete& d);
	friend void operator<<(ostream &console, Delete  d);
	friend void operator>>(istream& console, Delete  d);

};