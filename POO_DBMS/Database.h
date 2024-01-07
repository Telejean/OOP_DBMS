#pragma once
#include "Table.h"
using namespace std;



class Database {
	string name;
	int noTables;
	Table* tables;
	string nameList[10];

public:
	Database();
	Database(string name, Table tables[], int noTables);
	string* getNameList();
	string getName();
	Table* getTables();
	void setName(string name);
	void setTables(Table tables[]);
	Database(Database& d);
	~Database();
	void operator=(Database& d);
};