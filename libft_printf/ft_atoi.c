/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:49:37 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/01 15:52:43 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	fl(long r, int s, char c)
{
	return (r = r * s * 10 + (c - '0'));
}

long	ft_check_limit(long r, int s, char c)
{
	if (r * s > 922337203685477580 && (fl(r, s, c) < 922337203685477580))
		return (-1);
	else if (r * s < -922337203685477580 && fl(r, s, c) > -922337203685477580)
		return (0);
	else
		return (r);
}

int	ft_atoi(const char *str)
{
	long	r;
	int		i;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_check_limit(r, s, str[i]) != r)
			return (ft_check_limit(r, s, str[i]));
		r = r * 10 + (str[i++] - '0');
	}
	return (r * s);
}
