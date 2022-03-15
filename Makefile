# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 20:15:09 by jrasser           #+#    #+#              #
#    Updated: 2022/03/15 11:32:29 by jrasser          ###   ########.fr        #
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

LIBFT		= make -C libft/

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

CPPFLAGS	= -I./include -I./libft

${NAME}:	${OBJS}
			${LIBFT}
			cp libft/libft.a $(NAME)
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re
