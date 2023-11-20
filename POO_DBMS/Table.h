#pragma once
#include <iostream>
#include "Attribute.h"
using namespace std;


class Table {
	string name;
	Attribute attributes[40];
public:
	Table();
	Table(string name, Attribute attributes[]);
	string getName();
	Attribute* getAttribute();
	void setName(string name);
	void setAttributes(Attribute attributes[]);
	~Table();
};


