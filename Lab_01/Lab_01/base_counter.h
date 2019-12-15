#ifndef BASE_COUNTER_H
#define BASE_COUNTER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Базовый класс для алгоритмов
class base_counter
{
public:
    std::string str1;
    std::string str2;

    virtual void execute()=0;
    virtual void show()=0;

    virtual size_t result()=0;
    virtual ~base_counter()=default;
};

#endif // BASE_COUNTER_H
