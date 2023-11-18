#pragma once
#include <string>
using namespace std;


enum Datatype { INTEGER, REAL, TEXT };

class Attribute {
	string name;
	Datatype type;
public:
	Attribute(string name, Datatype type);
	Attribute();
	string getName();
	Datatype getDatatype();
	void setName(string name);
	void setDatatype(Datatype type);
	~Attribute();
};