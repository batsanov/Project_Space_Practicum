#include <iostream>
#include "Planet.h"
#include "Stormtrooper.h"
#include "Jedi.h"


int main()
{
	Planet fst("Earth", "Dominac", "Tangiers", Chthonian_planet);
	Jedi firstJed("Ivan", Padawan, 10.31, fst, "Athletic ", "frontLiner");
	Stormtrooper firstTroop("184293", Patroltrooper, "fighter", fst);

	print(fst); 
	std::cout << std::endl;
	print(firstTroop);
	std::cout << std::endl;
	print(firstJed);
    std::cout << std::endl;

	Stormtrooper secondTroop;
	std::cin >> secondTroop;
	print(secondTroop);
	std::cout << std::endl;

	Jedi secondJedi;
	getUserInput(secondJedi);
	print(secondJedi);
}
