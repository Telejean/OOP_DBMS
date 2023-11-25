#pragma once
#include "CreateParams.h"

#pragma region Constructors
CreateParams::CreateParams()
{
    this->columnName = "default";
    this->columnDefaultValue = "0";
    this->columnSize = 10;
    this->columnType = "int";
}
CreateParams::CreateParams(string columnName, string columnType, int columnSize, string defaultValue)
{
    this->columnName = columnName;
    this->columnDefaultValue = defaultValue;
    this->columnSize = columnSize;
    this->columnType = columnType;

}
#pragma endregion


#pragma region Setters

void CreateParams::setColumnName(string columnName)
{
    this->columnName = columnName;
}

void CreateParams::setColumnType(string columnType)
{
    this->columnType = columnType;

}

void CreateParams::setColumnSize(int columnSize)
{
    this->columnSize = columnSize;
}

void CreateParams::setColumnDefaultValue(string defaultValue)
{
    this->columnDefaultValue = defaultValue;
}
#pragma endregion

#pragma region Getters

string CreateParams::getColumnName()
{
    return this->columnName;
}

string CreateParams::getColumnType()
{
    return this->columnType;
}

int CreateParams::getColumnSize()
{
    return this->columnSize;
}

string CreateParams::getColumnDefaultValue()
{
    return this->columnDefaultValue;
}

#pragma endregion

void CreateParams::parseInput(string input)
{


}