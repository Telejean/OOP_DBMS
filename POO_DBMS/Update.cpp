#include "Update.h"
#include "Table.h"


#pragma region Constructors
Update::Update()
{
	this->variant = "undefined";
	this->identifier = "undefined";
	this->conditionType = "undefinded";
	this->conditionParam = "undefined";
	this->conditionSpecifier = "undefined";
}

Update::Update(string variant, string identifier, string identifier2, string param, string conditionType, string conditionSpecifier, string conditionParam)
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
	userInput.erase(0, this->identifier.size() + 1);

	this->variant = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->variant.size() + 1);

	this->identifier2 = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find('=') + 2);

	this->param = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->param.size() + 1);

	this->conditionType = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->conditionType.size() + 1);


	this->conditionSpecifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find('=') + 2);

	this->conditionParam = userInput;

}

void Update::displayAll()
{
	cout << "Identifier: " << this->identifier << " Variant:" << this->variant << " Identifier2" << this->identifier2 << " Parameter" << this->param << " Condition Type";
	cout << this->conditionType << " Condition Specifier" << this->conditionSpecifier << " ConditionParam" << this->conditionParam << endl;
}

Attribute Update::searchInTableForColumn(Table t, string u)
{
	for (int i = 0; i < t.getNoAttributes(); i++) {
		if (strcmp(u.c_str(), t.getAttribute()[i].getName()) == 0) {
			return t.getAttribute()[i];
		}
	}
}

void Update::updateColumn(Attribute a, int i) {
	switch (a.getDatatype())
	{
	case INTEGER:
	{
		a.setIntOnSpecifiedPosition(stoi(this->param), i);

	}
	break;
	case REAL:
	{
		a.setFloatOnSpecifiedPosition(stof(this->param), i);
	}
	break;
	case TEXT:
	{
		a.setStringOnSpecifiedPosition(this->param, i);

	}
	break;
	default:
		throw exception("Invalid Data Type");
		break;
	}
}


void Update::findIdentdifier2(Table t)
{
	Attribute b = searchInTableForColumn(t, conditionSpecifier);
	switch (b.getDatatype())
	{
	case INTEGER:
	{
		for (int i = 0; i < b.getNoRows(); i++) {
			if (b.getIntergerData()[i] == stoi(this->conditionParam)) {

				updateColumn(searchInTableForColumn(t, identifier2), i);
			}
		}
	}
	break;
	case REAL:
	{
		for (int i = 0; i < b.getNoRows(); i++) {
			if (b.getFloatData()[i] == stof(this->conditionParam)) {

				updateColumn(searchInTableForColumn(t, identifier2), i);
			}
		}

	}
	break;
	case TEXT:
	{
		for (int i = 0; i < b.getNoRows(); i++) {
			if (b.getStringData()[i] == this->conditionParam) {

				updateColumn(searchInTableForColumn(t, identifier2), i);
			}
		}

	}
	break;
	default:
		throw exception("Invalid Data Type");
		break;
	}



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
