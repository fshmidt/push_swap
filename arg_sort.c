/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:20:01 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 01:55:45 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	recursive_swap(char **arg, int index, int *max)
{
	char	*tmp;

	if (index > 0 && index < *max && ft_atoi(arg[index - 1])
		> ft_atoi(arg[index]))
	{
		tmp = arg[index - 1];
		arg[index - 1] = arg[index];
		arg[index] = tmp;
		recursive_swap(arg, index - 1, max);
	}
}

static int	*recursive_sort_conv(int *arr, t_args *args, int *elem_number,
int *split_flag)
{
	int	a;

	a = 0;
	while (args->arg[a])
	{
		recursive_swap(args->arg, a + 1, elem_number);
		a++;
	}
	while (a--)
		arr[a] = ft_atoi(args->arg[a]);
	return (arr);
}

static int	sorted(char **arg, int counter, int *elem_number)
{
	int	b;

	*elem_number = -1;
	while (arg[++(*elem_number)])
	{
		b = *elem_number;
		while (arg[++b])
		{
			if (ft_atoi(arg[*elem_number]) > ft_atoi(arg[b]))
				counter++;
		}
	}
	return (!counter);
}

int	*arg_sort(t_args *args, int *elem_number, int *split_flag, int exec)
{
	int	*arr;
	int	counter;

	counter = 0;
	if (sorted(args->arg, counter, elem_number) && exec)
	{
		destroy_arg(args, split_flag);
		exit (0);
	}
	arr = (int *)malloc(sizeof(int) * *elem_number);
	if (arr == NULL)
	{
		destroy_arg(args, split_flag);
		exit (3);
	}
	return (recursive_sort_conv(arr, args, elem_number, split_flag));
}
