#include "array_functions.h"
#define default_array_size 100

#include <iostream>
#include <fstream>

using std::cout;
using std::fstream;

void show(int* a) {
	int b = 0;
	for (int i = 0; i < default_array_size; i++) {
		cout << a[i] << "\t";
		b++;
		if (b == 10) {
			cout << "\n";
			b = 0;
		}
	}
	cout << "\n";
}

void fill(int* a) {
	fstream file;
	file.open("data.txt");

	int temp;

	for (int i = 0; i < default_array_size; i++) {
		file >> temp;
		a[i] = temp;
	}

	file.close();
}

void sort(int* a)
{
	int temp, item;

	for (int counter = 1; counter < default_array_size; counter++) {
		temp = a[counter];
		item = counter - 1;
		while (item >= 0 && a[item] > temp) {
			a[item + 1] = a[item];
			a[item] = temp;
			item--;
		}
	}
}