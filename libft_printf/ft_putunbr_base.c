/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:18:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/11 00:02:30 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putuchar(char c, unsigned int *len)
{
	write(1, &c, 1);
	*len += 1;
}

static unsigned int	ft_scale(long nb, int len)
{
	unsigned int	res;
	
	res = 1;
	while ((nb / len) > 0)
	{
		nb = nb / len;
		res *= len;
	}
	return (res);
}

static int	check_base(char *str)
{
	int	i;
	int	j;
	int	res;

	res = 1;
	if (str[0] == '+' || str[0] == '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (str[i] == str[j])
				return (0);
			j--;
		}
		i++;
	}
	return (res);
}

unsigned int	ft_putunbr_base(unsigned int nbr, char *base)
{
	int				len_base;
	long			scale;
	unsigned int	len;

	len = 0;
	if (ft_strlen(base) > 1 && check_base(base))
	{
		len_base = ft_strlen(base);
		scale = ft_scale(nbr, ft_strlen(base));
		while (scale > 0)
		{
			ft_putuchar(base[nbr / scale], &len);
			nbr %= scale;
			scale /= len_base;
		}
	}
	return (len);
}
