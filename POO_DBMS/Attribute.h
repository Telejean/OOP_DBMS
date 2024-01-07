#pragma once
#include <string>
using namespace std;


enum Datatype { INTEGER, REAL, TEXT };

class Attribute {
	char* name;
	Datatype type;
	int integerData[200];
	float floatData[200];
	string stringData;
	static int noOfTables;

public:
	Attribute(char* name, Datatype type);
	Attribute();
	char* getName();
	Datatype getDatatype();
	void setName(char* name);
	void setDatatype(Datatype type);
	Attribute(Attribute &a);
	void operator=(Attribute& attribute);
};