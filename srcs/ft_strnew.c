/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:53:14 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/13 20:05:28 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_str;

	if (size + 1 == 0)
		return (NULL);
	if (!(new_str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (new_str);
}
