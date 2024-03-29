#include "philosophers.h"

/**
 * @brief picks up the forks for a specific philosopher
 * if there is 3 philosophers
 * 1 = (1 , 2)
 * 2 = (2 , 3)
 * 3 = (3 , 1)
 */
void get_forks(t_philo *philo)
{
    t_data *d;
    t_philo *next;

    next = &(d->philos[(philo->philo_id % d->n_philo)]);
    if (philo->philo_id < d->n_philo)
    {
        pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(next->fork);
    }
    else
    {
        pthread_mutex_lock(next->fork);
        pthread_mutex_lock(philo->fork);
    }
    //lock print
    if (!see_dead() || !see_full())
        return;
    printf (); //fork 
    printf (); //fork
    printf (); //eat
}

/**
 * @brief a specific philosopher drops the forkss
 * 
 */
void drop_forks()
{
    printf(TO_DO);
}