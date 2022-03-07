/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:31:39 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/05 22:27:14 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list  *tmp;
	t_list  *new_list;
	t_list	*tmp_next;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);

	while (lst)
	{
		tmp_next = lst->next;
		tmp = malloc(sizeof(t_list));
		if (tmp == NULL)
			return (NULL);
		tmp->content = f(lst->content);
		tmp->next = lst->next;
		new_list = tmp;
		del(lst->content);
		free(&lst);
		lst = tmp_next;
	}
	return (new_list);
}
*/