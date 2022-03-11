/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:35:56 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/11 01:37:51 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned int	ft_printf_char(va_list ptr)
{
	int	c;

	c = va_arg(ptr, int);
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}
