/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:08:13 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/13 22:18:30 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*shift_str(const char *s)
{
	while (*s)
	{
		if (*s != '%')
			s++;
		else
		{
			if (*(s + 1) == '%')
				s += 2;
			else
				return (s);
		}
	}
	return (s);
}

static int			count_elems(const char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			s++;
			while (!types(*s) && *s)
				s++;
			if (*s)
				s++;
			i++;
		}
		else
		{
			s = shift_str(s);
			i++;
		}
	}
	return (i);
}

void				print_perc(t_printf st)
{
	if (st.flags.minus)
	{
		print_repeat(st.type, 1);
		print_repeat(' ', st.width - 1);
		return ;
	}
	print_repeat((st.flags.zero ? '0' : ' '), st.width - 1);
	print_repeat(st.type, 1);
}

int					ft_printf(const char *s, ...)
{
	int			am_elems;
	t_printf	*format;
	va_list		args;

	g_return = 0;
	am_elems = count_elems(s);
	if (!(format = (t_printf *)malloc(sizeof(t_printf) * am_elems)))
		return (-1);
	if (fill_struct(format, am_elems, s) < 0)
	{
		free(format);
		return (0);
	}
	va_start(args, s);
	print(format, am_elems, args);
	va_end(args);
	free(format);
	write(1, g_buf, g_return % 2048);
	return (g_return);
}
