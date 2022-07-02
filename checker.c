/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:17:35 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 01:57:04 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	command_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static int	push_rotate_swap(t_node **a, t_node **b, char *command,
int success)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		s_a(a, UNWRITABLE);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		s_b(b, UNWRITABLE);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		s_s(a, b, UNWRITABLE);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		p_a(a, b, UNWRITABLE);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		p_b(a, b, UNWRITABLE);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		r_a(a, UNWRITABLE);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		rr_a(a, UNWRITABLE);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		r_b(b, UNWRITABLE);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rr_b(b, UNWRITABLE);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(b, a, UNWRITABLE);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(b, a, UNWRITABLE);
	else
		return (command_error());
	return (success);
}

static int	read_and_execute(t_node **a, t_node **b)
{
	char	*command;
	int		success;

	success = 0;
	command = get_next_line(0);
	while (command)
	{
		success = push_rotate_swap(a, b, command, SUCCESS);
		free(command);
		if (success == 0)
			return (0);
		command = get_next_line(0);
	}
	if (command)
	{
		free(command);
		command = NULL;
	}
	return (success);
}

static void	check_and_free(int *arr, t_stacks *stacks, t_args *args,
int *split_flag)
{
	if (stacks->b == NULL && !unsorted_stack(&(stacks->a)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	destroy_arg(args, split_flag);
	free_recent(arr, &(stacks->a), &(stacks->b));
}

int	main(int argc, char **argv)
{
	int			*arr;
	t_args		*args;
	int			elem_number;
	int			split_flag;
	t_stacks	stacks;

	if (argc < 2)
		exit(1);
	args = (t_args *)malloc(sizeof(t_args));
	if (args == NULL)
		exit(2);
	args->arg = (write_arg(argc, argv, &split_flag));
	args->original = (write_arg(argc, argv, &split_flag));
	if (not_validated(args->arg))
		ft_error(args, &split_flag);
	arr = arg_sort(args, &elem_number, &split_flag, CHECKER);
	stacks.a = list_developement(args->original, arr, elem_number, &(stacks.b));
	if (read_and_execute(&(stacks.a), &(stacks.b)) == 0)
	{
		destroy_arg(args, &split_flag);
		free_recent(arr, &(stacks.a), &(stacks.b));
		exit(4);
	}
	check_and_free(arr, &stacks, args, &split_flag);
	return (0);
}
