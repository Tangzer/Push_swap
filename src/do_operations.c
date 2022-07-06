/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:33:49 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:33:51 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_operation(int op)
{
	if (op == SA)
		ft_putstr_fd("sa\n", 1);
	else if (op == SB)
		ft_putstr_fd("sb\n", 1);
	else if (op == SS)
		ft_putstr_fd("ss\n", 1);
	else if (op == PA)
		ft_putstr_fd("pa\n", 1);
	else if (op == PB)
		ft_putstr_fd("pb\n", 1);
	else if (op == RA)
		ft_putstr_fd("ra\n", 1);
	else if (op == RB)
		ft_putstr_fd("rb\n", 1);
	else if (op == RR)
		ft_putstr_fd("rr\n", 1);
	else if (op == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (op == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (op == RRR)
		ft_putstr_fd("rrr\n", 1);
}

void	do_op(int op, t_ps *ps)
{
	ps->ops++;
	if (op == SA || op == SS)
		swap(&ps->stack_a);
	if (op == SB || op == SS)
		swap(&ps->stack_b);
	if (op == PA)
		push(&ps->stack_b, &ps->stack_a);
	if (op == PB)
		push(&ps->stack_a, &ps->stack_b);
	if (op == RA || op == RR)
		rotate(&ps->stack_a);
	if (op == RB || op == RR)
		rotate(&ps->stack_b);
	if (op == RRA || op == RRR)
		reverse_rotate(&ps->stack_a);
	if (op == RRB || op == RRR)
		reverse_rotate(&ps->stack_b);
	print_operation(op);
}
