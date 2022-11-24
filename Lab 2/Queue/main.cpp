#include <iostream>
#include "q.h"
#include <fstream>
using std::fstream;
using std::cout;
using std::cin;

void fill(q &obj, int n) {
	fstream f;
	int temp;
	f.open("file.txt");
	while (!f.eof()) {
		f >> temp;
		obj.push(temp);
	}
		
}

void show(q obj) {
	while (!obj.empty()) {
		cout << obj.front() << "  ";
		obj.pop();
	} cout << "\n";
}

void print_menu() {
	cout << "1. Size" << "\n";
	cout << "2. Average" << "\n";
	cout << "3. Show min and max" << "\n";
	cout << "4. Show defore min" << "\n";
	cout << "> ";
}
int main()
{
	q q;
	int option;

	fill(q, 10);
	while (true) {
		show(q);
		print_menu();
		cin >> option;
		switch (option)
		{
		case 1:
			cout << q.Size() << "\n";
			break;
		case 2:
			cout << q.average() << "\n";
			break;
		case 3:
			q.show_min_and_max();
			break;
		case 4:
			q.show_before_min();
			break;
		default:
			break;
		}
	}
}
