#ifndef BASE_TEST_H
#define BASE_TEST_H

#include "base_counter.h"

//класс-тестировщик, получает на вход объект класса
//base-counter и считает время выполнения работы алгоритма
class base_test: public base_counter
{
    public:
        base_test();
        explicit base_test(const base_counter&);

    private:
        base_counter *wrapee;
};

#endif // BASE_TEST_H
