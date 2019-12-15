#include "generator.h"

// класс генератора, получает на вход минимальное и максимальное значение
// расстояний между городами
Generator::Generator(int st, int end){

    auto t = static_cast<int>(time(nullptr));
    gen = std::mt19937(t); // сам генератор
    range = std::uniform_int_distribution<> (st, end); // распределение значений
}

// переопределение () - на вход размер матрицы
// вернет заполненную рандомными значениями
// симметричную относительно главной диагонали матрицу
map_t<size_t> Generator::operator()(size_t size){
    map_t<size_t> map;

    for (size_t i=0; i<size; i++){
        auto path = path_t();

        for (size_t j=0; j<size; j++)
            path.push_back(0);

        map.push_back(path);
    }

    int value;

    for (size_t i=0; i<size; i++)
        for(size_t j=0; j<size; j++){

            if (j==i)
                map[i][j] = 0;
            else {
                value = range(gen);
                map[i][j] = map[j][i] = value;
            }
        }


    return map;
}
