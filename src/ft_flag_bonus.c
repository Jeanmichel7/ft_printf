/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:06:49 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/15 11:55:16 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_arg_multi(const char *str, int i)
{
	int		j;
	char	*nbr;

	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		j++;
	}
	nbr = malloc(sizeof(char) * (j + 1));
	i -= j;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr[j++] = str[i++];
	nbr[j] = '\0';
	return (nbr);
}

int	ft_dash_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	size_t	nbr;
	size_t	count_inital;

	if (str[i] != '.')
	{
		str_nbr = ft_arg_multi(str, i);
		i += ft_strlen(str_nbr);
		str_arg = ft_sub_char(str[i], ptr);
		nbr = ft_atoi(str_nbr);
		count_inital = 0;
		*z += ft_strlen(str_arg);
		ft_putstr(str_arg, str[i]);
		if (ft_strlen(str_arg) < nbr)
			count_inital = ft_atoi(str_nbr) - ft_strlen(str_arg) + 1;
		while (count_inital && --count_inital)
			*z += ft_put_char(' ');
		if (str[i] == 'p')
		*z += 2;
		return (ft_strlen(str_nbr) + 1);
	}
	return (0);
}

void	ft_dot_flag_sub(size_t count_inital, size_t nbr, char *str_arg, int *z)
{
	while (count_inital < nbr)
		ft_put_char(str_arg[count_inital++]);
	*z -= ft_strlen(str_arg) - count_inital;
}

int	ft_dot_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	size_t	nbr;
	size_t	count_inital;

	str_nbr = ft_arg_multi(str, i);
	i += ft_strlen(str_nbr);
	str_arg = ft_sub_char(str[i], ptr);
	nbr = ft_atoi(str_nbr);
	count_inital = ft_strlen(str_arg);
	*z += count_inital;
	if (str[i] != 's' && str[i] != 'c')
		while (count_inital++ < nbr)
			*z += ft_put_char('0');
	count_inital = 0;
	if (ft_strlen(str_arg) > nbr && str[i] == 's')
		ft_dot_flag_sub(count_inital, nbr, str_arg, z);
	else
		ft_putstr(str_arg, str[i]);
	if (str[i] == 'p')
		*z += 2;
	if (str[i - ft_strlen(str_nbr) - 2] == '-')
		return (ft_strlen(str_nbr) + 2);
	return (ft_strlen(str_nbr) + 1);
}

int	ft_zero_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	char	c;
	size_t	nbr;
	size_t	count_inital;

	str_nbr = ft_arg_multi(str, i);
	i += ft_strlen(str_nbr);
	str_arg = ft_sub_char(str[i], ptr);
	nbr = ft_atoi(str_nbr);
	count_inital = ft_strlen(str_arg);
	*z += count_inital;
	c = '0';
	if (str[i] == 's' || str[i] == 'c')
		c = ' ';
	if (str[i] == 'p')
		count_inital += 2;
	if (str[i] == 'p')
		*z += 2;
	while (count_inital++ < nbr)
		*z += ft_put_char(c);
	ft_putstr(str_arg, str[i]);
	return (ft_strlen(str_nbr) + 1);
}
