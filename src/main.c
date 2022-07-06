/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:26:12 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:27:13 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	fill_stack_a(int argc, char **argv, t_ps *ps)
{
	t_list	*new;
	int		*n;
	int		i;

	i = 1;
	while (i < argc)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		new = ft_lstnew(n);
		if (!new)
			ft_lstclear(&ps->stack_a, free);
		ft_lst_add_back(&ps->stack_a, new);
		i++;
	}
}

static void	init_ps(t_ps *ps)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->ops = 0;
}

static void	execute_algo(int argc, char **argv)
{
	t_ps	ps;

	init_ps(&ps);
	fill_stack_a(argc, argv, &ps);
	if (lst_is_already_sorted(ps.stack_a))
	{
		ft_lstclear(&ps.stack_a, free);
		exit (EXIT_SUCCESS);
	}
	if (lst_size(ps.stack_a) <= 5)
		sort_small(&ps);
	else
		radix_sort(&ps);
	ft_lstclear(&ps.stack_a, free);
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1] != NULL)
	{
		if (parsing(argv))
		{
			ft_putstr_fd("ERROR : input is incorrect\n", 2);
			exit(EXIT_FAILURE);
		}
		execute_algo(argc, argv);
	}
	return (0);
}
