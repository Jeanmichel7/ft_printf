/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:35:56 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/15 12:01:37 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ctos(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

unsigned int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_putstr(char *str, char c)
{
	int	len;
	
	len = ft_strlen(str);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (c == 's')
	{

		write(1, str, len);
		return (len);
	}
	else
	{
		write(1, str, len);
		if (str[0] == '%' || (str[0] == '0' && str[1] == 'x' && str[2] == '\0')
			|| (str[0] == '0' && str[1] == 'X' && str[2] == '\0'))
			return (len);
		else
			free (str);
		return (len);
	}
	return (0);
}



/*unsigned int	ft_putstrstr(char *str)
{
	int	len;
	
	len = ft_strlen(str);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, len);
	return (len);
}*/
