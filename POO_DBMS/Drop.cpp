#include "Drop.h"

Drop::Drop()
{
	this->identifier = "undefined";
	this->variant = "undefinded";
}

Drop::Drop(string variant, string identifier)
{
	this->variant = variant;
	this->identifier = identifier;
}

Drop::Drop(Drop& d)
{
	this->variant = d.getVariant();
	this->identifier = d.getIdentifier();
}

void Drop::setVariant(string variant)
{
	this->variant = variant;
}

void Drop::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

string Drop::getVariant()
{
	return this->variant;
}

string Drop::getIdentifier()
{
	return this->identifier;
}

void Drop::parseUserInput(string userInput)
{
	userInput.erase(0, userInput.find(" ")+1);
	this->variant = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->variant.size() + 1);

	this->identifier = userInput;
	deleteFile(this->identifier);
}

void Drop::displayAll()
{
	cout <<"Variant:"<< this->variant << endl << "Identifier:" << this->identifier << endl;
}

void Drop::deleteFile(const string filename)
{
	int result = remove(filename.c_str());
	if (result == 0)
	{
		cout << "File deleted successfully." << endl;
	}
	else
	{
		cout << "Error deleting the file." << endl;
	}
}

void Drop::operator=(Drop& d)
{
	this->identifier = d.getIdentifier();
	this->variant = d.getVariant();
}


void operator<<(ostream& console, Drop& d)
{
	console << "Variant:" << d.getVariant()<< endl << "Identifier:" << d.getIdentifier()<< endl;
}

void operator>>(istream& console, Drop& d)
{
	string variant, identifier;
	console >> variant >> identifier;
	d.setVariant(variant);
	d.setIdentifier(identifier);
}
