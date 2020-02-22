/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:52:57 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/17 19:45:22 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_overflow_right(char *n)
{
	int	i;
	int buf;

	i = 0;
	while (n[i] != 'x')
		i++;
	i--;
	while (i > 0)
	{
		if (n[i] >= 10)
		{
			buf = n[i];
			n[i] = buf % 10;
			n[i - 1] += buf / 10;
		}
		i--;
	}
}

static void	sum_num(char *nbr, const char *buf, int shift)
{
	int	size_b;
	int	i;

	size_b = 0;
	i = 0;
	while (buf[size_b] != 'x')
		size_b++;
	shift -= size_b;
	while (i < shift)
	{
		if (nbr[i] == 'x')
			nbr[i] = 0;
		i++;
	}
	i = 0;
	while (size_b)
	{
		if (nbr[shift + i] == 'x')
			nbr[shift + i] = buf[size_b - 1];
		else
			nbr[shift + i] += buf[size_b - 1];
		i++;
		size_b--;
	}
	check_overflow_right(nbr);
}

static void	pow_right(char *nbr, int pow)
{
	int i;

	while (pow)
	{
		i = 0;
		while (nbr[i] != 'x')
			nbr[i++] *= 5;
		check_overflow(nbr);
		pow--;
	}
}

void		get_right(const char *m, t_wfloat *res)
{
	char	buf[EDGE];
	int		pos;
	int		pow;

	fill_x(res->right);
	if (res->l >= 52)
		return ;
	fill_x(buf);
	pos = (res->l > 0 ? res->l : 0);
	buf[0] = 1;
	pow = 0;
	if (res->r)
	{
		pow_right(buf, res->r);
		sum_num(res->right, buf, res->r);
	}
	while (pos < 52)
	{
		pow_right(buf, 1);
		if (m[pos] == '1')
			sum_num(res->right, buf, res->r + pow + 1);
		pow++;
		pos++;
	}
}
