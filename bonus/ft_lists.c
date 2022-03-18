/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:06:14 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/07 14:48:41 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = content;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{	
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}	
	if (lst)
		ft_lstlast(*(lst))->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		if ((*lst)->data)
			del((*lst)->data);
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
	lst = (NULL);
}
