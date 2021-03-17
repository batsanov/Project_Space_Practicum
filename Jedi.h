#pragma once
#include "Planet.h"
enum jediRank { Youngling, Padawan, Master, Grand_Master };


class Jedi {
private:
	char* name;
	jediRank rank;
	double midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;
public:
	Jedi();
	Jedi(const char*, jediRank, double, Planet, const char*, const char*);
	Jedi(Jedi& other);
	~Jedi();
	Jedi& operator = (const Jedi&);
	

	void print();
	char* getName()const;
	jediRank getRank()const;
	double getMidichlorian()const;
	Planet getPlanet();
	char* getSpicies()const;
	char* getMilitaryRank()const;
	void setName(const char*);
	void setRank(jediRank);
	void setMidichlorian(double);
	void setPlanet(Planet);
	void setSpicies(const char*);
	void setMilitaryRank(const char*);

	friend std::ostream& operator<< (std::ostream&, const Jedi&);
	friend std::istream& operator>> (std::istream&, Jedi&);
};
