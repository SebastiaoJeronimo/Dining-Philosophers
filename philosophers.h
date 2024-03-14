#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

//philo state args
#define EAT 1
#define THINK 2
#define SLEEP 3

//philo args
#define N_PHILO 1
#define T_DIE   2
#define T_EAT   3
#define T_SLEEP 4
#define N_T_EAT 5

//messages
# define MSG_FORK   "has taken a fork\n"
# define MSG_EAT    "is eating\n"
# define MSG_SLEEP  "is sleeping\n"
# define MSG_THINK  "is thinking\n"
# define MSG_DIE    "died\n"
# define INVALID_INPUT "invalid input\n"

struct s_data //cena da data
{
    int n_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int eat_times;
};
typedef struct s_data t_data;


//data.c

t_data *get_data();

//arg_check.c

int check_args(int argc, char **argv);
int check_valid_number(char *num_str);
void store_valid_input(int num_arg, int num);

//utils.c

int	ft_isdigit(int c);

//program.c
void start_program();

//time.c
long long getTime();


#endif