#include <iostream>
#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"
#include <Jedi.cpp>


int main()
{
	Planet fst("Earth", "Dominac", "Tangiers");

	Jedi firstJed("Ivan", B, 10.31, fst, "Athletic ", "frontLiner");
	Stormtrooper firstTroop("184293", C, "fighter", fst);
	firstJed.print();
	firstJed.getPlanet().print();
}

