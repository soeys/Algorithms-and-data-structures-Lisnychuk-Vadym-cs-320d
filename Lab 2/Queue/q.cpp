#include "q.h"
#include <iostream>
int q::Size()
{
    return size;
}

int q::front()
{
    return data[0];
}

void q::push(int value)
{
    data[size] = value;
    size++;
}

void q::pop()
{
    size--;
    for (int i = 0; i < size; i++) {
        data[i] = data[i + 1];
    }
}

bool q::empty()
{
    return !size;
}

double q::average()
{
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    
    double avg = sum / size;

    return avg;
}

void q::show_min_and_max()
{
    int max = data[0];
    for (int i = 0; i < size; i++) {
        if (data[i] > max)
            max = data[i];
    }

    std::cout << "max element: " << max << "\n";

    int min = data[0];
    for (int i = 0; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    std::cout << "min element: " << min << "\n";
}

void q::show_before_min()
{
    int min = data[0];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
            index = i;
        }
    }
    if (index == size - 1) {
        std::cout << "Min element is last" << "\n";
    }
    else {
        std::cout << data[index + 1] << "\n";
    }
}
