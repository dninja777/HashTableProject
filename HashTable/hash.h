#pragma once

#include "pch.h"
#include <iostream>
#include <string>





class hash {

private:
	static const int tableSize = 10;

	struct item {
		std::string name;
		std::string drink;
		item* next;
	};

	item* HashTable[tableSize];


public:
	hash();
	int Hash(std::string key);
	void AddItem(std::string name, std::string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();

};