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
	strcpy_s(this->commandName, "");
}



Create::Create(string variant, string identifier, string condition, int noColumns, CreateParams* params, const char name[20])
{
	this->setVariant(variant);
	this->setIdentifier(identifier);
	this->setCondition(condition);
	this->setNoColumns(noColumns);
	this->setParams(params, noColumns);
	this->setCommandName(name);
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

void Create::setIdentifier(string identifier)
{
	try {
		if (identifier.size()<30)
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

void Create::setNoColumns(int noColumns)
{
	try {
		if (noColumns < 30)
		{
			this->noColumns = noColumns;
		}
		else {
			throw exception("Too many columns");
		}
	}
	catch (exception) {
		cout << "Too many columns. You entered:  " << noColumns << endl << endl;
	}
}



void Create::setParams(CreateParams* params, int noColumns)
{
		if (params != nullptr)
		{
			this->params = new CreateParams[noColumns];
			for (int i = 0; i < noColumns; i++)
			{
				this->params[i].setColumnName(params[i].getColumnName());
				this->params[i].setColumnSize(params[i].getColumnSize());
				this->params[i].setColumnType(params[i].getColumnType());
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

void Create::setCommandName(const char name[20])
{
	int sizeOfInput = sizeof(name) / sizeof(name[0]);
	try {
		if ( sizeOfInput< 20)
		{
			strcpy_s(this->commandName, name);
		}
		else {
			throw exception("Nume comanda prea mare");
		}
	}
	catch (exception) {
		cout << "Input size is too big: " << sizeOfInput << "\n" << "\n";
	}

}

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

	this->params = new CreateParams[noColumns];
	string setOfParams;

	setOfParams = userInput.substr(0, userInput.find(')'));
	userInput.erase(0, setOfParams.size() + 1);
	setOfParams.erase(0, setOfParams.find('(') + 1);
	string token;

	token = setOfParams.substr(0, setOfParams.find(','));
	this->params[0].setColumnName(token);
	setOfParams.erase(0, token.size() + 2);

	token = setOfParams.substr(0, setOfParams.find(','));
	this->params[0].setColumnType(token);
	setOfParams.erase(0, token.size() + 2);

	token = setOfParams.substr(0, setOfParams.find(','));
	this->params[0].setColumnSize(stoi(token));
	setOfParams.erase(0, token.size() + 2);

	token = setOfParams.substr(0, setOfParams.find(','));
	this->params[0].setColumnDefaultValue(token);
	setOfParams.erase(0, token.size() + 2);

	for (int i = 1; i < noColumns; i++)
	{

		setOfParams =userInput.substr(0, userInput.find(')'));
		userInput.erase(0, setOfParams.size()+1);
		setOfParams.erase(0, setOfParams.find('(') + 1);

		token = setOfParams.substr(0, setOfParams.find(','));
		this->params[i].setColumnName(token);
		setOfParams.erase(0, token.size() + 2);

		token = setOfParams.substr(0, setOfParams.find(','));
		this->params[i].setColumnType(token);
		setOfParams.erase(0, token.size() + 2);

		token = setOfParams.substr(0, setOfParams.find(','));
		this->params[i].setColumnSize(stoi(token));
		setOfParams.erase(0, token.size() + 2);

		token = setOfParams.substr(0, setOfParams.find(','));
		this->params[i].setColumnDefaultValue(token);
		setOfParams.erase(0, token.size() + 2);

	}

}

void Create::displayAll()
{
	for (int i = 0; i < noColumns; i++)
	{
		cout << i+1<<" set of params: ";
		cout << this->params[i].getColumnName() << " " << this->params[i].getColumnType() << " " << this->params[i].getColumnSize() << " " << this->params[i].getColumnDefaultValue() << endl;
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



void operator<<(ostream& console, Create create)
{
	console << "Variant:" << create.getVariant() << "  Identifier:" << create.getIdentifier()<<"   Condition:"<<create.getCondition() << "   No. Columns:" << create.getNoColumns() << endl;
	for (int i = 0; i < create.noColumns; i++)
	{
		console << i + 1 << " set of params: ";
		console << create.getParams()[i].getColumnName() << " " << create.getParams()[i].getColumnType() << " " << create.getParams()[i].getColumnSize() << " " << create.getParams()[i].getColumnDefaultValue() << endl;
	}
}


void operator>>(istream& console, Create create)
{
	string condition;
	console >> condition;
	create.setCondition(condition);
}
