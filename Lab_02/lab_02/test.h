#ifndef TEST_H
#define TEST_H

#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "data_generation.h"
#include "sort.h"


using namespace std;

void time_test_mode();
void test_wrapee(string file,  int* (* generator)(int), void (* sort)(int*, int));
void check(int n,  int* (* generator)(int), void (* sort)(int*, int));
void show(int *arr, int n);
double timer(int *arr, int size, void (* sort)(int*, int));
double test(int size,  int* (* generator)(int), void (* sort)(int*, int));


void func_test_mode();
void process_data(string f1, string f2, void (* sort)(int*, int));
int* get_array_from_file(string file_name);
bool compare(int *arr, int* exp_arr);
void run_test(int *arr, int* exp_arr,  void (* sort)(int*, int));


void user_mode();
int get_choice();
void show_menu();
int *set_array(int &n);

#endif // TEST_H
