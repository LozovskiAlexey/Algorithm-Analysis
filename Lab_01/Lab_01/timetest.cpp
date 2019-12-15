#include "timetest.h"


TimeTest::TimeTest(base_counter *base)
{
    wrapee = base;
};


// Вызывает один из алгоритмов, считает время выполнения
void TimeTest::execute()
{
    int n = 10;

    auto start = clock();

    for (int i=0; i < n; i++)
        wrapee->execute();

    auto end = clock();

    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    time /= n;

    show();
};

// Возвращает время выполнения алгоритма
void TimeTest::show()
{
    cout.setf(ios::fixed);
    std::cout <<"Processing time = " << time << std::endl;
};


size_t TimeTest::result()
{
    return 0;
}
