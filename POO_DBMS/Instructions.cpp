#pragma once
#include <iostream>
#include <string>
#include "Instructions.h"

using namespace std;


//	CREATE = 1, DROP = 2, DISPLAY = 3,
//  INSERT = 4, SELECT = 5, UPDATE = 6, DELETE = 7,
//  UNDEFINED = 0


COMMAND_TYPES converter(string input)
{
	if (input == "CREATE")return COMMAND_TYPES::CREATE;
	if (input == "DROP")return COMMAND_TYPES::DROP;
	if (input == "DISPLAY")return COMMAND_TYPES::DISPLAY;
	if (input == "INSERT")return COMMAND_TYPES::INSERT;
	if (input == "SELECT")return COMMAND_TYPES::SELECT;
	if (input == "UPDATE")return COMMAND_TYPES::UPDATE;
	if (input == "DELETE")return COMMAND_TYPES::DELETE;
	if (input == "EXIT")return COMMAND_TYPES::EXIT;
	if (input == "HELP")return COMMAND_TYPES::HELP;

	return COMMAND_TYPES::UNDEFINED;

}

Instructions::Instructions()
{
	this->command = COMMAND_TYPES::UNDEFINED;
}

Instructions::Instructions(string command)
{
	this->command = command;
}

COMMAND_TYPES Instructions::checkInstruction()
{
	string command=this->command.substr(0, this->command.find(" "));
	return converter(command);
}

string Instructions::getCommand()
{
	return this->command;
}

void Instructions::setCommand(string command)
{
	this->command = command;
}
