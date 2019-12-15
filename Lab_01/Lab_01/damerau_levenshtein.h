#ifndef DAMERAU_LEVENSHTEIN_H
#define DAMERAU_LEVENSHTEIN_H

#include "base_counter.h"


// Рекурсивный алгоритм Дамерау-Левенштейна
class damerau_levenshtein: public base_counter
{
    public:
        damerau_levenshtein(std::string, std::string);

        void execute() override;
        void show() override;

    protected:
        size_t result() override;

    private:
        size_t res;
        //size_t n;

        size_t dist(std::string&, size_t, std::string&, size_t);
};


#endif // DAMERAU_LEVENSHTEIN_H
