/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:00:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 03:14:19 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_litoa_len(long int n)
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

char	*ft_litoa(long int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	str = malloc(sizeof(char) * (ft_litoa_len(n) + 1 + sign));
	if (str == NULL)
		return (NULL);
	str[ft_litoa_len(n) + sign] = '\0';
	i = ft_litoa_len(n) + sign - 1;
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
	return (str);
}
