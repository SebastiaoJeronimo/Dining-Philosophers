#include "philosophers.h"

void free_stuff(t_philo *philo)
{
    free(philo->fork);
    free(philo);
}

void    free_struct()
{
    t_data *d;
    int i;

    d = get_data();
    if (!d->philos)
        return ;
    i = 0;
    while (i < d->n_philo)
    {
        if (!d->philos[i].fork)
            break;
        pthread_mutex_destroy(d->philos[i].fork);
        free(d->philos[i].fork);
        i++;
    }
    //DAR FREE A TUDO NA STRUCT GLOBAL
    free(d->philos); //ja foi visto que existe na verificacao do inicio
}