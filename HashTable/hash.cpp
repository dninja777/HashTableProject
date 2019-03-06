
#include "pch.h"
#include <iostream>
#include <string>

#include "hash.h"


hash::hash() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
		
	}
}

void hash::AddItem(std::string name, std::string drink) {
	int index = Hash(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* Ptr = HashTable[index];
		item* n = new item;

		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (Ptr->next != NULL) {
			Ptr = Ptr->next ;
		}
		Ptr->next = n;
	}
}


int hash::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else {
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;

		}
	}
	return count;
}

void hash::PrintTable() {
	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		std::cout << "---------------------------------\n";
		std::cout << "index = " << i << std::endl;
		std::cout << HashTable[i]->name << std::endl;
		std::cout << HashTable[i]->drink << std::endl;
		std::cout << "# of items = " << number << std::endl;
		std::cout << "---------------------------------\n";
	}
}

int hash::Hash(std::string key) {
	 
	int hash = 0;
	int index;

	

	for (int i = 0; i < key.length(); i++) {

		hash = hash + (int)key[i];
		std::cout << "Hash = " << hash << std::endl;
	}



	/*std::cout << "key[0] = " << (int)key[0] << std::endl;
	std::cout << "key[1] = " << (int)key[1] << std::endl;
	std::cout << "key[2] = " << (int)key[2] << std::endl;
	std::cout << "key[3] = " << (int)key[3] << std::endl;
	std::cout << "key[4] = " << (int)key[4] << std::endl;*/

	index = hash % tableSize;

	

	return index;
}