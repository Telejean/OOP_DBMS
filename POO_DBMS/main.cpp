#include <iostream>
#include "Database.h"
#include "Attribute.h"
#include "Table.h"
#include "Instructions.h"
#include "Create.h"
#include <fstream>

using namespace std;

//Instruction Variant  Specifier
//   INSERT    INTO     studenti VALUES (1,”John”,”1001”)

Create create;

int main()
{
	ifstream Commands("Commands.txt");
	string userInput;
	getline(Commands, userInput);

	Instructions instruction(userInput);
	COMMAND_TYPES command= instruction.checkInstruction();




	//Comenzi userCommands = DEFAULT;
	while (command != EXIT)
	{
		cout << "Enter command. Type HELP for more info" << endl;

		//cin >> userInput;
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
			CreateParams x;
			cout << create.getCondition() << endl;
			cout << create.getIdentifier() << endl;
			cout << create.getNoColumns() << endl;
			cout << create.getVariant() << endl;

		}break;
		case(DROP):
		{

		}break;
		case(DISPLAY):
		{

		}break;
		case(INSERT):
		{

		}break;
		case(SELECT):
		{

		}break;
		case(UPDATE):
		{

		}break;
		case(DELETE):
		{

		}break;
		default:
			cout << "comanda necunoscuta" << '\n';
			break;
		}
	}

}