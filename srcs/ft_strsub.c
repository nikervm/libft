/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:11:23 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/08 15:22:02 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new_str;
	char *start_new_str;

	if (!s)
		return (NULL);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	start_new_str = new_str;
	s += start;
	while (*s && len--)
		*new_str++ = *s++;
	*new_str = '\0';
	return (start_new_str);
}
