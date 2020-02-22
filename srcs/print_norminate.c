/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:48:36 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/12 21:08:14 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_right_nm_extra(t_printf st, t_wfloat r)
{
	print_reverse_common_text(r.left, r.l);
	print_repeat('.', (st.prec_ex && st.prec ? 1 : 0) || (!st.prec_ex)
	|| (st.prec_ex && !st.prec && st.flags.hash ? 1 : 0));
	print_right_num(r.right, r.r, (st.prec_ex ? st.prec : 6));
}

void	get_size_of_number(t_double nr, t_wfloat *r)
{
	if (nr.t_byte.exp - EF >= 0)
	{
		r->l = nr.t_byte.exp - EF;
		r->r = 0;
	}
	else
	{
		r->l = 0;
		r->r = EF - nr.t_byte.exp;
	}
}

void	get_size_of_number_l(t_ldouble nr, t_wfloat *r)
{
	if (nr.t_lbyte.exp - EL >= 0)
	{
		r->l = nr.t_lbyte.exp - EL;
		r->r = 0;
	}
	else
	{
		r->l = 0;
		r->r = EL - nr.t_lbyte.exp;
	}
}
