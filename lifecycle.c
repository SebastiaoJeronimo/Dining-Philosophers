#include "philosophers.h"

void start_lifecycle(void *philo_arg)
{
    t_philo *philo;

    philo = (t_philo *) philo_arg;

    if (philo->philo_id % 2)
        usleep(DELAY*3); //EXPERIMENTAR COM ESTE VALOR
    if (!see_dead())//if () ver se alguem ja morreu ou ja comeram
        lifecycle(philo);
    return ;
}

void lifecycle(t_philo *philo)
{
    while(1)
    {
        usleep(DELAY);
        if (see_dead() || (get_data()->eat_times && see_full()))
            return;
        get_forks(philo);
        wait(get_data()->time_eat);
        drop_forks(philo);
    }
}
