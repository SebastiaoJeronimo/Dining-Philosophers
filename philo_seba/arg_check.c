/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:30 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:30 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_mutexes(void)
{
	t_data	*d;

	d = get_data();
	d->death_lock = malloc(sizeof(pthread_mutex_t));
	if (!d->death_lock)
		return (0);
	if (pthread_mutex_init((d->death_lock), NULL))
	{
		free(d->death_lock);
		return (0);
	}
	d->meal_lock = malloc(sizeof(pthread_mutex_t));
	if (!d->meal_lock)
		return (free_death());
	if (pthread_mutex_init((d->meal_lock), NULL))
	{
		free(d->meal_lock);
		return (free_death());
	}
	return (1);
}

/**
 * @brief stores the valid input number in the static/singleton struct
 *
 * @param num_arg the number of the argv position of the argument
 * @param num the int of the argv number
 */
void	store_valid_input(int num_arg, int num)
{
	t_data	*data;

	data = get_data();
	if (num_arg == N_PHILO)
		data->n_philo = num;
	else if (num_arg == T_DIE)
		data->time_die = num;
	else if (num_arg == T_EAT)
		data->time_eat = num;
	else if (num_arg == T_SLEEP)
		data->time_sleep = num;
	else
	{
		data->eat_times = num;
		data->meal = 0;
		data->death = 0;
	}
}

/**
 * @brief checks if the number is valid it has to be positive and lower than < 1
 * @param num_str each arg which is a number in string format
 * @returns 0 if the number is valid and returns the number if its valid //
 */
int	check_valid_number(char *num_str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (num_str[i])
	{
		if ((num > INT_MAX) | !ft_isdigit(num_str[i]) | i >= 10)
			return (0);
		num = num * 10 + (num_str[i] - '0');
		i++;
	}
	return (num);
}

/**
 * @brief checks if the arguments are in the correct format
 *
 * @param argc number of arguments
 * @param argv the array with with arguments
 * @returns 1 if the arguments are in a correct form  0 if not
 */
int	check_args(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	if (!(argc == 5 || argc == 6))
		return (0);
	while (i < argc)
	{
		num = check_valid_number(argv[i]);
		if (!num)
			return (0);
		store_valid_input(i, num);
		if (i == 1 && num > 1)
		{
			if (!create_mutexes())
			{
				printf(FAILED_MALLOC);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
