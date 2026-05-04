#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

int main(int argc, char **argv)
{
	int id;
	Pokemon pokemon;
	HashMap hashMap;

	loadGen1(hashMap);
	if (argc == 2)
	{
		id = stoi(argv[1]);
		pokemon = *hashMap.lookup(id);
	}
	else
	{
		return(1);
	}
	std::cout << "Pokemon nr " << id << " is " << pokemon.name << "!\nTheir types are : " << pokemon.type1;
	if (pokemon.type2 != "")
		std::cout << " and " << pokemon.type2;
	std::cout << std::endl;
	return(0);
}