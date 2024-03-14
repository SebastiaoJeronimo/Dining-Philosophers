#include "philosophers.h"

/**
 * @brief this function its just to threat the edge case 
 * where there is only one philosopher
 * 
 */
void one_philo_case()
{
    
}

void start_program()
{
    t_data *data;

    data = get_data();
    if (data->n_philo == 1)
    {
        one_philo_case();
    }
    else 
    {
        more_philo();
    }
}