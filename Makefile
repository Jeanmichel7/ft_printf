# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 20:15:09 by jrasser           #+#    #+#              #
#    Updated: 2022/03/08 04:29:47 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c \
			srcs/ft_putstr.c \
			srcs/ft_itoa.c \
			srcs/ft_uitoa.c \
			srcs/ft_litoa.c \
			srcs/ft_strlen.c \
			srcs/ft_putnbr_base.c \
			srcs/ft_putunbr_base.c \
			srcs/ft_put_pointer.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra

.c.o:		${CC} ${CFLAGS} -c -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
