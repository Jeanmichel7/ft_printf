/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/11 04:00:22 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_sub_printf(char c, va_list ptr, int *z);

static unsigned int	ft_sub_flag(const char *str, int i, va_list ptr, int *z)
{
	int		j;
	char	*nbr;
	int		dif_z;

	j = 0;
	dif_z = *z;
	if (str[i++] == '-')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			j++;
		}
		nbr = malloc(sizeof(char) * (j + 1));
		i -= j;
		j = 0;
		while (str[i] >= '0' && str[i] <= '9')
			nbr[j++] = str[i++];
		nbr[j] = '\0';
		ft_sub_printf(str[i], ptr, z);
		dif_z = *z - dif_z;
		while (dif_z++ < ft_atoi(nbr))
			*z += ft_put_char(' ');
	}
	return (j + 1);
}

static int	ft_sub_printf_double(char c, va_list ptr, int *z)
{
	if (c == 'd')
		*z += ft_litoa(va_arg(ptr, long int));
	else if (c == 'o')
		*z += ft_putunbr_base(va_arg(ptr, unsigned int), "01234567");
	else if (c == 'u')
		*z += ft_uitoa(va_arg(ptr, unsigned int));
	else
		return (0);
	return (1);
}

static int	ft_sub_printf(char c, va_list ptr, int *z)
{
	if (c == 'd' || c == 'i')
		*z += ft_itoa(va_arg(ptr, int));
	else if (c == 'o')
		*z += ft_putunbr_base(va_arg(ptr, unsigned int), "01234567");
	else if (c == 'u')
		*z += ft_uitoa(va_arg(ptr, unsigned int));
	else if (c == 'x')
		*z += ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		*z += ft_putunbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (c == 's')
		*z += ft_putstr(va_arg(ptr, char *));
	else if (c == 'c')
		*z += ft_printf_char(ptr);
	else if (c == 'p')
		*z += ft_put_ptr(va_arg(ptr, unsigned long int), "0123456789abcdef");
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		z;

	i = 0;
	z = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == '-' || str[i] == '0' || str[i] == '.')
				i += ft_sub_flag(str, i, ptr, &z);
			else if (str[i] == 'l')
				i += ft_sub_printf_double(str[i + 1], ptr, &z);
			else
				ft_sub_printf(str[i], ptr, &z);
		}
		else
			z += ft_put_char(str[i]);
		i++;
	}
	va_end(ptr);
	return (z);
}
