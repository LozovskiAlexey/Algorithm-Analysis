#ifndef MTX_MULTIPLICATION_H
#define MTX_MULTIPLICATION_H

#include "mtx_generation.h"

bool check(int c1, int r2);
mtx_t *standart(mtx_t *A, mtx_t *B);
mtx_t *vinograd(mtx_t *A, mtx_t *B);
mtx_t *super_vinograd(mtx_t *A, mtx_t *B);


#endif // MTX_MULTIPLICATION_H
