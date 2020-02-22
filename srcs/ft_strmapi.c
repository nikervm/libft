/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:48:29 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/08 14:57:22 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*start;
	char			*new_str;
	unsigned int	count;

	if (!s || !f)
		return (NULL);
	if (!(new_str = (char *)ft_strnew(ft_strlen(s))))
		return (NULL);
	start = new_str;
	count = 0;
	while (*s)
		*new_str++ = f(count++, *s++);
	*new_str = '\0';
	return (start);
}
