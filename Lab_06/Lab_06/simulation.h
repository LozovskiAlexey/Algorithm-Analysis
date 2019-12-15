#ifndef SIMULATION_H
#define SIMULATION_H

#include "ant.h"

using colony_t = std::vector<Ant>;

Ant cycle(Map& map, colony_t &colony); // цикл работы

colony_t init(Map *);

void night(Map &, colony_t&);

void day(colony_t &);

Ant get_best(colony_t&);

#endif // SIMULATION_H
