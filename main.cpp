#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "HashMap.h"

using namespace std;

int main(void)
{
	int id;
	Pokemon pokemon;
	HashMap hashMap;
		
	loadGen1(hashMap);

	std::cout << "Welcome to the interactive Pokédex. Type HELP for commands.\n";
	std::string line;
	while (true)
	{
		std::cout << "pokedex> ";
		if (!std::getline(std::cin, line))
			break;

		// trim leading/trailing whitespace
		auto ltrim = [](std::string &s) {
			s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch){ return !std::isspace(ch); }));
		};
		auto rtrim = [](std::string &s) {
			s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch){ return !std::isspace(ch); }).base(), s.end());
		};
		ltrim(line);
		rtrim(line);
		if (line.empty()) continue;

		std::istringstream iss(line);
		std::vector<std::string> tokens;
		std::string tok;
		while (iss >> tok) tokens.push_back(tok);
		if (tokens.empty()) continue;

		// uppercase the command
		std::string keyword = tokens[0];
		std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);

		if (keyword == "EXIT" || keyword == "QUIT")
		{
			break;
		}
		else if (keyword == "HELP")
		{
			std::cout << "Commands:\n  SEARCH <ID>\n  ADD <ID> <NAME> <TYPE1> [TYPE2]\n  DELETE <ID>\n  EXIT / QUIT\n";
			continue;
		}
		else if (keyword == "SEARCH")
		{
			if (tokens.size() < 2) { std::cout << "Usage: SEARCH <ID>\n"; continue; }
			try {
				id = std::stoi(tokens[1]);
			} catch (...) { std::cout << "Invalid ID.\n"; continue; }
			Pokemon* p = hashMap.lookup(id);
			if (p == NULL) { std::cout << "No Pokemon with ID " << id << " found.\n"; continue; }
			pokemon = *p;
			std::cout << "Pokemon nr " << id << " is " << pokemon.name << "!\nTheir types are : " << pokemon.type1;
			if (pokemon.type2 != "") std::cout << " and " << pokemon.type2;
			std::cout << "\n";
		}
		else if (keyword == "ADD")
		{
			if (tokens.size() < 4) { std::cout << "Usage: ADD <ID> <NAME> <TYPE1> [TYPE2]\n"; continue; }
			int newId;
			try { newId = std::stoi(tokens[1]); } catch(...) { std::cout << "Invalid ID.\n"; continue; }
			std::string name = tokens[2];
			std::string type1 = tokens[3];
			std::string type2 = (tokens.size() > 4) ? tokens[4] : "";
			hashMap.insert(newId, {name, type1, type2});
			std::cout << name << " has been added to the pokédex with ID " << newId << ".\n";
		}
		else if (keyword == "DELETE")
		{
			if (tokens.size() < 2) { std::cout << "Usage: DELETE <ID>\n"; continue; }
			int delId;
			try { delId = std::stoi(tokens[1]); } catch(...) { std::cout << "Invalid ID.\n"; continue; }
			Pokemon* p = hashMap.lookup(delId);
			if (p == NULL) {
				std::cout << "No Pokemon with ID " << delId << " found.\n";
				continue;
			}
			std::string name = p->name;
			if (hashMap.remove(delId))
				std::cout << name << " has been removed from the pokédex.\n";
			else
				std::cout << "Error removing " << name << " from the pokédex.\n";
		}
		else
		{
			std::cout << "Unknown command. Type HELP for commands.\n";
		}
	}
	std::cout << std::endl;
	return(0);
}