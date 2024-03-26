#include "philosophers.h"

/*
int init_threads()
{
    int i = 0;

    while(i < get_data()->n_philo)
    {
        if (pthread_create(get_data()->philos[i].thread, NULL \
        
        i++;
    }
}
*/



void start_program()
{
    t_data *data;

    data = get_data(); //ver se realmente preciso desta shit aqui
    //data->start_time = getTime();

    if (data->n_philo == 1)
        one_philo_case();
    else 
        more_philos();
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
/*
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
*/