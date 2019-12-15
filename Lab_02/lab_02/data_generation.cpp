#include <cstdlib>

#include "data_generation.h"

int* create_sorted(int size)
{
    int *arr = new int[size];
    for (int i=0; i<size; i++)
        arr[i] = i;

    return arr;
}


int* create_reversed(int size)
{
    int *arr = new int[size];
    for (int i=0; i<size; i++)
        arr[i] = size-i;

    return arr;
}


int my_rand(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int* create_random(int size)
{
    int *arr = new int[size];

    for (int i=0; i<size; i++)
        arr[i] = my_rand(0, size);

    return arr;
}


void release_data(int* arr)
{
    delete []arr;
    arr = nullptr;
}
