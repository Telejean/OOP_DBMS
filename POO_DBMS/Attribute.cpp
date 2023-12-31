#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Attribute.h"
#include <fstream>
using namespace std;



Attribute::Attribute() {
	this->floatData = nullptr;
	this->integerData = nullptr;
	this->name = nullptr;
	this->stringData = nullptr;
	this->noRows = 0;
	this->type = { INTEGER };

}



Attribute::Attribute(char* name, Datatype type, int* intergerData, float* floatData, string* stringData, int noRows)
{
	this->setName(name);
	this->setDatatype(type);
	this->setNoRows(noRows);

	switch (type)
	{
	case INTEGER:
	{
		this->setIntegerData(intergerData);

	}
	break;
	case REAL:
	{
		this->setFloatData(floatData);

	}
	break;
	case TEXT:
	{
		this->setStringData(stringData);

	}
	break;
	default:
		throw exception("Invalid Data Type");
		break;
	}


}

Attribute::Attribute(const char* name, Datatype type) {
	setName(this->name);
	this->type = type;
}





char* Attribute::getName() {
	char* copy = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name) + 1; i++) {
		copy[i] = name[i];
	}
	return copy;
}
Datatype Attribute::getDatatype() {
	return this->type;
}
int* Attribute::getIntergerData()
{
	int* copy = new int[this->noRows];
	for (int i = 0; i < this->noRows; i++)
		copy[i] = this->integerData[i];
	return copy;
}
float* Attribute::getFloatData()
{
	float* copy = new float[this->noRows];
	for (int i = 0; i < this->noRows; i++)
		copy[i] = this->floatData[i];
	return copy;
}
string* Attribute::getStringData()
{
	string* copy = new string[this->noRows];
	for (int i = 0; i < this->noRows; i++)
		copy[i] = this->stringData[i];
	return copy;
}
int Attribute::getNoRows()
{
	return this->noRows;
}

void Attribute::setDatatype(Datatype type) {
	this->type = type;
}
void Attribute::setIntegerData(int* integer) {
	this->integerData = new int[noRows];
	if (this->integerData != nullptr) {
		for (int i = 0; i < this->noRows; i++) {
			this->integerData[i] = integer[i];
		}
	}
	else {
		throw exception("No integer data");
	}

}

void Attribute::setStringData(string* stringData) {
	this->stringData = new string[this->noRows];
	if (this->stringData != nullptr) {
		for (int i = 0; i < this->noRows; i++) {
			this->stringData[i] = stringData[i];
		}
	}
	else {
		throw exception("No string data");
	}

}


void Attribute::setName(char* name) {
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else {
		throw exception("Received name is null");
	}

}


void Attribute::setNoRows(int n) {
	if (this->noRows >= 0) {

		this->noRows = n;
	}
	else
	{
		throw exception("Number of rows invalid");
	}
}

void Attribute::setFloatData(float* f) {
	this->floatData = new float[noRows];
	if (this->floatData != nullptr) {
		for (int i = 0; i < this->noRows; i++) {
			this->floatData[i] = f[i];
		}
	}
	else {
		throw exception("No float data");
	}

}
void Attribute::saveInFile()
{
	ofstream f("columns.bin", ios::binary);
	unsigned length = strlen(this->name);
	f.write((char*)&length, sizeof(length));
	f.write(this->name, length + 1);
}

void Attribute::operator=(Attribute& a)
{
	this->name = a.name;
	this->type = a.type;
}

void Attribute::displayAttributes()
{
	cout << "Column name: " << this->getName() << endl;
	cout << "Number of rows: " << this->getNoRows() << endl;
	cout << "Data Type:" << this->getDatatype() << endl;
	cout << "-----------------------------------" << endl;
}
