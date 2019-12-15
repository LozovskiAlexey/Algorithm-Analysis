#include "damerau_levenshtein.h"

damerau_levenshtein::damerau_levenshtein(std::string s, std::string t)
{
    this->str1 = s;
    this->str2 = t;
};


// Вызывает рекурсивный алгоритм
void damerau_levenshtein::execute()
{
    size_t len_s = this->str1.length();
    size_t len_t = this->str2.length();

    std::string s = this->str1;
    std::string t = this->str2;

    res = dist(s, len_s, t, len_t);
};


// Реализация рекурсивного алгоритма
size_t damerau_levenshtein::dist(std::string& s, size_t len_s, std::string& t, size_t len_t)
{
    //n += 1;
    if (len_s == 0)
        return len_t;

    if (len_t == 0)
        return len_s;

    size_t cost = (s[len_s - 1] == t[len_t - 1]) ? 0 : 1;

    if (len_s > 1 && len_t > 1 && s[len_s-1] == t[len_t-2] && s[len_s-2] == t[len_t-1])
        return  std::min({
                             dist(s, len_s - 1, t, len_t    ) + 1,
                             dist(s, len_s, t, len_t - 1) + 1,
                             dist(s, len_s - 1, t, len_t - 1 ) + cost,
                             dist(s, len_s - 2, t, len_t - 2 ) + 1
                         });

    else
        return std::min({
                            dist(s, len_s - 1, t, len_t    ) + 1,
                            dist(s, len_s, t, len_t - 1) + 1,
                            dist(s, len_s - 1, t, len_t - 1 ) + cost
                        });
};


void damerau_levenshtein::show()
{
    std::cout << "Damerau-levenshtein recursion result = " << res<< std::endl;
    //std::cout << "recursion depth = " << n<< std::endl;

};


size_t damerau_levenshtein::result()
{
    return res;
}

