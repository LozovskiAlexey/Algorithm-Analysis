#include "simulation.h"

// цикл работы алгоритма
// день - работают муравьи
// ночь - обновление феромона
Ant cycle(Map &map, colony_t &colony){
    day(colony);

    auto best = get_best(colony);

    night(map, colony);

    return best;
}

// инициализация колонии
colony_t init(Map *map){
    colony_t colony;

    size_t city_number = map->countCities();

    for (size_t start=0; start<city_number; start++){
            Ant ant = Ant(map, start);
            colony.push_back(ant);
    }

    return colony;
}


// поиск всеми муравьями маршрутов
void day(colony_t &colony){

    for (auto &ant : colony)
        ant.findPath();
}


// обновление феромона на дорогах
void night(Map &map, colony_t& colony){
    map.update();

    for (auto &ant : colony)
        ant.update(); // обнуление путей, у каждого муравья
}


Ant get_best(colony_t& colony){
    auto best = colony[0];

    for (auto &ant : colony)
        if (best.getPathDistance() > ant.getPathDistance())
            best = ant;

    return best;
}

