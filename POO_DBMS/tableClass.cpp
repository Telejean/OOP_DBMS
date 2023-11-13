#include "tableClass.h"
#include <iostream>
using namespace std;


Table::Table() {
	this->name = "undefined";
}

string Table::getName()
{
	return this->name;
}