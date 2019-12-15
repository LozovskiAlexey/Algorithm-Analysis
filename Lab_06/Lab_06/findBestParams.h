#ifndef FINDBESTPARAMS_H
#define FINDBESTPARAMS_H

#include "bestPath.h"
#include "simulation.h"

#define TMAX 10000

typedef struct params{

    size_t len;
    int iter;
    double a;
    double p;


    void init(size_t& len, int &iter, double& a, double& p){

        this->len = len;
        this->iter = iter;
        this->a = a;
        this->p = p;

    }

    void update(int &iter, double& a, double& p){

        this->iter = iter;
        this->a = a;
        this->p = p;
    }

    void show(){

        std::cout << "Best length : " << len << std::endl;
        std::cout << "iterations : " << iter << std::endl;
        std::cout << "a : " << a << std::endl;
        std::cout << "p : " << p << std::endl;
    }

} params_t;


params_t find_best(map_t<size_t> map, double, double);

#endif // FINDBESTPARAMS_H
