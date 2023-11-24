#pragma once
#include <string>
#include <iostream>
using namespace std;

//CREATE TABLE students ((id, integer, 1000, 0), (nume, text, 128, ’’), (grupa, text,50,’1000’))
//CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), …) 

class userInput {
	string command;
	string tableName;
	int noColumns;
	string *columnName;
	string *type;
	int size;


};