/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:59:41 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/12 22:57:38 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_number(intmax_t n)
{
	char	a;
	int		sign;

	a = '0';
	sign = 1;
	if (n < 0)
		sign = -1;
	if (sign * (n / 10) != 0)
		print_number(sign * (n / 10));
	a += sign * (n % 10);
	((g_return % 2048 == 0 && g_return) ? write(1, g_buf, 2048)
	: (g_buf[g_return % 2048] = a));
	g_return++;
}

void		print_sign(intmax_t n, t_printf st)
{
	if (n >= 0 && (st.flags.plus || st.flags.space))
	{
		if (st.flags.plus)
			((g_return % 2048 == 0 && g_return) ? write(1, g_buf, 2048)
			: (g_buf[g_return % 2048] = '+'));
		else
			((g_return % 2048 == 0 && g_return) ? write(1, g_buf, 2048)
			: (g_buf[g_return % 2048] = ' '));
		g_return++;
	}
	if (n < 0)
	{
		((g_return % 2048 == 0 && g_return) ? write(1, g_buf, 2048)
		: (g_buf[g_return % 2048] = '-'));
		g_return++;
	}
}

void		print_minus_flag(intmax_t n, int len, t_printf st)
{
	print_sign(n, st);
	print_repeat('0', (st.prec > len ? st.prec - len : 0));
	if (!(st.prec_ex && !st.prec))
		print_number(n);
	if (st.prec_ex && !st.prec)
		len = 0;
	print_repeat(' ', st.width - (n >= 0 ? (st.flags.plus
	|| st.flags.space) : 1) - (st.prec > len ? st.prec : len));
}

static void	prec_zero(int *len, int n)
{
	*len = 0;
	if (n != 0)
		print_number(n);
}

void		print_no_minus_flag(intmax_t n, int len, t_printf st)
{
	if (st.prec_ex)
	{
		if (!st.prec)
			prec_zero(&len, n);
		print_repeat(' ', st.width - (n >= 0 ? (st.flags.plus
		|| st.flags.space) : 1) - (st.prec > len ? st.prec : len));
		print_sign(n, st);
		print_repeat('0', (st.prec > len ? st.prec - len : 0));
		(st.prec != 0 ? print_number(n) : NULL);
		return ;
	}
	if (st.flags.zero)
	{
		print_sign(n, st);
		print_repeat('0', st.width - (n >= 0 ? st.flags.plus
		|| st.flags.space : 1) - len);
	}
	else
	{
		print_repeat(' ', st.width - (n >= 0 ? st.flags.plus
		|| st.flags.space : 1) - len);
		print_sign(n, st);
	}
	print_number(n);
}
