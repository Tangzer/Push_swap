/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:20:58 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:21:06 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int *new_content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = new_content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = NULL;
	}
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			if (del)
				del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	ft_lst_add_back(t_list **address_lst, t_list *new_node)
{
	t_list	*tmp;

	if (address_lst && new_node)
	{
		if (!*address_lst)
		{
			*address_lst = new_node;
			new_node->prev = NULL;
		}
		else
		{
			tmp = ft_lstlast(*address_lst);
			tmp->next = new_node;
			new_node->prev = tmp;
		}
		new_node->next = NULL;
	}
}

void	ft_lst_add_front(t_list **address_lst, t_list *new_node)
{
	if (address_lst && new_node)
	{
		new_node->next = *address_lst;
		new_node->prev = NULL;
		if (*address_lst)
			(*address_lst)->prev = new_node;
		*address_lst = new_node;
	}
}
