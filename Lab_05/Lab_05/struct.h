#ifndef STRUCT_H
#define STRUCT_H

typedef struct task {
    int number;
}Task;


typedef struct data {

    int line_number;
    int task_number;

    double time_start;
    double time_end;

}data_t;

Task init(int);

data_t init(int &ln, int &tn, double tst, double te);

#endif // STRUCT_H
