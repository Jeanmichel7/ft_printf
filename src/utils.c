/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:35:56 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/13 01:43:49 by jrasser          ###   ########.fr       */
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

unsigned int	ft_putstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
