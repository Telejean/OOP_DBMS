#include "Database.h"
#include "Table.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS


Database::Database(string name, Table tables[], int noTables) {
	this->name = name;
	this->tables = new Table[noTables];
	for (int i = 0; i < noTables; i++)
	{
		this->tables[i] = tables[i];
	}
}

Database::Database() = default;

string Database::getName()
{
	return this->name;
}
string* Database::getNameList() {
	for (int i = 0; i < noTables; i++) {
		this->nameList[i] = tables[i].getName();
	}
	return nameList;
}

Table* Database::getTables()
{
	return this->tables;
}

void Database::setName(string name) {
	this->name = name;
}
void Database::setTables(Table tables[]) {
	for (int i = 0; i < noTables; i++)
	{
		this->tables[i] = tables[i];
	}
}
Database::Database(Database& d) {
	setName(d.name);
	setTables(d.tables);
}
Database::~Database() {
	delete[] this->tables;
}
void Database::operator=(Database& d)
{
	this->name = d.name;
	for (int i = 0; i < noTables; i++)
	{
		this->tables[i] = d.tables[i];
	}
}