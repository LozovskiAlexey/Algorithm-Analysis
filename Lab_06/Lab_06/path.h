#ifndef Path_H
#define Path_H

#include <vector>
#include <iostream>
#include <algorithm>

using path_t = std::vector<size_t>;

class Path
{
public:
    Path();
    Path(size_t);

    void addToVisited(size_t); // пометит город, как просмотренный
    void removeFromVisited(); // удаляет из помеченный

    size_t last(); // вернет последний посещенный город
    size_t first(); // вернет первый элемент пути

    size_t countVisited(); // возвращает количество посещенных городов
    size_t verticles();

    bool isFinished(); // если путь завершен
    bool isVisited(size_t); // проверяет если элемент есть в visited

    void show();

    size_t& operator()(); // вернет длину проденного пути

private:
    path_t visited; // посещенные города

    size_t length; // длина пути

    size_t vert; // количество вершин в пути
};

#endif // Path_H
