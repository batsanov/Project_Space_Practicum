#pragma once
#include "Planet.h"
enum Rank { A, B, C, D };


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