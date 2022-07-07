/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:24:52 by tverdood          #+#    #+#             */
/*   Updated: 2022/05/26 18:24:54 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

int	ft_is_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' && arg[i + 1])
		i++;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int				i;
	long long		res;
	int				neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (OVERFLOW);
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (neg == -1 && res - 1 > INT_MAX)
		return (OVERFLOW);
	if (neg == 1 && res > INT_MAX)
		return (OVERFLOW);
	return (res * neg);
}
