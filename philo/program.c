/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:50 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:50 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_program(void)
{
	t_data	*data;

	data = get_data();
	if (data->n_philo == 1)
		one_philo_case();
	else
		more_philos(data->n_philo);
}
