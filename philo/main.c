/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:43 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:43 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief main function of the program
 *
 * @param argc number of arguments of the program
 * @param argv arguments of the program
 */
int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (printf(INVALID_INPUT));
	start_program();
	free_struct();
	return (0);
}
