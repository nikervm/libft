/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:57:58 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/11 20:38:32 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	char	*start_new_str;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (*(s + start) == ' ' || *(s + start) == '\n'
	|| *(s + start) == '\t')
		start++;
	while (*(s + end) == ' ' || *(s + end) == '\n'
	|| *(s + end) == '\t')
		end--;
	if (ft_strlen(s + start) == 0)
		return (new_str = ft_strnew(0));
	if (!(new_str = ft_strnew(end - start + 1)))
		return (NULL);
	start_new_str = new_str;
	while (end - start + 1)
		*new_str++ = *(s + start++);
	*new_str = '\0';
	return (start_new_str);
}
