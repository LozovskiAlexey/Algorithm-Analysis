#ifndef MAP_H
#define MAP_H

#include <cmath>

#include "bestPath.h"

#define START_VALUE 0.5
#define CONST 1.0

class Map
{
public:
    double a;
    double b;


    Map();
    Map(map_t<size_t>&, double, double, double);

    void update(); //обновление феромона

    double getPheromone(size_t, size_t);
    size_t getDistance(size_t, size_t);

    size_t countCities(); // вернет число вершин в маршруте

    double f(size_t); // целевая функция

    void setVisited(size_t, size_t);
    bool isVisited(size_t, size_t);

    void restore(double&); // восстановление феромона

private:
    map_t<size_t> map;
    map_t<bool> visited;
    map_t<double> pheromone;


    double p; // коэфф скорости испарение
    double q; // концентрация нанесения феромона
};

#endif // MAP_H
