#pragma once
#include "Create.h"
#include<string>

#pragma region Constructors
Create::Create()
{
	this->variant = "UNDEFINED";
	this->identifier = "undefined";
	this->condition = "";
	this->noColumns = 1;
	this->params = nullptr;
}

Create::Create(string variant, string identifier, string condition, int noColumns, CreateParams* params)
{
	this->variant = variant;
	this->identifier = identifier;
	this->condition = condition;
	this->noColumns = noColumns;
	if (params != nullptr)
	{
		this->params = new CreateParams[noColumns];
		for (int i = 0; i < noColumns; i++)
		{
			//TODO overload '=' in createParams
			this->params[i] = params[i];
		}
	}
	else {
		this->params = nullptr;
	}
}
Create::Create(Create& c)
{
	this->variant = c.getVariant();
	this->identifier = c.getIdentifier();
	this->condition = c.getCondition();
	this->noColumns = c.getNoColumns();
	if (c.getParams()!= nullptr)
	{
		this->params = new CreateParams[c.getNoColumns()];
		for (int i = 0; i < c.getNoColumns(); i++)
		{
			//TODO overload '=' in createParams
			this->params = c.getParams();
		}
	}
	else {
		this->params = nullptr;
	}
}
#pragma endregion

#pragma region Setters

void Create::setVariant(string variant)
{
	this->variant = variant;
}

void Create::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

void Create::setNoColumns(int noColumns)
{
	this->noColumns = noColumns;
}



void Create::setParams(CreateParams* params, int noColumns)
{
	if (params != nullptr)
	{
		this->params = new CreateParams[noColumns];
		for (int i = 0; i < noColumns; i++)
		{
			//TODO overload '=' in createParams
			this->params[i] = params[i];
		}
	}
	else {
		this->params = nullptr;
	}
}
void Create::setCondition(string condition)
{
	this->condition = condition;
}
#pragma endregion


#pragma region Getters

string Create::getVariant()
{
	return this->variant;
}

string Create::getIdentifier()
{
	return this->identifier;
}

string Create::getCondition()
{
	return this->condition;
}

int Create::getNoColumns()
{
	return this->noColumns;
}

CreateParams* Create::getParams()
{
	CreateParams* copy;

	if (this->params != nullptr)
	{
		copy = new CreateParams[this->noColumns];
		for (int i = 0; i < noColumns; i++)
		{
			copy[i] = params[i];
		}
	}
	else {
		copy= nullptr;
	}
	return copy;
}
#pragma endregion

#pragma region Methods

void Create::parseUserInput(string userInput)
{
	CreateParams* userParams;
	/*string instruction =userInput.substr(0, userInput.find(" "));
	string table =userInput.substr(instruction.size(), userInput.find())*/
	
	if (userInput.find("TABLE")!=-1)
	{
		this->setVariant("TABLE");
	}

	if (userInput.find("INDEX") != -1)
	{
		this->setVariant("INDEX");
	}

	if (userInput.find("IF NOT EXISTS") != -1)
	{
		this->setCondition("IF NOT EXISTS");
	}

	userInput.erase(0, 13); //CREATE INDEX/TABLE -13 characters

	this->setIdentifier(userInput.substr(0, userInput.find(" ")));
	userInput.erase(0, this->getIdentifier().length()+this->getCondition().length() + 2);



	int noColumns = 0;
	string copy = userInput;

	while (copy.find(')') != 0)
	{
		// cout << input.find(")")<<endl;
		copy.erase(0, copy.find(")") + 1);
		noColumns++;
	}

	this->setNoColumns(noColumns);

	CreateParams* params = new CreateParams[noColumns];
	string setOfParams;

	setOfParams = userInput.substr(0, userInput.find(')'));
	userInput.erase(0, setOfParams.size() + 1);
	setOfParams.erase(0, setOfParams.find('(') + 2);

	string token;
	token = setOfParams.substr(0, setOfParams.find(','));
	params[0].setColumnName(token);
	setOfParams.erase(0, token.size() + 2);

	token = setOfParams.substr(0, setOfParams.find(','));
	params[0].setColumnType(token);
	setOfParams.erase(0, token.size() + 2);

	token = setOfParams.substr(0, setOfParams.find(','));
	params[0].setColumnSize(stoi(token));
	setOfParams.erase(0, token.size() + 2);

	token = setOfParams.substr(0, setOfParams.find(','));
	params[0].setColumnDefaultValue(token);
	setOfParams.erase(0, token.size() + 2);

	for (int i = 1; i < noColumns; i++)
	{
		cout << setOfParams << endl;

		setOfParams =userInput.substr(0, userInput.find(')'));
		userInput.erase(0, setOfParams.size()+1);
		setOfParams.erase(0, setOfParams.find('(') + 1);

		token = setOfParams.substr(0, setOfParams.find(','));
		params[i].setColumnName(token);
		setOfParams.erase(0, token.size() + 2);

		token = setOfParams.substr(0, setOfParams.find(','));
		params[i].setColumnType(token);
		setOfParams.erase(0, token.size() + 2);

		token = setOfParams.substr(0, setOfParams.find(','));
		params[i].setColumnSize(stoi(token));
		setOfParams.erase(0, token.size() + 2);

		token = setOfParams.substr(0, setOfParams.find(','));
		params[i].setColumnDefaultValue(token);
		setOfParams.erase(0, token.size() + 2);
	}

	this->setParams(params, noColumns);
}

void Create::displayAll()
{
	for (int i = 0; i < noColumns; i++)
	{
		cout << i+1<<" set of params: ";
		cout << params[i].getColumnName() << " " << params[i].getColumnType() << " " << params[i].getColumnSize() << " " << params[i].getColumnDefaultValue() << endl;
	}
	
	cout << "Variant:" << this->variant << "  Identifier:" << this->identifier << "   No. Columns:" << this->noColumns << endl;
}

#pragma endregion

Create::~Create()
{
	if (this->params != nullptr)
		delete[] this->params;
}

void Create::operator=(Create& c)
{
	this->variant = c.getVariant();
	this->identifier = c.getIdentifier();
	this->condition = c.getCondition();
	this->noColumns = c.getNoColumns();

	if (c.params != nullptr)
	{
		if (this->params = c.getParams())
		{
			return;
		}
		else {
			delete[] this->params;
			this->params = new CreateParams[this->noColumns];
			for (int i = 0; i < this->noColumns; i++)
			{
				this->params[i] = c.params[i];
			}
		}
	}
	else {
		this->params = nullptr;
	}


}

CreateParams Create::operator[](int counter)
{
	return CreateParams();
}

void operator<<(ostream& console, Create create)
{
	for (int i = 0; i < create.noColumns; i++)
	{
		cout << i + 1 << " set of params: ";
		cout << create.getParams()[i].getColumnName() << " " << create.getParams()[i].getColumnType() << " " << create.getParams()[i].getColumnSize() << " " << create.getParams()[i].getColumnDefaultValue() << endl;
	}

	cout << "Variant:" << create.getVariant() << "  Identifier:" << create.getIdentifier() << "   No. Columns:" << create.getNoColumns() << endl;
}

void operator>>(ifstream& console, Create create)
{
}
