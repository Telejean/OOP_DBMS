#pragma once
#include <iostream>
using namespace std;

class Drop {
	string variant;
	string identifier;

public:
	Drop();
	Drop(string variant, string identifier);
	Drop(Drop& d);

	void setVariant(string variant);
	void setIdentifier(string identifier);

	string getVariant();
	string getIdentifier();

	void parseUserInput(string userInput);
	void displayAll();
	void deleteFile(const string filename);

	void operator=(Drop& d);
	friend void operator<<(ostream& console, Drop &d);
	friend void operator>>(istream& console, Drop& d);

};