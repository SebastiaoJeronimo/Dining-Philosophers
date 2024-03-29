/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:06:55 by scosta-j          #+#    #+#             */
/*   Updated: 2024/03/29 06:06:55 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief checks if a character is a ascii digit
 *
 * @param c character that is going to be checked
 * @returns 1 if a character is a number 0 if its not
 */
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
