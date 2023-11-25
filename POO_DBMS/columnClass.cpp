#include <iostream>
#include "columnClass.h"
using namespace std;


Column::Column()
{
this->name = "Undefined";
this->type = "int";
this->size = 1;
this->textValue = nullptr;
this->floatValue = nullptr;
}

Column::Column(string name, string type, int size, const char** textValue, float* floatValue);
{
	this.		
}