#include "Display.h"

Display::Display()
{
	this->identifier = "undefined";
	this->variant = "undefinded";
}

Display::Display(string variant, string identifier)
{
	this->variant = variant;
	this->identifier = identifier;
}

Display::Display(Display& d)
{
	this->variant = d.getVariant();
	this->identifier = d.getIdentifier();
}

void Display::setVariant(string variant)
{
	this->variant = variant;
}

void Display::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

string Display::getVariant()
{
	return this->variant;
}

string Display::getIdentifier()
{
	return this->identifier;
}

void Display::parseUserInput(string userInput)
{
	userInput.erase(0, userInput.find(" ") + 1);
	this->variant = userInput.substr(0, userInput.find(" "));
	userInput.erase(0, this->variant.size() + 1);

	this->identifier = userInput;

}

void Display::displayAll()
{
	cout <<"Variant:" << this->variant << endl <<"Identifier:" << this->identifier << endl;
}

void Display::operator=(Display& d)
{
	this->variant = d.getVariant();
	this->identifier = d.getIdentifier();
}
