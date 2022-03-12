/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:18:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/12 17:59:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strreverse_0x(char	*str)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strlen(str);
	//printf("len : %d \n", len);
	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ret[i] = str[len - i - 1];
		//printf("boucle : ret[%d] = str[%d - %d - 1] = %c\n", i, len, i, ret[i]);
		i++;
	}
	ret[i] = '\0';
	//printf("milieu put_ptr : %s", ret);

	return (ret);
}

char	*ft_put_ptr(unsigned long int nbr, char *base)
{
	char			*str;
	char			*ret;
	int				i;

	if (!nbr)
		return ("0");
	str = malloc(sizeof(char) * (12 + 1));
	i = 0;
	while (nbr)
	{
		str[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		str[i] = base[(int)str[i]];
	//printf("avant put_ptr : %s ", str);

	ret = ft_strreverse_0x(str);
	//printf("retour put_ptr : %s", ret);
	return (ret);
}
