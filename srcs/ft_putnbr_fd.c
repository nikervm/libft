/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:03:17 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/12 19:01:40 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int sign;

	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	if (n > -10 && n < 0)
		ft_putchar_fd('-', fd);
	sign = (n > 0) ? 1 : -1;
	ft_putchar_fd(sign * (n % 10) + '0', fd);
}
