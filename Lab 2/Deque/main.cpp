#include <iostream>
#include "deq.h"
#include "fun.h"
using std::cout;
using std::cin;

void print_menu() {
	cout << "1. Empty?" << "\n";
	cout << "2. Push front" << "\n";
	cout << "3. Push back" << "\n";
	cout << "4. 6th element" << "\n";
	cout << "5. Last" << "\n";

	cout << "> ";
}

int main()
{
	int option;
	int temp;
	deq d;

	fill(d);
	
	while (true) {
		cout << "Dequeue: "; 
		show(d);
		print_menu();
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			if (d.empty()) {
				cout << "Stack is empty" << "\n";
			}
			else {
				cout << "Stack is not empty" << "\n";
			}
			break;
			system("pause");
			system("cls");
		case 2:
			cin >> temp;
			d.push_front(temp);
			break;
		case 3:
			system("cls");
			cin >> temp;
			d.push_back(temp);
			system("cls");
			break;
		case 4:
			system("cls");
			cout << d.ret_sixth_el() << "\n";
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << d.Last() << "\n";
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}
}