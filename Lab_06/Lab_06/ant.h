#ifndef ANT_H
#define ANT_H

#include <random>
#include <chrono>

#include "map.h"


class Ant{

public:
    Ant();
    Ant(Map*);
    Ant(Map*, size_t);

    void findPath();
    void findPath(size_t); // параметр - вершина старта

    size_t getPathDistance();

    void addToVisited(size_t); // пометит город, как просмотренный
    size_t countVisited();

    size_t chooseNextCity();
    double countPossibility(size_t, size_t);
    double mult(size_t, size_t);

    bool isVisited(size_t);
    bool isFinished();

    size_t last(); // вернет последний посещенный город
    size_t first(); // вернет первый элемент пути

    void update();

    void show();

private:
    path_t visited; // посещенные города

    size_t length; // длина пути

    size_t vert; // Количество вершин

    Map *map;

    std::mt19937 choice;
    std::uniform_real_distribution<> range;
};

#endif // ANT_H
