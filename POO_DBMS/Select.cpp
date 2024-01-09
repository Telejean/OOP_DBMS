#include "Select.h"

#pragma region Constructors
Select::Select()
{
	this->variant = "undefined";
	this->identifier = "undefined";
	this->conditionType = "undefinded";
	this->conditionParam = "undefined";
	this->conditionSpecifier = "undefined";
	this->params = nullptr;
	this->noParams = 0;
}

Select::Select(string variant, string identifier, int noParams, string conditionType, string conditionSpecifier, string conditionParam, string* params)
{
	this->variant = variant;
	this->identifier = identifier;
	this->conditionParam = conditionParam;
	this->conditionType = conditionType;
	this->conditionSpecifier = conditionSpecifier;
	this->noParams = noParams;
	if (params != nullptr)
	{
		this->params = new string[noParams];
		for (int i = 0; i < noParams; i++)
			this->params[i] = params[i];
	}
}

Select::Select(Select& s)
{
	this->variant = s.getVariant();
	this->identifier = s.getIdentifier();
	this->conditionParam = s.getConditionParam();
	this->conditionType = s.getConditionType();
	this->conditionSpecifier = s.getConditionSpecifier();
	this->noParams = s.getnoParams();
	if (s.getParams() != nullptr)
	{
		this->params = new string[s.getnoParams()];
		for (int i = 0; i < s.getnoParams(); i++)
			this->params = s.getParams();
	}
}

#pragma endregion

#pragma region Setters
void Select::setVariant(string variant)
{
	this->variant = variant;
}

void Select::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

void Select::setnoParams(int noParams)
{
	this->noParams = noParams;
}

void Select::setParams(string* params, int noParams)
{
	if (params != nullptr && noParams > 0)
	{
		this->params = new string[noParams];
		for (int i = 0; i < noParams; i++)
			this->params[i] = params[i];

	}
	else {
		this->params = nullptr;
	}
}

void Select::setConditionSpecifier(string conditionSpecifier)
{
	this->conditionSpecifier = conditionSpecifier;
}

void Select::setConditionType(string conditionType)
{
	this->conditionType = conditionType;
}

void Select::setConditionParam(string conditionParam)
{
	this->conditionParam = conditionParam;
}

#pragma endregion

#pragma region Getters
string Select::getVariant()
{
	return this->variant;
}

string Select::getIdentifier()
{
	return this->identifier;
}

int Select::getnoParams()
{
	return this->noParams;
}

string* Select::getParams()
{
	string* copy;

	if (this->params != nullptr)
	{
		copy = this->params;
	}
	else {
		copy = nullptr;
	}

	return copy;
}

string Select::getConditionType()
{
	return this->conditionType;
}

string Select::getConditionSpecifier()
{
	return this->conditionSpecifier;
}

string Select::getConditionParam()
{
	return this->conditionParam;
}
#pragma endregion

#pragma region Methods
void Select::parseUserInput(string userInput)
{
	userInput.erase(0, userInput.find(" ") + 2);

	string copy = userInput;
	int pos;
	int noParams = 0;
	while ((pos = copy.find(',')) != -1)
	{
		noParams++;
		copy.erase(0, pos + 1);
	}
	noParams++;
	this->noParams = noParams;
	string* params = new string[noParams];

	for (int i = 0; i < noParams - 1; i++)
	{
		params[i] = userInput.substr(0, userInput.find(','));
		userInput.erase(0, userInput.find(',') + 1);
	}

	params[noParams - 1] = userInput.substr(0, userInput.find(')'));
	userInput.erase(0, userInput.find(')') + 2);

	this->params = new string[noParams];
	for (int i = 0; i < noParams; i++)
	{
		this->params[i] = params[i];
	}


	this->variant = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->variant.size() + 1);

	this->identifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->identifier.size() + 1);

	this->conditionType = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->conditionType.size() + 1);

	this->conditionSpecifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find('=') + 2);

	this->conditionParam = userInput;



}

void Select::displayAll()
{
	cout << "Params:";
	for (int i = 0; i < this->noParams; i++)
	{
		cout << this->params[i] << " ";
	}
	cout << endl;
	cout << "Variant: " << this->variant << "\n" << "Identifier: " << this->identifier << "\n" << "Condition type: " << this->conditionType << "\n" << "Condition parameter: ";
	cout << this->conditionParam << "\n" << "Condition specifier: " << this->conditionSpecifier << endl;
}

void Select::searchParams(Table t)
{
	Attribute c = searchInTableForColumns(t, conditionSpecifier);
	int x = searchInTableForPositions(t, params[0]);
	switch (c.getDatatype())
	{
	case INTEGER:
	{
		for (int j = 0; j < c.getNoRows(); j++) {
			if (c.getIntergerData()[j] == stoi(conditionParam)) {
				if (this->noParams == 1) {
					if (searchInTableForColumns(t, params[0]).getDatatype() == INTEGER) {
						searchInTableForColumns(t, params[0]).getIntergerData()[x];
					 }
					if (searchInTableForColumns(t, params[0]).getDatatype() == REAL) {
						searchInTableForColumns(t, params[0]).getFloatData()[x];
					}
					if (searchInTableForColumns(t, params[0]).getDatatype() == TEXT) {
						searchInTableForColumns(t, params[0]).getStringData()[x];
					}
					else cout << "murim";

				}
				if (this->noParams > 1) {
					Attribute* b = new Attribute[noParams];
					for (int i = 0; i < noParams; i++) {
						searchInTableForPositions(t, params[i]);
					}
				}
				else {
					throw exception("wrong parameters");
				}
			}
		}
	}
	break;
	case REAL:
	{
		for (int j = 0; j < c.getNoRows(); j++) {
			if (c.getFloatData()[j] == stof(conditionParam)) {

			}
		}
	}
	break;
	case TEXT:
	{
		for (int j = 0; j < c.getNoRows(); j++) {
			if (c.getStringData()[j] == conditionParam) {

			}
		}
	}
	break;
	default:
		throw exception("Invalid Data Type in select");
		break;
	}

	if (this->noParams == 1) {
		
	}
	if (this->noParams > 1) {
		Attribute* b = new Attribute[noParams];
		for (int i = 0; i < noParams; i++){
			searchInTableForColumns(t, params[i]);
		}
	}
	else {
		throw exception("wrong parameters");
	}
}

Attribute Select::searchInTableForColumns(Table t, string u)
{
	for (int i = 0; i < t.getNoAttributes(); i++) {
		if (strcmp(u.c_str(), t.getAttribute()[i].getName()) == 0) {
			return t.getAttribute()[i];
		}
		else
			cout << "We couldn t search";
	}

}

int Select::searchInTableForPositions(Table t, string u)
{
	for (int i = 0; i < t.getNoAttributes(); i++) {
		if (strcmp(u.c_str(), t.getAttribute()[i].getName()) == 0) {
			return i;
		}
		else
			cout << "We couldn t search";
	}

}

void Select::searchConditionSpecifier(Table t)
{
	searchInTableForColumns(t, conditionSpecifier);
}


#pragma endregion

void Select::operator=(Select& s)
{
	this->params = s.getParams();
	this->variant = s.getVariant();
	this->identifier = s.getIdentifier();
	this->conditionParam = s.getConditionParam();
	this->conditionSpecifier = s.getConditionSpecifier();
	this->conditionType = s.getConditionType();
}
