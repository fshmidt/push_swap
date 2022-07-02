/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:16:59 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/15 23:35:58 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrb_rra_rrr(t_node **a, t_node **b, t_node *temp, int flag)
{
	if (flag == 4)
	{
		while ((*a)->index < temp->index || ((*a)->index > temp->index
				&& (*a)->prev->index > temp->index))
			rrr(b, a, WRITABLE);
		if (temp->swap_flag == 5)
		{
			s_b(b, WRITABLE);
			p_a(a, b, WRITABLE);
			return ;
		}
		while (temp->index != (*b)->index)
			rr_b(b, WRITABLE);
		p_a(a, b, WRITABLE);
	}
	if (flag == 5)
	{
		while (temp->index != (*b)->index)
			rrr(b, a, WRITABLE);
		while (temp->index > (*a)->index || (temp->index < (*a)->index
				&& temp->index < (*a)->prev->index))
			rr_a(a, WRITABLE);
		p_a(a, b, WRITABLE);
	}
}

static void	rrb_rra_rb_ra(t_node **a, t_node **b, t_node *temp, int flag)
{
	if (flag == 2)
	{
		while ((*a)->index < temp->index || ((*a)->index > temp->index
				&& (*a)->prev->index > temp->index))
			r_a(a, WRITABLE);
		while (temp->index != (*b)->index)
			rr_b(b, WRITABLE);
		p_a(a, b, WRITABLE);
	}
	if (flag == 3)
	{
		while (temp->index != (*b)->index)
			r_b(b, WRITABLE);
		while (temp->index > (*a)->index || (temp->index < (*a)->index
				&& temp->index < (*a)->prev->index))
			rr_a(a, WRITABLE);
		p_a(a, b, WRITABLE);
	}
}

static void	rr_ra_rb(t_node **a, t_node **b, t_node *temp, int flag)
{
	if (flag == 0)
	{
		while ((*a)->index < temp->index || ((*a)->index > temp->index
				&& (*a)->prev->index > temp->index))
			rr(b, a, WRITABLE);
		while (temp->index != (*b)->index)
			r_b(b, WRITABLE);
		p_a(a, b, WRITABLE);
	}
	if (flag == 1)
	{
		while (temp->index != (*b)->index)
			rr(b, a, WRITABLE);
		if (temp->swap_flag == 1)
		{
			s_b(b, WRITABLE);
			p_a(a, b, WRITABLE);
			return ;
		}
		while ((*a)->index < temp->index || ((*a)->index > temp->index
				&& (*a)->prev->index > temp->index))
			r_a(a, WRITABLE);
		p_a(a, b, WRITABLE);
	}
}

void	execution(t_node **a, t_node **b, int index)
{
	t_node	*temp;

	if (index < 0)
	{
		if (index == -1)
			s_b(b, WRITABLE);
		else
			rrr(b, a, WRITABLE);
		return ;
	}
	temp = *b;
	while (temp->index != index)
		temp = temp->next;
	if (temp->decision == 0)
		rr_ra_rb(a, b, temp, 0);
	if (temp->decision == 1)
		rr_ra_rb(a, b, temp, 1);
	if (temp->decision == 2)
		rrb_rra_rb_ra(a, b, temp, 2);
	if (temp->decision == 3)
		rrb_rra_rb_ra(a, b, temp, 3);
	if (temp->decision == 4)
		rrb_rra_rrr(a, b, temp, 4);
	if (temp->decision == 5)
		rrb_rra_rrr(a, b, temp, 5);
}
