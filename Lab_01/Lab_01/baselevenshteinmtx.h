#ifndef BASELEVENSHTEINMTX_H
#define BASELEVENSHTEINMTX_H

#include "base_counter.h"


// Базовый класс для матричных алгоритмов
class BaseLevenshteinMtx : public base_counter
{
    public:
         virtual void execute()=0;
         virtual void show()=0;
};
#endif // BASELEVENSHTEINMTX_H
