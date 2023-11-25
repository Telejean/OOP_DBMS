#include "Delete.h"

#pragma region Constructors
Delete::Delete()
{
	this->variant = "undefined";
	this->identifier = "undefined";
	this->conditionType = "undefinded";
	this->conditionParam = "undefined";
	this->conditionSpecifier = "undefined";
}

Delete::Delete(string variant, string identifier, string conditionType, string conditionSpecifier, string conditionParam)
{
	this->variant = variant;
	this->identifier = identifier;
	this->conditionParam = conditionParam;
	this->conditionType = conditionType;
	this->conditionSpecifier = conditionSpecifier;
}

Delete::Delete(Delete& d)
{
	this->variant = d.getVariant();
	this->identifier = d.getIdentifier();
	this->conditionParam = d.getConditionParam() ;
	this->conditionType = d.getConditionType();
	this->conditionSpecifier = d.getConditionSpecifier();
}

#pragma endregion


#pragma region Setters
void Delete::setVariant(string variant)
{
	this->variant = variant;
}

void Delete::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

void Delete::setConditionType(string conditionType)
{
	this->conditionType = conditionType;
}

void Delete::setConditionSpecifier(string conditionSpecifier)
{
	this->conditionSpecifier = conditionSpecifier;
}

void Delete::setConditionParam(string conditionParam)
{
	this->conditionParam = conditionParam;
}

#pragma endregion

#pragma region Getters

string Delete::getVariant()
{
	return this->variant;
}

string Delete::getIdentifier()
{
	return this->identifier;
}

string Delete::getConditionType()
{
	return this->conditionType;
}

string Delete::getConditionSpecifier()
{
	return this->conditionSpecifier;
}

string Delete::getConditionParam()
{
	return this->conditionParam;
}

#pragma endregion

void Delete::parseUserInput(string userInput)
{
	userInput.erase(0, userInput.find(" ")+1);
	this->variant = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->variant.size()+1);

	this->identifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->identifier.size() + 1);

	this->conditionType = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->conditionType.size() + 1);

	this->conditionSpecifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find('=')+2);

	this->conditionParam = userInput;

}

void Delete::displayAll()
{
	cout <<"Variant: " << this->variant << "  |Identifier: " << this->identifier << " |Condition type:" << this->conditionType << " |Condition parameter:" << this->conditionParam << " |Condition specifier:" << this->conditionSpecifier << endl;

}
