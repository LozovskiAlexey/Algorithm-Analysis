#include "levenstein_mtx.h"
#include "damerau_levenshtein.h"
#include "damerau_levenshtein_mtr.h"

#include "test.h"


void test1()
{
    std::string s = "skat";
    std::string t = "kot";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto test1 = new Test(method1, 2);
    auto test2 = new Test(method2, 2);
    auto test3 = new Test(method3, 2);

    test1->execute();
    test2->execute();
    test3->execute();

    delete method1;
    delete method2;
    delete method3;
};


void test2()
{
    std::string s = "backseat";
    std::string t = "seatback";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto test1 = new Test(method1, 8);
    auto test2 = new Test(method2, 8);
    auto test3 = new Test(method3, 8);

    test1->execute();
    test2->execute();
    test3->execute();

    delete method1;
    delete method2;
    delete method3;
};


void test3()
{
    std::string s = "";
    std::string t = "kot";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto test1 = new Test(method1, 3);
    auto test2 = new Test(method2, 3);
    auto test3 = new Test(method3, 3);

    test1->execute();
    test2->execute();
    test3->execute();

    delete method1;
    delete method2;
    delete method3;
};



void test4()
{
    std::string s = "";
    std::string t = "";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto test1 = new Test(method1, 0);
    auto test2 = new Test(method2, 0);
    auto test3 = new Test(method3, 0);

    test1->execute();
    test2->execute();
    test3->execute();

    delete method1;
    delete method2;
    delete method3;
};



void test5()
{
    std::string s = "martial";
    std::string t = "matrial";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto test1 = new Test(method1, 2);
    auto test2 = new Test(method2, 1);
    auto test3 = new Test(method3, 1);

    test1->execute();
    test2->execute();
    test3->execute();

    delete method1;
    delete method2;
    delete method3;
};


void func_testing_mode()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
