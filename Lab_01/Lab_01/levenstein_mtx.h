#ifndef LEVENSTEIN_MTX_H
#define LEVENSTEIN_MTX_H

#include "base_counter.h"

//Алгоритм Левенштейна, реализованный матрицей
class levenstein_mtx: public base_counter
{
    public:
        levenstein_mtx(const std::string&, const std::string&);

        void execute() override;
        void show() override;

        ~levenstein_mtx() override;

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

#endif // LEVENSTEIN_MTX_H
