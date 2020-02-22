/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:10:19 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/17 19:45:21 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_overflow(char *nbr)
{
	int	i;
	int	buf;

	i = 0;
	while (nbr[i] != 'x')
	{
		if (nbr[i] >= 10)
		{
			buf = nbr[i];
			nbr[i] = buf % 10;
			if (nbr[i + 1] == 'x')
				nbr[i + 1] = buf / 10;
			else
				nbr[i + 1] += buf / 10;
		}
		i++;
	}
}

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

void		fill_x(char *n)
{
	int size;

	size = EDGE;
	while (size)
	{
		size--;
		n[size] = 'x';
	}
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

void		get_left(const char *mantis, t_wfloat *res)
{
	char	buf[EDGE];
	int		pos;

	fill_x(res->left);
	fill_x(buf);
	pos = (res->l > 52 ? 51 : res->l - 1);
	buf[0] = 1;
	if (res->r != 0)
	{
		res->left[0] = 0;
		return ;
	}
	res->left[0] = 1;
	pow_left(res->left, res->l);
	(res->l - 52 > 0 ? pow_left(buf, res->l - 52) : NULL);
	while (pos >= 0)
	{
		if (mantis[pos] == '1')
			sum_num(res->left, buf);
		pow_left(buf, 1);
		pos--;
	}
}
