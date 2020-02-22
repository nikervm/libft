/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:43:38 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/06 20:33:14 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		if (len == 0 || dst == src)
			return (dst);
		d = (unsigned char *)dst + len - 1;
		s = (unsigned char *)src + len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
