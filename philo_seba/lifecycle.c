/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:38 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:38 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_lifecycle(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *) philo_arg;
	if (philo->philo_id % 2)
		usleep(philo->data->time_eat * 1000);
	if (!see_dead())
		lifecycle(philo);
	return (NULL);
}

void	lifecycle(t_philo *philo)
{
	while (1)
	{
		ft_usleep(DELAY);
		if (see_dead() || (philo->data->eat_times && see_full()))
			return ;
		get_forks(philo);
		wait(philo->data->time_eat);
		drop_forks(philo);
	}
}
