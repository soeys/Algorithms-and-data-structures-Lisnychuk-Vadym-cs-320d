#include <iostream>
#include <iomanip>

#include <chrono>

using namespace std;

#include "Fun.h"

int main()
{
	const char separator = ' ';
	const int nameWidth = 16;
	const int numWidth = 8;

// BLOCK START
	cout << setw(24) << "Selection sort:" << endl;
	cout << "Random" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayRand(arr, size);
		//

		// SORT
		selectionSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t" 
			 << left << setw(nameWidth) 
			 << size
			 << right << setw(nameWidth) 
			 << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() 
			 << endl;

		delete[] arr;
	}
	// BLOCK END

	cout << "In order" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayInOrder(arr, size);
		//

		// SORT
		selectionSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}

	cout << "Improper" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayImproper(arr, size);
		//

		// SORT
		selectionSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}


	cout << setw(24) << "insertionSort" << endl;
	cout << "Random" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayRand(arr, size);
		//

		// SORT
		insertionSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}
	// BLOCK END

	cout << "In order" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayInOrder(arr, size);
		//

		// SORT
		insertionSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}

	cout << "Improper" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayImproper(arr, size);
		//

		// SORT
		insertionSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}

	cout << setw(24) << "radixsort" << endl;
	cout << "Random" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayRand(arr, size);
		//

		// SORT
		radixSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}
	// BLOCK END

	cout << "In order" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayInOrder(arr, size);
		//

		// SORT
		radixSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}

	cout << "Improper" << endl;
	for (int size = 10; size <= 10000; size *= 10) {
		auto begin = chrono::high_resolution_clock::now();

		int* arr = new int[size];

		// FILL
		fillArrayImproper(arr, size);
		//

		// SORT
		radixSort(arr, size);
		//
		auto end = chrono::high_resolution_clock::now();

		cout << "\t"
			<< left << setw(nameWidth)
			<< size
			<< right << setw(nameWidth)
			<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
			<< endl;

		delete[] arr;
	}
}