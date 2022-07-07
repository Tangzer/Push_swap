/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:21:43 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:22:36 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_digit(argv[i]))
			i++;
		else
			return (ERROR);
	}
	return (0);
}

static int	check_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (ERROR);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

static int	check_min_max(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == OVERFLOW)
			return (ERROR);
		i++;
	}
	return (0);
}

int	parsing(char **argv)
{
	if (check_args(argv))
		return (ERROR);
	if (check_double(argv))
		return (ERROR);
	if (check_min_max(argv))
		return (ERROR);
	return (0);
}
