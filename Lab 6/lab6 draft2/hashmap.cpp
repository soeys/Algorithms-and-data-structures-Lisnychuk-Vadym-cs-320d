#include "hashmap.h"
#include <iostream>
using std::cout;

int hashmap::hashFunction(data o) {
    return o.k % capacity;
}

int hashmap::hashFunction(int k)
{
    return k % capacity;
}

void hashmap::add(data o) {
    int H = hashFunction(o);
    bool added = false;
    while (added != true) {
        if (H < capacity) {
            if (table[H].d == "" || table[H].d == "!deleted!") {
                table[H] = o;
                added = true;
            }
            else {
                H++;
            }
        }
        else {
            if (isFull()) {
                cout << "HashMap is full!" << "\n";
                added = true;
            }
            else {
                return;
            }
        }
    }
}

void hashmap::add(int k, string d)
{
    data o;
    o.set(k, d);

    int hashKey = hashFunction(o);
    bool success = false;
    while (success != true) {
        if (hashKey < capacity) {
            if (table[hashKey].d == "" || table[hashKey].d == "!deleted!") {
                table[hashKey] = o;
                success = true;
            }
            else {
                hashKey++;
            }
        }
        else {
            if (isFull()) {
                cout << "HashMap is full!" << "\n";
                success = true;
            }
            else {
                return;
            }
        }
    }
}

void hashmap::show() {
    for (int i = 0; i < capacity; i++) {
        if (table[i].d != "" && table[i].d != "!deleted!") {
            cout << " " << table[i] << "\n";
        }
    }
    cout << "\n";
}

bool hashmap::isFull()
{
    int sum = 0;
    for (int i{}; i < capacity; i++) {
        if (table[i].d != "")
            sum++;
    }

    if (sum == capacity) {
        return true;
    }
    else {
        return false;
    }
}

bool hashmap::isEmpty()
{
    int sum = 0;
    for (int i{}; i < capacity; i++) {
        if (table[i].d != "")
            sum++;
    }

    if (!sum) {
        return true;
    }
    else {
        return false;
    }
}

int hashmap::search(int k)
{
    int H = hashFunction(k);
    bool s = false;
    while (s != true) {
        if (H < capacity) {
            if (table[H].d != "") {
                if (table[H].k == k) {
                    cout << table[H] << "\n";
                    return H;
                    s = true;
                }
                else {
                    H++;
                }
            }
            else {
                return -1;
                s = true;
            }
        }
    }
}

void hashmap::remove(int index)
{
    table[index].k = 0;
    table[index].d = "";
}