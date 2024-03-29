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

    d = get_data();
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
    lock_print(philo,M_FORK);
    lock_print(philo,M_FORK);
    lock_print(philo,M_EAT);
    eat(philo);
}

/**
 * @brief a specific philosopher drops the forkss
 * 
 */
void drop_forks(t_philo *philo)
{
    t_philo *next;
    t_data *d;

    d = get_data();
    next = &(d->philos[(philo->philo_id % d->n_philo)]);
    pthread_mutex_unlock(philo->fork);
    pthread_mutex_unlock(next->fork);
    if (see_dead() || see_full())
        return ;
    lock_print(philo,M_SLEEP);
    wait(d->time_sleep);
    lock_print(philo,M_THINK);
}

void eat(t_philo *philo)
{
    t_data *d;

    d = get_data();
    pthread_mutex_lock(d->meal_lock);
    philo->n_eat_times++;
    philo->last_eat_time = get_real_time(get_time());
    pthread_mutex_unlock(d->meal_lock);
    //FALTA AQUI O WAIT
}


void lock_print(t_philo *philo, char *msg)
{
    if (see_dead() || see_full())
        return ;
    //printf("o tempo em milisegundos é %lld", get_real_time(get_time()));
    printf("%lld %d %s",get_real_time(get_time()), philo->philo_id, msg);
}

