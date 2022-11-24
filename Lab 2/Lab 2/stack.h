#pragma once
#include <string>
using namespace std;
#define capacity 100


class stack {
	string data[capacity];
	int size;
public:
	stack();
	~stack();
	//base
	void push(int value);
	void push(string value);
	string top();;
	int i_top();
	void pop();
	bool empty();
	bool full();
	int Size();
	//tasks
		//поміняти місцями перший і останній елементи стека;
	void swap();

	//розгорнути стек, тобто зробити "дно" стека вершиною, а вершину -"дном";
	void reverse();

	//видалити кожен другий елемент стека;
	void erase_every_second();

	//вставити символ '*' в середину стека, якщо число елементів парне, 
		//або після середнього елемента, якщо число елементів непарне;
	void insert_star_middle();

	//знайти максимальний елемент і вставити після нього 0;
	void insert_zero_aft_max();

	//видалити мінімальний елемент;
	void erase_min();

	//видалити всі елементи, крім першого;
	void erase_all_but_first();

	//видалитивсі елементи, крімостаннього.
	void erase_all_but_last();
};