#ifndef TEST_H
#define TEST_H

#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>


#include "mtx_multiplication.h"

using namespace std;

// Для тестирования времени
void time_test_mode();
double timer(mtx_t *A, mtx_t *B, mtx_t* (* mult)(mtx_t*, mtx_t*));
double test(int size, mtx_t* (* mult)(mtx_t*, mtx_t*));
void test_wrapee(string file, int size, int limit, mtx_t* (* mult)(mtx_t*, mtx_t*));
void show(mtx_t *A);


// Для пользовательского режима
void user_mode();
mtx_t *set_mtx();
void show_menu();
int get_choice();


// Для функционального тестирования
void func_test_mode();
bool compare(mtx_t *C, mtx_t *AWAIT_C);
mtx_t *get_mtx_from_file(string file_name);
void func_test(mtx_t *A, mtx_t *B, mtx_t *AWAIT_C, mtx_t* (* mult)(mtx_t*, mtx_t*));
void process_data(string f1, string f2, string f3, mtx_t* (* mult)(mtx_t*, mtx_t*));

#endif // TEST_H
