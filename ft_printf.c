/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 04:21:12 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static void	ft_printf_char(va_list ptr)
{
	int	c;
	
	c = va_arg(ptr, int);
	write(1, &c, 1);
}

static int	ft_sub_printf_double(char c, va_list ptr)
{
	if (c == 'd')
		ft_litoa(va_arg(ptr, long int));
	else if (c == 'o')
		ft_putunbr_base(va_arg(ptr, unsigned int), "01234567");
	else if (c == 'u')
		ft_uitoa(va_arg(ptr, unsigned int));
	else
		return (0);
	return (1);
}

static void	ft_sub_printf(char c, va_list ptr)
{
	if (c == 'd' || c == 'i')
		ft_itoa(va_arg(ptr, int));
	else if (c == 'o')
		ft_putunbr_base(va_arg(ptr, unsigned int), "01234567");
	else if (c == 'u')
		ft_uitoa(va_arg(ptr, unsigned int));
	else if (c == 'x')
		ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 's')
		ft_putstr(va_arg(ptr, char *));
	else if (c == 'c')
		ft_printf_char(ptr);
	else if (c == 'p')
		ft_put_pointer(va_arg(ptr, unsigned long int), "0123456789abcdef");
	else
		write(1, &c, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list     ptr;
	int		  	i;

	i = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 'l')
				i += ft_sub_printf_double(str[i + 1], ptr);
			else 
				ft_sub_printf(str[i], ptr);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (0);
}