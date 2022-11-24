#pragma once
#include <cstddef>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;

template <class T>
class Node
{
public:
    T data;
    Node* next, * prev;
};

template <class T>
class List
{
    Node<T>* head, * tail;
    int size = 0;
    bool circle = false;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        while (head)
        {
            tail = head->next;
            delete head;
            head = tail;
        }
    }
    void print_straight()
    {
        Node<T>* current = head;

        if (circle) {
            cout << "list: ";
            for (int i = 0; i < size; i++) {
                cout << current->data << ", ";
                current = current->next;
            }
            cout << "\n";
        }
        else {
            cout << "list: ";
            while (current != NULL) {
                cout << current->data << ", ";
                current = current->next;
            }
            cout << "\n";
        }

    }
    void print_reversed()
    {
        Node<T>* current = tail;

        cout << "list: ";
        if (circle) {
            for (int i = 0; i < size; i++) {
                cout << current->data << ", ";
                current = current->prev;
            }
            cout << "\n";
        }
        else {
            while (current != NULL) {
                cout << current->data << ", ";
                current = current->prev;
            }
            cout << "\n";
        }
    }
    void push_back(T data)
    {
        Node<T>* current = new Node<T>;
        current->next = NULL;
        current->data = data;

        if (head == NULL) {
            current->prev = NULL;
            head = tail = current;
        }
        else {
            current->prev = tail;
            tail->next = current;
            tail = current;
        }

        size++;
    }
    int Lenght() { return this->size; }
    T at(int index)
    {
        Node<T>* current = new Node<T>;

        current = head;

        if (index < Lenght()) {
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->data;
        }
        else {
            cout << "Index is greather than lenght " << endl;
        }
    }
    void swap(int index_one, int index_two)
    {
        T temp;

        Node<T>* index_one_el = new Node<T>;
        Node<T>* index_two_el = new Node<T>;

        index_one_el = head;
        index_two_el = head;

        for (int i = 0; i < index_one; i++) {
            index_one_el = index_one_el->next;
        }

        for (int i = 0; i < index_two; i++)
        {
            index_two_el = index_two_el->next;
        }

        temp = index_one_el->data;
        index_one_el->data = index_two_el->data;
        index_two_el->data = temp;
    }
    int search(T value) {
        Node<T>* current = new Node<T>;

        current = head;
        int index = 0;

        while (current != NULL) {
            if (current->data == value) {
                return index;
            }
            else {
                current = current->next;
                index++;
            }
        }
        return -1;
    }
    void list_merger(List<T> templist) {
        Node<T>* current = new Node<T>;

        current = templist.head;

        while (current != NULL) {
            this->push_back(current->data);
            current = current->next;
        }
    }
    void to_circle_list() {
        if (head != nullptr && tail != nullptr) {
            head->prev = tail;
            tail->next = head;

            circle = true;

            cout << "Now list is circled" << endl;
        }
        else {
            cout << "List is empty" << endl;
        }
    }
    void fill_from_file() {
        std::fstream f;
        int temp;
        f.open("file.txt");

        while (!f.eof()) {
            f >> temp;
            this->push_back(temp);
        }
    }
    void toFile() {
        std::fstream f;
        f.open("result.txt");

        Node<int>* current = head;
        int temp;
        if (circle) {
            cout << "list: ";
            for (int i = 0; i < size; i++) {
                temp = current->data;
                current = current->next;
                f << temp << "\n";
            }
        }
        else {
            cout << "list: ";
            while (current != NULL) {
                temp = current->data;
                current = current->next;
                f << temp << "\n";
            }
        }

        f.close();
    }
};