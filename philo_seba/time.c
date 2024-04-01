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
