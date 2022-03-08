/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 03:12:44 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* va_start(va_list ap, argN)	Cela permet d’accéder aux arguments de fonction variadiques.
* va_arg(va_list ap, tapez)	Celui-ci accède au prochain argument de la fonction variadique.
* va_copy(va_list dest, va_list src)	Cela fait une copie des arguments de la fonction variadique.
* va_end(va_list ap)	Ceci termine le parcours des arguments de la fonction variadique.
**/

#include "ft_printf.h"


void	ft_printf_int(va_list ptr)
{
	char	*str;

	str = ft_itoa(va_arg(ptr, int));
	write(1, str, ft_strlen(str));
}

void	ft_printf_unsigned_int(va_list ptr)
{
	char				*str;

	str = ft_uitoa(va_arg(ptr, unsigned int));
	write(1, str, ft_strlen(str));
}

void	ft_printf_base(va_list ptr, char *base)
{
	ft_putunbr_base(va_arg(ptr, unsigned int), base);
}

void	ft_printf_pointer(va_list ptr, char *base)
{
	ft_put_pointer(va_arg(ptr, unsigned long int), base);
}

void	ft_printf_long_int(va_list ptr)
{
	char	*str;

	str = ft_litoa(va_arg(ptr, long int));
	write(1, str, ft_strlen(str));
}

/* STR */
void	ft_printf_str(va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char *);
	write(1, str, ft_strlen(str));
}

void	ft_printf_char(va_list ptr)
{
	write(1, va_arg(ptr, char *), ft_strlen(va_arg(ptr, char *)));
}

int	ft_printf(const char *str, ...)
{
	va_list     ptr;
	size_t  	i;

	i = 0;
	va_start(ptr, str);
	//printf("len de s : %ld\n", ft_strlen(va_arg(ptr, char *)));
	while (str[i])
	{
		//printf(" %c => %d" , s[i], s[i]);
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 'd' || str[i] == 'i')
				ft_printf_int(ptr);
			else if (str[i] == 'o')
				ft_printf_base(ptr, "01234567");
			else if (str[i] == 'u')
				ft_printf_unsigned_int(ptr);
			else if (str[i] == 'x')
				ft_printf_base(ptr, "0123456789abcdef");
			else if (str[i] == 'X')
				ft_printf_base(ptr, "0123456789ABCDEF");
			else if (str[i] == 'l')
			{
				i++;
				if (str[i] == 'd')
					ft_printf_long_int(ptr);
				if (str[i] == 'o')
					ft_printf_base(ptr, "01234567");
				if (str[i] == 'u')
					ft_printf_unsigned_int(ptr);
			}
			else if (str[i] == 's')
				ft_printf_str(ptr);
			else if (str[i] == 'c')
				ft_printf_char(ptr);
			else if (str[i] == 'p')
				ft_printf_pointer(ptr, "0123456789abcdef");
			else
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}

	return (0);
	
}