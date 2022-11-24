#include "array_search.h"
#include "array_functions.h"

int linearSearch(int& steps, int* a, int key)
{
    for (int i = 0; i < default_array_size; i++) {
        steps += 2;
        if (a[i] == key) {
            steps++;
            return i;
        }
    }
    steps++;
    return -1;
}

int barrierSearch(int& steps, int* a, int key)
{
    int last = a[default_array_size - 1];
    a[default_array_size - 1] = key;
    int i = 0;
    
    steps += 3;

    for (i = 0; a[i] != key; ++i) {
        steps++;
    }
    
    a[default_array_size - 1] = last;
    steps++;

    steps += 2;
    if (i != (default_array_size - 1) || key == last) {
        steps++;
        return i;
    }

    steps++;
    return -1;
}

int binarySearch(int& steps, int* a, int key, int left, int right)
{
    sort(a);
    while (left <= right) {
        steps++;
        int middle = left + (right - left) / 2;

        steps += 2;
        if (a[middle] == key) {
            steps++;
            return middle;
        }
        steps += 2;
        if (a[middle] < key) {
            steps++;
            left = middle + 1;
        }
        else {
            steps++;
            right = middle - 1;
        }
    }
    steps++;
    return -1;
}