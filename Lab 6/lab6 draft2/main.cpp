#include <iostream>
#include "data.h"
#include "hashmap.h"

void menu() {
	std::cout << "0 - Set up from file" << "\n";
	std::cout << "1 - Add" << "\n";
	std::cout << "2 - Remove" << "\n";
	std::cout << "3 - Show" << "\n";
	std::cout << "4 - Check if hashmap is empty" << "\n";
	std::cout << "5 - Check if hashmap is full" << "\n";
	std::cout << "6 - Search" << "\n";
	std::cout << "9 - exit" << "\n";
	std::cout << "> ";
}

int main()
{
	int option;
	int search_key;
	bool run = true;
	int index;
	int k;
	string d;

	const int size = 10;
	data temp[size];

	hashmap map;

	while (run) {
		map.show();

		menu();
		std::cin >> option;

		switch (option) {
		case 0:
			set_up(temp, size);

			for (int i{}; i < size; i++)
				map.add(temp[i]);

			system("cls");
			break;
		case 1:
			std::cout << "Enter key (int): ";
			std::cin >> k;
			std::cout << "Enter data: ";
			std::cin >> d;
			map.add(k, d);
			break;
		case 2:
			std::cout << "Enter index: ";
			std::cin >> index;
			map.remove(index);
			break;
		case 3:
			map.show();
			break;
		case 4:
			if(map.isEmpty())
				std::cout << "Hashmap is empty!" << "\n";
			else
				std::cout << "Hashmap is not empty!" << "\n";
		case 5:
			if (map.isFull())
				std::cout << "Hashmap is full!" << "\n";
			else
				std::cout << "Hashmap is not full!" << "\n";
		case 6:
			std::cout << "Enter key to search: ";
			std::cin >> search_key;
			std::cout << "Position: " << map.search(search_key) << "\n";
			
			break;
		case 9:
			run = false;
			break;
		}
	}
}