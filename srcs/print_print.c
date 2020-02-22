/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:55:12 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/13 22:12:54 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_reverse_common_text(const char *s, int size)
{
	while (size--)
	{
		if (g_return % 2048 == 0 && g_return)
			write(1, g_buf, 2048);
		g_buf[g_return++ % 2048] = *(s + size);
	}
}

void	print_common_text(const char *string, int size)
{
	if (!string)
		return ;
	while (size--)
	{
		if (g_return % 2048 == 0 && g_return)
			write(1, g_buf, 2048);
		if (*string == '%' && *(string + 1) == '%')
		{
			g_buf[g_return++ % 2048] = *string;
			string += 2;
			size--;
		}
		else
			g_buf[g_return++ % 2048] = *string++;
	}
}

void	print_repeat(char chr, int count)
{
	while (count-- > 0)
	{
		while (g_return % 2048 == 0 && g_return)
			write(1, g_buf, 2048);
		g_buf[g_return++ % 2048] = chr;
	}
}

void	print_float_perc(t_printf st, va_list args)
{
	if (st.type == 'f')
		print_f(st, args);
	else
		print_perc(st);
}

void	print(t_printf *st, int size, va_list args)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (st[i].type == 't')
			print_common_text(st[i].start, st[i].width);
		else if (st[i].type == 'c')
			print_c(st[i], args);
		else if (st[i].type == 's')
			print_s(st[i], args);
		else if (st[i].type == 'p')
			print_p(st[i], args);
		else if (st[i].type == 'd' || st[i].type == 'i')
			print_d_i(st[i], args);
		else if (st[i].type == 'u')
			print_u(st[i], args);
		else if (st[i].type == 'o')
			print_o(st[i], args);
		else if (st[i].type == 'x' || st[i].type == 'X')
			print_x(st[i], args);
		else if (st[i].type == 'f' || st[i].type == '%')
			print_float_perc(st[i], args);
	}
}
