    #include "deq.h"
#include <iostream>
bool deq::empty()
{
    return !size;
}

void deq::pop_back()
{

}

void deq::pop_front()
{
    size--;
    int* temp = new int[size];
    for (int i = 0; i < size; i++)
        temp[i] = data[i];

    for (int i = 0; i < size; i++)
        data[i] = temp[i];
        
    delete[] temp;
}

int deq::front()
{
    return data[size - 1];

}

int deq::back()
{
    return data[0];

}

void deq::push_front(int value)
{
    data[size] = value;
    size++;
    last = "front";
}

void deq::push_back(int value)
{
    int* temp = new int[size];
    
    for (int i = 0; i < size; i++)
        temp[i] = data[i];

    data[0] = value;

    for (int i = 0; i < size; i++)
        data[i + 1] = temp[i];

    size++;
    delete[] temp;
    last = "back";    
}

int deq::ret_sixth_el()
{
    if (size >= 5)
    {
        return data[5];
    }
    else
    {
        std::cout << "there is no 6th element in deque" << std::endl;
        return 0;
    }
}

int deq::Last()
{
    if(last == "back")
        return back();
    if (last == "front")
        return front();
}