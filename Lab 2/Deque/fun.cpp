#include "deq.h"
#include "fun.h"
#include <fstream>
using std::fstream;
#include <iostream>

void fill(deq& d) {
	fstream f;
	int temp;
	f.open("data.txt");
	while (!f.eof()) {
		f >> temp;
		d.push_back(temp);
	}
	f.close();
}

void show(deq d) {
	while (!d.empty()) {
		std::cout << d.front() << "  ";
		d.pop_front();
	} std::cout << "\n";
}
