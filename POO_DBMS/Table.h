#pragma once
#include <iostream>
#include "Attribute.h"
using namespace std;


class Table {
	char name[20];
	int noAttributes;
	Attribute* attributes;
public:
	Table();
	Table(const char name[], Attribute* attributes, int noAttributes);
	char* getName();
	Attribute* getAttribute();
	void setName(char name[20]);
	void setAttributes(Attribute attributes[]);
	~Table();
	void operator=(Table& t);
};


