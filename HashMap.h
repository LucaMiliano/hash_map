#include "Pokemon.h"

#pragma once

struct Node {
	int key;
	Pokemon value;
	Node* next;

	Node(int k, Pokemon v) : key(k), value(v), next(NULL) {}
};


class HashMap {
	private:
		static const int NUM_BUCKETS = 16;
		Node* buckets[NUM_BUCKETS];
		int size; // usefull for rehashing for later versions

	public:
		HashMap();
		void insert(int id, Pokemon pokemon);
		Pokemon *lookup(int id);
		bool remove(int id);
		int getSize();
		~HashMap();
};

void loadGen1(HashMap& map);