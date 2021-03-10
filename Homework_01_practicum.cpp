
#include <iostream>

enum Rank { A,B,C,D};
class Planet {
private:
	char* name;
	char* system;
	char* republic;

public:

	Planet();
	Planet(const char*, const char*, const char*);
	Planet(Planet& otherPlanet);

	void print();
	char* getName();
	char* getSystem();
	char* getRepublic();
	void setName(const char*);
	void setSystem(const char*);
	void setRepublic(const char*);
	Planet& operator = (const Planet& otherPlanet);

	~Planet();
};

class Jedi {
private:
	char* name;
	Rank rank;
	double midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;
public:
	Jedi();
	Jedi(const char*, Rank, double, Planet, const char*, const char*);
	Jedi(Jedi& other);
	~Jedi();
	Jedi& operator = (const Jedi&);

	void print();
	char* getName();
	Rank getRank();
	double getMidichlorian();
	Planet getPlanet();
	char* getSpicies();
	char* getMilitaryRank();
	void setName(const char*);
	void setRank(Rank);
	void setMidichlorian(double);
	void setPlanet(Planet);
	void setSpicies(const char*);
	void setMilitaryRank(const char*);

};

class Stormtrooper {
	private:
	char* id;
	Rank rank;
	char* type;
	Planet planet;
	public:

		Stormtrooper();
		Stormtrooper(const char*, Rank, const char*, Planet);
		Stormtrooper(Stormtrooper& otherStormtrooper);
		~Stormtrooper();
		Stormtrooper& operator=(const Stormtrooper&);

		void print();
		char* getId();
		Rank getRank();
		char* getType();
		Planet getPlanet();
		void setId(const char*);
		void setRank(Rank);
		void setType(const char*);
		void setPlanet(Planet);


};



int main()
{
	Planet fst("Earth", "Dominac", "Tangiers");

	Jedi firstJed("Ivan", B, 10.31, fst, "Athletic ", "frontLiner");
	Stormtrooper firstTroop("184293", C, "fighter", fst);
	firstJed.print();
	firstJed.getPlanet().print();
}

//---------------------------------------------------------------------------------------------------

Jedi::Jedi() {
	name = spicies = militaryRank = nullptr;
	rank = A;
	midichlorian = 0;
	planet.setName("");
	planet.setRepublic("");
	planet.setSystem("");                 
}
Jedi::Jedi(const char* _name, Rank _rank, double _midichlorian, Planet _planet, const char* _spicies, const char* _militaryRank) {

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
	this->name = new char[strlen(other.name + 1)];
	strcpy_s(name, strlen(other.name + 1), other.name);

	rank = other.rank;
	midichlorian = other.midichlorian;
	planet = other.planet;

	this->spicies = new char[strlen(other.spicies + 1)];
	strcpy_s(spicies, strlen(other.spicies + 1), other.spicies);

	this->militaryRank = new char[strlen(other.militaryRank + 1)];
	strcpy_s(militaryRank, strlen(other.militaryRank + 1), other.militaryRank);

}

Jedi::~Jedi() {
	delete[] name;
	delete[] spicies;
	delete[] militaryRank;
	rank = A;
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
char* Jedi::getName() {
	return name;
}
Rank Jedi::getRank(){
	return rank;
}
double Jedi::getMidichlorian() {
	return midichlorian;
}
Planet Jedi::getPlanet() {              
	return planet;
}

char* Jedi::getSpicies() {
	return spicies;
}
char* Jedi::getMilitaryRank() {
	return militaryRank;
}

void Jedi::setName(const char* _name) {
	if (name != nullptr)
		delete[] name;

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
} 
void Jedi::setRank(Rank _rank) {
	rank = _rank;
}
void Jedi::setMidichlorian(double _midichlorian) {
	midichlorian = _midichlorian;
}
void Jedi::setPlanet(Planet _planet) {          // problem
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
//return *this ????????????


//--------------------------------------------------------------------------------------------------


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
	return *this ;
}

//--------------------------------------------------------------------------------------------------------


Planet::Planet() {
	name = system = republic = nullptr;
}
Planet::Planet(const char* _name, const char* _system, const char* _republic ) {
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

