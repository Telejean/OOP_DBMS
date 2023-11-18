#include "Table.h"
#include "Attribute.h"
#include <iostream>


Table::Table(string name, Attribute attributes[40]) {
	this->name = name;
	for (int i = 0; i < 40; i++)
	{
		this->attributes[i] = attributes[i];
	}	
}
Table::Table() {
	this->name = "";
}
string Table::getName() {

	return this->name;
}
Attribute* Table::getAttribute() {
	return this->attributes;
}
void Table::setName(string name)
{
	this->name = name;
}
void Table::setAttributes(attributes[40]) {
	
	for (int i = 0; i < 40; i++)
	{
		this->attributes[i] = attributes[i];
	}
}
Table::~Table() {
	delete[] this->attributes;
}