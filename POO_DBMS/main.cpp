#include <iostream>
#include "Database.h"
#include "Attribute.h"
#include "Table.h"
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
Datatype stringToDataType(string userInput) {
	if (userInput == "INTEGER") return INTEGER;
	if (userInput == "REAL") return REAL;
	return TEXT;
}


int main()
{
	/*
	Attribute model, numarUsi;
	numarUsi.setName("Numar usi");
	numarUsi.setDatatype(INTEGER);
	model.setName("Model");
	model.setDatatype(TEXT);

	////vector
    Attribute attributes[40];
	attributes[0] = model;
	attributes[1] = numarUsi;

	Table masini;
	masini.setAttributes(attributes);
	for (int i = 0; i < 3; i++)
	{
		cout <<"    " << attributes[i].getName();
	}
	*/
	
	Comenzi userCommands = DEFAULT;
	string userInput;

	while (userCommands != EXIT)
	{
		cout << "Enter command. Type HELP for more info" << endl;

		cin >> userInput;
		userCommands = stringToCommand(userInput);

		switch (userCommands)
		{
		case(HELP): {
			cout << "Commands: CREATE_TABLE, CREATE_INDEX, CREATE_INDEX, DROP_TABLE, DROP_INDEX, DISPLAY_TABLE, EXIT" << '\n';
		}break;

		case(EXIT):
		{
			cout << "Bye";
		}break;
		case(CREATE_TABLE):
		{
			int noAttributes;
			string name;
			Table t;
			Attribute attributeVector[10];
			cout << "Enter table name: ";
			cin >> name;
			t.setName(name);
			cout << "Enter number of attributes: ";
			cin >> noAttributes;
			cin.get();


			for (int i = 0; i < noAttributes; i++) {
				Attribute a;
				
				cout << "Enter attribute " << i << "'s name: ";
				cin >> name;
				a.setName(name);
				cout << "Enter data type: ";
				cin >> userInput;
				a.setDatatype(stringToDataType(userInput));
				attributeVector[i] = a;
			}


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
			cout << "comanda necunoscuta" << '\n';
			break;
		}
	}

}