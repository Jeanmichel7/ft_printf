/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:00:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 03:47:17 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_itoa_len(int n)
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

void	ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	str = malloc(sizeof(char) * (ft_itoa_len(n) + 1 + sign));
	if (str == NULL)
		return (NULL);
	str[ft_itoa_len(n) + sign] = '\0';
	i = ft_itoa_len(n) + sign - 1;
	if (n == 0)
		str[i--] = '0';
	while (n)
	{
		if (sign)
			str[i--] = ((n % 10) * -1) + '0';
		else
			str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		str[i] = '-';
	ft_putstr(str);
}
