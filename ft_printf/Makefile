# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 20:15:09 by jrasser           #+#    #+#              #
#    Updated: 2022/03/07 21:12:41 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= make -C libft/

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		${CC} ${CFLAGS}-c $< -o ${<:.c=.o}

${NAME}:	
			${LIBFT}
			${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
