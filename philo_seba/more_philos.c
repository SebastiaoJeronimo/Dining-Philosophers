/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:44 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:44 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialize_philos(int n_philos, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		philos[i].philo_id = i + 1;
		philos[i].n_eat_times = 0;
		philos[i].last_eat_time = 0;
		philos[i].fork = malloc(sizeof(pthread_mutex_t));
		philos[i].data = get_data();
		if (!philos[i].fork)
			return (0);
		if (pthread_mutex_init((philos[i].fork), NULL))
			return (0);
		philos[i].next = &(philos[(philos[i].philo_id % n_philos)]);
		i++;
	}
	return (1);
}

void	more_philos(int n_philos)
{
	t_data	*d;

	d = get_data();
	d->philos = malloc(sizeof(t_philo) * n_philos);
	if (!d->philos)
	{
		printf(FAILED_MALLOC);
		return ;
	}
	if (!initialize_philos(n_philos, d->philos))
	{
		printf(ERROR_INIT);
		return ;
	}
	start_threads();
	check_dead_full(get_data());
	join_threads();
}

/**
 * @brief stops the program when dead or full CHECKER
 *
 */
void	check_dead_full(t_data *d)
{
	int	i;

	while (!see_dead() && !see_full())
	{
		usleep(LOOP_DELAY);
		if (d->eat_times)
			check_full(d);
		i = 0;
		while (i < d->n_philo)
		{
			pthread_mutex_lock(d->meal_lock);
			if ((get_time() - get_data()->start_time)
				>= time_sum(d->philos[i].last_eat_time,
					d->time_die))
			{
				pthread_mutex_unlock(d->meal_lock);
				set_dead(d, i);
			}
			else
				pthread_mutex_unlock(d->meal_lock);
			i++;
		}
	}
}

/**
 * @brief marks that one philo_diogo is killed
 *
 */
void	set_dead(t_data *d, int i)
{
	if (see_dead() || see_full())
		return ;
	pthread_mutex_lock(d->death_lock);
	d->death = 1;
	pthread_mutex_unlock(d->death_lock);
	printf("%ld %d %s", (get_time() - get_data()->start_time), i + 1, M_DIE);
}

/**
 * @brief checks if all the philosophers are full
 *
 */
void	check_full(t_data *d)
{
	int	i;

	i = 0;
	if (see_dead() || see_full())
		return ;
	while (i < d->n_philo)
	{
		pthread_mutex_lock(d->meal_lock);
		if (d->philos[i].n_eat_times < d->eat_times)
		{
			pthread_mutex_unlock(d->meal_lock);
			return ;
		}
		else
			pthread_mutex_unlock(d->meal_lock);
		i++;
	}
	pthread_mutex_lock(d->meal_lock);
	d->meal = 1;
	pthread_mutex_unlock(d->meal_lock);
}
