#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Attribute.h"
using namespace std;

	Attribute::Attribute(string name, Datatype type) {
		this-> name = name;
		this->type = type;
	}
	Attribute::Attribute() {
		this->name = "";
		this->type = INTEGER;
	}
	string Attribute::getName() {
		return this->name;
	}
	Datatype Attribute::getDatatype(Datatype type) {
		return this->type;
	}
	void Attribute::setName(string name) {
		this->name = name;
	}
	void Attribute::setDatatype() {
		this->type = type;
	}
	