#pragma once
#include <iostream>
using namespace std;

class CreateParams {
	string columnName;
	string columnType;
	int columnSize;
	string columnDefaultValue;

public:
	CreateParams();
	CreateParams(string columnName,string columnType, int columnSize, string defaultValue);
#pragma region Setters
	void setColumnName(string columnName);
	void setColumnType(string columnType);
	void setColumnSize(int columnSize);
	void setColumnDefaultValue(string defaultValue);
#pragma endregion

#pragma region Getters
	string getColumnName();
	string getColumnType();
	int  getColumnSize();
	string getColumnDefaultValue();
#pragma endregion

	void parseInput(string input);

};