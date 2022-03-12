/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/12 18:47:05 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *ft_sub_printf(char c, va_list ptr);

char *ft_arg_multi(const char *str, int i)
{
	int j;
	char *nbr;

	j = 0;
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
	//printf("retour nbr : %s      ", nbr);
	return (nbr);
}

//  %-50d
static unsigned int ft_sub_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	char	c;
	size_t	nbr;
	size_t	count_inital;

	if (str[i] == '-')
	{
		i++;
		str_nbr = ft_arg_multi(str, i);
		i += ft_strlen(str_nbr);
		str_arg = ft_sub_printf(str[i], ptr);
		ft_putstr(str_arg);
		*z += ft_strlen(str_arg);
		nbr = ft_atoi(str_nbr);
		count_inital = 0;
		if (ft_strlen(str_arg) < nbr)
			count_inital = ft_atoi(str_nbr) - ft_strlen(str_arg) + 1;
		//printf("\n count : %d, arg : '%s' len : %ld, nb : '%s' len : %d, a rajouter %d\n", *z, str_arg, ft_strlen(str_arg), str_nbr, ft_atoi(str_nbr), diff);
		while ( count_inital && --count_inital)
			*z += ft_put_char(' ');
	}
	else if (str[i] == '0')
	{
		i++;
		str_nbr = ft_arg_multi(str, i);
		i += ft_strlen(str_nbr);
		str_arg = ft_sub_printf(str[i], ptr);
		count_inital = ft_strlen(str_arg);
		nbr = ft_atoi(str_nbr);
		*z += count_inital;
		if (str[i] == 's' || str[i] == 'c')
			c = ' ';
		else
			c = '0';
		if (str[i] == 'p')
			count_inital += 2;
		if (str[i] == 'p')
			*z += 2;
		while (count_inital++ < nbr)
			*z += ft_put_char(c);
		ft_putstr(str_arg);
	}
	else if (str[i] == '.')
	{
		i++;
		str_nbr = 		ft_arg_multi(str, i);
		i +=			ft_strlen(str_nbr);
		str_arg = 		ft_sub_printf(str[i], ptr);
		count_inital = 	ft_strlen(str_arg);
		nbr = 			ft_atoi(str_nbr);
		*z += 			count_inital;

		if (str[i] != 's' && str[i] != 'c')
			while (count_inital++ < nbr)
				*z += ft_put_char('0');
		if (ft_strlen(str_arg) > nbr && str[i] == 's')
		{
			count_inital = -1;
			while (++count_inital < nbr)
				ft_put_char(str_arg[count_inital]);
			*z -= ft_strlen(str_arg) - count_inital;
		}
		else
			ft_putstr(str_arg);
	}
	return (ft_strlen(str_nbr) + 1);
}

char *ft_sub_printf_double(char c, va_list ptr)
{
	if (c == 'd')
		return (ft_litoa(va_arg(ptr, long int)));
	else if (c == 'o')
		return (ft_putunbr_base(va_arg(ptr, unsigned int), "01234567"));
	else if (c == 'u')
		return (ft_uitoa(va_arg(ptr, unsigned int)));
	return (NULL);
}

char *ft_sub_printf(char c, va_list ptr)
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

int ft_printf(const char *str, ...)
{
	va_list ptr;
	int i;
	int z;

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
				z += ft_putstr(ft_sub_printf_double(str[i++ + 1], ptr));
			else if (str[i] == 'p')
				z += ft_putstr(ft_sub_printf(str[i], ptr)) + 2;
			else
				z += ft_putstr(ft_sub_printf(str[i], ptr));
		}
		else
			z += ft_put_char(str[i]);
		i++;
	}
	va_end(ptr);
	return (z);
}
