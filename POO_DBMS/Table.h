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
	Table(char name[20], Attribute* attributes, int noAttributes);
	char* getName();
	Attribute* getAttribute();
	void setName(char name[20]);
	void setAttributes(Attribute attributes[]);
	~Table();
};


