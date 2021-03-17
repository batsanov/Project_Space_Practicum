#include <iostream>
#include "Planet.h"
#include <string.h>

Planet::Planet() {
	name = system = republic = nullptr;
}
Planet::Planet(const char* _name, const char* _system, const char* _republic, type _typePlanet) {
	this->name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);

	this->system = new char[strlen(_system) + 1];
	strcpy_s(system, strlen(_system) + 1, _system);

	this->republic = new char[strlen(_republic) + 1];
	strcpy_s(republic, strlen(_republic) + 1, _republic);

	typePlanet = _typePlanet;
}
Planet::Planet(Planet& otherPlanet) {
	this->name = new char[strlen(otherPlanet.name) + 1];
	strcpy_s(name, strlen(otherPlanet.name) + 1, otherPlanet.name);

	this->system = new char[strlen(otherPlanet.system) + 1];
	strcpy_s(system, strlen(otherPlanet.system) + 1, otherPlanet.system);

	this->republic = new char[strlen(otherPlanet.republic) + 1];
	strcpy_s(republic, strlen(otherPlanet.republic) + 1, otherPlanet.republic);
	typePlanet = otherPlanet.typePlanet;
}
Planet::~Planet() {
	delete[] name;
	delete[] system;
	delete[] republic;
}


void Planet::setName(const char* _name) {
	if (name != nullptr)
		delete[] name;

	int length = strlen(_name) + 1;
	this->name = new char[length];
	strcpy_s(name, length, _name);
}
void Planet::setSystem(const char* _system) {
	if (system != nullptr)
		delete[] system;

	int length = strlen(_system) + 1;
	this->system = new char[length];
	strcpy_s(system, length, _system);
}


void Planet::setRepublic(const char* _republic) {
	if (republic != nullptr)
		delete[] republic;

	int length = strlen(_republic) + 1;
	this->republic = new char[length];
	strcpy_s(republic, length, _republic);
}

void Planet::setType(type other)
{
	this->typePlanet = other;
}

char* Planet::getName() const {
	return this->name;
}
char* Planet::getSystem() const {
	return this->system;
}
char* Planet::getRepublic() const {
	return this->republic;
}

type Planet::getType()const
{
	return this->typePlanet;

	return type();
}



Planet& Planet:: operator= (const Planet& otherPlanet) {
	if (this != &otherPlanet) {
		delete[] name;
		delete[] system;
		delete[] republic;


		typePlanet = otherPlanet.typePlanet;
		this->name = new char[strlen(otherPlanet.name) + 1];
		strcpy_s(name, strlen(otherPlanet.name) + 1, otherPlanet.name);

		this->system = new char[strlen(otherPlanet.system) + 1];
		strcpy_s(system, strlen(otherPlanet.system) + 1, otherPlanet.system);

		this->republic = new char[strlen(otherPlanet.republic) + 1];
		strcpy_s(republic, strlen(otherPlanet.republic) + 1, otherPlanet.republic);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Planet& planet)
{
	os << "Name: " << planet.name << std::endl;
	os << "System: " << planet.system << std::endl;
	os << "Republic: " << planet.republic << std::endl;

	os << "Type: ";

	switch (planet.typePlanet)
	{
	case Chthonian_planet: os << "Chtonian planet" << std::endl;
		break;
	case Carbon_planet: os << "Carbon planet" << std::endl;
		break;
	case Coreless_planet: os << "Coreless planet" << std::endl;
		break;
	case Desert_planet: os << "Desert planet" << std::endl;
		break;
	default:
		break;
	}
	return os;
}

std::istream& operator>>(std::istream& is , Planet& planet)
{
	char buffer[50];

	std::cout << "Enter planet's name: ";
	is.getline(buffer, 50);
	planet.setName(buffer);

	std::cout << "Enter planet's system: ";
	is.getline(buffer, 50);
	planet.setSystem(buffer);

	std::cout << "Enter planet's republic: ";
	is.getline(buffer, 50);
	planet.setRepublic(buffer);

	
	char temp[20];
	std::cout << "Choose between Chthonian planet, Carbon planet, Coreless planet or Desert planet" << std::endl;
	std::cout << "Enter planet's type: ";
	is.getline(temp, 20);
	
	if (strcmp(temp, "Chthonian planet")  == 0) planet.setType(Chthonian_planet);
	else if (strcmp(temp, "Carbon planet") == 0) planet.setType(Carbon_planet);
	else if (strcmp(temp, "Coreless planet") == 0) planet.setType(Coreless_planet);
	else if (strcmp(temp, "Desert planet") == 0) planet.setType(Desert_planet);
		
	return is;
}
