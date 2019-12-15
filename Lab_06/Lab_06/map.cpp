#include "map.h"

Map::Map() {}


Map::Map(map_t<size_t>& map, double a, double p, double q){
    this->map = map;

    for (size_t i=0; i < map.size(); i++){

        auto v = std::vector<bool>();
        visited.push_back(v);

        auto ph = std::vector<double>();
        pheromone.push_back(ph);
    }


    for (size_t i=0; i<map.size(); i++)
        for (size_t j=0; j<map.size(); j++){

            visited[i].push_back(0);
            pheromone[i].push_back(START_VALUE);
        }


    this->a = a;
    this->p = p;
    this->q = q;
    this->b = CONST - a;
}


// целевая функция 1/D
double f(size_t dist){
    return 1/dist;
}


void Map::setVisited(size_t start, size_t end){
    visited[start][end] = 1;
    visited[end][start] = 1;
}


void Map::update(){

    double new_ph = 0;
    double updated_ph;
    double dist;

    for (size_t start=0; start<map.size(); start++)
        for (size_t end=0; end<map.size(); end++){

            // проверяем было ли посещено ребро
            // если да - вычисляем, если нет - 0
            dist = map[start][end];

            if (dist != 0.0)
                new_ph = isVisited(start, end) * q/dist;
            else
                new_ph = 0;

            // обновляем значение феромона
            updated_ph = (1-p) * (pheromone[start][end] + new_ph);

            // восстанавливаем значение, если все испарилось
            restore(updated_ph);
            pheromone[start][end] = updated_ph;

//            std::cout << "Pheromone[" << start << "][" <<
//                         end << "] = " << updated_ph << std::endl;

            visited[start][end] = 0;
        }
}


bool Map::isVisited(size_t start, size_t end){
    return visited[start][end];
}

// контролирует значение феромона,
// если феромон 0 - восполнит до минимума
void Map::restore(double &ph){
    ph = ph <= 0 ? START_VALUE : ph;
}


size_t Map::countCities(){
    return map.size();
}


size_t Map::getDistance(size_t start, size_t end){
    return map[start][end];
}


double Map::getPheromone(size_t start, size_t end){
    return pheromone[start][end];
}
