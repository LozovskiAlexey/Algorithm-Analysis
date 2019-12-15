#include "user_mode.h"

void user_mode()
{
    std::string s;
    std::string t;

    std::cout << "Input the 1st string: ";
    std::cin >> s;

    std::cout << "Input the 2nd string: ";
    std::cin >> t;


    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);


    auto user_method1 = new UserLevenshtein(method1);
    auto user_method2 = new UserLevenshtein(method2);
    auto user_method3 = new UserLevenshtein(method3);


    user_method1->execute();
    user_method2->execute();
    user_method3->execute();
}
