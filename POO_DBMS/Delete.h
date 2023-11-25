#pragma once
#include <iostream>
using namespace std;

//Instruction  Variant Identifier          Condition   

class Delete{
	string variant;
	string identifier;
	string conditionType;
	string conditionSpecifier;
	string conditionParam;

public:
	Delete();
	Delete(string variant, string identifier, string conditionType, string conditionSpecifier, string conditionParam);
	Delete(Delete& d);

	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setConditionType(string conditionType);
	void setConditionSpecifier(string conditionSpecifier);
	void setConditionParam(string conditionParam);

	string getVariant();
	string getIdentifier();
	string getConditionType();
	string getConditionSpecifier();
	string getConditionParam();

	void parseUserInput(string userInput);
	void displayAll();
};