/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:18:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/10 21:13:20 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putptrchar(char c, unsigned int *len)
{
	write(1, &c, 1);
	*len += 1;
}

unsigned int	ft_put_ptr(unsigned long int nbr, char *base)
{
	int				size_base;
	int				nbr_final[12];
	int				i;
	unsigned int	len;

	len = 0;
	i = 0;
	size_base = 16;
	ft_putptrchar('0', &len);
	ft_putptrchar('x', &len);
	if (!nbr)
		ft_putptrchar('0', &len);
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i >= 0)
		ft_putptrchar(base[nbr_final[i]], &len);
	return (len);
}
