/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:20:31 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/12 19:39:31 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*prev_elem;

	if (!lst || !(*f))
		return (NULL);
	new_lst = f(lst);
	prev_elem = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_elem = f(lst);
		prev_elem->next = new_elem;
		prev_elem = new_elem;
		lst = lst->next;
	}
	prev_elem->next = NULL;
	return (new_lst);
}
