#pragma once
#include <iostream>
using namespace std;

class Display {
	string variant;
	string identifier;

public:
	Display();
	Display(string variant, string identifier);
	Display(Display& d);

	void setVariant(string variant);
	void setIdentifier(string identifier);

	string getVariant();
	string getIdentifier();

	void parseUserInput(string userInput);
	void displayAll();

	void operator=(Display& d);
};