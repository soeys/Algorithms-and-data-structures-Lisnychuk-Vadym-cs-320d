#pragma once
#include <string>
using std::string;

int linearStringSearch(int &steps, string text, string key);

void findPrefix(int& steps, string pattern, int m, int prefArray[]);
void kmpStringSearch(int& steps, string mainString, string pattern, int* locArray, int& loc);

void badCharHeuristic(int& steps, string str, int size, int badchar[256]);
int bmStringSearch(int& steps, string txt, string pat);

void rabinKarpSearch(int& steps, string mainString, string pattern, int prime, int array[], int* index);