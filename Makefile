# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnasturt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:51:58 by vnasturt          #+#    #+#              #
#    Updated: 2020/02/22 16:13:23 by vnasturt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   ft_atoi.c           		ft_bzero.c          		ft_isalnum.c        		ft_isalpha.c        		\
        ft_isascii.c        		ft_isdigit.c        		ft_isprint.c        		ft_itoa.c           		\
        ft_lstadd.c         		ft_lstdel.c         		ft_lstdelone.c      		ft_lstiter.c        		\
        ft_lstmap.c         		ft_lstnew.c         		ft_memalloc.c       		ft_memccpy.c        		\
        ft_memchr.c         		ft_memcmp.c         		ft_memcpy.c         		ft_memdel.c         		\
        ft_memmove.c        		ft_memset.c         		ft_putchar.c        		ft_putchar_fd.c     		\
        ft_putendl.c        		ft_putendl_fd.c     		ft_putnbr.c         		ft_putnbr_fd.c      		\
        ft_putstr.c         		ft_putstr_fd.c      		ft_strcat.c         		ft_strchr.c         		\
        ft_strclr.c         		ft_strcmp.c         		ft_strcpy.c         		ft_strdel.c         		\
        ft_strdup.c         		ft_strequ.c         		ft_striter.c        		ft_striteri.c       		\
        ft_strjoin.c        		ft_strlcat.c        		ft_strlen.c         		ft_strmap.c         		\
        ft_strmapi.c        		ft_strncat.c        		ft_strncmp.c        		ft_strncpy.c        		\
        ft_strnequ.c        		ft_strnew.c         		ft_strnstr.c        		ft_strrchr.c        		\
        ft_strsplit.c       		ft_strstr.c         		ft_strsub.c         		ft_strtrim.c        		\
        ft_tolower.c        		ft_toupper.c        		ft_count_words.c    		ft_isspace.c        		\
        ft_lst_print.c      		ft_nbrlen.c         		ft_strrev.c         		ft_isprime.c				\
		get_next_line.c				print_check.c				print_decimal_extra.c		print_extra.c				\
		print_ft_printf.c			print_get_left.c			print_get_leftl.c			print_get_right.c			\
		print_get_rightl.c			print_handle_print.c		print_initialize.c			print_norminate.c			\
		print_print.c				print_print_base.c			print_print_csp.c			print_print_float.c			\
		print_print_float_extra.c	print_print_long_double.c	print_print_unsigned.c		print_signed_decimal.c		\
		print_unsigned_extra.c
OBJ =   $(SRC:.c=.o)

SRCDIR  = srcs
OBJDIR  = objs
SRCS    = $(addprefix $(SRCDIR)/, $(SRC))
OBJS    = $(addprefix $(OBJDIR)/, $(OBJ))

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -c

NAME    = libft.a
HEADER  = -I includes

.PHONY:     all clean fclean re
.SUFFIXES:  .c .o

all: $(NAME)

directories:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	 $(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME): directories $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
