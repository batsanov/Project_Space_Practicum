#pragma once
#include "Planet.h"

enum Rank { A, B, C, D };


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
