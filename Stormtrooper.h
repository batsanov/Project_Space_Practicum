#pragma once
#include "Planet.h"

enum trooperRank {
  Patroltrooper, Swamptrooper, Jumptrooper, Deathtrooper
};


class Stormtrooper {
private:
	char* id;
	trooperRank rank;
	char* type;
	Planet planet;
public:

	Stormtrooper();
	Stormtrooper(const char*, trooperRank, const char*, Planet);
	Stormtrooper(Stormtrooper& otherStormtrooper);
	~Stormtrooper();
	Stormtrooper& operator=(const Stormtrooper&);

	void print();
	char* getId() const;
	trooperRank getRank() const;
	char* getType() const;
	Planet getPlanet();
	void setId(const char*);
	void setRank(trooperRank);
	void setType(const char*);
	void setPlanet(Planet);

	friend std::istream& operator >> (std::istream&, Stormtrooper&);
	friend std::ostream& operator << (std::ostream&, const Stormtrooper);
};
