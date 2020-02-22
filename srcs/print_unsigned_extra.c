/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:19:47 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/13 20:20:13 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	uprint_number(unsigned long long n)
{
	char	a;

	a = '0';
	if ((n / 10) != 0)
		uprint_number((n / 10));
	a += (n % 10);
	((g_return % 2048 == 0 && g_return) ? write(1, g_buf, 2048)
										: (g_buf[g_return % 2048] = a));
	g_return++;
}

void		uprt_m(unsigned long long n, int len, t_printf st)
{
	print_repeat('0', (st.prec > len ? st.prec - len : 0));
	if (!(st.prec_ex && !st.prec))
		uprint_number(n);
	if (st.prec_ex && !st.prec)
		len = 0;
	print_repeat(' ', st.width - (st.flags.plus
	|| st.flags.space) - (st.prec > len ? st.prec : len));
}

static void	prec_zero(int *len, unsigned long long n)
{
	*len = 0;
	if (n != 0)
		uprint_number(n);
}

void		uprt_nm(unsigned long long n, int len, t_printf st)
{
	if (st.prec_ex)
	{
		if (!st.prec)
			prec_zero(&len, n);
		print_repeat(' ', st.width - (st.prec > len ? st.prec : len));
		print_repeat('0', (st.prec > len ? st.prec - len : 0));
		(st.prec != 0 ? uprint_number(n) : NULL);
		return ;
	}
	if (st.flags.zero)
		print_repeat('0', st.width - (st.flags.plus
		|| st.flags.space) - len);
	else
		print_repeat(' ', st.width - (st.flags.plus
		|| st.flags.space) - len);
	uprint_number(n);
}
