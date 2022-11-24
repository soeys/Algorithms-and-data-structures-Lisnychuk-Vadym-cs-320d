#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

struct data
{
	int k;
	string d;

	void set(int k, string d);
	void set(int k);
	friend ostream& operator<<(ostream& os, const data& dt);
};

void set_up(data* o, int size);
void show(data* o);