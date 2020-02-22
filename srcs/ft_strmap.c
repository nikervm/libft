/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:32:39 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/11 19:49:44 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*start;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	if (!(new_str = (char *)ft_strnew(ft_strlen(s))))
		return (NULL);
	start = new_str;
	while (*s)
		*new_str++ = f(*s++);
	*new_str = '\0';
	return (start);
}
