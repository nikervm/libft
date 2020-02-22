/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:07:27 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/14 16:34:16 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_check(size_t nbr)
{
	if (nbr <= 1)
		return (0);
	if (nbr == 2)
		return (1);
	if (!(nbr % 2))
		return (0);
	if (nbr < 9)
		return (1);
	if (!(nbr % 3))
		return (0);
	return (2);
}

static int	second_check(size_t nbr)
{
	size_t i;

	i = 5;
	while ((i * i) <= nbr)
	{
		if (!(nbr % i))
			return (0);
		if (!(nbr % (i + 2)))
			return (0);
		i += 6;
	}
	return (1);
}

int			ft_isprime(size_t nbr)
{
	size_t i;

	i = first_check(nbr);
	if (i == 0)
		return (0);
	else if (i == 1)
		return (1);
	if (second_check(nbr))
		return (1);
	return (0);
}
