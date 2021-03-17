#include <iostream>
#include "Stormtrooper.h"
#include <string.h>


Stormtrooper::Stormtrooper() {
	id = type = nullptr;
	rank = Patroltrooper;
	planet.setName("");
	planet.setRepublic("");
	planet.setSystem("");
}
Stormtrooper::Stormtrooper(const char* _id, trooperRank _rank, const  char* _type, Planet _planet) {
	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
	rank = _rank;
	type = new char[strlen(_type) + 1];
	strcpy_s(type, strlen(_type) + 1, _type);
	planet = _planet;
}
Stormtrooper::Stormtrooper(Stormtrooper& other) {
	this->id = new char[strlen(other.id ) + 1];
	strcpy_s(id, strlen(other.id ) + 1, other.id);
	rank = other.rank;
	this->type = new char[strlen(other.type) + 1];
	strcpy_s(type, strlen(other.type) + 1, other.type);
	planet = other.planet;


}
Stormtrooper ::~Stormtrooper() {
	delete[] id;
	delete[]type;
	rank = Patroltrooper;
	planet.setName("");
	planet.setRepublic("");
	planet.setSystem("");
}


void Stormtrooper::print()
{
	std::cout << "Id: " << id << std::endl;
	std::cout << "Rank: ";
	switch (rank)
	{
	case Patroltrooper: std::cout << "Patroltrooper";
		break;
	case Swamptrooper:std::cout << "Swamptrooper";
		break;
	case Jumptrooper: std::cout << "Jumptrooper";
		break;
	case Deathtrooper: std::cout << "Deathtrooper";
		break;
	default:
		break;
	}
	std::cout << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Planet: " << planet.getName() << std::endl;
}
char* Stormtrooper::getId()const
{
	return this->id;
}
trooperRank Stormtrooper::getRank()const
{
	return this->rank;
}
char* Stormtrooper::getType()const {
	return this->type;
}
Planet Stormtrooper::getPlanet()
{
	return planet;
}

void Stormtrooper::setId(const char* _id) {
	if (id != nullptr)
		delete[] id;

	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
}
void Stormtrooper::setRank(trooperRank _rank) {
	rank = _rank;
}
void Stormtrooper::setType(const char* _type) {
	if (type != nullptr)
		delete[] type;

	type = new char[strlen(_type) + 1];
	strcpy_s(type, strlen(_type) + 1, _type);
}
void Stormtrooper::setPlanet(Planet _planet) {
	planet = _planet;
}

Stormtrooper& Stormtrooper :: operator = (const Stormtrooper& otherStormtrooper) {
	if (this != &otherStormtrooper) {
		delete[] id;
		delete[] type;

		id = new char[strlen(otherStormtrooper.id) + 1];
		strcpy_s(id, strlen(otherStormtrooper.id) + 1, otherStormtrooper.id);

		rank = otherStormtrooper.rank;

		type = new char[strlen(otherStormtrooper.type) + 1];
		strcpy_s(type, strlen(otherStormtrooper.type) + 1, otherStormtrooper.type);

		planet = otherStormtrooper.planet;
	}
	return *this;
}

std::istream& operator>>(std::istream& is , Stormtrooper& troop)
{
	char buffer[50];

	std::cout << "Enter Stormtrooper's id: ";
	is.getline(buffer, 50);
	troop.setId(buffer);

	std::cout << "Choose between Patroltrooper, Swamptrooper, Jumptrooper or Deathtrooper" << std::endl;
	std::cout << "Enter Stormtrooper's rank: ";
	is.getline(buffer, 50);
	char temp[20];
	strcpy_s(temp, 20,buffer);
	if (strcmp(temp, "Patroltrooper") == 0) troop.setRank(Patroltrooper);
	else if (strcmp(temp, "Swamptrooper") == 0) troop.setRank(Swamptrooper);
	else if (strcmp(temp, "Jumptrooper") == 0) troop.setRank(Jumptrooper);
	else if (strcmp(temp, "Deathtrooper") == 0) troop.setRank(Deathtrooper);

	std::cout << "Enter Stormtrooper's type: ";
	is.getline(buffer, 50);
	troop.setType(buffer);

	std::cout << "Enter Stormtrooper's planet: ";
		is >> troop.planet;

		return is;
}

std::ostream& operator<<(std::ostream& os,  Stormtrooper trooper)
{
	os << "Id: " << trooper.id << std::endl;
	os << "Rank: ";
	switch (trooper.rank)
	{
	case Patroltrooper: std::cout << "Patroltrooper";
		break;
	case Swamptrooper:std::cout << "Swamptrooper";
		break;
	case Jumptrooper: std::cout << "Jumptrooper";
		break;
	case Deathtrooper: std::cout << "Deathtrooper";
		break;
	default:
		break;
	}
	
	std::cout << std::endl;
	std::cout << "Type: " << trooper.type << std::endl;
	std::cout << "Planet: " << trooper.getPlanet().getName() << std::endl;
	return os;
}
