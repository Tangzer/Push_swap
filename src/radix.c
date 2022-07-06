/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:23:43 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:23:44 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	optimisation_bitshifting(t_ps *ps, int max_bits)
{
	int	size;
	int	max_num;

	size = lst_size(ps->stack_a);
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	execute_radix(t_ps *ps, int j)
{
	int	k;
	int	max_bits;
	int	top_num;
	int	size;

	size = lst_size(ps->stack_a);
	max_bits = 0;
	max_bits = optimisation_bitshifting(ps, max_bits);
	while (j < max_bits)
	{
		k = 0;
		while (k < size)
		{
			top_num = *(int *)ps->stack_a->content;
			if (((top_num >> j) & 1) == 1)
				do_op(RA, ps);
			else
				do_op(PB, ps);
			k++;
		}
		while (ps->stack_b)
			do_op(PA, ps);
		j++;
	}
}

static int	get_index(t_list *stack_a, int n)
{
	t_list	*node;
	int		index;

	node = stack_a;
	index = 0;
	while (node != NULL)
	{
		if (*(int *)node->content < n)
			index++;
		node = node->next;
	}
	return (index);
}

void	radix_sort(t_ps *ps)
{
	t_list	*node;
	int		j;

	j = 0;
	node = ps->stack_a;
	while (node)
	{
		node->index = get_index(ps->stack_a, *(int *)node->content);
		node = node->next;
	}
	node = ps->stack_a;
	while (node)
	{
		*(int *)node->content = node->index;
		node = node->next;
	}
	execute_radix(ps, j);
}
