#pragma once
#include "tableClass.h"
using namespace std;

class Column {
	string name;
	string type;
	int size;
	char** textValue;
	float* floatValue;

public:
	Column();

	Column(string name, string type, int size, const char** textValue, float* floatValue);

};