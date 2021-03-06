/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:50:30 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/02 02:06:44 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ret = ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		ret = ((char *)s + i);
	}
	return (ret);
}
