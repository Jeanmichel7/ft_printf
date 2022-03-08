/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:11:02 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 03:14:33 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
char    *ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_litoa(long int n);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putunbr_base(unsigned int nbr, char *base);
void	ft_put_pointer(unsigned long int nbr, char *base);

#endif