/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:48:21 by vnasturt          #+#    #+#             */
/*   Updated: 2020/01/23 23:09:07 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void		print_c(t_printf st, va_list args)
{
	char c;

	c = va_arg(args, int);
	if (!st.flags.minus)
	{
		while (--st.width > 0)
		{
			if (st.flags.zero)
				(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
				: (g_buf[g_return++ % 2048] = '0'));
			else
				(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
				: (g_buf[g_return++ % 2048] = ' '));
		}
		(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
		: (g_buf[g_return++ % 2048] = c));
		return ;
	}
	(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
	: (g_buf[g_return++ % 2048] = c));
	while (--st.width > 0)
		(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
		: (g_buf[g_return++ % 2048] = ' '));
}

void		print_s(t_printf st, va_list args)
{
	const char	*s;
	int			pr;

	s = va_arg(args, const char *);
	(!s ? (s = "(null)") : NULL);
	pr = (st.prec_ex && st.prec < ft_strlen(s) ? st.prec : ft_strlen(s));
	if (!st.flags.minus)
	{
		while (st.width-- - pr > 0)
		{
			if (st.flags.zero)
				(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
				: (g_buf[g_return++ % 2048] = '0'));
			else
				(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
				: (g_buf[g_return++ % 2048] = ' '));
		}
		print_common_text(s, pr);
		return ;
	}
	print_common_text(s, pr);
	while (st.width-- - pr > 0)
		(g_return % 2048 == 0 && g_return ? write(1, g_buf, 2048)
		: (g_buf[g_return++ % 2048] = ' '));
}

int			get_n_base(unsigned long long int a, char *ha, int base, int up)
{
	char	*alph;
	int		i;

	if (!up)
		alph = "0123456789abcdef";
	else
		alph = "0123456789ABCDEF";
	i = 0;
	while (a / base != 0)
	{
		ha[i++] = alph[a % base];
		a = a / base;
	}
	ha[i] = alph[a % base];
	ha[i + 1] = '\0';
	return (i + 1);
}

void		print_p(t_printf st, va_list args)
{
	long int	addr;
	char		hex_addr[64];
	int			len;

	addr = va_arg(args, intptr_t);
	len = get_n_base(addr, &hex_addr[0], 16, 0);
	if (st.flags.minus)
	{
		print_common_text("0x", 2);
		print_repeat('0', (st.prec > len ? st.prec - len : 0));
		print_reverse_common_text(&hex_addr[0], len);
		print_repeat(' ', st.width - 2 - (st.prec > len ? st.prec : len));
	}
	else
		print_p_no_minus(len, st, &hex_addr[0]);
}
