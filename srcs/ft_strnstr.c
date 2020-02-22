/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:02:00 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/09 20:07:12 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		len_needle;

	if (!*needle)
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	while (*haystack && len-- >= len_needle)
	{
		if (*haystack == *needle)
			if (!(ft_memcmp(haystack, needle, len_needle)))
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
