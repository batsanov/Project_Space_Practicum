#include <iostream>
#include "Jedi.h"
#include <string.h>



Jedi::Jedi() {
	name = spicies = militaryRank = nullptr;
	rank = Youngling;
	midichlorian = 0;
	planet.setName("");
	planet.setRepublic("");
	planet.setSystem("");
}

Jedi::Jedi(const char* _name, jediRank _rank, double _midichlorian, Planet _planet, const char* _spicies, const char* _militaryRank) {

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);

	rank = _rank;
	midichlorian = _midichlorian;
	planet = _planet;

	spicies = new char[strlen(_spicies) + 1];
	strcpy_s(spicies, strlen(_spicies) + 1, _spicies);

	militaryRank = new char[strlen(_militaryRank) + 1];
	strcpy_s(militaryRank, strlen(_militaryRank) + 1, _militaryRank);
}

Jedi::Jedi(Jedi& other) {
	this->name = new char[strlen(other.name ) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	rank = other.rank;
	midichlorian = other.midichlorian;
	planet = other.planet;

	this->spicies = new char[strlen(other.spicies) + 1];
	strcpy_s(spicies, strlen(other.spicies) + 1, other.spicies);

	this->militaryRank = new char[strlen(other.militaryRank) + 1];
	strcpy_s(militaryRank, strlen(other.militaryRank ) + 1, other.militaryRank);

}

Jedi::~Jedi() {
	delete[] name;
	delete[] spicies;
	delete[] militaryRank;
	rank = Youngling;
	midichlorian = 0;
}



void Jedi::print() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Rank: " << rank << std::endl;
	std::cout << "Midichlorian: " << midichlorian << std::endl;
	std::cout << "Planet: " << planet.getName() << std::endl;
	std::cout << "Spicies: " << spicies << std::endl;
	std::cout << "militaryRank: " << militaryRank << std::endl;
}
char* Jedi::getName() const {
	return name;
}
jediRank Jedi::getRank()const {
	return rank;
}
double Jedi::getMidichlorian()const {
	return midichlorian;
}
Planet Jedi::getPlanet()  {
	return planet;
}

char* Jedi::getSpicies()const {
	return spicies;
}
char* Jedi::getMilitaryRank() const {
	return militaryRank;
}

void Jedi::setName(const char* _name) {
	if (name != nullptr)
		delete[] name;

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
void Jedi::setRank(jediRank _rank) {
	rank = _rank;
}
void Jedi::setMidichlorian(double _midichlorian) {
	midichlorian = _midichlorian;
}
void Jedi::setPlanet(Planet _planet) {
	planet = _planet;
}

void Jedi::setSpicies(const char* _spicies) {
	if (spicies != nullptr)
		delete[] spicies;

	spicies = new char[strlen(_spicies) + 1];
	strcpy_s(spicies, strlen(_spicies) + 1, _spicies);
}
void Jedi::setMilitaryRank(const char* _militaryRank) {
	if (militaryRank != nullptr)
		delete[] militaryRank;

	militaryRank = new char[strlen(_militaryRank) + 1];
	strcpy_s(militaryRank, strlen(_militaryRank) + 1, _militaryRank);
}

Jedi& Jedi::operator = (const Jedi& otherJedi) {
	if (this != &otherJedi)
	{
		delete[] name;
		delete[] spicies;
		delete[] militaryRank;

		name = new char[strlen(otherJedi.name) + 1];
		strcpy_s(name, strlen(otherJedi.name) + 1, otherJedi.name);

		rank = otherJedi.rank;
		midichlorian = otherJedi.midichlorian;
		planet = otherJedi.planet;

		spicies = new char[strlen(otherJedi.spicies) + 1];
		strcpy_s(spicies, strlen(otherJedi.spicies) + 1, otherJedi.spicies);

		militaryRank = new char[strlen(otherJedi.militaryRank) + 1];
		strcpy_s(militaryRank, strlen(otherJedi.militaryRank) + 1, otherJedi.militaryRank);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os , const Jedi& jedi)
{
	os << "Name: " << jedi.name << std::endl << "Rank: ";
	switch (jedi.rank)
	{
	case Youngling: os << "Youngling" << std::endl;
		break;
	case Padawan: os << "Padawan" << std::endl;
		break;
	case Master :os << "Master" << std::endl;
		break;
	case Grand_Master: os << "Grand Master" << std::endl;
		break;
	default:
		break;
	}
	os << "Midichlorian: " << jedi.midichlorian << std::endl;
	os << "Planet: " << jedi.planet.getName() << std::endl;
	os << "Spicies: " << jedi.spicies << std::endl;
	os << "Military rank: " << jedi.militaryRank << std::endl;


	return os;
}

std::istream& operator>>(std::istream& is, Jedi& jedi)
{
	char buffer[50];

	std::cout << "Enter Jedi's name: ";
	is.getline(buffer, 50);
	jedi.setName(buffer);
	
	std::cout << "Choose between Youngling, Padawan, Master, Grand Master" << std::endl;
	std::cout << "Enter Jedi's rank: ";
	char temp[20];
	is.getline(buffer, 50);
	strcpy_s(temp, 20, buffer);
	if (strcmp(temp, "Youngling") == 0) jedi.setRank(Youngling);
	else if (strcmp(temp, "Padawan") == 0) jedi.setRank(Padawan);
	else if (strcmp(temp, "Master") == 0) jedi.setRank(Master);
	else if (strcmp(temp, "Grand Master") == 0) jedi.setRank(Grand_Master);

	std::cout << "Enter Jedi's midichlorian: ";
	is >> jedi.midichlorian;
	is.ignore();
	is >> jedi.planet;

	std::cout << "Enter Jedi's spicies: ";
	is.getline(buffer, 50);
	jedi.setSpicies(buffer);
	
	std::cout << "Enter Jedi's Military rank: ";
	is.getline(buffer, 50);
	jedi.setMilitaryRank(buffer);
	return is;
}

