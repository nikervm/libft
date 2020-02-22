/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:16:18 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/12 23:20:07 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(unsigned long long nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}

void		print_udecimal(t_printf st, unsigned long long n)
{
	int len;

	len = nbr_len(n);
	if (st.flags.minus)
		uprt_m(n, len, st);
	else
		uprt_nm(n, len, st);
}
