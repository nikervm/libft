/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:31:16 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/07 18:23:49 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t res;

	len_dst = ft_strlen(dst);
	res = ft_strlen(src);
	if (size <= len_dst)
		res += size;
	else
		res += len_dst;
	dst += len_dst;
	while (*src && (len_dst + 1) < size)
	{
		*dst++ = *src++;
		len_dst++;
	}
	*dst = '\0';
	return (res);
}
