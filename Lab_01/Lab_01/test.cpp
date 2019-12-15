#include "test.h"

Test::Test(base_counter *base, size_t res)
{
    wrapee = base;
    exp_res = res;
}


void Test::execute()
{
    wrapee->execute();
    show();
}


size_t Test::result()
{
    return wrapee->result();
}


void Test::show()
{
    std::cout << "Test string1: " << wrapee->str1 << std::endl;
    std::cout << "Test string2: " << wrapee->str2 << std::endl;

    std::cout << "Expected result: " << exp_res << std::endl;
    std::cout << "Real result: " << wrapee->result() << std::endl;

    std::string message = wrapee->result() == exp_res ? "Complited." : "Failed.";

    std::cout << "Test: " << message << "\n" << std::endl;
}
