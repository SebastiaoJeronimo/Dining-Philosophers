#include "philosophers.h"

/**
 * @brief starts a tread for each philosopher
 * 
 * @return 1 if all the threads were created correctly
 *         0 if one of the threads 
 *          
 */
int start_threads(){
    t_data *d;
    int i;

    i = 0;
    d = get_data();
    d->start_time = get_time();
    while(i < d->n_philo)
    {
        if (pthread_create(&(d->philos[i].thread), NULL,(void *) start_lifecycle, &(d->philos[i])))
            return 0;
        i++;
    }
    return 1;
}

/**
 * @brief this method waits for all the threads to be over and terminates them
 * 
 * @return int 
 */
int join_threads(){
    t_data *d;
    int i;
    
    i = 0;
    d = get_data();
    while (i < d->n_philo)
    {   
        if (pthread_join(d->philos[i].thread, NULL)) //esperar que as threads com o id especifico terminem
            return (0);
        i++;
    }
    return 1;
}

int see_dead()
{
    t_data *d;
    int result;

    d = get_data();
    pthread_mutex_lock(d->death_lock);
    result = d->death;
    pthread_mutex_unlock(d->death_lock);
    return result;
}

int see_full()
{
    t_data *d;
    int result;

    d = get_data();
    pthread_mutex_lock(d->meal_lock);
    result = d->meal;
    pthread_mutex_unlock(d->meal_lock);
    return result;
}

