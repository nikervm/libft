/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:44 by vnasturt          #+#    #+#             */
/*   Updated: 2020/02/22 15:27:38 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define EF 1023
# define EL 16383
# define EDGE 16383

# include <stdarg.h>
# include <stdint.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

int		g_return;
char	g_buf[2048];

typedef struct				s_wfloat
{
	char					left[EDGE];
	char					right[EDGE];
	int						l;
	int						r;
	short					sign;
}							t_wfloat;

typedef union				u_ldouble
{
	long double				value;
	struct					s_lbyte
	{
		unsigned long long	mantis : 64;
		unsigned short int	exp : 15;
		unsigned int		sign : 1;
	}						t_lbyte;
}							t_ldouble;

typedef union				u_double
{
	double					value;
	struct					s_byte
	{
		unsigned long long	mantis : 52;
		unsigned short int	exp : 11;
		unsigned int		sign : 1;
	}						t_byte;
}							t_double;

typedef struct				s_flag
{
	int						minus;
	int						plus;
	int						space;
	int						hash;
	int						zero;
}							t_flag;

typedef struct				s_printf
{
	t_flag					flags;
	int						width;
	int						prec;
	int						prec_ex;
	int						mod;
	char					type;
	const char				*start;
}							t_printf;

int							ft_printf(const char *format, ...);

int							types(char a);
int							fill_struct(t_printf *st,
							int size, const char *string);
void						flags(t_printf *st, const char **string);
void						width(t_printf *st, const char **string);
void						prec(t_printf *st, const char **s);
void						mod(t_printf *st, const char **s);

void						print(t_printf *st, int size, va_list arguments);
void						print_common_text(const char *string, int size);
void						print_repeat(char chr, int count);
void						print_number(intmax_t number);
void						print_reverse_common_text(const char *s, int size);
void						print_inf_nan(long double number, t_printf st);

void						print_perc(t_printf st);

void						print_d_i(t_printf st, va_list arguments);
void						print_decimal(t_printf st, intmax_t number);
void						print_minus_flag(intmax_t n,
							int len, t_printf st);
void						print_no_minus_flag(intmax_t n,
							int len, t_printf st);

void						print_u(t_printf st, va_list arguments);
void						print_udecimal(t_printf st, unsigned long long n);
void						uprt_nm(unsigned long long n, int len, t_printf st);
void						uprt_m(unsigned long long n, int len, t_printf st);

void						print_c(t_printf st, va_list args);

void						print_s(t_printf st, va_list arguments);

void						print_p(t_printf st,
							va_list arguments);
int							get_n_base(unsigned long long int a,
							char *ha, int base, int up);
void						print_p_no_minus(int len, t_printf st,
							char *hex_addr);

void						print_o(t_printf st, va_list args);
void						print_base_o(t_printf st, unsigned long long int n);
void						print_o_no_minus(unsigned long long number,
							int len, t_printf st,
							char *o_addr);

void						print_x(t_printf st, va_list args);
void						print_base_x(t_printf st,
							intmax_t n);
void						print_x_no_minus(int n, int len, t_printf st,
							char *x_addr);

void						print_f(t_printf st, va_list args);
void						print_f_mod(t_printf st, double n);
void						print_l_mod(t_printf st, long double n);

void						get_left(const char *mantis, t_wfloat *result);
void						fill_x(char *number);
void						check_overflow(char *nbr);
void						get_right(const char *mantis, t_wfloat *result);
void						rounding(t_printf st, t_wfloat *result);
void						print_right_m(t_printf st, t_wfloat result);
void						print_right_nm(t_printf st, t_wfloat result);
void						check_overflow_round_left(char *nbr);
void						check_overflow_round_right(t_wfloat *result,
							int pos);
void						check_bank_round(t_wfloat *result, int pos);
void						print_right_num(const char *n, int r, int size);
void						print_right_nm_extra(t_printf st, t_wfloat r);
void						get_size_of_number(t_double nr, t_wfloat *r);
void						res_print(t_printf st, t_wfloat r);
void						get_size_of_number_l(t_ldouble nr, t_wfloat *r);
void						get_leftl(const char *mantis, t_wfloat *res);
void						get_rightl(const char *m, t_wfloat *res);

#endif
