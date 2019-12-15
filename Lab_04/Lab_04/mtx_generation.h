#ifndef MTX_GENERATION_H
#define MTX_GENERATION_H

#include <iostream>

using namespace std;

typedef struct mtx{
    int **mtx;
    int r;
    int c;
}mtx_t;


mtx_t *generate_mtx(int r, int c);
void fill_mtx(mtx_t *mtx);
void release_mtx(mtx_t *mtx);


#endif // MTX_GENERATION_H
