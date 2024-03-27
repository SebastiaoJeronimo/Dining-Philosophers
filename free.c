#include "philosophers.h"

int free_death()
{
    t_data *d;

    d = get_data();
    pthread_mutex_destroy(d->death_lock);
    free(d->death_lock);
    return 0;
}

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
    if (d->meal_lock)
    {
        pthread_mutex_destroy(d->meal_lock);
        free(d->meal_lock);
        pthread_mutex_destroy(d->death_lock);
        free(d->death_lock);
    }
    free(d->philos); //ja foi visto que existe na verificacao do inicio
}