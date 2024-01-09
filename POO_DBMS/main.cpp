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
Create create2;

Insert insert;
Insert insertt;

Delete delet;
Drop drop;
Display display;
Select select;
Update update;


int main()
{
	Table tabel;
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
			tabel = create;
			tabel.displayTable();
			tabel.saveTable();

		}break;
		case(DROP):
		{
			drop.parseUserInput(userInput);
			drop.displayAll();
		}break;
		case(DISPLAY):
		{
			display.parseUserInput(userInput);
			cout << display;

		}break;
		case(INSERT):
		{
			insert.parseUserInput(userInput);
			insertt = insert;

			insert.displayAll();
			insertt.displayAll();
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
			cout << delet;
		}break;
		default:
			cout << "comanda necunoscuta" << '\n';
			break;
		}
	}

}