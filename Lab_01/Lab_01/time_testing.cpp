#include "time_testing.h"

//200 символов
void timetest0()
{
    cout << "длина " << 200 << endl;

    std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb\
aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    std::string t = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb\
aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);

    time1->execute();
    time2->execute();

    delete method1;
    delete method2;

    cout << endl;
}

//100
void timetest1()
{
    cout << "длина " << 100 << endl;

    std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    std::string t = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);

    time1->execute();
    time2->execute();

    delete method1;
    delete method2;

    cout << endl;
}

//50 символов
void timetest2()
{
    cout << "длина " << 50 << endl;

    std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    std::string t = "bbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaa";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);

    time1->execute();
    time2->execute();

    delete method1;
    delete method2;

    cout << endl;
}

//10 символов
void timetest3()
{
    cout << "длина " << 10 << endl;

    std::string s = "aaaaabbbbb";
    std::string t = "bbbbbaaaaa";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


//8 символов
void timetest4()
{
    cout << "длина " << 8 << endl;

    std::string s = "aaaabbbb";
    std::string t = "bbbbaaaa";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


//5 символов
void timetest5()
{
    cout << "длина " << 5 << endl;

    std::string s = "aaaaa";
    std::string t = "bbbbb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


void timetest6()
{
    std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    std::string t = "bb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}

void timetest7()
{
    std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb";
    std::string t = "bbbb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


//11 символов
void timetest8()
{
    cout << "длина " << 11 << endl;

    std::string s = "aaaabbbbbbb";
    std::string t = "bbbbbbbaaaa";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


//12 символов
void timetest9()
{
    cout << "длина " << 12 << endl;

    std::string s = "aaaabbbbbbba";
    std::string t = "aaaabbbbbbba";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


//4 символa
void timetest10()
{
    cout << "длина " << 4 << endl;

    std::string s = "aaaa";
    std::string t = "bbbb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}



//2 символов
void timetest11()
{
    cout << "длина " << 2 << endl;

    std::string s = "aa";
    std::string t = "bb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


//5 символов
void timetest12()
{
    cout << "длина " << 5 << endl;

    std::string s = "aaaaa";
    std::string t = "bbbbb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}



//7 символов
void timetest13()
{
    cout << "длина " << 7 << endl;

    std::string s = "aaaaaaa";
    std::string t = "bbbbbbb";

    auto method1 = new levenstein_mtx(s, t);
    auto method2 = new damerau_levenshtein_mtr(s, t);
    auto method3 = new damerau_levenshtein(s, t);

    auto time1 = new TimeTest(method1);
    auto time2 = new TimeTest(method2);
    auto time3 = new TimeTest(method3);

    time1->execute();
    time2->execute();
    time3->execute();

    delete method1;
    delete method2;
    delete method3;

     cout << endl;
}


void time_testing_mode()
{
    timetest0();
    timetest1();
    timetest2();
    timetest3();
    //timetest4();
    //timetest5();
    //timetest6();
    //timetest7();
    //timetest8();
    //timetest9();
    //timetest10();
    //timetest11();
    //timetest12();
    //timetest13();

}

