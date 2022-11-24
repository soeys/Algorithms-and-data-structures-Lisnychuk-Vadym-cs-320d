#pragma once

void fillArrayRand(int* arr, int size);
void fillArrayInOrder(int* arr, int size);
void fillArrayImproper(int* arr, int size);

void show(int* arr, int size);

long long int selectionSort(int arr[], size_t size);
long long int insertionSort(int* arr, int size);
long long int radixSort(int arr[], int n);

void countSort(int arr[], int n, int exp, long long int& steps);
int getMax(int arr[], int n, long long int& steps);