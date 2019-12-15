#ifndef MTX_MULTIPLICATION_H
#define MTX_MULTIPLICATION_H

#include <thread>

#include "mtx_generation.h"

void magic(mtx_t *res, mtx_t *A, mtx_t *B, int *mh, int *mv, int st, int end, bool);
mtx_t *vinograd(mtx_t *A, mtx_t *B, int n);
bool check(int c1, int r2);

#endif // MTX_MULTIPLICATION_H
