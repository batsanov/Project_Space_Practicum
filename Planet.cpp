#include <iostream>
#include "Planet.h"
#include <string.h>

Planet::Planet() {
	name = system = republic = nullptr;
}
Planet::Planet(const char* _name, const char* _system, const char* _republic) {
	this->name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);

	this->system = new char[strlen(_system) + 1];
	strcpy_s(system, strlen(_system) + 1, _system);

	this->republic = new char[strlen(_republic) + 1];
	strcpy_s(republic, strlen(_republic) + 1, _republic);
}
Planet::Planet(Planet& otherPlanet) {
	this->name = new char[strlen(otherPlanet.name) + 1];
	strcpy_s(name, strlen(otherPlanet.name) + 1, otherPlanet.name);

	this->system = new char[strlen(otherPlanet.system) + 1];
	strcpy_s(system, strlen(otherPlanet.system) + 1, otherPlanet.system);

	this->republic = new char[strlen(otherPlanet.republic) + 1];
	strcpy_s(republic, strlen(otherPlanet.republic) + 1, otherPlanet.republic);
}
Planet::~Planet() {
	delete[] name;
	delete[] system;
	delete[] republic;
}
void Planet::print() {
	std::cout << "Planet's name: " << this->name << std::endl;
	std::cout << "Planet's System: " << this->system << std::endl;
	std::cout << "Planet's Republic: " << this->republic << std::endl;
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

char* Planet::getName() {
	return this->name;
}
char* Planet::getSystem() {
	return this->system;
}
char* Planet::getRepublic() {
	return this->republic;
}

Planet& Planet:: operator= (const Planet& otherPlanet) {
	if (this != &otherPlanet) {
		delete[] name;
		delete[] system;
		delete[] republic;

		this->name = new char[strlen(otherPlanet.name) + 1];
		strcpy_s(name, strlen(otherPlanet.name) + 1, otherPlanet.name);

		this->system = new char[strlen(otherPlanet.system) + 1];
		strcpy_s(system, strlen(otherPlanet.system) + 1, otherPlanet.system);

		this->republic = new char[strlen(otherPlanet.republic) + 1];
		strcpy_s(republic, strlen(otherPlanet.republic) + 1, otherPlanet.republic);
	}
	return *this;
}