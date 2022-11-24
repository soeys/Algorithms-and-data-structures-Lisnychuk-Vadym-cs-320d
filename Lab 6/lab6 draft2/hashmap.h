#pragma once
#include "data.h"

class hashmap
{
	static const int capacity = 25;
	data table[capacity];
	int hashFunction(data o);
	int hashFunction(int k);
public:
	void add(data o);
	void add(int k, string d);
	void remove(int index);
	void show();
	bool isFull();
	bool isEmpty();
	int search(int k);
};