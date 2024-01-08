#pragma once
#include <string>
using namespace std;


enum Datatype { INTEGER, REAL, TEXT };

class Attribute {
	char* name;
	Datatype type;
	int* integerData;
	float* floatData;
	string* stringData;
	int noRows;

public:
	Attribute(char* name, Datatype type, int* intergerData, float* floatData, string* stringData, int noRows);
	Attribute(const char* name, Datatype type);
	Attribute();

	//GETTERS
	char* getName();
	Datatype getDatatype();
	int* getIntergerData();
	float* getFloatData();
	string* getStringData();
	int getNoRows();


	//SETTERS
	void setName(char* name);
	void setDatatype(Datatype type);
	void setIntegerData(int* interger);
	void setNoRows(int noRows);
	void setFloatData(float* floatData);
	void setStringData(string* stringData);

	void saveInFile();

	void operator=(Attribute& attribute);

	void displayAttributes();
};