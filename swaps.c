/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:04:11 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 01:07:13 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a)
{
	t_node	*temp;

	if ((*stack_a)->next == (*stack_a)->prev)
	{
		(*stack_a) = (*stack_a)->next;
		return ;
	}
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = (*stack_a)->next;
	temp->next->prev = temp;
	(*stack_a)->prev = temp->prev;
	temp->prev->next = *stack_a;
	(*stack_a)->next = temp;
	temp->prev = (*stack_a);
}

void	swap_b(t_node **stack_b)
{
	t_node	*temp;

	if (((*stack_b)->next == (*stack_b)->prev) && (*stack_b)->next != NULL)
	{
		(*stack_b) = (*stack_b)->next;
		return ;
	}
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = (*stack_b)->next;
	temp->next->prev = temp;
	(*stack_b)->prev = temp->prev;
	temp->prev->next = *stack_b;
	(*stack_b)->next = temp;
	temp->prev = (*stack_b);
}

void	s_b(t_node **stack_b, int wr)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL
		|| (*stack_b)->prev == NULL)
		return ;
	swap_b(stack_b);
	if (wr)
		write(1, "sb\n", 3);
}

void	s_a(t_node **stack_a, int wr)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| (*stack_a)->prev == NULL)
		return ;
	swap_a(stack_a);
	if (wr)
		write(1, "sa\n", 3);
}

void	s_s(t_node **stack_a, t_node **stack_b, int wr)
{
	if (!(*stack_a)->next && !(*stack_a)->prev && !(*stack_b)->next
		&& !(*stack_b)->prev)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
	if (wr)
		write(1, "ss\n", 3);
}
