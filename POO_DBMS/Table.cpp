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
		strcpy(copy, this->name);

	}
	else {
		copy = nullptr;
	}
	return copy;

}
Attribute* Table::getAttribute() {
	Attribute* copy;
	if (this->attributes != nullptr)
	{
		int arrSize = this->getNoAttributes();
		 copy = new Attribute[arrSize];
		 for (int i = 0; i < arrSize; i++)
			 copy[i] = this->attributes[i];
	}
	else {
		copy = nullptr;
	}
	cout << "attributes returned!" << '\n';
	return copy;
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

		delete[] name;

		//for (int i = 0; i < noAttributes; ++i) {
		//	delete[] this->attributes[i].dealocateName();
		//	delete[] this->attributes[i].dealocateFloatData();
		//	delete[] this->attributes[i].dealocateIntegerData();
		//	delete[] this->attributes[i].dealocateStringData();
		//}

		for (int i = 0; i < noAttributes; i++)
			this->attributes[i].~Attribute();
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
		int noRows= this->attributes[0].getNoRows();
		int* integerData = new int[noRows];
		float* realData= new float[noRows];
		string* stringData= new string[noRows];

		for (int i = 0; i < this->getNoAttributes(); i++)
		{
			//2. We write the lenght of the name of the attribute
			int lenghtOfName = strlen(this->attributes[i].getName());
			tableFile.write((char*)&lenghtOfName, sizeof(int));


			//3. We write the name of the attribute
			char* attributeName= new char[lenghtOfName];
			strcpy(attributeName, this->attributes[i].getName());
			tableFile.write(attributeName, lenghtOfName* sizeof(char));


			//4. We write the number of entries the attribute has
			int noRows = this->attributes[i].getNoRows();
			tableFile.write((char*)&noRows, sizeof(int));


			//5. We write the data type

			int dataType = this->attributes[i].getDatatype();
			tableFile.write((char*)&dataType, sizeof(int));

			

			switch (this->attributes[i].getDatatype())
			{
			case INTEGER:
			{
				integerData = this->attributes[i].getIntergerData();
				if (integerData != nullptr)
				{
				for (int j = 0; j < noRows; j++)
					{
					//cout << "intData: " << integerData[j] << " ";
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
					cout << "stringData: " << stringData << " ";
					tableFile.write(stringData[j].c_str(), sizeof(string));
				}

			}
			break;
			default:
				throw exception("Invalid Data Type");
				break;
			}
			cout << endl;
		}

		tableFile.close();
		cout << "File saved succesfully"<<endl << endl << endl;
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

		tableFile.read((char*)&attributeNameLength, sizeof(int));
		attributeNameLength++;
		attributeName = new char[attributeNameLength];

		tableFile.read(attributeName, attributeNameLength * sizeof(char) - 1);
		attributeName[attributeNameLength - 1] = '\0';

		this->attributes[0].setName(attributeName);


		tableFile.read((char*)&noRows, sizeof(int));
		this->attributes[0].setNoRows(noRows);

		intArr = new int[noRows];
		floatArr = new float[noRows];
		stringArr = new string[noRows];

		tableFile.read((char*)&dataType, sizeof(int));
		this->attributes[0].setDatatype(static_cast<Datatype>(dataType));

		delete[] attributeName;
		attributeName = nullptr;


		cout << "noRows" << noRows<<endl;
		cout << "Attribute 0:" << endl;
		switch (static_cast<Datatype>(dataType))
		{
		case INTEGER:
		{
			for (int j = 0; j < noRows; j++)
			{
				tableFile.read((char*)&intArr[j], sizeof(int));
				cout << "intArr " << j << ": " << intArr[j] << " ";
			}
			cout << endl;
		}
		break;
		case REAL:
		{
			for (int j = 0; j < noRows; j++)
			{
				tableFile.read((char*)&floatArr[j], sizeof(float));
			}
		}
		break;
		case TEXT:
		{
			for (int j = 0; j < noRows; j++)
			{
				tableFile.read((char*)&stringArr[j], sizeof(string));
				cout << "stringArr " << j << ": " << stringArr[j] << " ";
			}
			cout << endl;
		}
		break;
		default:
			throw exception("Invalid Data Type");
			break;
		}

		for (int i = 1; i < noAttributes; i++)
		{
			cout << "Attribute " << i << endl;
			tableFile.read((char*)&attributeNameLength, sizeof(int));
			attributeNameLength++;
			attributeName = new char[attributeNameLength];

			tableFile.read(attributeName, attributeNameLength * sizeof(char)-1);
			attributeName[attributeNameLength-1] = '\0';

			this->attributes[i].setName(attributeName);
			

			tableFile.read((char*)&noRows, sizeof(int));
			this->attributes[i].setNoRows(noRows);



			tableFile.read((char*)&dataType, sizeof(int));
			this->attributes[i].setDatatype(static_cast<Datatype>(dataType));
			cout << "Data type: " << dataType << endl;
			delete[] attributeName;
			attributeName = nullptr;

				switch (static_cast<Datatype>(dataType))
				{
				case INTEGER:
				{

					for (int j = 0; j < noRows; j++)
					{
						tableFile.read((char*)&intArr[j], sizeof(int));
						cout<<"intArr "<<j<<": " << intArr[j] << " ";
					}
					cout << endl;
				}
				break;
				case REAL:
				{

					for (int j = 0; j < noRows; j++)
					{
						tableFile.read((char*)&floatArr[j] , sizeof(float));
					}
				}
				break;
				case TEXT:
				{

					for (int j = 0; j < noRows; j++)
					{
						tableFile.read((char*)&stringArr[j], sizeof(string));
						cout << "stringArr " << j << ": " << stringArr[j] << " ";
					}
					cout << endl;
				}
				break;
				default:
					throw exception("Invalid Data Type");
					break;
				}
				cout << endl;
		}
		tableFile.close();
		cout << "File read succesfully"<<endl << endl << endl;
		
	}
	else {
		cout << "file could not be opened";
	}
}

