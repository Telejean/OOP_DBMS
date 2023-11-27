#pragma once
#include <iostream>

using namespace std;

class Insert {
	string variant;
	string identifier;
	int noParams;
	string* params;

public:
	Insert();
	Insert(string variant, string identifier, int noParams, string* params);
	Insert(Insert& i);

	void setVariant(string variant);
	void setIdentifier(string identifier);
	void setNoParams(int noParams);
	void setParams(string* params);

	string getVariant();
	string getIdentifier();
	int getNoParams();
	string* getParams();

	void parseUserInput(string userInput);
	void displayAll();

	void operator=(Insert& i);
};