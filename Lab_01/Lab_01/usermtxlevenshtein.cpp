#include "usermtxlevenshtein.h"


UserLevenshtein::UserLevenshtein(base_counter *base)
{
    wrapee = base;
}


void UserLevenshtein::execute()
{
    wrapee->execute();  // вычисление расстояния
    show();
}


void UserLevenshtein::show()
{
    wrapee->show();
}


size_t UserLevenshtein::result()
{
    return wrapee->result();
}
