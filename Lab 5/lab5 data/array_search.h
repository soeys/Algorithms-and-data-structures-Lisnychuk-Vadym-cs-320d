#pragma once
#define default_array_size 100

int linearSearch(int &steps, int* a, int key);
int barrierSearch(int& steps, int* a, int key);
int binarySearch(int& steps, int* a, int key, int l = 0, int r = default_array_size);