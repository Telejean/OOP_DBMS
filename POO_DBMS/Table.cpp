#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include "Attribute.h"
#include <iostream>


Table::Table(const char name[20], Attribute* attributes, int noAttributes) {
	strcpy(this->name, name);
	attributes = new Attribute[noAttributes];
	for (int i = 0; i < noAttributes; i++)
	{
		this->attributes[i].setDatatype(attributes[i].getDatatype());
	}	
}
Table::Table() = default;

char* Table::getName() {
	char copy[20];
	strcpy(copy, name);
	return copy;
}
Attribute* Table::getAttribute() {
	return this->attributes;
}
void Table::setName(char name[20])
{
	strcpy(this->name, name);
}
void Table::setAttributes(Attribute attributes[]) {
	
	for (int i = 0; i < 40; i++)
	{
		this->attributes[i] = attributes[i];
	}
}
Table::~Table() {
	delete[] this->attributes;

}

void Table::operator=(Table& t)
{
	for (int i = 0; i < t.noAttributes; i++)
	{
		this->attributes[i].setDatatype(t.attributes[i].getDatatype());
	}
	strcpy(this->name, t.name);
	this->noAttributes = t.noAttributes;
}