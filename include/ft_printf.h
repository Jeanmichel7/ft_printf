/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:11:02 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/12 02:41:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft_printf/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int				ft_printf(const char *str, ...);
unsigned int	ft_printf_char(va_list ptr);
unsigned int	ft_put_char(char c);
char        	*ft_put_ptr(unsigned long int nbr, char *base);
char        	*ft_putunbr_base(unsigned int nbr, char *base);
char        	*ft_uitoa(unsigned int n);
char	        *ft_itoa_printf(int n);
unsigned int	ft_putstr(char *str);
unsigned int	ft_litoa(long int n);
char	        *ctos(char c);

#endif
