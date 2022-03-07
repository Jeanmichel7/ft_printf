/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:16:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/07 21:10:54 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* va_start(va_list ap, argN)	Cela permet d’accéder aux arguments de fonction variadiques.
* va_arg(va_list ap, tapez)	Celui-ci accède au prochain argument de la fonction variadique.
* va_copy(va_list dest, va_list src)	Cela fait une copie des arguments de la fonction variadique.
* va_end(va_list ap)	Ceci termine le parcours des arguments de la fonction variadique.
**/

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
void	ft_printf_int(va_list ptr)
{
	write(1, va_arg(ptr, char *), ft_strlen(va_arg(ptr, char *)));
}

void	ft_printf_str(va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char *);
	printf("test : %s\n", va_arg(ptr, char *));
	//write(1, va_arg(ptr, char*), ft_strlen(va_arg(ptr, char*)));
}

void	ft_printf_char(va_list ptr)
{
	write(1, va_arg(ptr, char *), ft_strlen(va_arg(ptr, char *)));
}
*/




int	ft_printf(const char *s, ...)
{
	printf("len : %zu", ft_strlen(s));
/*
	va_list                 ptr;
	unsigned long long int  i;
	unsigned long long int  n;

	i = 0;
	n = 0;
	va_start(ptr, s);
	while (s[i] || s[i] == '%')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd')
				ft_printf_int(ptr);
			else if (s[i] == 's')
				ft_printf_str(ptr);
			else if (s[i] == 'c')
				ft_printf_char(ptr);
			i++;
		}
		else
			write (1, &s[i], 1);
		i++;
	}
*/
	return (0);
	
}