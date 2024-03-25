#include "philosophers.h"

/****
 * 
 * timestamp_in_ms X has taken a fork
 * timestamp_in_ms X is eating
 * timestamp_in_ms X is sleeping
 * timestamp_in_ms X is thinking
 * timestamp_in_ms X died
 * 
 * FINISH THIS FUNCTION get the correct timings
*/
void *routine_one(void *arg)
{
    t_philo *philo = (t_philo *) arg;

    printf("%lld \n",get_data()->start_time);
    printf("%lld %d %s", (getTime() - get_data()->start_time), philo->philo_id, MSG_FORK);
    printf("%lld %d %s", (getTime() - get_data()->start_time), philo->philo_id, MSG_DIE);
    usleep(200000); 
    printf("%lld %d %s", (getTime() - get_data()->start_time), philo->philo_id, MSG_FORK);
    printf("%lld %d %s", (getTime() - get_data()->start_time), philo->philo_id, MSG_DIE);
    return 0;
}

/**
 * @brief this function its just to threat the edge case 
 * where there is only one philosopher
 * 
 */
void one_philo_case()
{
    t_philo *philo = (t_philo *) malloc(sizeof(t_philo)* 1);
    //free the stuff if fail
    //checkar malloc
    philo->n_eat_times = 0;
    philo->last_eat_time = getTime() - get_data()->start_time;
    philo->philo_id = 1;
    philo->fork = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
    //philo->fork = PTHREAD_MUTEX_INITIALIZER;
    printf("HERE1\n");
    if (pthread_mutex_init(philo->fork,NULL))
        return ; //free the stuff if fail
    printf("HERE2\n");
    if (pthread_create(&(philo->thread),NULL,routine,philo))
        return ; //free the stuff if fail 
    pthread_join(philo->thread, NULL);
    pthread_mutex_destroy(philo->fork);
    free(philo->fork);
    free(philo);
}

int init_threads()
{
    int i = 0;

    while(i < get_data()->n_philo)
    {
        if (pthread_create(get_data()->philos[i].thread, NULL \
        
        i++;
    }
}

void start_program()
{
    t_data *data;
    t_philo *philos;

    data = get_data();
    data->start_time = getTime();

    data->philos = malloc(sizeof(t_philo) * data->n_philo);
    int i = 0;
    while (i < data->n_philo)
    {
        philos[i].philo_id = i+1;
        philos[i].n_eat_times = 0;
        philos[i].last_eat_time = 0;
        philos[i].fork = malloc(sizeof(pthread_mutex_t));
        if (pthread_mutex_init(philos[i].fork,NULL))
            return ; //checkar se deu erro tipo mallo
        i++;
    } 



    //verificar malloc
    if (data->n_philo == 1)
    {
        printf("one philo\n");
        one_philo_case();
    }
    else 
    {
        printf("more than one philo\n");
        init_threads();
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