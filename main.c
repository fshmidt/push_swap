/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:17:35 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 01:56:28 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	arr = arg_sort(args, &elem_number, &split_flag, PUSH_SWAP);
	stacks.a = list_developement(args->original, arr, elem_number, &(stacks.b));
	sorting(&(stacks.a), &(stacks.b), elem_number - 1);
	free_recent(arr, &(stacks.a), &(stacks.b));
	destroy_arg(args, &split_flag);
	return (0);
}
