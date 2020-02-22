/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:01:48 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/11 22:33:41 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_l_mod(t_printf st, long double n)
{
	t_ldouble	nr;
	t_wfloat	r;
	int			size;
	char		m[64];

	if (n == 1.0 / 0.0 || n == -1.0 / 0.0 || n != n || n == 0)
		return (print_inf_nan(n, st));
	nr.value = n;
	size = 64;
	while (size--)
	{
		m[size] = (char)(nr.t_lbyte.mantis % 2 + '0');
		nr.t_lbyte.mantis /= 2;
	}
	r.sign = (short)nr.t_lbyte.sign;
	get_size_of_number_l(nr, &r);
	get_leftl(m, &r);
	get_rightl(m, &r);
	res_print(st, r);
}
