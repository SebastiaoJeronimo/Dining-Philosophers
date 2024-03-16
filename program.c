#include "philosophers.h"

/****
 * 
 * timestamp_in_ms X has taken a fork
 * timestamp_in_ms X is eating
 * timestamp_in_ms X is sleeping
 * timestamp_in_ms X is thinking
 * timestamp_in_ms X died
 * 
*/
void *routine(void *arg)
{
    t_philo *philo = (t_philo *) arg;

    printf("%lld \n",get_data()->start_time);
    printf("%lld %d %s", (getTime() - get_data()->start_time), philo->philo_id, MSG_FORK);
    printf("%lld %d %s", (getTime() - get_data()->start_time), philo->philo_id, MSG_DIE);
}

/**
 * @brief this function its just to threat the edge case 
 * where there is only one philosopher
 * 
 */
int one_philo_case()
{
    t_philo *philo = (t_philo *) malloc(sizeof(t_philo)* 1);
    //checkar malloc
    philo->n_eat_times = 0;
    philo->last_eat_time = getTime() - get_data()->start_time;
    philo->philo_id = 1;
    philo->fork = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
    //philo->fork = PTHREAD_MUTEX_INITIALIZER;
    printf("HERE1\n");
    if (pthread_mutex_init(philo->fork,NULL))
        return (printf("error\n"),0);
    printf("HERE2\n");
    if (pthread_create(&(philo->thread),NULL,routine,philo))
        return (printf("error\n"),0);
    /**
     * philo 
     * neattimes
     * last eat time
     * n_philo
     * fork
     */
    //usleep(1000000);
    //free(philo->fork);
    //free(philo);
    pthread_join(philo->thread, NULL);
    pthread_mutex_destroy(philo->fork);
    free(philo->fork);
    free(philo);
}

void start_program()
{
    t_data *data;

    data = get_data();
    data->start_time = getTime();
    if (data->n_philo == 1)
    {
        printf("one_philo\n");
        one_philo_case();
    }
    else 
    {
        printf("something to be implemented");
        //more_philo();
    }
}

/*
void init_threads()
{
    int i;
    
    i = 0; 
    while (i < get_data()->n_philo)
    {
        if(pthread_create(&))
        i++;
    } 
}
*/