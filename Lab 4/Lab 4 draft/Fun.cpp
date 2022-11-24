#include "Fun.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

#include <cstddef>
#include <utility>

using namespace std;

void fillArrayRand(int* arr, int size) {
	fstream file("data.txt");
	int temp;

	for (int i = 0; i < size; i++) {
		file >> temp;
		arr[i] = temp;
	}
}

void fillArrayInOrder(int* arr, int size) {
	for (int i = 0; i < size; i++)
		arr[i] = i;
}

void fillArrayImproper(int* arr, int size) {
	for (int i = 0; i < size; i++)
		arr[i] = size - i - 1;
}

void show(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << "\n";
}

long long int selectionSort(int arr[], size_t size)
{
	long long int steps = 0;

	for (size_t idx_i = 0; idx_i < size - 1; idx_i++) {
		size_t min_idx = idx_i;		steps++;
		for (size_t idx_j = idx_i + 1; idx_j < size; idx_j++) {
			if (arr[idx_j] < arr[min_idx]) {
				min_idx = idx_j; steps++;
			} steps += 2;
		}
		if (min_idx != idx_i) {
			swap(arr[idx_i], arr[min_idx]); steps++;
			min_idx = idx_i; steps++;
		} steps += 2;
	}

	return steps;
}

long long int insertionSort(int* arr, int size)
{
	long long int steps = 0;

	int temp,
		item;

	steps += 2;

	for (int counter = 1; counter < size; counter++) {
		temp = arr[counter]; steps++;
		item = counter - 1; steps++;
		while (item >= 0 && arr[item] > temp) {
			arr[item + 1] = arr[item]; steps++;
			arr[item] = temp; steps++;
			item--; steps++;
		}
	}

	return steps;
}

int getMax(int arr[], int n, long long int& steps)
{
	int mx = arr[0]; steps++;
	for (int i = 1; i < n; i++)
		if (arr[i] > mx) {
			mx = arr[i];
			steps++;
		}
	return mx;
}

void countSort(int arr[], int n, int exp, long long int& steps)
{
	int* output = new int[n]; steps++;
	int i, count[10] = { 0 }; steps++;

	for (i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
		steps++;
	}
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
		steps++;
	}

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
		steps++;

	}

	for (i = 0; i < n; i++) {
		arr[i] = output[i];
		steps++;
	}

	delete[] output;
}

long long int radixSort(int arr[], int n)
{
	long long int steps = 0;

	int m = getMax(arr, n, steps); steps++;

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp, steps);
		steps++;
	}

	return steps;
}
