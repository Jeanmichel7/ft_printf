/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:00:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/10 21:16:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_sub_itoa(unsigned int sign, char *str, unsigned int *i, int *n)
{
	if (sign)
		*(str + (*i)--) = ((*n % 10) * -1) + '0';
	else
		*(str + (*i)--) = (*n % 10) + '0';
	*n /= 10;
}

unsigned int	ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	sign;
	unsigned int	len;

	sign = 0;
	if (n < 0)
		sign = 1;
	str = malloc(sizeof(char) * (ft_itoa_len(n) + 1 + sign));
	str[ft_itoa_len(n) + sign] = '\0';
	i = ft_itoa_len(n) + sign - 1;
	len = i + 1;
	if (n == 0)
		str[i--] = '0';
	while (n)
		ft_sub_itoa(sign, str, &i, &n);
	if (sign)
		str[i] = '-';
	ft_putstr(str);
	free(str);
	return (len);
}