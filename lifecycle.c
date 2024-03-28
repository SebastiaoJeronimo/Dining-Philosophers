#include "philosophers.h"

void start_lifecycle(void *philo_arg)
{
    t_philo *philo;

    philo = (t_philo *) philo_arg;
    philo_arg = NULL;
    printf("o id do philo e %d\n", philo->philo_id);
    if (philo->philo_id % 2)
        usleep(50); //EXPERIMENTAR COM ESTE VALOR
    //if () ver se alguem ja morreu ou ja comeram
    lifecycle(philo);
    return ;
}

void lifecycle(t_philo *philo)
{
    printf(TO_DO);
    int i = philo->philo_id; //so para nao dar erro
    printf("o num do philo e : %d \n" , i);
    //get_forks(philo);
    //get_forks()
    //pega no garfo esquerda 
    //pega no da direita 
    //largar os garfos

    //pensa
    //dorme
}