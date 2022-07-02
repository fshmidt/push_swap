/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes_and_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:05:53 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/15 17:49:03 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	command(int wr)
{
	if (wr)
		write(1, "pb\n", 3);
}

void	p_b(t_node **stack_a, t_node **stack_b, int wr)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = temp->prev;
	temp->prev->next = *stack_a;
	temp->next = *stack_b;
	if (*stack_b != NULL && (*stack_b)->prev)
	{
		temp->prev = (*stack_b)->prev;
		temp->prev->next = temp;
		(*stack_b)->prev = temp;
	}
	else if (*stack_b)
	{
		(*stack_b)->next = temp;
		(*stack_b)->prev = temp;
		temp->prev = *stack_b;
	}
	else
		temp->prev = NULL;
	*stack_b = temp;
	command(wr);
}

void	p_a(t_node **stack_a, t_node **stack_b, int wr)
{
	t_node	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (temp->next == temp->prev && temp->next)
	{
		(*stack_b)->prev = NULL;
		(*stack_b)->next = NULL;
	}
	else if (temp->prev)
	{
		(*stack_b)->prev = temp->prev;
		temp->prev->next = (*stack_b);
	}
	temp->next = *stack_a;
	temp->prev = (*stack_a)->prev;
	temp->prev->next = temp;
	(*stack_a)->prev = temp;
	*stack_a = temp;
	if (wr)
		write(1, "pa\n", 3);
}

void	rrr(t_node **stack_b, t_node **stack_a, int wr)
{
	if (!*stack_a || !(*stack_a)->prev)
		return ;
	*stack_a = (*stack_a)->prev;
	if (!*stack_b || !(*stack_b)->prev)
		return ;
	*stack_b = (*stack_b)->prev;
	if (wr)
		write(1, "rrr\n", 4);
}
