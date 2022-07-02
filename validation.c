/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:09:56 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/17 21:20:53 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	dushnila_s_kovichkami(char **arg)
{
	int	a;
	int	b;
	int	num;

	a = -1;
	while (arg[++a])
	{
		b = -1;
		num = 0;
		while (arg[a][++b])
		{
			if (ft_isdigit(arg[a][b]) && !num)
				num = 1;
			if ((arg[a][b] == ' ' || (arg[a][b] >= 9 && arg[a][b] <= 13))
				&& num)
				num = 2;
			if (num == 2 && ft_isdigit(arg[a][b]))
				return (1);
		}
	}
	return (0);
}

static int	not_only_numbers(char **arg)
{
	int	a;
	int	b;

	a = -1;
	while (arg[++a])
	{
		b = -1;
		while (arg[a][++b])
		{
			if (arg[a][b] != ' ' && (arg[a][b] < 9 || arg[a][b] > 13)
				&& arg[a][b] != '-' && arg[a][b] != '+'
				&& !ft_isdigit(arg[a][b]))
				return (1);
			else if ((arg[a][b] == '-' || arg[a][b] == '+')
				&& !ft_isdigit(arg[a][b + 1]))
				return (1);
		}
	}
	return (0);
}

static int	cross_limits(char **arg)
{
	long long int	a;
	int				b;

	b = -1;
	while (arg[++b])
	{
		a = atoi_limit_checker(arg[b]);
		if (a > INT_MAX || a < INT_MIN)
			return (1);
	}
	return (0);
}

static int	duplicates(char **arg)
{
	int	a;
	int	b;

	a = -1;
	while (arg[++a])
	{
		b = a;
		while (arg[++b])
		{
			if (ft_atoi(arg[a]) == ft_atoi(arg[b]))
				return (1);
		}
	}
	return (0);
}

int	not_validated(char **arg)
{
	if (not_only_numbers(arg) || cross_limits(arg) || duplicates(arg)
		|| dushnila_s_kovichkami(arg))
		return (1);
	return (0);
}
