/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:16:09 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/06 22:45:29 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*dst;

	length = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (length + 1));
	if (!dst)
		return (NULL);
	dst[length] = '\0';
	while (length--)
		dst[length] = s1[length];
	return (dst);
}
