/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:19:09 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/15 17:48:22 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_a(t_node **stack_a, int wr)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	*stack_a = (*stack_a)->next;
	if (wr)
		write(1, "ra\n", 3);
}

void	r_b(t_node **stack_b, int wr)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	*stack_b = (*stack_b)->next;
	if (wr)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_b, t_node **stack_a, int wr)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	*stack_a = (*stack_a)->next;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	*stack_b = (*stack_b)->next;
	if (wr)
		write(1, "rr\n", 3);
}

void	rr_a(t_node **stack_a, int wr)
{
	if (!*stack_a || !(*stack_a)->prev)
		return ;
	*stack_a = (*stack_a)->prev;
	if (wr)
		write(1, "rra\n", 4);
}

void	rr_b(t_node **stack_b, int wr)
{
	if (!*stack_b || !(*stack_b)->prev)
		return ;
	*stack_b = (*stack_b)->prev;
	if (wr)
		write(1, "rrb\n", 4);
}
