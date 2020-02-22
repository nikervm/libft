/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:12:00 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/13 21:59:11 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(t_printf *st, const char **s)
{
	while (**s == '-' || **s == '+' || **s == ' '
	|| **s == '#' || **s == '0')
	{
		if (**s == '-')
			st->flags.minus = 1;
		else if (**s == '+')
			st->flags.plus = 1;
		else if (**s == ' ')
			st->flags.space = 1;
		else if (**s == '#')
			st->flags.hash = 1;
		else if (**s == '0')
			st->flags.zero = 1;
		(*s)++;
	}
}

void	width(t_printf *st, const char **s)
{
	while (**s >= '0' && **s <= '9')
	{
		st->width = st->width * 10 + **s - '0';
		(*s)++;
	}
}

void	prec(t_printf *st, const char **s)
{
	if (**s == '.')
	{
		(*s)++;
		st->prec_ex = 1;
		while (**s >= '0' && **s <= '9')
		{
			st->prec = st->prec * 10 + **s - '0';
			(*s)++;
		}
	}
}

void	mod(t_printf *st, const char **s)
{
	if (**s == 'h')
	{
		st->mod = 1;
		(*s)++;
		if (**s == 'h')
		{
			st->mod = 2;
			(*s)++;
		}
	}
	else if (**s == 'l')
	{
		st->mod = 3;
		(*s)++;
		if (**s == 'l')
		{
			st->mod = 4;
			(*s)++;
		}
	}
	else if (**s == 'L')
	{
		st->mod = 5;
		(*s)++;
	}
}

int		types(char a)
{
	if (a == 'd' || a == 'i' || a == 'o'
	|| a == 'u' || a == 'x' || a == 'X'
	|| a == 'f' || a == 'c' || a == 'p'
	|| a == 's' || a == '%')
		return (1);
	return (0);
}
