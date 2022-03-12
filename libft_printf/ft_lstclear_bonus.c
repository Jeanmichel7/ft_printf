/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:30:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/02/28 20:12:03 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = &**lst;
	while (*lst){
		tmp = (*lst)->next;
		del(*lst->content);
		free(&**lst);
		*lst = tmp;
	}
}
*/

#include <stdio.h>
void    ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	printf("**lst  : %p, %p, %s, %p\n", lst, *lst, (char *)(*lst)->content, (*lst)->next);
	tmp = &**lst;
	printf("tmp    : %p\n\n", tmp->next);


	while (*lst){
		printf("**lst  : %p, %p, %s, %p\n", lst, *lst, (char *)(*lst)->content, (*lst)->next);

		tmp = (*lst)->next;
		del((*lst)->content);
		//free(*lst);

		*lst = (*lst)->next;
	}
}

