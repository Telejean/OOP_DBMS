#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Attribute.h"
using namespace std;

	Attribute::Attribute(char* name, Datatype type) {
		this->name = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name) + 1; i++) {
			this->name[i] = name[i];
		}
		this->type = type;
	}
	Attribute::Attribute() = default;
	char* Attribute::getName() {
		char* copy = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name) + 1; i++) {
			copy[i] = name[i];
		}
		return copy;
	}
	Datatype Attribute::getDatatype() {
		return this->type;
	}
	void Attribute::setName(char* name) {
		for (int i = 0; i < strlen(name) + 1; i++) {
			this->name[i] = name[i];
		}
	}
	void Attribute::setDatatype(Datatype type) {
		this->type = type;
	}
	
	void Attribute::operator=(Attribute& a)
	{
		this->name = a.name;
		this->type = a.type;
	}
	