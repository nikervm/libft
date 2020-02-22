/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:21:59 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/09 20:56:29 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					sign;

	sign = 1;
	nbr = 0;
	while (*str == '\n' || *str == '\t'
	|| *str == '\r' || *str == '\f' || *str == '\v'
	|| *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (unsigned long long)(nbr * 10 + *str++ - '0');
		if (nbr > 9223372036854775807 && sign == 1)
			return (-1);
		if (nbr > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)(nbr * sign));
}
