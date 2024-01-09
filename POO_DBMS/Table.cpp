#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Table.h"
#include "Attribute.h"
#include "Insert.h"
#include <iostream>
#include <fstream>


Table::Table(char* name, Attribute* attributes, int noAttributes) {
	setName(name);
	setNoAttributes(noAttributes);
	setAttributes(attributes);
}

Table::Table() {
	this->name = nullptr;
	this->noAttributes = 0;
	this->attributes = nullptr;
};

char* Table::getName() {
	char* copy;
	if (this->name != nullptr)
	{
		copy = new char[strlen(this->name) + 1];
		strcpy(copy, name);

	}
	else {
		copy = nullptr;
	}
	return copy;

}
Attribute* Table::getAttribute() {
	return this->attributes;
}
int Table::getNoAttributes() {
	return noAttributes;
}
void Table::setName(char* name)
{
	if (name != nullptr) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

}
void Table::setAttributes(Attribute attributes[]) {

	if (this->name != nullptr) {
		attributes = new Attribute[noAttributes];
		for (int i = 0; i < this->getNoAttributes(); i++)
		{
			this->attributes[i] = attributes[i];
		}
	}
}



void Table::setNoAttributes(int n) {
	this->noAttributes = n;
}


void Table::convertParams(CreateParams* p, int noColumns)
{
	for (int i = 0; i < noColumns; i++)
	{
		this->attributes[i].setMaxRows(p[i].getColumnSize());


		char* columnName;
		int nameLength = p[i].getColumnName().length() + 1;
		columnName = new char[nameLength];
		for (int j = 0; j < nameLength; j++)
			columnName[j] = p[i].getColumnName()[j];

		this->attributes[i].setName(columnName);
		if (p[i].getColumnType() == "text" || p[i].getColumnType() == "Text" || p[i].getColumnType() == "TEXT")
		{
			this->attributes[i].setDatatype(TEXT);
		}
		else if (p[i].getColumnType() == "integer" || p[i].getColumnType() == "Integer" || p[i].getColumnType() == "INTEGER") {
			this->attributes[i].setDatatype(INTEGER);
		}
		else if (p[i].getColumnType() == "real" || p[i].getColumnType() == "Real" || p[i].getColumnType() == "REAL")
		{
			this->attributes[i].setDatatype(REAL);
		}
		else {
			throw exception("No valid data type found");
		}
	}
}


Table::~Table() {
	delete[] this->name;
	delete[] this->attributes;
}

void Table::operator=(Create& c)
{
	int lengthOfName = c.getIdentifier().length();
	char* parsedName;
	parsedName = new char[lengthOfName];
	for (int i = 0; i < lengthOfName; i++)
	{
		parsedName[i] = c.getIdentifier()[i];
	}
	parsedName[lengthOfName] = '\0';

	this->setName(parsedName);


	this->setNoAttributes(c.getNoColumns());
	this->attributes = new Attribute[c.getNoColumns()];
	this->convertParams(c.getParams(), c.getNoColumns());

}

void Table::saveTable()
{

	ofstream tableFile(this->getName(), ios::binary);
	ofstream tableList("tableList.txt", ios::app);
	tableList << this->getName();
	tableList << " ";
	tableList.close();

	if (tableFile)
	{
		int noAttributes = this->getNoAttributes();
		//1. We write the number of attributes

		tableFile.write((char*)&noAttributes, sizeof(int));

		for (int i = 0; i < this->getNoAttributes(); i++)
		{
			//2. We write the lenght of the name of the attribute
			int lenghtOfName = strlen(this->attributes[i].getName());
			tableFile.write((char*)&lenghtOfName, sizeof(int));


			//3. We write the name of the attribute
			cout << "pos:" << tableFile.tellp();
			tableFile.write(this->attributes[i].getName(), strlen(this->attributes[i].getName()) * sizeof(char));


			//4. We write the number of entries the attribute has
			int noRows = this->attributes[i].getNoRows();
			tableFile.write((char*)&noRows, sizeof(int));
			cout << "-" << tableFile.tellp() << endl;


			//5. We write the data type

			int dataType = this->attributes[i].getDatatype();
			tableFile.write((char*)&dataType, sizeof(int));

			int* integerData;
			float* realData;
			string* stringData;

			switch (this->attributes[i].getDatatype())
			{
			case INTEGER:
			{
				integerData = this->attributes[i].getIntergerData();
				if (integerData != nullptr)
				{
				for (int j = 0; j < noRows; j++)
					{
					tableFile.write((char*)&integerData[j], sizeof(int));
					}
				}

			}
			break;
			case REAL:
			{
				realData = this->attributes[i].getFloatData();
				if (realData != nullptr)
				for (int j = 0; j < noRows; j++)
				{
					tableFile.write((char*)&realData[j], sizeof(float));
				}
			}
			break;
			case TEXT:
			{
				stringData = this->attributes[i].getStringData();
				if (stringData != nullptr)
				for (int j = 0; j < noRows; j++)
				{
					tableFile.write(stringData[j].c_str(), sizeof(string));
				}

			}
			break;
			default:
				throw exception("Invalid Data Type");
				break;
			}
		}

		tableFile.close();
		cout << "File saved succesfully"<<endl << endl << endl << endl << endl << endl << endl;
	}
	else {
		cout << "File couldn not be opened";
	}


}

