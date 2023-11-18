#include <iostream>
#include "Database.h"
using namespace std;

enum Comenzi { EXIT, HELP, CREATE_TABLE, CREATE_INDEX, DROP_TABLE, DROP_INDEX, DISPLAY_TABLE, DEFAULT };

Comenzi stringToCommand(string userInput)
{
	if (userInput == "EXIT") return EXIT;
	if (userInput == "CREATE TABLE") return CREATE_TABLE;
	if (userInput == "CREATE INDEX") return CREATE_INDEX;
	if (userInput == "DROP TABLE") return DROP_TABLE;
	if (userInput == "DROP INDEX") return DROP_INDEX;
	if (userInput == "DISPLAY TABLE") return DISPLAY_TABLE;
	if (userInput == "HELP") return HELP;
	return DEFAULT;
}


int main()
{
	Attribute g = Attribute("audi", INTEGER), h= Attribute("benz", TEXT);

	cout << g.getName() << " " << g.getDatatype() << endl;
	cout << h.getName() << " " << h.getDatatype() << endl;
	

	Table t = ("masini", );
	cout << t.getAttribute();
	Database db = ("Vehicule Transport", t);
	cout << db.getTables();
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
		case(CREATE_TABLE):
		{
			
		}break;
		case(CREATE_INDEX):
		{

		}break;
		case(DROP_TABLE):
		{

		}break;
		case(DROP_INDEX):
		{

		}break;
		case(DISPLAY_TABLE): 
		{

		}break;
		default:
			cout << "comanda necunoscuta"<<'\n';
			break;
		}
	}

}