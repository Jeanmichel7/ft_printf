/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:03:52 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/13 03:47:24 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_space_flag_c(size_t str_arg_len, size_t nbr, char *str_arg, int *z)
{
	while (str_arg_len < nbr)
		ft_put_char(str_arg[str_arg_len++]);
	*z -= ft_strlen(str_arg) - str_arg_len;
}

int	ft_space_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	size_t	nbr;
	size_t	str_arg_len;

	str_nbr = ft_arg_multi(str, i);
	i += ft_strlen(str_nbr);
	str_arg = ft_sub_char(str[i], ptr);
	nbr = ft_atoi(str_nbr);
	str_arg_len = ft_strlen(str_arg);
	*z += str_arg_len;
	if (str[i] != 's' && str[i] != 'c')
	{
		*z += ft_put_char(' ');
		str_arg_len++;
		while (str_arg_len++ < nbr)
			*z += ft_put_char(' ');
	}
	ft_putstr(str_arg);
	return (ft_strlen(str_nbr) + 1);
}
// '%#o'

int	ft_diese_flag(const char *str, int i, va_list ptr, int *z)
{
	char	*str_nbr;
	char	*str_arg;
	size_t	count_inital;

	str_nbr = ft_arg_multi(str, i);
	i += ft_strlen(str_nbr);
	str_arg = ft_sub_char(str[i], ptr);
	count_inital = ft_strlen(str_arg);
	*z += count_inital;
	if (str[i] == 'o')
	{
		while (count_inital++ + 1 < (size_t)ft_atoi(str_nbr))
			*z += ft_put_char(' ');
		*z += ft_put_char('0');
	}
	else if (str[i] == 'x' || str[i] == 'X')
	{
		while (count_inital++ + 2 < (size_t)ft_atoi(str_nbr))
			*z += ft_put_char(' ');
		if (str[i] == 'x')
			*z += ft_putstr("0x");
		else if (str[i] == 'X')
			*z += ft_putstr("0X");
	}
	else
		while (count_inital++ < (size_t)ft_atoi(str_nbr))
			*z += ft_put_char(' ');
	ft_putstr(str_arg);
	return (ft_strlen(str_nbr) + 1);
}

int	ft_plus_flag(const char *str, int i, va_list ptr, int *z)
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
	while (count_inital++ + 1 < nbr)
		*z += ft_put_char(' ');
	if (atoi(str_arg) >= 0)
		*z += ft_put_char('+');
	else
		*z += ft_put_char(' ');
	count_inital = 0;
	if (ft_strlen(str_arg) > nbr && str[i] == 's')
		ft_space_flag_c(count_inital, nbr, str_arg, z);
	else
		ft_putstr(str_arg);
	if (str[i] == 'p')
		*z += 2;
	if (str[i - ft_strlen(str_nbr) - 2] == '-')
		return (ft_strlen(str_nbr) + 2);
	return (ft_strlen(str_nbr) + 1);
}
