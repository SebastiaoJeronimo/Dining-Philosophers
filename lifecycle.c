#include "philosophers.h"

void start_lifecycle(void *philo_arg)
{
    t_philo *philo;

    philo = (t_philo *) philo_arg;
    printf("o id do philo e %d\n", philo->philo_id);
    if (philo->philo_id % 2)
        usleep(DELAY/2); //EXPERIMENTAR COM ESTE VALOR
    //if () ver se alguem ja morreu ou ja comeram
    lifecycle(philo);
    return ;
}

void lifecycle(t_philo *philo)
{
    //int i = philo->philo_id; //so para nao dar erro
    //printf("o num do philo e : %d \n" , i);
    while(1)
    {
        usleep(DELAY);
        if (see_dead() || (get_data()->eat_times && see_full()))
            return;
        get_forks(philo);
        drop_forks(philo);
    }
}
