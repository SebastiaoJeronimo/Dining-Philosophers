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
        more_philos(data->n_philo);
}

