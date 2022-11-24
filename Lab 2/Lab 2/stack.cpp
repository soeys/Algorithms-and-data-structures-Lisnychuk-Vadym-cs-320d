#include "stack.h"
#include <iostream>
#include "fun.h"
stack::stack() {
	size = 0;
}


stack::~stack() {
	while (!empty()) {
		pop();
	}
}

string stack::top()
{
	return data[size - 1];
}

int stack::i_top()
{
	return stoi(data[size - 1]);
}

void stack::pop()
{
	size--;

	string* temp = new string[size];

	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}

	for (int i = 0; i < size; i++) {
		data[i] = temp[i];
	}

	delete[] temp;
}

bool stack::empty()
{
	return !(size);
}

int stack::Size()
{
	return this->size;
}

void stack::swap()
{
	string temp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = temp;
}

void stack::reverse()
{
	int temp_size = size;
	int* temp = new int[temp_size];

	for (int i = 0; i < temp_size; i++) {
		temp[i] = i_top();
		pop();
	}

	for (int i = 0; i < temp_size; i++)
		push(temp[i]);

	delete[] temp;
}

void stack::erase_every_second()
{
	int temp_size = size;

	int* temp_arr = new int[size];

	for (int i = 0; i < temp_size; i++) {
		temp_arr[i] = i_top();
		pop();
	}

	for (int i = 0; i < temp_size; i++) {
		if (i % 2 != 0) {
			continue;
		}
		else {
			push(temp_arr[i]);
		}
	}

	reverse();
	delete[] temp_arr;
}

void stack::insert_star_middle()
{
	int temp_size = size;
	string* temp_arr = new string[size + 1];

	if (temp_size % 2 == 0) {
		for (int i = temp_size; i > temp_size / 2; i--) {
			temp_arr[i] = top();
			pop();
		}
		push("*");
		for (int i = temp_size / 2 + 1; i <= temp_size; i++) {
			push(temp_arr[i]);
		}
	}
	else
	{
		for (int i = temp_size; i > temp_size / 2 + 1; i--) {
			temp_arr[i] = top();
			pop();
		}
		push("*");
		for (int i = temp_size / 2 + 2; i <= temp_size; i++) {
			push(temp_arr[i]);
		}
	}

	delete[] temp_arr;
}

void stack::insert_zero_aft_max()
{
	//int temp_size = size;
	//int max = stoi(data[0]);
	//int* temp_arr = new int[temp_size];

	//for (int i = 0; i < temp_size; i++) {
	//	if (data[i] == "*")
	//		continue;
	//	temp_arr[i] = i_top();
	//	pop();
	//}

	//for (int i = 0; i < temp_size; i++) {
	//	if (data[i] == "*")
	//		continue;
	//	if (stoi(data[i]) > max)
	//		max = stoi(data[i]);
	//}

	//for (int i = temp_size - 1; i >= 0; i--) {
	//	push(temp_arr[i]);
	//	if (temp_arr[i] == max)
	//		push(0);
	//}

	//delete[] temp_arr;

	int temp_size = size;
	string* copy = new string[size];

	for (int i = 0; i < size; i++)
		copy[i] = data[i];

	while (!empty()) {
		pop();
	}

	int max = stoi(copy[0]);

	for (int i = 0; i < temp_size; i++) {
		if (copy[i] == "*")
			continue;
		if (stoi(copy[i]) > max)
			max = stoi(copy[i]);
	}

	for (int i = 0; i < temp_size; i++) {
		push(copy[i]);
		if (copy[i] == "*") {

		}
		else {
			if (stoi(copy[i]) == max)
				push(0);
		}

	}
	delete[] copy;
}

void stack::erase_min()
{
	int temp_size = size;
	string* copy = new string[size];

	for (int i = 0; i < temp_size; i++)
		copy[i] = data[i];

	while (!empty()) {
		pop();
	}
	int min;

	if (copy[0] == "*") {
		for (int i = 1; i < temp_size; i++) {
			if (copy[i] == "*") {
				continue;
			}
			else {
				min = stoi(copy[i]);
			}
		}
	}
	else {
		min = stoi(copy[0]);
	}

	for (int i = 0; i < temp_size; i++) {
		if (copy[i] == "*") {
			continue;
		}
		if (stoi(copy[i]) < min) {
			min = stoi(copy[i]);
		}
	}

	for (int i = 0; i < temp_size; i++) {
		if (copy[i] == "*") {
			push("*");
			continue;
		}
		if (stoi(copy[i]) == min) {
			continue;
		}
		push(copy[i]);
	}
}

void stack::erase_all_but_first()
{
	int temp_size = size;
	for (int i = 0; i < temp_size - 1; i++) pop();
}

void stack::erase_all_but_last()
{
	string temp = top();
	while (!empty()) {
		pop();
	}
	push(temp);
}

void stack::push(int value) {
	data[size] = to_string(value);
	size++;
}

void stack::push(string value)
{
	data[size] = value;
	size++;
}

bool stack::full() {
	return size;
}
