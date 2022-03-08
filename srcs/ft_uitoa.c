/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:00:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 04:32:39 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static unsigned int	ft_uitoa_len(unsigned int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_uitoa(unsigned int n)
{
	char				*str;
	unsigned long int	i;

	str = malloc(sizeof(char) * (ft_uitoa_len(n) + 1));
	str[ft_uitoa_len(n)] = '\0';
	i = ft_uitoa_len(n) - 1;
	if (n == 0)
		str[i--] = '0';
	while (n)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	ft_putstr(str);
}
