#pragma once
#include <iostream>
using namespace std;
#include "Table.h"
class Display {
	string variant;
	string identifier;

public:
	//Constructors
	Display();
	Display(string variant, string identifier);
	Display(Display& d);

	//Setters
	void setVariant(string variant);
	void setIdentifier(string identifier);

	//Getters
	string getVariant();
	string getIdentifier();

	//Methods
	void parseUserInput(string userInput);
	void displayAll();
	void displayTable(Table t);


	//Operators
	void operator=(Display& d);
	friend void operator<<(ostream& console, Display& d);
	friend void operator>>(istream& console, Display& d);
};