/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:11:02 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/18 21:05:14 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define PTR "0123456789abcdef"

int				ft_printf(const char *str, ...);
unsigned int	ft_printf_char(va_list ptr);
unsigned int	ft_put_char(char c);
char			*ft_put_ptr(unsigned long long int nbr, char *base);
char			*ft_putunbr_base(unsigned int nbr, char *base);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa_printf(int n);
unsigned int	ft_putstr(char *str, char c);
char			*ft_litoa(long int n);
char			*ctos(char c);
char			*ft_sub_char(char c, va_list ptr);
unsigned int	ft_putstrstr(char *str);

/* BONUS */

unsigned int	ft_putstr_minus_less(char *str, char c);
char			*ft_arg_multi(const char *str, int i);
char			*ft_arg_multi(const char *str, int i);
int				ft_dash_flag(const char *str, int i, va_list ptr, int *z);
int				ft_dot_flag(const char *str, int i, va_list ptr, int *z);
int				ft_zero_flag(const char *str, int i, va_list ptr, int *z);

/* BONUS2 */

int				ft_space_flag(const char *str, int i, va_list ptr, int *z);
int				ft_diese_flag(const char *str, int i, va_list ptr, int *z);
int				ft_plus_flag(const char *str, int i, va_list ptr, int *z);

#endif
