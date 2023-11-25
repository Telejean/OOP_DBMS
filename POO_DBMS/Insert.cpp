#include "Insert.h"


#pragma region Constructors
Insert::Insert()
{
	this->identifier = "default";
	this->noParams = 0;
	this->params = nullptr;
}

Insert::Insert(string variant, string identifier, int noParams, string* params)
{
	this->identifier = identifier;
	this->variant = variant;
	this->noParams = noParams;
	if (params != nullptr)
	{
		this->params = new string[noParams];
		for (int i = 0; i < noParams; i++)
		{
			this->params[i] = params[i];
		}
	}
	else {
		this->params = nullptr;
	}
}

Insert::Insert(Insert& i)
{
	this->identifier = i.getIdentifier();
	this->variant = i.getVariant();
	this->noParams = i.getNoParams();
	if (i.getParams()!= nullptr &&i.getNoParams()>0)
	{
		this->params = new string[i.getNoParams()];
		this->params = i.getParams();
	}
	else {
		this->params = nullptr;
	}
}

#pragma endregion

#pragma region Setters

void Insert::setVariant(string variant)
{
	this->variant = variant;
}

void Insert::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

void Insert::setNoParams(int noParams)
{
	this->noParams = noParams;
}

void Insert::setParams(string* params)
{
	if (params != nullptr)
	{
		this->params = new string[noParams];
		for (int i = 0; i < noParams; i++)
		{
			this->params[i] = params[i];
		}
	}
	else {
		this->params = nullptr;
	}
}
#pragma endregion

#pragma region Getters

string Insert::getVariant()
{
	return this->variant;
}

string Insert::getIdentifier()
{
	return this->identifier;
}

int Insert::getNoParams()
{
	return noParams;
}

string* Insert::getParams()
{
	string* copy;
	if (this->params != nullptr)
	{
		copy = new string[this->noParams];
		for (int i = 0; i < this->noParams; i++)
		{
			copy[i] = this->params[i];
		}
	}

	else copy = nullptr;

	return copy;
}
void Insert::parseUserInput(string userInput)
{
	userInput.erase(0,userInput.find(" ")+1);

	this->variant=userInput.substr(0,userInput.find(" "));
	userInput.erase(0, userInput.find(" ") + 1);

	this->identifier = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, userInput.find(" ") + 1);
	userInput.erase(0, userInput.find(" ") + 2);


	string copy = userInput;
	int pos;
	int noParams = 0;
	while ((pos = copy.find(','))!=-1)
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
		userInput.erase(0, params[i].size() + 1);
	}

	params[noParams-1] = userInput.substr(0, userInput.find(')'));
	this->params = new string[noParams];

	for (int i = 0; i < noParams; i++)
	{
		this->params[i] = params[i];
	}

}
void Insert::displayAll()
{
	cout << "Variant:" << this->variant << '\n'<<"Identifier:"<<this->identifier<<'\n'<<"Params:";
	for (int i = 0; i < this->noParams; i++)
	{
		cout << this->params[i] << " ";
	}
	cout << endl;
}
#pragma endregion

