/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:38:45 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/10 19:38:53 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_struct;

	if (!(new_struct = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_struct->content = NULL;
		new_struct->content_size = 0;
	}
	else
	{
		if (!(new_struct->content = (size_t *)malloc(content_size)))
			return (NULL);
		ft_memcpy(new_struct->content, content, content_size);
		new_struct->content_size = content_size;
	}
	new_struct->next = NULL;
	return (new_struct);
}
