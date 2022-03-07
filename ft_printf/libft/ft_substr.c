/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:59:59 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/05 15:04:24 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	max(size_t len, char const *s)
{
	size_t	max;

	if (len >= ft_strlen(s))
		max = ft_strlen(s);
	else
		max = len;
	return (max);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	else
		str = malloc(sizeof(char) * (max(len, s) + 1));
	if (str == NULL)
		return (NULL);
	i = start;
	while (len && s[i])
	{
		str[i - start] = s[i];
		len--;
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
