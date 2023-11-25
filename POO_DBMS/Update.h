#pragma once
#include <iostream>
using namespace std;



class Update {
	string variant;
	string identifier;
	string identifier2;
	string param;
	string conditionType;
	string conditionSpecifier;
	string conditionParam;

public:
	//Constructors
	Update();
	Update(string variant, string identifier, string identifier2, string param, string conditionType, string conditionSpecifier, string conditionParam);
	Update(Update& u);

	//Setters
	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setIdentifier2(string identifier2);
	void setParam(string param);
	void setConditionType(string conditionType);
	void setConditionSpecifier(string conditionSpecifier);
	void setConditionParam(string conditionParam);

	//Getters
	string getVariant();
	string getIdentifier();
	string getIdentifier2();
	string getParam();
	string getConditionType();
	string getConditionSpecifier();
	string getConditionParam();

	//Methods
	void parseUserInput(string userInput);
	void displayAll();

	//Overloads
	Update operator=(const Update& U);
};