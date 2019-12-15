#include "usermtx.h"

userMtx::userMtx(base_counter *obj)
{
    wrapee = obj;
};


size_t userMtx::execute()
{
    size_t res = wrapee->execute();

    return res;
};
