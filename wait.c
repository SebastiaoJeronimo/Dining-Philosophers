#include "philosophers.h"

void wait(t_philo *philo, long long wait)
{
    long long begin;

    begin = get_time();
    while(1)
    {
        if(see_dead())
            return ;
        if (get_time() - begin > wait)
            return ;
        usleep(DELAY);
    }
}