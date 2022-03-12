/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:31:39 by jrasser           #+#    #+#             */
/*   Updated: 2022/02/27 03:31:39 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//créer nouvelle liste
static t_list	*ft_lstnew_map(void *(*f)(void *))
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	f(tmp);
	return (tmp);
}

//ajouter contenu a la liste
static void	ft_lstadd_back_map(t_list **lst, t_list *new)
{
	t_list *tmp;

	tmp = &**lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = tmp;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list  *tmp;
	t_list  *new_list;

	new_list = ft_lstnew_map(f);
	lst = lst->next;
	while (lst)
	{
		del(lst->content);
		//free(lst->content);

		tmp = malloc(sizeof(t_list));
		if (tmp == NULL)
			return (NULL);
		f(tmp);
		ft_lstadd_back_map(&new_list, tmp);

		lst = lst->next;
	}
	return (new_list);
}