/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:07 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/12 18:27:51 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_get_nbr(char *s, int n, int sign)
{
	if (n >= 10 || n <= -10)
		s = ft_get_nbr(s, n / 10, sign);
	*s++ = sign * (n % 10) + '0';
	return (s);
}

static int		ft_memory(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		memory;

	sign = (n >= 0) ? 1 : -1;
	if (sign == -1)
		memory = ft_memory(n) + 1;
	else
		memory = ft_memory(n);
	if (!(str = ft_strnew(memory)))
		return (NULL);
	if (sign == -1)
	{
		str = ft_get_nbr(str + 1, n, sign);
		str -= ft_memory(n) + 1;
		*str = '-';
		return (str);
	}
	str = ft_get_nbr(str, n, sign);
	return (str - ft_memory(n));
}
