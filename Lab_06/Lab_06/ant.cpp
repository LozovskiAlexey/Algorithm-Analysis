#include "ant.h"


Ant::Ant(){}


Ant::Ant(Map *map){
    this->length = 0;
    this->map = map;
    this->vert = map->countCities();

    auto t = static_cast<int>(time(nullptr));
    choice = std::mt19937(t);
    range = std::uniform_real_distribution<> (0, 1);
}


Ant::Ant(Map *map, size_t city) : Ant(map){
    addToVisited(city);
}


void Ant::addToVisited(size_t target){

    if (countVisited() >= 1){
        auto start = last();
        map->setVisited(start, target);

        length += map->getDistance(start, target);
        visited.push_back(target);
    }
    else
        visited.push_back(target);
}


size_t Ant::chooseNextCity(){

    auto start = last(); // берем город в котором мы находимся

    size_t city = 0;  
    double possibility = 0;

    auto chosen = range(choice); // генератор случайных чисел (0 до 1)

    // проходим по всем городам и ищем вероятность
    // для каждого города
    for (size_t target = 0; target < vert; target++){

        if (!isVisited(target))
            possibility += countPossibility(start, target);
        else
            possibility += 0;

        if (chosen <= possibility){
            city = target;
            break;
        }
    }

    return city;
}


// переписать
double Ant::countPossibility(size_t start, size_t end){

    double up = mult(start, end);

    // тут можно оптимизировать и не считать каждый раз down
    double down = 0;
    for (size_t target=0; target < vert; target++)
        if (!isVisited(target))
            down += mult(start, target);

    return up/down;
}


double Ant::mult(size_t start, size_t end){

    auto dist = map->getDistance(start, end);
    double res;

    if (dist != 0){
        auto n = 1.0 / dist;
        auto t = map->getPheromone(start, end);

        res = pow(t, map->a) * pow(n, map->b);
    }
    else
        res = 0;

    return res;
}

// считает количество посещенных городов
size_t Ant::countVisited(){
    return visited.size();
}


// вернет первый посещенный город
size_t Ant::first(){
    return visited.front();
}


// вернет последний посещенный город
size_t Ant::last(){
    return visited.back();
}


// проверяет путь на полноту
bool Ant::isFinished(){
    return (vert == countVisited());
}


// проверяет если вершина была посещена
bool Ant::isVisited(size_t city){
    bool found = 0;

    for (size_t tmp : visited)
        if (tmp == city)
            found = 1;
    return found;
}


void Ant::findPath(){
    // проходим по всем городам
    // считаем вероятность для каждого
    size_t next_city = 0;

    while (!isFinished()){
        next_city = chooseNextCity();
        addToVisited(next_city);
    }

    auto start = first();
    addToVisited(start);
}


void Ant::findPath(size_t start_city){
    addToVisited(start_city);

    findPath();
}


size_t Ant::getPathDistance(){
    return length;
}


void Ant::show(){
    std::cout << "Path: ";

    for (auto city : visited)
        std::cout << city << " ";

    std::cout << std::endl;
}


void Ant::update(){
    length = 0;

    auto start = first();
    visited = std::vector<size_t>();
    addToVisited(start);
}
