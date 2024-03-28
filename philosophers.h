#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
#define M_FORK      "has taken a fork\n"
#define M_EAT       "is eating\n"
#define M_SLEEP     "is sleeping\n"
#define M_THINK     "is thinking\n"
#define M_DIE       "died\n"
#define INVALID_INPUT "invalid input\n"
#define FAILED_MALLOC "failed malloc\n"
#define ERROR_INIT "Error initialization\n"

//debug MACROS
#define TO_DO "TO BE IMPLEMENTED\n"
#define FREE "FREE ALLOCATED MEMORY\n"
#define FINISH "FINISH IMPLEMENTING\n"

//time Macros
#define DELAY 100
#define LOOP_DELAY 100


struct s_philo //philo struct
{
    int n_eat_times;
    long long last_eat_time;
    int philo_id;
    pthread_mutex_t *fork;
    pthread_t thread;
};
typedef struct s_philo t_philo;

struct s_data //cena da data
{
    int n_philo;
    int time_die; 
    int time_eat;
    int time_sleep;
    int eat_times;
    long long start_time; //AINDA NAO INICIALIZEI ESTA MERDA
    t_philo *philos;
    int meal;
    pthread_mutex_t *meal_lock;
    int death;
    pthread_mutex_t *death_lock;
};
typedef struct s_data t_data;

//data.c
t_data *get_data();

//arg_check.c
int check_args(int argc, char **argv);
int check_valid_number(char *num_str);
void store_valid_input(int num_arg, int num);
int create_mutexes();

//utils.c
int	ft_isdigit(int c);

//program.c
void start_program();
void routine2(void );

//one_philo.c
void one_philo_case();
void *routine_one();

//more_philos.c
void more_philos(int n_philos);
int initialize_philos(int n_philos, t_philo *philos);
void check_dead_full(t_data *d);
void set_dead(t_data *d, int index);
void check_full(t_data *d);

//free.c
void free_struct();
void free_stuff(t_philo *philo);
int free_death();

//time.c
long long get_time();
long long did_philo_starve(long long last_meal_time);
long long get_real_time(long long num);
long long time_diff(long long num1, long long num2);
long long time_sum(long long num1, long long num2);

//threads.c
int start_threads();
int join_threads();
int see_dead();
int see_full();
//void lock_alter

//lifecycle.c
void start_lifecycle(void *philo_arg);
void lifecycle();

#endif