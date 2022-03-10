# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 20:15:09 by jrasser           #+#    #+#              #
#    Updated: 2022/03/10 22:22:09 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= make -C libft_printf/

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I./libft_printf

LDFLAGS		= -I./include -I./libft_printf

${NAME}:	${OBJS}
			${LIBFT}
			ar rc ${NAME} ${OBJS}
			gcc -o bin main.c -I./include -I./libft_printf libft_printf/libft.a libftprintf.a

all:		${NAME}

clean:		
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME} libft_printf/*.o libft_printf/libft.a

re:			fclean all

.PHONY:		all clean fclean re
