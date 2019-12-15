#ifndef DAMERAU_LEVENSHTEIN_MTR_H
#define DAMERAU_LEVENSHTEIN_MTR_H

#include "base_counter.h"


// Алгоритм Дамерау-Левенштейна, реализованный матрицей
class damerau_levenshtein_mtr : public base_counter
{
    public:
        damerau_levenshtein_mtr(const std::string&, const std::string&);

        void execute() override;
        void show() override;

        ~damerau_levenshtein_mtr() override;

    protected:
        size_t result() override;

    private:
        size_t len_str1;
        size_t len_str2;

        size_t res;

        size_t **mtx;

        size_t dist(std::string&, size_t, std::string&, size_t);
        void set_strings(const std::string& , size_t,
                         const std::string& , size_t);
};

#endif // DAMERAU_LEVENSHTEIN_MTR_H
