/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:20:22 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/13 20:04:33 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p_no_minus(int len, t_printf st, char *hex_addr)
{
	if (st.prec_ex || !st.flags.zero)
	{
		print_repeat(' ', st.width - 2 - (st.prec > len ? st.prec : len));
		print_common_text("0x", 2);
		print_repeat('0', (st.prec > len ? st.prec - len : 0));
	}
	else
	{
		print_common_text("0x", 2);
		print_repeat('0', st.width - 2 - len);
	}
	print_reverse_common_text(&hex_addr[0], (st.prec_ex && !st.prec ? 0 : len));
}

void	print_o_no_minus(unsigned long long n, int len, t_printf st, char *add)
{
	if (st.flags.zero && !st.prec_ex)
		print_repeat('0', st.width - (st.flags.hash && n
		&& (st.prec <= len)) - (st.prec > len ? st.prec : len));
	else
		print_repeat(' ', st.width - (st.flags.hash && n && (st.prec <= len)) -
		(st.prec > len ? st.prec : len) - (st.prec_ex &&
		!st.prec && st.flags.hash && !n));
	print_repeat('0', (st.flags.hash && n && (st.prec <= len))
	|| (st.prec_ex && !st.prec && st.flags.hash && !n));
	print_repeat('0', (st.prec > len ? st.prec - len : 0));
	print_reverse_common_text(add, len);
}

void	print_x_no_minus(int n, int len, t_printf st, char *x_addr)
{
	char *start;

	start = "0x";
	(st.type == 'X' ? (start = "0X") : NULL);
	(!n ? st.flags.hash = 0 : 0);
	if (st.flags.zero && !st.prec_ex)
	{
		print_common_text(start, 2 * st.flags.hash);
		print_repeat('0', st.width - 2 * st.flags.hash - len);
		print_reverse_common_text(x_addr, len);
	}
	else
	{
		print_repeat(' ', st.width - 2 * st.flags.hash -
		(st.prec > len ? st.prec : len));
		print_common_text(start, 2 * st.flags.hash);
		print_repeat('0', (st.prec > len ? st.prec - len : 0));
		print_reverse_common_text(x_addr, len);
	}
}
