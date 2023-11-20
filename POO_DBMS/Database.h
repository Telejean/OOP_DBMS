#pragma once
#include "Table.h"
using namespace std;



class Database {
	string name;
	Table tables[40];

public:
	Database();
	Database(string name, Table tables[40]);
	string getName();
	Table* getTables();
	void setName(string name);
	void setTables(Table tables[]);
	~Database();
};