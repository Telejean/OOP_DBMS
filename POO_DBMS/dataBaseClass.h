#pragma once
#include "tableClass.h"
using namespace std;



class Database {
	string name;
	Table table;

public:
	Database();
	string getTableName();
};