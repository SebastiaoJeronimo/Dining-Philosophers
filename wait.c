#include "philosophers.h"

void wait(long long wait)
{
    long long begin;

    begin = get_time();
    while(1)
    {
        if(see_dead())
            return ;
        //printf ("time : %lld\n", get_time() - begin);
        //printf ("wait : %lld\n", wait);
        if (get_time() - begin > wait)
            return ;
        usleep(DELAY*5);
    }
}