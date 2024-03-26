#include "philosophers.h"

void start_lifecycle(void *philo_arg)
{
    t_philo *philo;

    philo = (t_philo *) philo_arg;
    if (philo->philo_id % 2)
        usleep(25);
    //if () ver se alguem ja morreu ou ja comeram
    //lifecycle()
    (philo);
}

void lifecycle(t_philo *philo)
{

}