#pragma once
#include <string>
using namespace std;


enum Datatype { INTEGER, REAL, TEXT };

class Attribute {
	string name;
	Datatype type;
	int integerData[200];
	float floatData[200];
	string stringData[200];

public:
	Attribute(string name, Datatype type);
	Attribute();
	string getName();
	Datatype getDatatype();
	void setName(string name);
	void setDatatype(Datatype type);

};