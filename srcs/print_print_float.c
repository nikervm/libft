/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:00:05 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/17 19:45:22 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_bank_round(t_wfloat *r, int pos)
{
	if (r->right[pos + 1] == 'x')
	{
		if (pos == 0)
		{
			if ((r->left[0] - '0') % 2 == 0 || r->right[0] == 'x')
				return ;
			r->left[0]++;
			return ;
		}
		if ((r->right[pos - 1] - '0') % 2 == 0)
			return ;
		r->right[pos - 1]++;
		return ;
	}
	if (pos == 0 && r->right[pos] >= '5')
	{
		r->left[0]++;
		return ;
	}
	(r->right[pos] >= '5' ? r->right[pos - 1]++ : 0);
}

void		check_overflow_round_left(char *nbr)
{
	int i;
	int buf;

	i = 0;
	while (nbr[i] != 'x')
	{
		if (nbr[i] - '0' >= 10)
		{
			buf = nbr[i] - '0';
			nbr[i] = (buf % 10) + '0';
			if (nbr[i + 1] == 'x')
				nbr[i + 1] = (buf / 10) + '0';
			else
				nbr[i + 1] += (buf / 10);
		}
		i++;
	}
}

void		check_overflow_round_right(t_wfloat *r, int pos)
{
	int buf;

	while (pos > 0 && r->right[pos] != 'x')
	{
		if (r->right[pos] - '0' >= 10)
		{
			buf = r->right[pos] - '0';
			r->right[pos] = (buf % 10) + '0';
			r->right[pos - 1] += (buf / 10);
		}
		pos--;
	}
	if (r->right[0] - '0' >= 10 && r->right[0] != 'x')
	{
		buf = r->right[0] - '0';
		r->right[0] = (buf % 10) + '0';
		r->left[0] += buf / 10;
		check_overflow_round_left(r->left);
	}
}

void		res_print(t_printf st, t_wfloat r)
{
	r.l = 0;
	r.r = 0;
	while (r.left[r.l] != 'x')
		r.left[r.l++] += '0';
	while (r.right[r.r] != 'x')
		r.right[r.r++] += '0';
	(st.prec <= EDGE ? rounding(st, &r) : NULL);
	if (st.flags.minus)
	{
		if ((st.flags.space || st.flags.plus) && !r.sign)
			print_repeat((st.flags.plus ? '+' : ' '), 1);
		print_repeat('-', r.sign);
		print_reverse_common_text(r.left, r.l);
		print_right_m(st, r);
	}
	else
		print_right_nm(st, r);
}

void		print_f_mod(t_printf st, double n)
{
	t_double	nr;
	t_wfloat	r;
	int			size;
	char		m[52];

	if (n == 1.0 / 0.0 || n == -1.0 / 0.0 || n != n || n == 0)
		return (print_inf_nan(n, st));
	nr.value = n;
	size = 52;
	while (size--)
	{
		m[size] = (char)(nr.t_byte.mantis % 2 + '0');
		nr.t_byte.mantis /= 2;
	}
	r.sign = (short)nr.t_byte.sign;
	get_size_of_number(nr, &r);
	get_left(m, &r);
	get_right(m, &r);
	res_print(st, r);
}
