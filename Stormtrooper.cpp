#include <iostream>
#include "Stormtrooper.h"
#include <string.h>


Stormtrooper::Stormtrooper() {
	id = type = nullptr;
	rank = A;
	planet.setName("");
	planet.setRepublic("");
	planet.setSystem("");
}
Stormtrooper::Stormtrooper(const char* _id, Rank _rank, const  char* _type, Planet _planet) {
	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
	rank = _rank;
	type = new char[strlen(_type) + 1];
	strcpy_s(type, strlen(_type) + 1, _type);
	planet = _planet;
}
Stormtrooper::Stormtrooper(Stormtrooper& other) {
	this->id = new char[strlen(other.id + 1)];
	strcpy_s(id, strlen(other.id + 1), other.id);
	rank = other.rank;
	this->type = new char[strlen(other.type + 1)];
	strcpy_s(type, strlen(other.type + 1), other.type);
	planet = other.planet;


}
Stormtrooper ::~Stormtrooper() {
	delete[] id;
	delete[]type;
	rank = A;
	planet.setName("");
	planet.setRepublic("");
	planet.setSystem("");
}


void Stormtrooper::print()
{
	std::cout << "Id: " << id << std::endl;
	std::cout << "Rank: " << rank << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Planet: " << planet.getName() << std::endl;
}
char* Stormtrooper::getId()
{
	return this->id;
}
Rank Stormtrooper::getRank()
{
	return this->rank;
}
char* Stormtrooper::getType() {
	return this->type;
}
Planet Stormtrooper::getPlanet()
{
	return  planet;
}

void Stormtrooper::setId(const char* _id) {
	if (id != nullptr)
		delete[] id;

	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
}
void Stormtrooper::setRank(Rank _rank) {
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
