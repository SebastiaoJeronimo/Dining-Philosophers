/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:48 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:48 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// philo state args
# define EAT 1
# define THINK 2
# define SLEEP 3

// philo args
# define N_PHILO 1
# define T_DIE 2
# define T_EAT 3
# define T_SLEEP 4
# define N_T_EAT 5

// messages
# define M_FORK "has taken a fork\n"
# define M_EAT "is eating\n"
# define M_SLEEP "is sleeping\n"
# define M_THINK "is thinking\n"
# define M_DIE "died\n"
# define INVALID_INPUT "invalid input\n"
# define FAILED_MALLOC "failed malloc\n"
# define ERROR_INIT "Error initialization\n"

// debug MACROS
# define TO_DO "TO BE IMPLEMENTED\n"
# define FREE "FREE ALLOCATED MEMORY\n"
# define FINISH "FINISH IMPLEMENTING\n"

// time Macros
# define DELAY 100
# define LOOP_DELAY 100

struct s_philo
{
	int				n_eat_times;
	long			last_eat_time;
	int				philo_id;
	pthread_mutex_t	*fork;
	pthread_t		thread;
};
typedef struct s_philo	t_philo;

struct s_data
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_times;
	long			start_time;
	t_philo			*philos;
	int				meal;
	pthread_mutex_t	*meal_lock;
	int				death;
	pthread_mutex_t	*death_lock;
};
typedef struct s_data	t_data;

// data.c
t_data	*get_data(void);

// arg_check.c
int		check_args(int argc, char **argv);
int		check_valid_number(char *num_str);
void	store_valid_input(int num_arg, int num);
int		create_mutexes(void);

// utils.c
int		ft_isdigit(int c);

// program.c
void	start_program(void);
void	routine2(void);

// one_philo.c
void	one_philo_case(void);
void	*routine_one(void *none);

// more_philos.c
void	more_philos(int n_philos);
int		initialize_philos(int n_philos, t_philo *philos);
void	check_dead_full(t_data *d);
void	set_dead(t_data *d, int index);
void	check_full(t_data *d);

// free.c
void	free_struct(void);
void	free_stuff(t_philo *philo);
int		free_death(void);

// threads.c
int		start_threads(void);
int		join_threads(void);
int		see_dead(void);
int		see_full(void);

// lifecycle.c
void	*start_lifecycle(void *philo_arg);
void	lifecycle(t_philo *philo);

// forks.c
void	get_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat(t_philo *philo);
void	lock_print(t_philo *philo, char *msg);

// wait.c
void	wait(long wait);

// time.c
long	get_time(void);
long	did_philo_starve(long last_meal_time);
long	get_real_time(long num);
long	time_diff(long num1, long num2);
long	time_sum(long num1, long num2);

#endif