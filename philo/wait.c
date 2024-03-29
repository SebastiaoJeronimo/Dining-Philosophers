/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:57 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:57 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait(long wait)
{
	long	begin;

	begin = get_time();
	while (1)
	{
		if (see_dead())
			return ;
		if (get_time() - begin > wait)
			return ;
		usleep(DELAY * 5);
	}
}
