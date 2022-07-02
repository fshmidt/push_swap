/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:16:45 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 01:06:01 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	final_sort(t_node **a, int *fin_rotation)
{
	t_node	*temp;
	int		rr;
	int		rrr;

	rr = 0;
	rrr = 0;
	temp = *a;
	*fin_rotation = WRITABLE;
	while (temp->index != 0)
	{
		temp = temp->next;
		rr++;
	}
	while (temp->index != (*a)->index)
	{
		temp = temp->next;
		rrr++;
	}
	if (rr <= rrr)
	{
		*fin_rotation = 0;
		return (rr);
	}
	return (rrr);
}

int	unsorted_stack(t_node **stack)
{
	t_node	*temp;
	int		status;

	temp = *stack;
	status = 0;
	while (temp->next != *stack)
	{
		if (temp->next->index < temp->index)
			status++;
		temp = temp->next;
	}
	return (status);
}

static void	tripple_sort(t_node **stack, int fin, int degree)
{
	if (fin == WRITABLE)
	{
		r_a(stack, WRITABLE);
		return ;
	}
	if ((*stack)->next->index > (*stack)->index && (*stack)->next->index
		> (*stack)->prev->index)
		rr_a(stack, WRITABLE);
	if (unsorted_stack(stack) > degree)
	{
		if ((*stack)->index < (*stack)->prev->index
			|| (*stack)->next->index > (*stack)->prev->index)
			s_a(stack, WRITABLE);
		if (unsorted_stack(stack) > degree)
		{
			if ((*stack)->index > (*stack)->next->index)
				r_a(stack, WRITABLE);
			else
				rr_a(stack, WRITABLE);
		}
	}
}

static int	no_favorites(t_node **a, t_node **stack_b, int fin)
{
	int	counter;

	counter = fin -2;
	if (fin < 3)
	{
		tripple_sort(a, fin, 0);
		return (NO_FAVORITES);
	}
	while (counter)
	{
		if ((*a)->index != 0 && (*a)->index != (*a)->median && (*a)->index
			!= fin)
		{
			p_b(a, stack_b, WRITABLE);
			counter--;
		}
		else if ((*a)->next->index != 0 && (*a)->next->index
			!= (*a)->median && (*a)->next->index != fin)
			r_a(a, WRITABLE);
		else
			rr_a(a, WRITABLE);
	}
	if (unsorted_stack(a) > 0)
		tripple_sort(a, fin, 0);
	return (0);
}

void	sorting(t_node **stack_a, t_node **stack_b, int fin)
{
	int		decided;
	int		fin_rotation;

	if (no_favorites(stack_a, stack_b, fin))
		return ;
	while (*stack_b)
	{
		scoring(stack_a, stack_b);
		decided = decision(stack_b, stack_a);
		execution(stack_a, stack_b, decided);
	}
	if (unsorted_stack(stack_a))
	{
		decided = final_sort(stack_a, &fin_rotation);
		while (decided--)
		{
			if (fin_rotation == 0)
				r_a(stack_a, WRITABLE);
			else
				rr_a(stack_a, WRITABLE);
		}
	}
}
