#include <iostream>
#include "Database.h"
#include "Attribute.h"
#include "Table.h"
#include "Instructions.h"
#include "Create.h"
#include "Insert.h"
#include "Delete.h"
#include "Drop.h"
#include "Display.h"
#include "Select.h"
#include "Update.h"
#include <fstream>

using namespace std;


Create create;
Insert insert;
Delete delet;
Drop drop;
Display display;
Select select;
Update update;

int main()
{
	string userInput;
	Instructions instruction;
	COMMAND_TYPES command = UNDEFINED;

	while (command != EXIT)
	{
		cout << "Enter command. Type HELP for more info" << endl;
		getline(cin, userInput);
		instruction.setCommand(userInput);
		command = instruction.checkInstruction();

		switch (command)
		{
		case(HELP): {
			cout << "Commands: CREATE, DROP, DISPLAY, INSERT,SELECT, UPDATE, DELETE, HELP, EXIT" << '\n';
		}break;

		case(EXIT):
		{
			cout << "Bye";
		}break;
		case(CREATE):
		{
			create.parseUserInput(userInput);
			create.displayAll();

		}break;
		case(DROP):
		{
			drop.parseUserInput(userInput);
			drop.displayAll();
		}break;
		case(DISPLAY):
		{
			display.parseUserInput(userInput);
			display.displayAll();
		}break;
		case(INSERT):
		{
			insert.parseUserInput(userInput);
			insert.displayAll();
		}break;
		case(SELECT):
		{
			select.parseUserInput(userInput);
			select.displayAll();
		}break;
		case(UPDATE):
		{
			update.parseUserInput(userInput);
			update.displayAll();
		}break;
		case(DELETE):
		{
			delet.parseUserInput(userInput);
			delet.displayAll();
		}break;
		default:
			cout << "comanda necunoscuta" << '\n';
			break;
		}
	}

}