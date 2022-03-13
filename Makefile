# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 20:15:09 by jrasser           #+#    #+#              #
#    Updated: 2022/03/13 02:03:48 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/ft_printf.c \
			src/utils.c \
			src/ft_itoa_printf.c \
			src/ft_put_ptr.c \
			src/ft_putunbr_base.c \
			src/ft_uitoa.c \
			src/ft_litoa.c \
			src/ft_flag_bonus.c \
			src/ft_flag_bonus2.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= make -C libft_printf/

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

LDFLAGS		= -I./include -I./libft_printf

${NAME}:	${OBJS}
			${LIBFT}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} libft_printf/*.o libft_printf/libft.a

re:			fclean all

.PHONY:		all clean fclean re