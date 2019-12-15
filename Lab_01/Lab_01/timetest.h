#ifndef TIMETEST_H
#define TIMETEST_H

#include <ctime>
#include "base_counter.h"


// Класс-обертка для экспериментального режима
// вычисляет время работы методов
class TimeTest : base_counter
{
    public:
        TimeTest(base_counter *);

        void execute() override;


    private:
        base_counter *wrapee;

        double time;

        void show() override;

        size_t result() override;
};


#endif // TIMETEST_H
