#ifndef TEST_H
#define TEST_H

#include <fstream>
#include <chrono>
#include <ctime>

#include "mtx_multiplication.h"


void exp_mode();
double timer(mtx_t *A, mtx_t *B, int n, mtx_t* (* mult)(mtx_t*, mtx_t*, int));
double test(int size, int n, mtx_t* (* mult)(mtx_t*, mtx_t*, int));
void test_wrapee(string file, int size, int limit, int n, mtx_t* (* mult)(mtx_t*, mtx_t*, int));
void show(mtx_t *A);


void user_mode();
void user_time_mode();
void user_func_test();
void show_menu();
void set(int &n, std::string info);
mtx_t *set_mtx(int rows, int cols);


#endif // TEST_H
