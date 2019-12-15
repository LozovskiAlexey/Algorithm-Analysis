#include "test.h"

mtx_t *standart(mtx_t *A, mtx_t *B)
{
    mtx_t *res = nullptr;
    int r = A->r;
    int c = B->c;

    if (check(A->c, B->r))
    {
        res = generate_mtx(r, c);

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                res->mtx[i][j] = A->mtx[i][0] * B->mtx[0][j];

                for(int k = 1; k < A->c; k++)
                    res->mtx[i][j] = res->mtx[i][j] + A->mtx[i][k] * B->mtx[k][j];
            }
    }
    return res;
}


mtx_t *vinograd(mtx_t *A, mtx_t *B)
{
    mtx_t *res = nullptr;
    int r = A->r;
    int c = B->c;

    if (check(A->c, B->r))
    {
        int *mulh = new int[r];

        // высчитывать в потоке
        for (int i=0; i<r; i++){
            mulh[i] = A->mtx[i][0] * A->mtx[i][1];

            for (int j=2; j<=B->r/2; j++){
                mulh[i] = mulh[i] + A->mtx[i][2*j-2] * A->mtx[i][2*j-1];
            }
        }

        int *mulv = new int[c];

        // высчитывать в потоке
        for (int i=0; i<c; i++){
            mulv[i] = B->mtx[0][i] * B->mtx[1][i];

            for (int j=2; j<=B->r/2; j++)
                mulv[i] = mulv[i] + B->mtx[2*j-2][i] * B->mtx[2*j-1][i];
        }


        res = generate_mtx(r, c);

        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++){
                res->mtx[i][j] = -mulh[i] - mulv[j];

                for (int k=1; k<=B->r/2; k++)
                    res->mtx[i][j] = res->mtx[i][j] + \
                            (A->mtx[i][2*k-2]+B->mtx[2*k-1][j])*(A->mtx[i][2*k-1]+B->mtx[2*k-2][j]);
            }

        if (r%2 != 0)
            for (int i=0; i<r; i++)
                for (int j=0; j<c; j++)
                    res->mtx[i][j] = res->mtx[i][j] + A->mtx[i][B->r-1] * B->mtx[B->r-1][j];

        delete []mulh;
        delete []mulv;
    }

    return res;
}


// Замена
// выражения в циклах b->r/2 на d +
// выражений типа a = a + b на a += b +
// увеличен шаг
// в цикле заменил k + 1 на k_1
// убран второй цикл

mtx_t *super_vinograd(mtx_t *A, mtx_t *B)
{
    mtx_t *res = nullptr;

    if (check(A->c, B->r))
    {
        int r = A->r; // row
        int c = B->c; // col
        int d = B->r-1; // Для последней строки-столбца в матрице

        //int d = B->r-1; // Значение для прохода пар элементов в матрицах(mulh, mulv)
        bool uneven = r % 2 != 0 ? 1 : 0; // Проверка размерности матрицы на четность

        int *mulh = new int[r]; // Массив отрицательных сумм по горизонтали
        int *mulv = new int[c]; // --//-- по вертикали
        int j_1;


        // Накапливаем отрицательные суммы
        for (int i=0; i<r; i++){

            mulh[i] = A->mtx[i][0] * A->mtx[i][1];
            mulv[i] = B->mtx[0][i] * B->mtx[1][i];

            for (int j=2; j<d; j+=2){

                j_1 = j+1;

                mulh[i] += A->mtx[i][j] * A->mtx[i][j_1];
                mulv[i] += B->mtx[j][i] * B->mtx[j_1][i];

            }
        }

        // Выделяем память под результирующую матрицу
        res = generate_mtx(r, c);
        int k_1;

        // Вычисляем матрицу
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++){
                res->mtx[i][j] = -mulh[i] - mulv[j];


                for (int k=0; k<d; k+=2){
                    k_1 = k+1;
                    res->mtx[i][j] += (A->mtx[i][k] + B->mtx[k_1][j])*\
                            (A->mtx[i][k_1] + B->mtx[k][j]);
                }

                // Если матрица нечетная
                if (uneven)
                    res->mtx[i][j] += A->mtx[i][d] * B->mtx[d][j];
            }

        delete []mulh;
        delete []mulv;
    }

    return res;
}


bool check(int c1, int r2)
{
    return c1 == r2 ? 1 : 0;
}


