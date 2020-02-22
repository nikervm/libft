/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:24:15 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/13 23:22:12 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		forward;
	int		backward;
	char	c;

	forward = 0;
	backward = ft_strlen(s) - 1;
	while (forward < (backward + 1) / 2)
	{
		c = *(s + forward);
		*(s + forward) = *(s + backward - forward);
		*(s + backward - forward) = c;
		forward++;
	}
	return (s);
}
