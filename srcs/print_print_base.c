/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:36:15 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/13 19:56:04 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_base_o(t_printf st, unsigned long long int n)
{
	char	o[64];
	char	*start;
	int		len;
	int		check;

	if (st.prec_ex && !st.prec && !n)
		len = 0;
	else
		len = get_n_base(n, &o[0], 8, 0);
	start = NULL;
	check = (st.prec_ex && !st.prec && st.flags.hash && !n);
	(((st.flags.hash && n && (st.prec <= len))
	|| check) ? (start = "0") : NULL);
	if (st.flags.minus)
	{
		print_common_text(start, (st.flags.hash &&
		n && (st.prec <= len)) || check);
		print_repeat('0', (st.prec >= len ? st.prec - len -
		(st.flags.hash && n && (st.prec <= len)) : 0));
		(st.prec_ex && !st.prec ? NULL : print_reverse_common_text(&o[0], len));
		print_repeat(' ', st.width - (st.flags.hash && n
		&& (st.prec <= len)) - check - (st.prec >= len ? st.prec : len));
	}
	else
		print_o_no_minus(n, len, st, &o[0]);
}

void		print_base_x(t_printf st, intmax_t n)
{
	char	x[64];
	char	*start;
	int		len;

	len = 0;
	start = "0x";
	((st.prec_ex && !st.prec && !n) ? 0 : (len = get_n_base(n,
	&x[0], 16, (st.type == 'X'))));
	(st.type == 'X' ? (start = "0X") : NULL);
	(!n ? st.flags.hash = 0 : 0);
	if (st.flags.minus)
	{
		print_common_text(start, 2 * st.flags.hash);
		print_repeat('0', (st.prec > len ? st.prec - len : 0));
		print_reverse_common_text(&x[0], len);
		print_repeat(' ', st.width - (st.prec > len ? st.prec : len) -
		2 * st.flags.hash);
	}
	else
		print_x_no_minus(n, len, st, &x[0]);
}
