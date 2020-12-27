# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 16:36:34 by cclarice          #+#    #+#              #
#    Updated: 2020/12/27 17:39:02 by cclarice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEAD	= 	ft_printf.h

SRCS	=	ft_printf.c \
			ft_printf_get.c \
			ft_printf_char.c\
			ft_printf_hex.c \
			ft_printf_nbr.c \
			ft_printf_str.c \
			ft_printf_unsigned.c \
			ft_printf_utils.c \
			ft_printf_put.c \
			ft_printf_phex.c \

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
AR		=	ar rc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} $?

${OBJS}:    %.o:%.c ${HEAD}
			${CC} -c ${CFLAGS} $<

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
