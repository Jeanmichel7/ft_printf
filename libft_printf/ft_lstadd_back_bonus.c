/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:29:52 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/02 00:02:00 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	tmp = &**lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = tmp;
}
*/

#include <stdio.h>
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	printf("\n--- input ---\n");
	printf("**lst  : %p\n         %p, %s, %p\n", lst, *lst, (char *)(*lst)->content, (*lst)->next);
	printf("*new   : %p, %s, %p\n", new, (char *)new->content, new->next);
	printf("---- fin input ---- \n\n");

	tmp = &**lst;
	printf("tmp    : %p\n\n", tmp->next);

	while ((*lst)->next)
	{
		printf("**lst  : %p\n            %p, %s, %p\n", lst, *lst, (char *)(*lst)->content, (*lst)->next);
		*lst = (*lst)->next;
	}

	(*lst)->next = new;
	printf("**lst  : %p, %p, %s, %p\n", lst, *lst, (char *)(*lst)->content, (*lst)->next);

	*lst = (*lst)->next;
	printf("**lst  : %p, %p, %s, %p\n", lst, *lst, (char *)(*lst)->content, (*lst)->next);

	*lst = tmp;
	printf("tmp    : %p\n\n", tmp->next);
}

