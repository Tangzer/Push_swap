/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:25:45 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:25:53 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*lst_last(t_list *lst)
{
	if (lst && lst->next)
		return (lst_last(lst->next));
	return (lst);
}

t_list	*lst_max(t_list *head)
{
	int		n;
	t_list	*node;

	n = *(int *)head->content;
	node = head;
	while (head)
	{
		if (*(int *)head->content > n)
		{
			n = *(int *)head->content;
			node = head;
		}
		head = head->next;
	}
	return (node);
}

t_list	*lst_min(t_list *head)
{
	int		n;
	t_list	*node;

	n = *(int *)head->content;
	node = head;
	while (head)
	{
		if (*(int *)head->content < n)
		{
			n = *(int *)head->content;
			node = head;
		}
		head = head->next;
	}
	return (node);
}

bool	lst_is_already_sorted(t_list *head)
{
	if (!head)
		return (true);
	if (!(head->content))
		head = head->next;
	if (head->prev)
		if (*(int *)(head->content) < *(int *)(head->prev->content))
			return (false);
	head = head->next;
	return (lst_is_already_sorted(head));
}
