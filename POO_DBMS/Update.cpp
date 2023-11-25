#include "Update.h"

#pragma region Constructors
Update::Update()
{
	this->variant = "undefined";
	this->identifier = "undefined";
	this->conditionType = "undefinded";
	this->conditionParam = "undefined";
	this->conditionSpecifier = "undefined";
}

Update::Update(string variant, string identifier, string identifier2,string param, string conditionType, string conditionSpecifier, string conditionParam)
{
	this->variant = variant;
	this->identifier = identifier;
	this->identifier2 = identifier2;
	this->conditionParam = conditionParam;
	this->conditionType = conditionType;
	this->param = param;
	this->conditionSpecifier = conditionSpecifier;
}

Update::Update(Update& u)
{
	this->variant = u.getVariant();
	this->identifier = u.getIdentifier();
	this->identifier2 = u.getIdentifier2();
	this->conditionParam = u.getConditionParam();
	this->conditionType = u.getConditionType();
	this->conditionSpecifier = u.getConditionSpecifier();
	this->param = u.getParam();
}

#pragma endregion

#pragma region Setters

void Update::setVariant(string variant)
{
	this->variant = variant;
}

void Update::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

void Update::setIdentifier2(string identifier2)
{
	this->identifier2 = identifier2;
}

void Update::setParam(string param)
{
	this->param = param;
}

void Update::setConditionSpecifier(string conditionSpecifier)
{
	this->conditionSpecifier = conditionSpecifier;
}

void Update::setConditionType(string conditionType)
{
	this->conditionType = conditionType;
}

void Update::setConditionParam(string conditionParam)
{
	this->conditionParam = conditionParam;
}

#pragma endregion

#pragma region Getters

string Update::getVariant()
{
	return this->variant;
}

string Update::getIdentifier()
{
	return this->identifier;
}

string Update::getIdentifier2()
{
	return this->identifier2;
}

string Update::getParam()
{
	return this->param;
}


string Update::getConditionType()
{
	return this->conditionType;
}

string Update::getConditionSpecifier()
{
	return this->conditionSpecifier;
}

string Update::getConditionParam()
{
	return this->conditionParam;
}


#pragma endregion

#pragma region Methods
void Update::parseUserInput(string userInput)
{
	userInput.erase(0, userInput.find(" ") + 1);
	this->identifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->identifier.size()+1);

	this->variant = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->variant.size() + 1);

	this->identifier2 = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find('=') + 2);

	this->param = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->param.size() + 1);

	this->conditionType = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->conditionType.size() + 1);


	this->conditionSpecifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find('=')+2);

	this->conditionParam = userInput;

	

}

void Update::displayAll()
{
	cout <<"Identifier: " << this->identifier << " Variant:" << this->variant << " Identifier2" << this->identifier2 << " Parameter" << this->param << " Condition Type";
	cout<< this->conditionType << " Condition Specifier" << this->conditionSpecifier << " ConditionParam" << this->conditionParam << endl;
}

#pragma endregion
Update Update::operator=(const Update& u)
{
	this->variant = u.variant;
	this->identifier = u.identifier;
	this->identifier2 = u.identifier2;
	this->conditionParam = u.conditionParam;
	this->conditionType = u.conditionType;
	this->conditionSpecifier = u.conditionSpecifier;
	this->param = u.param;

	return *this;
}
