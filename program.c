#include "philosophers.h"

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

