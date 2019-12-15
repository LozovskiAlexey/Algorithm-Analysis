#ifndef USERMTXLEVENSHTEIN_H
#define USERMTXLEVENSHTEIN_H

#include "base_counter.h"


//Базовый класс для пользовательского режима
//Позволяет выполнять методы с последующим выводом матрицы
class UserLevenshtein : public base_counter
{
    public:
        UserLevenshtein(base_counter *);

        void execute() override;
        size_t result() override;

    private:
        base_counter *wrapee;

        void show() override;
};

#endif // USERMTXLEVENSHTEIN_H
