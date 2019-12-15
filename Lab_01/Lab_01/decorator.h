#ifndef DECORATOR_H
#define DECORATOR_H

#include "base_counter.h"

class Decorator: public base_counter
{
    public:
        Decorator();
        virtual size_t execute()=0;

    private:
        base_counter *wrapee;
};




#endif // DECORATOR_H
