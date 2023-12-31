#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Table.h"
#include "Attribute.h"
#include <iostream>
#include <fstream>


Table::Table(char* name, Attribute* attributes, int noAttributes) {
	setName(name);
	setNoAttributes(noAttributes);
	setAttributes(attributes);
}

Table::Table() {
	this->name = nullptr;
	this->noAttributes = 0;
	this->attributes = nullptr;
};

char* Table::getName() {
	char* copy;
	if (this->name != nullptr)
	{
		copy = new char[strlen(this->name) + 1];
		strcpy(copy, name);

	}
	else {
		copy = nullptr;
	}
	return copy;

}
Attribute* Table::getAttribute() {
	return this->attributes;
}
int Table::getNoAttributes() {
	return noAttributes;
}
void Table::setName(char* name)
{
	if (name != nullptr) {
		cout << "name: " << name << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

}
void Table::setAttributes(Attribute attributes[]) {

	if (this->name != nullptr) {
		attributes = new Attribute[noAttributes];
		for (int i = 0; i < this->getNoAttributes(); i++)
		{
			this->attributes[i] = attributes[i];
		}
	}
}



void Table::setNoAttributes(int n) {
	this->noAttributes = n;
}


void Table::convertParams(CreateParams* p, int noColumns)
{
	for (int i = 0; i < noColumns; i++)
	{
		this->attributes[i].setNoRows(p[i].getColumnSize());


		char* columnName;
		int nameLength = p[i].getColumnName().length() + 1;
		columnName = new char[nameLength];
		for (int j = 0; j < nameLength; j++)
			columnName[j] = p[i].getColumnName()[j];

		this->attributes[i].setName(columnName);
		this->attributes[i].saveInFile();
		if (p[i].getColumnType() == "text" || p[i].getColumnType() == "Text" || p[i].getColumnType() == "TEXT")
		{
			this->attributes[i].setDatatype(TEXT);
		}
		else if (p[i].getColumnType() == "integer" || p[i].getColumnType() == "Integer" || p[i].getColumnType() == "INTEGER") {
			this->attributes[i].setDatatype(INTEGER);
		}
		else if (p[i].getColumnType() == "real" || p[i].getColumnType() == "Real" || p[i].getColumnType() == "REAL")
		{
			this->attributes[i].setDatatype(REAL);
		}
		else {
			throw exception("No valid data type found");
		}
	}
}


Table::~Table() {
	delete[] this->attributes;
}

void Table::operator=(Create& c)
{
	int lengthOfName = c.getIdentifier().length();
	char* parsedName;
	parsedName = new char[lengthOfName];
	for (int i = 0; i < lengthOfName; i++)
	{
		parsedName[i] = c.getIdentifier()[i];
	}
	parsedName[lengthOfName] = '\0';

	this->setName(parsedName);
	cout << this->getName() << endl;


	this->setNoAttributes(c.getNoColumns());
	this->attributes = new Attribute[c.getNoColumns()];
	this->convertParams(c.getParams(), c.getNoColumns());

}

void Table::displayTable()
{
	cout << "Tabel name: " << this->getName() << endl;
	cout << "Number of columns: " << this->getNoAttributes() << endl;
	for (int i = 0; i < this->getNoAttributes(); i++)
	{
		this->attributes[i].displayAttributes();
	}
}



ostream& operator<<(ostream& console, Table& t)
{
	console << "Tabel name: " << t.getName() << endl;
	console << "Number of columns: " << t.getNoAttributes() << endl;
	return console;

}

