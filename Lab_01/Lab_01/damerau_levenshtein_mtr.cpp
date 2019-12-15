#include "damerau_levenshtein_mtr.h"

damerau_levenshtein_mtr::damerau_levenshtein_mtr(const std::string& s, const std::string& t)
{
    size_t len_s = s.length();
    size_t len_t = t.length();


    if (len_s > len_t)
        set_strings(s, len_s, t, len_t);
    else
        set_strings(t, len_t, s, len_s);

    mtx = new size_t *[len_str1+1];

    for (size_t i=0; i<=len_str1; i++)
        mtx[i] = new size_t [len_str2+1];

    res = 0;
};


// Устанавливает строки в атрибуты класса
void damerau_levenshtein_mtr::set_strings(const std::string& s, size_t len_s,
                                          const std::string& t, size_t len_t)
{
    this->str1 = s;
    this->len_str1 = len_s;

    this->str2 = t;
    this->len_str2 = len_t;
};


// Вызывает матричный алгоритм Дамерау-Левенштейна
void damerau_levenshtein_mtr::execute()
{  
        res = dist(str1, len_str1, str2, len_str2);
};


// Матричный алгоритм Дамерау-Левенштейна
size_t damerau_levenshtein_mtr::dist(std::string& s, size_t len_s, std::string& t, size_t len_t)
{   
    for (size_t i=0; i<=len_str1; ++i)
        mtx[i][0] = i;

    for (size_t j=0; j<=len_str2; ++j)
        mtx[0][j] = j;

    if ((len_s == 0) and (len_t == 0))
        res = 0;
    else
    {
        for(size_t i = 1; i <= len_s; ++i)
        {
            for(size_t j = 1; j <= len_t; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    mtx[i][j] = mtx[i - 1][j - 1];
                else
                    mtx[i][j] = min(mtx[i - 1][j - 1] + 1,
                                min(mtx[i - 1][  j  ] + 1,
                                    mtx[  i  ][j - 1] + 1));

                if (i > 1 && j > 1 && s[i - 1] == t[j - 2] && s[i - 2] == t[j - 1])
                    mtx[i][j] = min(mtx[i][j], mtx[i - 2][j - 2] + 1);
            }
        }
        res = mtx[len_s][len_t];
    }
    return res;
};


// Вывод результрующей матрицы
void damerau_levenshtein_mtr::show()
{
    for (size_t i = 0; i <= len_str1; ++i)
    {
        for(size_t j = 0; j <= len_str2; ++j)
            printf("%d ", mtx[i][j]);

        printf("\n");
    }

    std::cout << "Damerau-Levenshtein matrix result = " << res << std::endl;
};


damerau_levenshtein_mtr::~damerau_levenshtein_mtr()
{
    for (size_t i=0; i < len_str1; i++)
       delete [] mtx[i];

    delete [] mtx;
}


size_t damerau_levenshtein_mtr::result()
{
    return res;
}
