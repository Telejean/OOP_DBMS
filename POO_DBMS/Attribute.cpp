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
	char* copy;
	if (this->name != nullptr)
	{
		copy = new char[strlen(this->name) + 1];
		for (int i = 0; i < strlen(this->name) + 1; i++) {
			copy[i] = this->name[i];
		}
	}
	else {
		copy = nullptr;
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
		copy = new int[this->noRows];
		for (int i = 0; i < this->noRows; i++)
			copy[i] = this->integerData[i];
	}
	else {
		copy = {};
	}
	return copy;
}

string* Attribute::getStringData()
{
	string* copy;
	if (this->stringData != nullptr)
	{
		copy = new string[this->noRows];
		for (int i = 0; i < this->noRows; i++)
			copy[i] = this->stringData[i];
	}
	else {
		copy = nullptr;
	}

	return copy;
}

float* Attribute::getFloatData()
{
	float* copy;
	if (this->floatData != nullptr)
	{
		copy = new float[this->noRows];
		for (int i = 0; i < this->noRows; i++)
			copy[i] = this->floatData[i];
	}
	else {
		copy = nullptr;
	}

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
	if (integer != nullptr) {
		if (this->integerData != nullptr)
		{
			delete[] this->integerData;
		}
		this->integerData = new int[noRows];

		for (int i = 0; i < this->noRows; i++) {
			this->integerData[i] = integer[i];
		}
	}
	else {
		this->integerData = nullptr;
	}

}

void Attribute::setStringData(string* stringData) {
	if (stringData != nullptr)
	{
		if (this->noRows > 0)
		{
			if (this->stringData != nullptr)
			{
				delete[] this->stringData;
			}
			this->stringData = new string[this->noRows];

			for (int i = 0; i < this->noRows; i++) {
				this->stringData[i] = stringData[i];
			}
		}
	}
	else {
		this->stringData = nullptr;
	}


}

void Attribute::setFloatData(float* f) {
	if (f != nullptr)
	{
		if (this->floatData == nullptr)
			delete[] this->floatData;

		this->floatData = new float[noRows];
		for (int i = 0; i < this->noRows; i++) {
			this->floatData[i] = f[i];
		}
	}
	else {
		this->floatData = nullptr;
	}

}



void Attribute::setFloatOnSpecifiedPosition(float f, int i)
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
		string* tempArr = new string[i];
		for (int u = 0; u < i; u++)
		{
			tempArr[u] = this->stringData[u];
		}
		delete[] this->stringData;

		this->stringData = new string[i+1];
		for (int u = 0; u < i; u++)
		{
			this->stringData[u] = tempArr[u];
		}
		delete[] tempArr;
	}
	else {
		this->stringData = new string[i + 1];
	}
	this->stringData[i] = s;
}

void Attribute::dealocateIntegerData()
{
	delete[]this->integerData;
}

void Attribute::dealocateFloatData()
{
	delete[] this->floatData;
}

void Attribute::dealocateStringData()
{
	delete[] this->stringData;
}

void Attribute::dealocateName()
{
	delete[] this->name;
}

void Attribute::setName(char* name) {
	if (name != nullptr)
	{
		if (this->name != nullptr)
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


void Attribute::setIntOnSpecifiedPosition(int data, int pos)
{
	if (this->integerData != nullptr)
	{
		int* tempArr = new int[pos + 1];
		for (int u = 0; u < pos; u++)
		{
			tempArr[u] = this->integerData[u];
		}

		delete[] this->integerData;
		this->integerData = new int[pos + 1];
		for (int u = 0; u < pos; u++)
		{
			this->integerData[u] = tempArr[u];
		}
		delete[] tempArr;
	}
	else {
		this->integerData = new int[pos + 1];
	}
	//cout << "pos: "<<pos<<"  value: "<<data<<endl;
	this->integerData[pos] = data;

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
			f.write((char*)&this->getIntergerData()[i], sizeof(int));

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
	this->setNoRows(a.getNoRows());
	this->setDatatype(a.getDatatype());
	this->setFloatData(a.getFloatData());
	this->setIntegerData(a.getIntergerData());
	this->setStringData(a.getStringData());
	this->setName(a.getName());
	this->setMaxRows(a.getMaxRows());
}

ostream& operator<<(ostream& console, Attribute& a) {

	console << a.getName() << endl;
	switch (a.getDatatype())
	{
	case INTEGER:
	{
		for (int i = 0; i < a.getNoRows(); i++)
		{
			console << endl << a.getIntergerData()[i];
		}

	}
	break;
	case REAL:
	{
		for (int i = 0; i < a.getNoRows(); i++)
		{
			console << endl << a.getFloatData()[i];
		}
	}
	break;
	case TEXT:
	{
		for (int i = 0; i < a.getNoRows(); i++)
		{
			console << endl << a.getStringData()[i];
		}
	}
	break;
	default:
		throw exception("Invalid Data Type in Attribute");
		break;
	}
	return console;
}

void Attribute::displayAttributes()
{
	int noRows = this->getNoRows();
	if (this->getName() != nullptr)
	{
		cout << "Column name: " << this->getName() << endl;
	}
	else {
		cout << "No name" << endl;
	}
	cout << "Data Type:";
	switch (this->getDatatype())
	{
	case INTEGER:
	{
		cout << " Integer" << endl;
		if (this->getIntergerData() != nullptr)
		{
			for (int i = 0; i < noRows; i++)
			{
				cout << endl << i << ": " << this->getIntergerData()[i] << endl;
			}
		}
		else {
			cout << "NULL" << endl;
		}

	}
	break;
	case REAL:
	{
		cout << " Real" << endl;

		if (this->getFloatData() != nullptr)
		{
			for (int i = 0; i < noRows; i++)
			{
				cout << endl << this->getFloatData()[i] << endl;
			}
		}
		else {
			cout << "NULL" << endl;
		}

	}
	break;
	case TEXT:
	{
		cout << " Text" << endl;
		if (this->getStringData() != nullptr)
			for (int i = 0; i < noRows; i++)
			{
				cout << endl << i << ": " << this->getStringData()[i] << endl;
			}
		else {
			cout << "NULL" << endl;
		}
	}
	break;
	default:
		throw exception("Invalid Data Type in Attribute");
		break;
	}

	cout << "-----------------------------------" << endl;
}

Attribute::~Attribute()
{
	delete[] integerData;
	delete[] floatData;
	delete[] stringData;
	delete[] name;
}
