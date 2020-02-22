/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:05:11 by vnasturt          #+#    #+#             */
/*   Updated: 2020/01/17 19:31:52 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(intmax_t nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}

void		print_decimal(t_printf st, intmax_t n)
{
	int len;

	len = nbr_len(n);
	if (st.flags.minus)
		print_minus_flag(n, len, st);
	else
		print_no_minus_flag(n, len, st);
}
