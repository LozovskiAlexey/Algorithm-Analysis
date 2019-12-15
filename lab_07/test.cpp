#include "test.h"

// TEST 1
bool shift_test_one_symbol(){
    std::string str = "a";
    auto size = str.length();

    shift_t expected = {0};
    shift_t shift = get_shift(str, size);

    return compare(shift, expected);
}


// TEST 2
bool shift_test_normal(){
    std::string str = "abcabcabcacb";
    auto size = str.length();

    shift_t expected = {0,0,0,1,2,3,4,5,6,7,0,0};
    auto shift = get_shift(str, size);

    return compare(shift, expected);
}


bool compare(shift_t& shift, shift_t& expected){
    bool isSame = true;
    auto size = shift.size();

    if (shift.size() == expected.size())
        for (size_t i=0; i<size; ++i)
            if (shift[i] != expected[i]){
                isSame = false;
                break;
            }

    return isSame;
}


bool kmp_test_1(){
    std::string str = "abcabcabcacb";
    std::string sub = "a";

    std::cout << bm(str, sub) << std::endl;

    return bm(str, sub) == 0 ? true : false;
}


bool kmp_test_2(){
    std::string str = "abcabcabcacb";
    std::string sub = "abcabcabcacb";

    std::cout << bm(str, sub) << std::endl;

    return bm(str, sub) == 0 ? true : false;
}


bool kmp_test_3(){
    std::string str = "abcabcabcacb";
    std::string sub = "bcacb";

    std::cout << bm(str, sub) << std::endl;

    return bm(str, sub) == 7 ? true : false;
}


bool kmp_test_4(){
    std::string str = "abcabcabcacb";
    std::string sub = "mn";

    std::cout << bm(str, sub) << std::endl;

    return bm(str, sub) == -1 ? true : false;
}


