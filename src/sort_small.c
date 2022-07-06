/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:24:08 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:24:09 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	return_min_value(int i, int j)
{
	if (i <= j)
	{
		if (i < 0)
			return (-i);
		return (i);
	}
	else
	{
		if (j < 0)
			return (-j);
		return (j);
	}
}

int	still_not_sorted(t_list *node)
{
	int		prv;
	int		nxt;
	t_list	*temp;

	prv = 0;
	nxt = 0;
	temp = node;
	while (temp)
	{
		prv++;
		temp = temp->prev;
	}
	temp = node;
	while (temp)
	{
		nxt--;
		temp = temp->next;
	}
	return (return_min_value(prv, nxt));
}

static void	sort_3(t_ps *ps)
{
	if (lst_max(ps->stack_a) != lst_last(ps->stack_a))
	{
		if (lst_max(ps->stack_a) == ps->stack_a)
			do_op(RA, ps);
		else
			do_op(RRA, ps);
	}
	if (!lst_is_already_sorted(ps->stack_a))
		do_op(SA, ps);
	while (ps->stack_b)
		do_op(PA, ps);
}

void	sort_small(t_ps *ps)
{
	while (lst_size(ps->stack_a) > 3)
	{
		if (still_not_sorted(lst_min(ps->stack_a)) > 0)
			while (ps->stack_a->content != lst_min(ps->stack_a)->content)
				do_op(RA, ps);
		else
			while (ps->stack_a != lst_min(ps->stack_a))
				do_op(RRA, ps);
		do_op(PB, ps);
	}
	sort_3(ps);
	while (ps->stack_b)
		do_op(PA, ps);
}
