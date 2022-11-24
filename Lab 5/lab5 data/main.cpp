#include <iostream>

#include "array_functions.h"
#include "array_search.h"
#include "substring_search.h"

using std::cout;


int main() {
	int a[100];
	int key = 79;

	int s = 0;

	fill(a);
	sort(a);
	show(a);

	cout << "Key:\t" << key << "\n";
	cout << "\n";
	cout << "Linear search\n" 
		 << "\tposition\t"  
		 << linearSearch(s, a, key) << "\n" 
		 << "\tsteps\t\t" << s << "\n";
	s = 0;
	cout << "Barrier search\n" 
		 << "\tposition\t" 
		 << barrierSearch(s, a, key) << "\n" 
		 << "\tsteps\t\t" << s << "\n";
	s = 0;
	cout << "Binary search\n"
		 << "\tposition\t"
		 << binarySearch(s, a, key) << "\n" 
		 << "\tsteps\t\t" << s << "\n";
	cout << "\n";

	s = 0;
	
	string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lobortis scelerisque fermentum dui faucibus in.";
	string string_key = "Lorem";

	cout << "Text:\t" << text << "\n";
	cout << "Key:\t" << string_key << "\n";
	cout << "\n";

	cout << "Linear substring search\n" 
		 << "\tposition\t"
		 << linearStringSearch(s, text, string_key) << "\n"
		 << "\tsteps\t\t" << s << "\n";

	s = 0;

	int index;
	int* locationArray = new int[text.size()];

	kmpStringSearch(s, text, string_key, locationArray, index);

	cout << "KMP substring search\n"
		 << "\tposition\t"
		 << *locationArray << "\n" 
		 << "\tsteps\t\t" << s << "\n";

	s = 0;

	cout << "BM substring search\n"
		<< "\tposition\t"
		<< bmStringSearch(s, text, string_key) << "\n"
		<< "\tsteps\t\t" << s << "\n";
	
	s = 0;

	int* locArray = new int[text.size()];
	int index1 = -1;
	rabinKarpSearch(s, text, string_key, 101, locArray, &index1);

	cout << "BM substring search\n"
		<< "\tposition\t"
		<< *locArray << "\n"
		<< "\tsteps\t\t" << s << "\n";

	s = 0;

	delete[] locArray;
	delete[] locationArray;
}