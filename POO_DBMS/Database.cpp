#include "Database.h"
#include "Table.h"
#include <iostream>



Database::Database(string name, Table tables[40]) {
	this->name = name;
	for (int i = 0; i < 40; i++)
	{
		this->tables[i] = tables[i];
	}
}

Database::Database()
{
	this->name = "undefined";
}

string Database::getName()
{
	return this->name;
}

Table* Database::getTables()
{
	return this->tables;
}

void Database::setName(string name) {
	this->name = name;
}
void Database::setTables(Table tables[]) {
	for (int i = 0; i < 40; i++)
	{
		this->tables[i] = tables[i];
	}
}
Database::~Database() {
	delete[] this->tables;
}