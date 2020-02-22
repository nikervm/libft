/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:56:25 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/06 21:18:39 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s01;
	unsigned char *s02;

	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	while (n--)
	{
		if (*s01 != *s02)
			return (*s01 - *s02);
		s01++;
		s02++;
	}
	return (0);
}
