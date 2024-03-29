/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:37 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:37 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_death(void)
{
	t_data	*d;

	d = get_data();
	pthread_mutex_destroy(d->death_lock);
	free(d->death_lock);
	return (0);
}

void	free_stuff(t_philo *philo)
{
	free(philo->fork);
	free(philo);
}

void	free_struct(void)
{
	t_data	*d;
	int		i;

	d = get_data();
	if (!d->philos)
		return ;
	i = 0;
	while (i < d->n_philo)
	{
		if (!d->philos[i].fork)
			break ;
		pthread_mutex_destroy(d->philos[i].fork);
		free(d->philos[i].fork);
		i++;
	}
	if (d->meal_lock)
	{
		pthread_mutex_destroy(d->meal_lock);
		free(d->meal_lock);
		pthread_mutex_destroy(d->death_lock);
		free(d->death_lock);
	}
	free(d->philos);
}
