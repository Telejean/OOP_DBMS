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
	this->noAttributes = noAttributes;
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
int Table::getNoAttributes() {
	return this->noAttributes;
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
Table::Table(Table& t) {
	setName(t.name);
	setAttributes(t.attributes);
}
Table::~Table() {
	delete[] this->attributes;

}

void Table::operator=(Table& t)
{
	setName(t.name);
	setAttributes(t.attributes);
}
void operator<<(ostream& COUT, Table& t) {
	COUT << "Name: " << t.getName() << endl;
	COUT << "Attributes: " << t.getAttribute() << endl;
	COUT << "Number of attributes : " << t.getNoAttributes() << endl;
}


