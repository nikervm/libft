/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:55:04 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/13 20:57:47 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(const char *s, char c)
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
