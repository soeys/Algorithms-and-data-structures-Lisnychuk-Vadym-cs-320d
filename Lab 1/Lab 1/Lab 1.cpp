#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "List.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

void print_menu() {
    cout << " 0. Fill with file" << endl;
    cout << " 1. Add an element" << endl;
    cout << " 2. Print list" << endl;
    cout << " 3. Print list backwards" << endl;
    cout << " 4. Get list lenth" << endl;
    cout << " 5. At" << endl;
    cout << " 6. Search" << endl;
    cout << " 7. Swap elements" << endl;
    cout << " 8. Create new list" << endl;
    cout << " 9. Clear list" << endl;
    cout << "10. Circle list" << endl;
    cout << "11. Save to file" << endl;
    cout << "12. Exit" << endl;

    cout << "> ";
}

int main() {
    List<int> lst;
    List<int> lst_2;
    string s;
    string token;
    size_t pos = 0;
    int n = 0;
    int option;
    int index;
    int element;
    int value;
    int element1, element2;
    int temp;
    while (true) {
        lst.print_straight();
        print_menu();
        cin >> option;

        switch (option)
        {
        case 0:
            lst.fill_from_file();
            break;
        case 1:
            cout << "Your element: ";
            cin >> element;
            lst.push_back(element);
            break;
        case 2:
            lst.print_straight();

            break;
        case 3:
            lst.print_reversed();
            break;
        case 4:
            cout << "List lenght: " << lst.Lenght() << endl;
            break;
        case 5:
            cout << "Enter index > ";
            cin >> index;
            if (index < lst.Lenght())
            {
                cout << "Element at index " << index << ": " << lst.at(index) << endl;
                system("pause");
            }
            else {
                cout << "Index is greather than lenght " << endl;
                system("pause");
                system("cls");
            }
            break;
        case 6:
            cout << "Enter value > ";
            cin >> value;
            cout << "Index of value " << value << ": " << lst.search(value) << endl;
            system("pause");
            break;
        case 7:
            cout << "El one index > ";
            cin >> element1;
            cout << "El two index > ";
            cin >> element2;
            lst.swap(element1, element2);
            break;
        case 8:
            system("cls");
            cout << "How many element you want to add at 2nd list?\n";
            cout << "> ";
            cin >> n;

            system("cls");
            for (int i = 0; i < n; i++) {
                cout << "Enter an element " << i << ": ";
                cin >> temp;
                lst_2.push_back(temp);
                system("cls");
            }

            lst.list_merger(lst_2);
            break;
        case 9:
            system("cls");
            lst.~List();
            cout << "List cleared\n";
            system("pause");
            system("cls");

            break;
        case 10:
            system("cls");
            lst.to_circle_list();
            system("pause");
            system("cls");
            break;
        case 11:
            lst.toFile();
            break;
        case 12:
            exit(0);
            
        default:
            system("cls");
            cout << "Wrong option\n" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}