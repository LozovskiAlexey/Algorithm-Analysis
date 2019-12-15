#ifndef TEST_H
#define TEST_H

#include "base_counter.h"

class Test : base_counter
{
public:
    Test(base_counter *, size_t);

    void execute() override;

private:
    base_counter *wrapee;
    size_t exp_res;

    void show() override;
    size_t result() override;

};

#endif // TEST_H
