#include "HashMap.h"

HashMap::HashMap() : size(0)
{
	for (int i = 0; i < NUM_BUCKETS; i++){
		buckets[i] = NULL;
	}
}

void HashMap::insert(int id, Pokemon pokemon)
{
	int index = id % NUM_BUCKETS;
	Node* current = buckets[index];

	while (current != NULL) {
		if (current->key == id) {
			current->value = pokemon;
			return ;
		}
		current = current->next;
	}

	Node* newNode = new Node(id, pokemon);
	newNode->next = buckets[index];
	buckets[index] = newNode;
	size++;
}

Pokemon *HashMap::lookup(int id)
{
	int index = id % NUM_BUCKETS;
	Node* current = buckets[index];

		while (current != NULL) {
		if (current->key == id) {
			return(&current->value);
		}
		current = current->next;
	}
	return NULL;
}

bool HashMap::remove(int id){
	int index = id % NUM_BUCKETS;
	Node* current = buckets[index];
	Node* prev = NULL;

	while (current != NULL) {
		if (current->key == id) {
			if (prev == NULL) {
				buckets[index] = current->next;
			} else {
				prev->next = current->next;
			}
			delete current ;
			size--;
			return true;
		}
		prev = current;
		current = current->next;
	}
	return false; // id not found
}

int HashMap::getSize(){
	return size;
}

HashMap::~HashMap() {
	for (int i = 0; i < NUM_BUCKETS; i++) {
		Node* current = buckets[i];
		while (current != NULL) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}
}