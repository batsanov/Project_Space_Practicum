#pragma once

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