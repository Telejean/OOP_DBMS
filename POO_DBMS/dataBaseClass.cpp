#include "dataBaseClass.h"
#include "tableClass.h"
#include <iostream>

Database::Database()
{
	this->name = "undefined";
}

string Database::getTableName()
{
	return this->table.getName();
}
