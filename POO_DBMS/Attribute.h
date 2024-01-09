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
	int maxRows;

public:
	Attribute(char* name, Datatype type, int* intergerData, float* floatData, string* stringData, int noRows, int maxRows);
	Attribute(const char* name, Datatype type);
	Attribute();

	//GETTERS
	char* getName();
	Datatype getDatatype();
	int* getIntergerData();
	float* getFloatData();
	string* getStringData();
	int getNoRows();
	int getMaxRows();


	//SETTERS
	void setMaxRows(int max);
	void setName(char* name);
	void setDatatype(Datatype type);
	void setIntegerData(int* interger);
	void setNoRows(int noRows);
	void setFloatData(float* floatData);
	void setStringData(string* stringData);
	void setIntOnSpecifiedPosition(int n, int i);
	void setFloatOnSpecifiedPosition(int f, int i);
	void setStringOnSpecifiedPosition(string s, int i);

	void saveInFile(char* filename, ostream f);

	void operator=(Attribute& attribute);

	void displayAttributes();
};