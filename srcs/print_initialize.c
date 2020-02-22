/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:56:59 by vnasturt          #+#    #+#             */
/*   Updated: 2020/01/17 19:04:46 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialize_st(t_printf *st, int size)
{
	while (size--)
	{
		st[size].flags.minus = 0;
		st[size].flags.plus = 0;
		st[size].flags.space = 0;
		st[size].flags.hash = 0;
		st[size].flags.zero = 0;
		st[size].width = 0;
		st[size].prec = 0;
		st[size].prec_ex = 0;
		st[size].mod = 0;
		st[size].type = 0;
		st[size].start = NULL;
	}
}

static void	common_text(t_printf *st, const char **s)
{
	if (**s == '%' && *(*s + 1) != '%')
		return ;
	st->type = 't';
	st->start = *s;
	while (**s)
	{
		if (**s == '%')
		{
			if (*(*s + 1) != '%')
				return ;
			st->width++;
			(*s)++;
		}
		st->width++;
		(*s)++;
	}
}

int			fill_struct(t_printf *st, int size, const char *s)
{
	int i;

	i = 0;
	initialize_st(st, size);
	while (i < size)
	{
		common_text(&st[i], &s);
		if (!st[i].type)
		{
			st[i].start = s++;
			flags(&st[i], &s);
			width(&st[i], &s);
			prec(&st[i], &s);
			mod(&st[i], &s);
			if (!types(*s))
				return (-1);
			st[i].type = *s;
			s++;
		}
		i++;
	}
	return (0);
}
