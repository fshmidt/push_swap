/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:19:24 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 00:08:57 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min(t_node *temp, t_node **a, t_node **b)
{
	int	min;
	int	ind;
	int	min_ind;

	ind = 0;
	min_ind = 0;
	min = temp->ind[ind];
	while (5 > ind)
	{
		if (temp->ind[ind + 1] && min > temp->ind[ind + 1])
		{
			min = temp->ind[ind + 1];
			min_ind = ind + 1;
		}
		ind++;
	}
	if (temp->rrr_flag == 1)
		return (-2);
	if ((min_ind == 0 || min_ind == 1) && temp == *b && (*b)->next
		&& (*b)->index < (*b)->next->index && (*b)->score_ar
		== temp->next->score_ar)
		return (-1);
	return (min_ind);
}

static	void	count_2(t_node *temp, t_node **a, t_node **b)
{
	if (temp->score_arr < temp->score_brr)
	{
		temp->ind[RRB_RRR] = temp->score_brr;
		temp->ind[RRA_RRR] = temp->score_arr + temp->fin;
	}
	else if (temp->score_arr >= temp->score_brr && temp->score_arr
		< temp->score_brr + 2)
	{
		temp->ind[RRB_RRR] = temp->score_arr + 1;
		temp->ind[RRA_RRR] = temp->score_arr + 1;
		if (temp->score_arr > temp->score_brr)
			temp->swap_flag = 5;
	}
	else if (temp->score_arr >= temp->score_brr + 2)
	{
		temp->ind[RRB_RRR] = temp->score_brr + temp->fin;
		temp->ind[RRA_RRR] = temp->score_arr;
	}
	temp->ind[RRB_RA] = temp->score_brr + temp->score_ar;
	temp->ind[RRA_RB] = temp->score_br + temp->score_arr;
}

static int	count(t_node *temp, t_node **a, t_node **b)
{
	temp->ind[RR_RB] = temp->score_br;
	temp->rrr_flag = 0;
	temp->swap_flag = 0;
	if (temp->score_ar <= temp->score_br - 2)
		temp->ind[RR_RA] = temp->score_br + temp->fin;
	else if (temp->score_ar > temp->score_br - 2 && temp->score_ar
		<= temp->score_br)
	{
		temp->ind[RR_RA] = temp->score_br;
		if (temp->score_br < temp->score_ar)
			temp->swap_flag = 1;
	}
	else
	{
		temp->ind[RR_RB] = temp->score_ar + temp->fin;
		temp->ind[RR_RA] = temp->score_ar;
		if (temp->score_ar == 1 && temp->prev && temp->next
			&& temp->prev->index + 1 == (*a)->prev->index && temp == *b)
			temp->rrr_flag = 1;
	}
	count_2(temp, a, b);
	return (min(temp, a, b));
}

static int	lists_comparison(t_node **b, t_node **stack_a, int *min_ind)
{
	t_node	*temp;
	t_node	*min;

	temp = *b;
	min = *b;
	while (temp->next != *b)
	{
		temp->decision = count(temp, stack_a, b);
		if (temp->decision < 0)
			return (temp->decision);
		if (temp->ind[temp->decision] < min->ind[min->decision])
		{
			*min_ind = temp->index;
			min = temp;
		}
		temp = temp->next;
	}
	temp->decision = count(temp, stack_a, b);
	if (temp->ind[temp->decision] < min->ind[min->decision])
		*min_ind = temp->index;
	return (*min_ind);
}

int	decision(t_node **b, t_node **stack_a)
{
	t_node	*temp;
	t_node	*min;
	int		min_ind;

	temp = *b;
	min_ind = temp->index;
	if (temp->next == NULL)
	{
		temp->decision = count(temp, stack_a, b);
		return (min_ind);
	}
	return (lists_comparison(b, stack_a, &min_ind));
}
