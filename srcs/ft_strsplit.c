/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:53:46 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/16 19:05:58 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		am_words(const char *s, char c)
{
	int			count;
	int			in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (in_word == 1 && *s == c)
			in_word = 0;
		if (in_word == 0 && *s != c)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_strlen_mod(const char *s, char c)
{
	int			i;

	i = 0;
	while (*s != c && *s++)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**new_arr;
	int			words;
	int			index;

	if (!s)
		return (NULL);
	index = 0;
	words = am_words((const char *)s, c);
	new_arr = (char **)malloc(sizeof(char *)
			* (am_words((const char *)s, c) + 1));
	if (!new_arr)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s)
			s++;
		new_arr[index] = ft_strsub((const char *)s,
				0, ft_strlen_mod((const char *)s, c));
		if (!new_arr[index])
			return (NULL);
		s = s + ft_strlen_mod(s, c);
		index++;
	}
	new_arr[index] = NULL;
	return (new_arr);
}
