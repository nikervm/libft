/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:21:06 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/12 20:49:34 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		rounding(t_printf st, t_wfloat *r)
{
	if (st.prec_ex)
	{
		if (st.prec == 0)
		{
			if (r->right[0] >= '5' && r->right[1] != 'x')
			{
				r->left[0]++;
				check_overflow_round_left(r->left);
			}
			else
				check_bank_round(r, 0);
			return ;
		}
		if (r->right[st.prec] >= '5' && r->right[st.prec] != 'x')
			check_bank_round(r, st.prec);
		check_overflow_round_right(r, st.prec - 1);
		return ;
	}
	if (r->right[6] >= '5' && r->right[6] != 'x')
		check_bank_round(r, 6);
	check_overflow_round_right(r, 5);
}

void		print_inf_nan(long double n, t_printf st)
{
	if (n == 1.0 / 0.0)
		print_common_text("inf", 3);
	else if (n == -1.0 / 0.0)
		print_common_text("-inf", 4);
	else if (n == 0)
	{
		print_common_text("0", 1);
		if (st.prec_ex)
		{
			if (!st.prec)
				return ;
			else
			{
				print_common_text(".", 1);
				print_repeat('0', st.prec);
				return ;
			}
		}
		print_common_text(".", 1);
		print_repeat('0', 6);
	}
	else
		print_common_text("nan", 3);
}

void		print_right_num(const char *n, int r, int size)
{
	int i;

	i = 0;
	while (size && i < r)
	{
		if (g_return % 2048 == 0 && g_return)
			write(1, g_buf, 2048);
		g_buf[g_return++ % 2048] = *(n + i);
		i++;
		size--;
	}
	while (size)
	{
		if (g_return % 2048 == 0 && g_return)
			write(1, g_buf, 2048);
		g_buf[g_return++ % 2048] = '0';
		size--;
	}
}

void		print_right_m(t_printf st, t_wfloat r)
{
	if (st.prec_ex)
	{
		if (!st.prec)
		{
			print_repeat('.', st.flags.hash);
			print_repeat(' ', st.width - (r.sign || st.flags.plus
			|| st.flags.space) - st.flags.hash - r.l);
			return ;
		}
		print_repeat('.', 1);
		print_right_num(r.right, r.r, st.prec);
		print_repeat(' ', st.width - (r.sign || st.flags.plus
		|| st.flags.space) - r.l - st.prec - 1);
		return ;
	}
	print_repeat('.', 1);
	print_right_num(r.right, r.r, 6);
	print_repeat(' ', st.width - (r.sign || st.flags.plus
	|| st.flags.space) - r.l - 7);
}

void		print_right_nm(t_printf st, t_wfloat r)
{
	if (st.flags.zero)
	{
		if ((st.flags.space || st.flags.plus) && !r.sign)
			print_repeat((st.flags.plus ? '+' : ' '), 1);
		print_repeat('-', r.sign);
		if (st.prec_ex && !st.prec)
			print_repeat('0', st.width - (st.flags.space || st.flags.plus
			|| r.sign) - st.flags.hash - r.l);
		else
			print_repeat('0', st.width - (st.flags.space || st.flags.plus
			|| r.sign) - r.l - (st.prec_ex ? st.prec + 1 : 7));
	}
	else
	{
		if (st.prec_ex && !st.prec)
			print_repeat(' ', st.width - (st.flags.space || st.flags.plus
			|| r.sign) - st.flags.hash - r.l);
		else
			print_repeat(' ', st.width - (st.flags.space || st.flags.plus
			|| r.sign) - r.l - (st.prec_ex ? st.prec + 1 : 7));
		if ((st.flags.space || st.flags.plus) && !r.sign)
			print_repeat((st.flags.plus ? '+' : ' '), 1);
		print_repeat('-', r.sign);
	}
	print_right_nm_extra(st, r);
}
