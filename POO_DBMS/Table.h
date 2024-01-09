#pragma once
#include <iostream>
#include "Attribute.h"
#include "Create.h"
using namespace std;


class Table {
	char* name;
	int noAttributes;
	Attribute* attributes;
public:
	Table();
	Table(char name[], Attribute* attributes, int noAttributes);
	char* getName();
	Attribute* getAttribute();
	int getNoAttributes();
	void setName(char name[20]);
	void setAttributes(Attribute attributes[]);
	void setNoAttributes(int n);
	void convertParams(CreateParams* p, int noColumns);
	~Table();
	void operator=(Create& c);
	friend ostream& operator<<(ostream&, Table&);

	void saveTable();
	void displayTable();
};
