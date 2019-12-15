#ifndef USERMTX_H
#define USERMTX_H

#include "decorator.h"

class userMtx:public Decorator
{
    public:
        userMtx(base_counter *);
        size_t execute() override;
        void show();

    private:
        base_counter *wrapee;

};

#endif // USERMTX_H
