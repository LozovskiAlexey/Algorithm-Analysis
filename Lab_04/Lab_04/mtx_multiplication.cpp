#include "mtx_multiplication.h"


bool check(int c1, int r2)
{
    return c1 == r2 ? 1 : 0;
}


void magic(mtx_t *res, mtx_t *A, mtx_t *B, int *mh, int *mv, int st, int end, bool uneven)
{
    int c = B->c;
    int d = B->r-1;
    int k_1;


    for (int i = st; i < end; i++)
        for (int j=0; j<c; j++){            

            res->mtx[i][j] = mh[i] + mv[j];       

            for (int k=0; k<d; k+=2){

                k_1 = k+1;

                res->mtx[i][j] += (A->mtx[i][k] + B->mtx[k_1][j])*\
                        (A->mtx[i][k_1] + B->mtx[k][j]);
            }

            if (uneven)
                res->mtx[i][j] += A->mtx[i][d] * B->mtx[d][j];

        }
}


mtx_t *vinograd(mtx_t *A, mtx_t *B, int n)
{
    mtx_t *res = nullptr;
    int r = A->r;
    int c = B->c;
    int d = B->r-1;

    bool uneven = r % 2 != 0 ? 1 : 0;


    if (check(A->c, B->r))
    {
        int *mulh = new int[r]; // Массив отрицательных сумм по горизонтали
        int *mulv = new int[c]; // --//-- по вертикали

        // Накапливаем отрицательные суммы
        int j_1;

        for (int i=0; i<r; i++){


            mulh[i] = A->mtx[i][0] * A->mtx[i][1];
            mulv[i] = B->mtx[0][i] * B->mtx[1][i];


            for (int j=2; j<d; j+=2){

                j_1 = j+1;

                mulh[i] -= A->mtx[i][j] * A->mtx[i][j_1];
                mulv[i] -= B->mtx[j][i] * B->mtx[j_1][i];

            }
        }


        res = generate_mtx(r, c);


        std::thread *thr = new std::thread [n];
        const int step = r / n + 1;


        int start;
        int fin;


        for (int i=0; i<n; i++){

            start = step * i;
            fin = min(start+step, r);

            thr[i] = std::thread(magic, \
                                 ref(res), A, B,\
                                 mulh, mulv, \
                                 start, fin, uneven);
        }


        for (int i=0; i<n; i++)
            thr[i].join();


        delete []thr;
        delete []mulh;
        delete []mulv;
    }

    return res;
}
