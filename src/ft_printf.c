/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/13 04:26:06 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static unsigned int	ft_sub_flag(const char *str, int i, va_list ptr, int *z)
{
	int		ret;

	if (str[i] == '-')
		ret = ft_dash_flag(str, ++i, ptr, z);
	if (str[i] == '.')
		ret = ft_dot_flag(str, ++i, ptr, z);
	else if (str[i] == '0' && str[i + 1] != '-')
		ret = ft_zero_flag(str, ++i, ptr, z);
	if (str[i] == ' ')
		ret = ft_space_flag(str, ++i, ptr, z);
	if (str[i] == '#')
		ret = ft_diese_flag(str, ++i, ptr, z);
	if (str[i] == '+')
		ret = ft_plus_flag(str, ++i, ptr, z);
	return (ret);
}

/*
char	*ft_sub_printf_double(char c, va_list ptr)
{
	if (c == 'd')
		return (ft_litoa(va_arg(ptr, long int)));
	else if (c == 'o')
		return (ft_putunbr_base(va_arg(ptr, unsigned int), "01234567"));
	else if (c == 'u')
		return (ft_uitoa(va_arg(ptr, unsigned int)));
	return (NULL);
}
*/

char	*ft_sub_char(char c, va_list ptr)
{
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(ptr, int)));
	else if (c == 'o')
		return (ft_putunbr_base(va_arg(ptr, unsigned int), "01234567"));
	else if (c == 'u')
		return (ft_uitoa(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (c == 's')
		return (va_arg(ptr, char *));
	else if (c == 'c')
		return (ctos(va_arg(ptr, int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_put_ptr(va_arg(ptr, unsigned long int), "0123456789abcdef"));
	}
	else if (c == '%')
		return ("%");
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		z;

	i = -1;
	z = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[++i + 1])
		{
			if (str[i] == '-' || str[i] == '0' || str[i] == '.' || str[i] == ' '
				|| str[i] == '#' || str[i] == '+')
				i += ft_sub_flag(str, i, ptr, &z);
			else if (str[i] == 'p')
				z += ft_putstr(ft_sub_char(str[i], ptr)) + 2;
			else
				z += ft_putstr(ft_sub_char(str[i], ptr));
		}
		else
			z += ft_put_char(str[i]);
	}
	va_end(ptr);
	return (z);
}
