#include "stack.h"
#include <iostream>
#include "fun.h"
#include <fstream>
#include <string>
#include <iterator> 


void show(stack obj)
{
	if (obj.empty()) {
		cout << "stack is empty" << "\n";
	}
	else {
		do {
			cout << obj.top() << "  ";
			obj.pop();
		} while (!obj.empty());
		cout << "\n";
	}

}

void fill(stack& obj, int arg)
{
	for (int i = 0; i < arg; i++)
		obj.push(i);
}

void fill_rand(stack& obj, int arg)
{
	srand(time(0));
	for (int i = 0; i < arg; i++)
		obj.push(rand() % 10);
}

void fill_from_file(stack &obj)
{
	srand(time(0));

	string path = "text.txt";
	string var_1;
	
	fstream f;
	f.open(path);

	while (!f.eof()) {
		f >> var_1;
		obj.push(var_1);
	}

	f.close();
}