void Table::readTable(string tableName)
{
	ifstream tableFile(tableName, ios::binary);
	if (tableFile) {
		char* c_tableName = new char[tableName.length()];
		strcpy(c_tableName, tableName.c_str());
		this->setName(c_tableName);

		int noAttributes;
		tableFile.read((char*)&noAttributes, sizeof(int));
		this->setNoAttributes(noAttributes);

		this->attributes = new Attribute[noAttributes];


		int attributeNameLength;
		char* attributeName;
		int noRows;
		int dataType;
		int* intArr;
		float* floatArr;
		string* stringArr;

		for (int i = 0; i < noAttributes; i++)
		{
			tableFile.read((char*)&attributeNameLength, sizeof(int));
			attributeNameLength++;
			attributeName = new char[attributeNameLength];

			cout << "pos:" << tableFile.tellg() << endl;
			tableFile.read(attributeName, attributeNameLength * sizeof(char));
			attributeName[attributeNameLength-1] = '\0';
			this->attributes[i].setName(attributeName);


			tableFile.read((char*)&noRows, sizeof(int));
			this->attributes[i].setNoRows(noRows);
			cout << "-" << tableFile.tellg() << endl;



			tableFile.read((char*)&dataType, sizeof(int));
			this->attributes[i].setDatatype(static_cast<Datatype>(dataType));

			delete[] attributeName;
			attributeName = nullptr;


				switch (static_cast<Datatype>(dataType))
				{
				case INTEGER:
				{
					intArr = new int[noRows];

					for (int j = 0; j < noRows; j++)
					{
						tableFile.read((char*)&intArr[j], sizeof(int));
					}
				}
				break;
				case REAL:
				{
					floatArr = new float[noRows];

					for (int j = 0; j < noRows; j++)
					{
						tableFile.read((char*)&floatArr[j] , sizeof(float));
					}
				}
				break;
				case TEXT:
				{
					stringArr = new string[noRows];

					for (int j = 0; j < noRows; j++)
					{
						tableFile.read((char*)&stringArr[j], sizeof(string));
					}
				}
				break;
				default:
					throw exception("Invalid Data Type");
					break;
				}
		}

		cout << "File opened succesfully"<<endl << endl << endl << endl << endl << endl << endl;

	}
	else {
		cout << "file could not be opened";
	}
}

void Table::displayTable()
{
	cout << "Tabel name: " << this->getName() << endl;
	cout << "Number of columns: " << this->getNoAttributes() << endl;
	for (int i = 0; i < this->getNoAttributes(); i++)
	{
		this->attributes[i].displayAttributes();

	}
}



ostream& operator>>(Insert& ins, Table& t)
{
	int noAttributes= t.getNoAttributes();
	int noRows = t.getAttribute()->getNoRows();
	noRows++;

	for (int i = 0; i < noAttributes; i++)
	{
		t.getAttribute()[i].setNoRows(noRows);

		switch (t.getAttribute()[i].getDatatype())
		{
		case INTEGER:
		{
			int intData= stoi(ins.getParams()[i]);
			t.getAttribute()[i].setIntOnSpecifiedPosition(intData, noRows);

		}
		break;
		case REAL:
		{
			int realData = stof(ins.getParams()[i]);
			t.getAttribute()[i].setFloatOnSpecifiedPosition(realData, noRows);
		}
		break;
		case TEXT:
		{			
			string stringData = ins.getParams()[i];
			t.getAttribute()[i].setStringOnSpecifiedPosition(stringData, noRows);
		}
		break;

		cout << endl << "Insert succesfull" << endl<<endl<<endl << endl << endl << endl;
		default:
			throw exception("Invalid Data Type");
			break;
		}
	}
}

ostream& operator<<(ostream& console, Table& t)
{
	console << "Tabel name: " << t.getName() << endl;
	console << "Number of columns: " << t.getNoAttributes() << endl;
	return console;

}

