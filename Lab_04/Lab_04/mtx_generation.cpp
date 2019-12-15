#include "mtx_generation.h"


mtx_t *generate_mtx(int r, int c)
{
    mtx_t *mtx = nullptr;

    if (c*r>=1)
    {
        mtx = new mtx_t;

        mtx->r = r;
        mtx->c = c;
        mtx->mtx = new int*[r];

        for (int i=0; i<r; i++)
            mtx->mtx[i] = new int[c];
    }
    return mtx;
}


void fill_mtx(mtx_t *mtx)
{
    for (int i=0; i<mtx->r; i++)
        for(int j=0; j<mtx->c; j++)
        {
            if (i == j)
                mtx->mtx[i][j] = 1;
            else
                mtx->mtx[i][j] = 0;
        }
}


void release_mtx(mtx_t *mtx)
{
    for (int i=0; i<mtx->r; i++)
        delete [] mtx->mtx[i];

    delete [] mtx->mtx;
    delete mtx;
}
