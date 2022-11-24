#pragma once

#include <string>
using std::string;

class deq {
	int data[100];
	int size;
	string last;
public:
	deq() { size = 0; };
	bool empty();
	void pop_back();
	void pop_front();

	int front();
	int back();

	void push_back(int value);
	void push_front(int value);
	int ret_sixth_el();
	int Last();
};