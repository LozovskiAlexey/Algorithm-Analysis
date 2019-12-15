#ifndef GENERATOR_H
#define GENERATOR_H

#include "ant.h"

class Generator
{
public:
    Generator(){}
    Generator(int, int);

    map_t<size_t> operator()(size_t);

private:
    std::mt19937 gen;
    std::uniform_int_distribution<> range;
};

#endif // GENERATOR_H
