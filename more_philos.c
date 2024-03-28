#include "philosophers.h"

int initialize_philos(int n_philos, t_philo *philos)
{
    int i;

    i = 0;
    while (i < n_philos)
    {
        philos[i].philo_id = i+1;
        philos[i].n_eat_times = 0;
        philos[i].last_eat_time = 0;
        philos[i].fork = malloc(sizeof(pthread_mutex_t));
        if (!philos[i].fork)
            return 0;
        if (pthread_mutex_init((philos[i].fork), NULL))
            return 0;
        i++;
    }
    return 1;
}

void more_philos(int n_philos)
{
    t_data *d;

    d = get_data();
    d->philos = malloc(sizeof(t_philo) *n_philos);
    if(!d->philos)
    {
        printf(FAILED_MALLOC);
        return;
    }
    if (!initialize_philos(n_philos, d->philos))
    {
        printf(ERROR_INIT); //FREE STUFF
        return ;
    }
    start_threads();
    check_dead_full(); //
    join_threads();
}

/**
 * @brief stops the program when dead or full CHECKER
 * 
 */
void check_dead_full()
{
    //the global structure has to have the starting data
    
}

void check_dead()
{
    //checks for dead philos
    printf(TO_DO);
}

void check_full()
{
    //checks if all the philos are full
    printf(TO_DO);
}