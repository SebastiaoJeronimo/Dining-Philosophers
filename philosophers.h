#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>

//philo state args
#define EAT 1
#define THINK 2
#define SLEEP 3

struct s_philo
{
    int n_philo;
    int time_die;
    int time_eat;
    int time_think;
    int eat_times;
};
typedef struct s_philo t_philo;

#endif