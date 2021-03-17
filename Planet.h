#pragma once
#include <iostream>

template <class T>

void print(T& someClass)
{
	std::cout << someClass;
}

template <class T>
void getUserInput(T& someClass)
{
	std::cin >> someClass;
}

enum type { Chthonian_planet, Carbon_planet, Coreless_planet, Desert_planet };

class Planet {
private:
	char* name;
	char* system;
	char* republic;
	type typePlanet;

public:

	Planet();
	Planet(const char*, const char*, const char*, type);
	Planet(Planet& otherPlanet);
	~Planet();
	Planet& operator = (const Planet& otherPlanet);

	char* getName()const;
	char* getSystem()const;
	char* getRepublic()const;
	type getType()const;


	void setName(const char*);
	void setSystem(const char*);
	void setRepublic(const char*);
	void setType(type);
	

	friend std::ostream& operator<<(std::ostream& , const Planet& );
	friend std::istream& operator>>(std::istream&, Planet&);
};

