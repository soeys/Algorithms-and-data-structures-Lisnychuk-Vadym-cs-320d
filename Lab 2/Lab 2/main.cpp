#include <iostream>
#include "stack.h"
#include "fun.h"
using namespace std;

void menu() 
{
	cout << "1. Push element" << endl;
	cout << "2. Show stack" << endl;
	cout << "3. Get stack size" << endl;
	cout << "4. Swap top and bottom elements" << endl;
	cout << "5. Reverse stack" << endl;
	cout << "6. Erase every second element" << endl;
	cout << "7. Insert star in middle" << endl;
	cout << "8. Insert zero after max element" << endl;
	cout << "9. Erase min element" << endl;
	cout << "10. Erase all but first" << endl;
	cout << "11. Erase all but last" << endl;
	cout << "12. Exit" << endl;
	cout << "> ";
}

int main()
{
	stack s;
	int option;
	int val_1;
	int amount;
	int el;

	bool a = true;
	while (a)
	{
		cout << "Fill stack 1 - Random, 2 - from file\n> ";
		cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
			cout << "amount of elements\n> ";
			cin >> amount;
			fill_rand(s, amount);
			a = false;
			break;
		case 2:
			fill_from_file(s);
			a = false;
			break;
		default:
			break;
		}
	}

	

	while (true) {
		show(s);
		cout << "stack size: " << s.Size() << endl;
		cout << "\n\n";
		menu();
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");

			cout << "Enter your element\n> ";
			cin >> el;
			s.push(el);
			system("cls");
			break;
		case 2:
			system("cls");
			show(s);
			system("pause");
			cout << "\n";
			break;
		case 3:
			system("cls");
			cout << "stack size: " << s.Size() << endl;
			break;
		case 4:
			system("cls");
			s.swap();
			break;
		case 5:
			system("cls");
			s.reverse();
			break;
		case 6:
			system("cls");
			s.erase_every_second();
			break;
		case 7:
			system("cls");
			s.insert_star_middle();
			break;
		case 8:
			system("cls");
			s.insert_zero_aft_max();
			break;
		case 9:
			system("cls");
			s.erase_min();
			break;
		case 10:
			system("cls");
			s.erase_all_but_first();
			break;
		case 11:
			system("cls");
			s.erase_all_but_last();
			break;
		case 12:
			exit(0);
		default:
			system("cls");
			break;
		}
	}
}