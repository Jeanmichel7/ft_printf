/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:30:01 by jrasser           #+#    #+#             */
/*   Updated: 2022/02/28 21:28:06 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list *ptr_list;
	printf("%p\n", lst);
	printf("%s\n", (char *)lst->content);
	printf("%p\n", lst->next);
	printf("adresse content %p %s\n", (char *)lst->content, (char *)lst->content);
	ptr_list = lst;
	printf("ptr_list %p %s\n", ptr_list, (char *)ptr_list->content);

	del(lst);
	free(&lst->content);
	lst = ptr_list;
}
*/