void Table::displayTable()
{
	cout << endl << "DISPLAYING TABLE" << endl;
	cout << "Tabel name: " << this->getName() << endl;
	cout << "Number of columns: " << this->getNoAttributes() << endl;
	cout << "Number of rows: " << this->attributes->getNoRows() << endl<<endl;
	for (int i = 0; i < this->getNoAttributes(); i++)
	{
		this->attributes[i].displayAttributes();

	}
}



ostream& operator>>(Insert& ins, Table& t)
{
	int noAttributes= t.getNoAttributes();
	Attribute* attributes = new Attribute[noAttributes];
	attributes = t.getAttribute();
	int noRows = attributes[0].getNoRows();
	noRows++;
	cout << noRows << endl;
	for (int i = 0; i < noAttributes; i++)
	{
		attributes[i].setNoRows(noRows);

		switch (attributes[i].getDatatype())
		{

		case INTEGER:
		{		
			int intData= stoi(ins.getParams()[i]);
			attributes[i].setIntOnSpecifiedPosition(intData, noRows-1);
			cout << "intData-a: " << intData << " ";
			cout << "   testpt2: " << attributes[i].getIntergerData()[noRows-1]<<endl;
		}
		break;
		case REAL:
		{
			int realData = stof(ins.getParams()[i]);
			attributes[i].setFloatOnSpecifiedPosition(realData, noRows-1);
		}
		break;
		case TEXT:
		{			
			string stringData = ins.getParams()[i];
			attributes[i].setStringOnSpecifiedPosition(stringData, noRows-1);
			cout << "stringData: " << stringData<<" ";
			cout << "testString2: " << attributes[i].getStringData()[noRows - 1]<<endl;
		}
		break;

		cout << endl << "Insert succesfull" << endl<<endl<<endl;
		default:
			throw exception("Invalid Data Type");
			break;
		}
		t.setAttributes(attributes);
		cout << endl;
	}
}

ostream& operator<<(ostream& console, Table& t)
{
	console << "Tabel name: " << t.getName() << endl;
	console << "Number of columns: " << t.getNoAttributes() << endl;
	return console;

}

