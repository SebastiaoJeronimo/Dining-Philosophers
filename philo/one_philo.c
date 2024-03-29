/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:46 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:46 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/****
 *
 * timestamp_in_ms X has taken a fork
 * timestamp_in_ms X + tdied
 *
 * FINISH THIS FUNCTION get the correct timings
 * ASK IF THE TIMMING IS 200 or 201 and if starts in 0 or 1
 */
void	*routine_one(void *none)
{
	(void) none;
	printf("%d %d %s", 0, 1, M_FORK);
	usleep(get_data()->time_die * 1000);
	printf("%d %d %s", get_data()->time_die, 1, M_DIE);
	return (0);
}

/**
 * @brief this function its just to threat the edge case
 * where there is only one philosopher
 *
 * BRUTE FORCE THIS
 */
void	one_philo_case(void)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (!philo)
		return ;
	philo->n_eat_times = 0;
	philo->last_eat_time = get_time() - get_data()->start_time;
	philo->philo_id = 1;
	philo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo->fork)
		return (free(philo));
	if (pthread_mutex_init(philo->fork, NULL))
		return (free_stuff(philo));
	if (pthread_create(&(philo->thread), NULL, routine_one, NULL))
		return (free_stuff(philo));
	pthread_join(philo->thread, NULL);
	pthread_mutex_destroy(philo->fork);
	free_stuff(philo);
}
