/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:15:20 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/12 22:57:38 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_i(t_printf st, va_list args)
{
	if (st.mod == 0 || st.mod == 5)
		print_decimal(st, va_arg(args, int));
	else if (st.mod == 1)
		print_decimal(st, (short int)va_arg(args, int));
	else if (st.mod == 2)
		print_decimal(st, (char)va_arg(args, int));
	else if (st.mod == 3)
		print_decimal(st, va_arg(args, long int));
	else if (st.mod == 4)
		print_decimal(st, va_arg(args, long long int));
}

void	print_u(t_printf st, va_list args)
{
	if (st.mod == 0 || st.mod == 5)
		print_udecimal(st, va_arg(args, unsigned int));
	else if (st.mod == 1)
		print_udecimal(st, (unsigned short int)va_arg(args, unsigned int));
	else if (st.mod == 2)
		print_udecimal(st, (unsigned char)va_arg(args, unsigned int));
	else if (st.mod == 3)
		print_udecimal(st, (unsigned long)va_arg(args, unsigned long int));
	else if (st.mod == 4)
		print_udecimal(st,
				(unsigned long long)va_arg(args, unsigned long long int));
}

void	print_o(t_printf st, va_list args)
{
	if (st.mod == 0 || st.mod == 5)
		print_base_o(st, va_arg(args, unsigned int));
	else if (st.mod == 1)
		print_base_o(st, (unsigned short int)va_arg(args, unsigned int));
	else if (st.mod == 2)
		print_base_o(st, (unsigned char)va_arg(args, unsigned int));
	else if (st.mod == 3)
		print_base_o(st, (unsigned long)va_arg(args, unsigned long int));
	else if (st.mod == 4)
		print_base_o(st,
				(unsigned long long)va_arg(args, unsigned long long int));
}

void	print_x(t_printf st, va_list args)
{
	if (st.mod == 0 || st.mod == 5)
		print_base_x(st, va_arg(args, unsigned int));
	else if (st.mod == 1)
		print_base_x(st, (unsigned short int)va_arg(args, unsigned int));
	else if (st.mod == 2)
		print_base_x(st, (unsigned char)va_arg(args, unsigned int));
	else if (st.mod == 3)
		print_base_x(st, (unsigned long)va_arg(args, long int));
	else if (st.mod == 4)
		print_base_x(st, (unsigned long long)va_arg(args, long long int));
}

void	print_f(t_printf st, va_list args)
{
	if (st.mod == 5)
		print_l_mod(st, (long double)va_arg(args, long double));
	else
		print_f_mod(st, (double)va_arg(args, double));
}
