
#pragma once

#include "Pokemon.h"
#include <string>
#include <iostream>

struct Node {
	int key;
	Pokemon value;
	Node* next;

	Node(int k, Pokemon v) : key(k), value(v), next(NULL) {}
};


class HashMap {
	private:
		static const int NUM_BUCKETS = 15;
		Node* buckets[NUM_BUCKETS];
		int size; // usefull for rehashing for later versions

	public:
		HashMap();
		void insert(int id, Pokemon pokemon);
		Pokemon *lookup(int id);
		bool remove(int id);
		int getSize();
		void addPokemon(HashMap& map, char **argv);
		~HashMap();
};

void loadGen1(HashMap& map);