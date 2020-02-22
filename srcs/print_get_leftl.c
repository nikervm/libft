/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_leftl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:14:14 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/12 20:35:54 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sum_num(char *nbr, char *buf)
{
	int i;

	i = 0;
	while (buf[i] != 'x')
	{
		if (nbr[i] == 'x')
			nbr[i] = buf[i];
		else
			nbr[i] += buf[i];
		i++;
	}
	check_overflow(nbr);
}

static void	pow_left(char *nbr, int pow)
{
	int i;

	while (pow)
	{
		i = 0;
		while (nbr[i] != 'x')
		{
			nbr[i] *= 2;
			i++;
		}
		check_overflow(nbr);
		pow--;
	}
}

void		get_leftl(const char *mantis, t_wfloat *res)
{
	char	buf[EDGE];
	int		pos;

	fill_x(res->left);
	fill_x(buf);
	pos = (res->l > 63 ? 62 : res->l - 1);
	buf[0] = 1;
	if (res->r != 0)
	{
		res->left[0] = 0;
		return ;
	}
	res->left[0] = 1;
	pow_left(res->left, res->l);
	(res->l - 63 > 0 ? pow_left(buf, res->l - 63) : NULL);
	while (pos >= 0)
	{
		if (mantis[pos + 1] == '1')
			sum_num(res->left, buf);
		pow_left(buf, 1);
		pos--;
	}
}
