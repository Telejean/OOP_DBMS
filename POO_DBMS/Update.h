#pragma once
#include <iostream>
#include "Attribute.h"
#include "Table.h"
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
	Attribute searchInTableForColumn(Table t, string u);
	void findIdentdifier2(Table t);
	void updateColumn(Attribute a, int i);

	//Overloads
	Update operator=(const Update& U);
};