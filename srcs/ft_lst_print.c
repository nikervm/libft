/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:59:22 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/13 22:30:57 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print(t_list *lst)
{
	if (lst)
		while (lst)
		{
			ft_putendl((char *)lst->content);
			ft_putnbr((int)lst->content_size);
			write(1, "\n\n", 2);
			lst = lst->next;
		}
}
