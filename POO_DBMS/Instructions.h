#pragma once
#include <string>
#include <iostream>
using namespace std;

//CREATE TABLE students ((id, integer, 1000, 0), (nume, text, 128, ’’), (grupa, text,50,’1000’))
//CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), …) 

enum COMMAND_TYPES
{
	HELP = 8,
	CREATE = 1, DROP = 2, DISPLAY = 3,
	INSERT = 4, SELECT = 5, UPDATE = 6, DELETE = 7,
	UNDEFINED = 0, EXIT = -1
};


class Instructions {
	string command;

public:
	Instructions();
	Instructions(string command);
	COMMAND_TYPES checkInstruction();
	string getCommand();
	void setCommand(string command);
	
};