#include "data.h"
#include <fstream>
using std::fstream;
using std::cout;

void data::set(int k, string d)
{
	this->k = k;
	this->d = d;
}

void data::set(int k)
{
	this->k = k;
}

ostream& operator<<(ostream& os, const data& dt)
{
	os << dt.k << " | " << dt.d;
	return os;
}

void set_up(data* o, int size) {
	fstream f1, f2;
	string d;
	int k{};
	f1.open("names.txt");
	f2.open("numbers.txt");

	for (int i = 0; i < size; i++) {
		f1 >> d;
		f2 >> k;
		o[i].set(k, d);
	}

	f1.close();
	f2.close();
}

void show(data* o) {
	for (int i = 0; i < 10; i++) {
		cout << o[i] << "\n";
	}
}