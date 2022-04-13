#include "philosopher.hpp"

void eat(diners_t* diner)
{
    diner->eat[diner->philosopher] = true;
}

sem_t& left(diners_t* diner)
{
    int pos = diner->philosopher - 1; 
    if (pos < 0)
        pos += diner->size;
    return diner->forks[pos];
}

sem_t& right(diners_t* diner)
{
    return diner->forks[diner->philosopher];
}



