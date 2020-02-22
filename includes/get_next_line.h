/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnasturt <vnasturt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:55:40 by vnasturt          #+#    #+#             */
/*   Updated: 2019/09/15 21:38:37 by vnasturt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "fcntl.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
