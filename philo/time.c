/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:53 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:53 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief get the time using the archaic function gettimeofday
 * @return long that corresponds to the time in miliseconds
 */
long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * @brief Get the real time difference since starting the program
 *
 * @param num is the number that is going to be subtracted to the initial value
 * @return long the real time value
 */
long	get_real_time(long num)
{
	return (num - get_data()->start_time);
}

/**
 * @brief computes the time diff
 *
 * @param num1 the latest timestamp
 * @param num2 teh older  timestamp
 * @returns the difference bettween the two numebrs of miliseconds
 */
long	time_diff(long num1, long num2)
{
	return (num1 - num2);
}

/**
 * @brief computes the sum of the timestamps
 *
 * @param num1
 * @param num2
 * @return long
 */
long	time_sum(long num1, long num2)
{
	return (num1 + num2);
}

/**
 * @brief checks if the philosopher starved
 * using its last meal timestamp
 *
 * @param last_meal_time the last time that the philosopher ate
 * @returns 1 if the philosopher starved and 0 if it didnt starve
 */
long	did_philo_starve(long last_meal_time)
{
	t_data	*data;

	data = get_data();
	if ((get_time() - last_meal_time) > data->time_eat)
		return (1);
	return (0);
}
