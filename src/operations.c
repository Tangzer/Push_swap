/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:26:06 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:29:12 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **head)
{
	t_list	*new_head;

	if (head && lst_size(*head) > 1)
	{
		new_head = (*head)->next;
		(*head)->next = new_head->next;
		if (new_head->next)
			new_head->next->prev = (*head);
		ft_lst_add_front(head, new_head);
	}
}

void	rotate(t_list **head)
{
	t_list	*new_head;

	if (head && lst_size(*head) > 1)
	{
		new_head = (*head)->next;
		new_head->prev = NULL;
		ft_lst_add_back(head, *head);
		*head = new_head;
	}
}

void	reverse_rotate(t_list **head)
{
	t_list	*new_last;

	if (head && lst_size(*head) > 1)
	{
		new_last = lst_last(*head)->prev;
		ft_lst_add_front(head, lst_last(*head));
		new_last->next = NULL;
	}
}

void	push(t_list **src, t_list **dst)
{
	t_list	*new_head;

	if (src && *src && dst)
	{
		new_head = (*src)->next;
		if (new_head)
			new_head->prev = NULL;
		ft_lst_add_front(dst, *src);
		*src = new_head;
	}
}
