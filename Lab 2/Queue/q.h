#pragma once

class q {
	int data[100];
	int size;
public:
//base
	q() { size = 0; }
	int Size();
	int front();
	void push(int value);
	void pop();
	bool empty();
//task
	// знайти та вивести кількість елементі в черги; 
		//Size();

	//знайти та вивести середнє арифметичне збережених елементів; 
	double average();

	//знайти та вивести мінімальний та максимальний елемент; 
	void show_min_and_max();

	//знайти та вивести елемент, що йде перед мінімальним елементом.
	void show_before_min();

};