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
    check_dead_full(get_data());
    join_threads();
}
 
/**
 * @brief stops the program when dead or full CHECKER
 * 
 */
void check_dead_full(t_data *d)
{
    long long marker;
    int i;

    while (!see_dead() && !see_full() /*!d->death && !d->meal*/)
    {
        usleep(LOOP_DELAY);
        if (d->eat_times)
            set_full(d);
        i = 0;
        while (i < d->n_philo)
        {
            pthread_mutex_lock(d->meal_lock);
            if (get_real_time(get_time()) >= time_sum(d->philos[i].last_eat_time, d->time_die))
            {
                pthread_mutex_unlock(d->meal_lock); //temos que dar unlock antes
                set_dead(d, i);
            }
            else
                pthread_mutex_unlock(d->meal_lock);
            i++;
        }
    }
}

/**
 * @brief marks that one philo is killed
 * 
 */
void set_dead(t_data *d, int i)
{
    if (see_dead() || see_full())
        return ;
    pthread_mutex_lock(d->death_lock);
    d->death = 1;
    pthread_mutex_unlock(d->death_lock);
    printf("%lld %d %s", get_real_time(get_time()), i, M_DIE);
}

/**
 * @brief set the flag to mark that all the philosophers are full 
 * 
 */
void set_full(t_data *d)
{
    printf(TO_DO);
}