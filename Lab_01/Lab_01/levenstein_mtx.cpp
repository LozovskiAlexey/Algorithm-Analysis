#include "levenstein_mtx.h"

levenstein_mtx::levenstein_mtx(const std::string& s, const std::string& t)
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


void levenstein_mtx::set_strings(const std::string& s, size_t len_s,
                                          const std::string& t, size_t len_t)
{
    this->str1 = s;
    this->len_str1 = len_s;

    this->str2 = t;
    this->len_str2 = len_t;
};


// Вызов алгоритма Левенштейна
void levenstein_mtx::execute()
{
    res = dist(str1, len_str1,str2, len_str2);
};


// Матричный алгоритм Левенштейна
size_t levenstein_mtx::dist(std::string& s, size_t len_s, std::string& t, size_t len_t)
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
            }
        }
        res = mtx[len_s][len_t];
    }
    return res;
};

// Вывод результирующей матрицы
void levenstein_mtx::show()
{
    for (size_t i = 0; i <= len_str1; ++i)
    {
        for(size_t j = 0; j <= len_str2; ++j)
            printf("%d ", mtx[i][j]);

        printf("\n");
    }

    std::cout << "Levenshtein matrix result = " << res << std::endl;
};


levenstein_mtx::~levenstein_mtx()
{
    for (size_t i=0; i < len_str1; i++)
       delete [] mtx[i];

    delete [] mtx;
}


size_t levenstein_mtx::result()
{
    return res;
}
