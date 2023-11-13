#include <iostream>
#include "getters.h"
#include "dataBaseClass.h"
using namespace std;

enum Comenzi { EXIT, HELP, DEFAULT };

Comenzi stringToCommand(string userInput)
{
	if (userInput == "EXIT") return EXIT;
	if (userInput == "HELP") return HELP;
	return DEFAULT;
}


int main()
{
	Database a;
	cout << a.getTableName();
	testFunction();
	Comenzi userCommands=DEFAULT;
	string userInput;

	while (userCommands != EXIT)
	{
		cout << "Enter command. Type HELP for more info" << endl;

		cin >> userInput;
		userCommands = stringToCommand(userInput);

		switch (userCommands)
		{
		case(HELP):{
			cout << "Here something useful will be written"<<'\n';
		}break;

		case(EXIT):
			{
				cout << "Bye";
			}break;

		default:
			cout << "comanda necunoscuta"<<'\n';
			break;
		}
	}

}