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

    d = get_data();
    i = 0;
    while(i < d->n_philo)
    {
        if (pthread_create(d->philos, NULL, start_lifecycle, &(d->philos[i])))
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
    printf(TO_DO);
}