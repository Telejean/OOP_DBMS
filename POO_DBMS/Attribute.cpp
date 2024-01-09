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
	this->maxRows = 0;

}



Attribute::Attribute(char* name, Datatype type, int* intergerData, float* floatData, string* stringData, int noRows, int maxRows)
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


int Attribute::getMaxRows() {
	return this->maxRows;
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
	int* copy;
	if (this->integerData != nullptr)
	{
		delete[] this->integerData;
		copy = new int[this->noRows];
		for (int i = 0; i < this->noRows; i++)
			copy[i] = this->integerData[i];
	}
	else {
		copy = {};
	}
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

void Attribute::setMaxRows(int max)
{
	if (max >= 0)
	{
		this->maxRows = max;

	}
	else
	{
		throw exception("invalid max rows");
	}
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

void Attribute::setIntOnSpecifiedPosition(int n,int i)
{
	if (this->integerData != nullptr)
	{
		this->integerData[i] = n;
	}
}

void Attribute::setFloatOnSpecifiedPosition(int f, int i)
{
	if (this->floatData != nullptr)
	{
		this->floatData[i] = f;
	}
}

void Attribute::setStringOnSpecifiedPosition(string s, int i)
{
	if (this->stringData != nullptr)
	{
		this->stringData[i] = s;
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
void Attribute::saveInFile(char* filename, ostream f)
{

	f.write(this->name, strlen(this->name) * sizeof(char));
	f.write((char*)&this->noRows, sizeof(int));

	switch (this->getDatatype())
	{
	case INTEGER:
	{
		for (int i = 0; i < this->getNoRows(); i++)
		{
			f.write((char*)3, sizeof(int));
			cout << "caca";

		}

	}
	break;
	case REAL:
	{
		for (int i = 0; i < this->getNoRows(); i++)
			f.write((char*)&this->getFloatData()[i], sizeof(float));

	}
	break;
	case TEXT:
	{
		for (int i = 0; i < this->getNoRows(); i++)
			f.write((char*)&this->getStringData()[i], sizeof(string));
	}
	break;
	default:
		throw exception("Invalid Data Type");
		break;
	}

}

void Attribute::operator=(Attribute& a)
{
	this->name = a.name;
	this->type = a.type;
}

ostream& operator<<(ostream& console, Attribute& a) {
		
	console << a.getName() << endl;
	switch (a.getDatatype())
		{
		case INTEGER:
		{
			for (int i = 0; i <a.getNoRows(); i++)
			{
				console <<endl<< a.getIntergerData()[i];
			}

		}
		break;
		case REAL:
		{
			for (int i = 0; i < a.getNoRows(); i++)
			{
				console <<endl<< a.getFloatData()[i];
			}
		}
		break;
		case TEXT:
		{
			for (int i = 0; i < a.getNoRows(); i++)
			{
				console <<endl<< a.getStringData()[i];
			}
		}
		break;
		default:
			throw exception("Invalid Data Type in Attribute");
			break;
		}
	
}

void Attribute::displayAttributes()
{
	cout << "Column name: " << this->getName() << endl;
	cout << "Number of rows: " << this->getNoRows() << endl;
	cout << "Data Type:" << this->getDatatype() << endl;
	cout << "-----------------------------------" << endl;
}
