/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:13:22 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/15 22:51:28 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	atoi_limit_checker(const char *str)
{
	int				i;
	int				minusi;
	long long int	tni;

	i = 0;
	minusi = 1;
	tni = 0;
	while (((str[i] <= 13) && (str[i] >= 9)) || ((str[i] == ' ')))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i++] == '-')
			minusi = minusi * (-1);
	}
	while ((str[i] >= 48) && (str[i] <= 57))
		tni = (tni * 10) + str[i++] - 48;
	return (tni * minusi);
}

void	free_recent(int *arr, t_node **a, t_node **b)
{
	free(arr);
	if (*b)
		free(*b);
	if (*a != NULL)
	{
		while (*a != NULL)
		{
			if ((*a)->next != NULL)
			{
				*a = (*a)->next;
				if ((*a)->prev->prev)
					(*a)->prev->prev->next = NULL;
				free((*a)->prev);
				(*a)->prev = NULL;
			}
			else
			{
				free(*a);
				*a = NULL;
			}
		}
	}
}

void	ft_error(t_args *args, int *split_flag)
{
	write(2, "Error\n", 6);
	destroy_arg(args, split_flag);
	exit (2);
}

void	destroy_arg(t_args *args, int *split_flag)
{
	int	a;

	a = 0;
	if (args->arg[a] && *split_flag)
	{
		while (args->arg[a])
		{
			free(args->arg[a]);
			args->arg[a] = NULL;
			free(args->original[a]);
			args->original[a] = NULL;
			a++;
		}
	}
	else
	{
		if (args->arg)
			free(args->arg);
		if (args->original)
			free(args->original);
	}
}

char	**write_arg(int argc, char **argv, int *split_flag)
{
	char	**arg;
	int		count;

	if (argc == 2)
	{
		*split_flag = 1;
		return (ft_split(argv[1], ' '));
	}
	arg = (char **)malloc(sizeof(char *) * argc);
	if (arg == NULL)
		exit(2);
	count = 0;
	while (argc - count)
	{
		arg[count] = argv[count + 1];
		count++;
	}
	arg[count] = 0;
	*split_flag = 0;
	return (arg);
}
