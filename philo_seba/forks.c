/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:35 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:35 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief picks up the forks for a specific philosopher
 * if there is 3 philosophers
 * 1 = (1 , 2)
 * 2 = (2 , 3)
 * 3 = (3 , 1)
 */
void	get_forks(t_philo *philo)
{
	t_data	*d;
	//t_philo	*next;

	d = philo->data;
	//next = &(d->philos[(philo->philo_id % d->n_philo)]);
	if (philo->philo_id < d->n_philo)
	{
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(philo->next->fork);
		//pthread_mutex_lock(next->fork);
	}
	else
	{
		//pthread_mutex_lock(next->fork);
		pthread_mutex_lock(philo->next->fork);
		pthread_mutex_lock(philo->fork);
	}
	lock_print(philo, M_FORK);
	lock_print(philo, M_FORK);
	lock_print(philo, M_EAT);
	eat(philo);
}

void	think(t_philo *philo)
{
	lock_print(philo, M_THINK);
	if (philo->data->n_philo % 2)
		if (philo->data->time_eat * 2 > philo->data->time_sleep)
			usleep((philo->data->time_eat * 2
					- philo->data->time_sleep) * 1000);
}

/**
 * @brief a specific philosopher drops the forkss
 *
 */
void	drop_forks(t_philo *philo)
{
	//t_philo	*next;
	t_data	*d;

	d = philo->data;
	//next = &(d->philos[(philo->philo_id % d->n_philo)]);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
	//pthread_mutex_unlock(next->fork);
	if (see_dead() || see_full())
		return ;
	lock_print(philo, M_SLEEP);
	wait(d->time_sleep);
	think(philo);
}

void	eat(t_philo *philo)
{
	t_data	*d;

	d = philo->data;
	pthread_mutex_lock(d->meal_lock);
	philo->n_eat_times++;
	philo->last_eat_time = (get_time() - philo->data->start_time);
	pthread_mutex_unlock(d->meal_lock);
}

void	lock_print(t_philo *philo, char *msg)
{
	t_data	*d;

	d = philo->data;
	pthread_mutex_lock(d->meal_lock);
	pthread_mutex_lock(d->death_lock);
	if (philo->data->death || philo->data->meal)
	{
		pthread_mutex_unlock(d->meal_lock);
		pthread_mutex_unlock(d->death_lock);
		return ;
	}
	printf("%ld %d %s", (get_time()
			- philo->data->start_time), philo->philo_id, msg);
	pthread_mutex_unlock(d->meal_lock);
	pthread_mutex_unlock(d->death_lock);
}
