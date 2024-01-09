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
	this->setVariant(variant);
	this->setIdentifier(identifier);
	this->setConditionParam(conditionParam);
	this->setConditionType(conditionType);
	this->setConditionSpecifier(conditionSpecifier);
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
	try {
		if (variant != "TABLE" || variant != "INDEX")
		{
			this->variant = variant;
		}
		else {
			throw exception("Invalid variant");
		}
	}
	catch (exception) {
		cout << "Invalid variant. Your variant: " << variant << endl << endl;
	}
}

void Delete::setIdentifier(string identifier)
{
	try {
		if (identifier.size() < 30)
		{
			this->identifier = identifier;
		}
		else {
			throw exception("Identifier too long");
		}
	}
	catch (exception) {
		cout << "Identifier too long. Max size is 30, your size:  " << identifier.size() << endl << endl;
	}
}

void Delete::setConditionType(string conditionType)
{
	try {
		if (conditionType.size() < 30)
		{
			this->conditionType = conditionType;
		}
		else {
			throw exception("conditionType too long");
		}
	}
	catch (exception) {
		cout << "conditionType too long. Max size is 30, your size:  " << conditionType.size() << endl << endl;
	}
}

void Delete::setConditionSpecifier(string conditionSpecifier)
{
	try {
		if (conditionSpecifier.size() < 30)
		{
			this->conditionSpecifier = conditionSpecifier;
		}
		else {
			throw exception("conditionSpecifier too long");
		}
	}
	catch (exception) {
		cout << "conditionSpecifier too long. Max size is 30, your size:  " << conditionSpecifier.size() << endl << endl;
	}
}


void Delete::setConditionParam(string conditionParam)
{
	try {
		if (conditionParam.size() < 30)
		{
			this->conditionParam = conditionParam;
		}
		else {
			throw exception("conditionParam too long");
		}
	}
	catch (exception) {
		cout << "conditionParam too long. Max size is 30, your size:  " << conditionParam.size() << endl << endl;
	}
}

void Delete::setCommandName(const char name[20])
{
	if (strchr(name, ' ') == NULL)
	{
		strcpy_s(this->commandName, name);
	}
	else {
		cout << "Command name can't contain spaces" << endl<<endl;
	}
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

const char* Delete::getCommandName()
{
	return this->commandName;
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

void Delete::operator=(Delete& d)
{
	this->variant = d.getVariant();
	this->identifier = d.getIdentifier();
	this->conditionParam = d.getConditionParam();
	this->conditionSpecifier = d.getConditionSpecifier();
	this->conditionType = d.getConditionType();
}

void operator<<(ostream &console, Delete d)
{
	console << "Variant: " << d.getVariant() << "  |Identifier: " << d.getIdentifier() << " |Condition type:" << d.getConditionType() << " |Condition parameter:" << d.getConditionParam() << " |Condition specifier:" << d.getConditionSpecifier() << endl;

}

void operator>>(istream& console, Delete d)
{
	string identifier;
	cout << "Enter new identifier: ";
	console >> identifier;
	d.setIdentifier(identifier);
}
