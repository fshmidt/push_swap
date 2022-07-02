/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:06:41 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/16 14:38:53 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ar_score(int index, t_node **stack)
{
	int		score;
	t_node	*temp;

	temp = *stack;
	score = 0;
	while (temp->next != *stack)
	{
		if (temp->index < index || (temp->index > index && index
				< temp->prev->index))
			score++;
		else
			return (score);
		temp = temp->next;
	}
	return (score);
}

static int	arr_score(int index, t_node **stack)
{
	int		score;
	t_node	*temp;

	temp = *stack;
	score = 0;
	while (temp->prev != *stack)
	{
		if (temp->index < index || (temp->index > index && index
				< temp->prev->index))
			score++;
		else
			return (score);
		temp = temp->prev;
	}
	return (score);
}

static int	b_score(t_node *temp, t_node **b, int flag)
{
	int	score;

	score = 0;
	if (flag == 0)
	{
		while (temp != *b)
		{
			score++;
			temp = temp->prev;
		}
	}
	else
	{
		while (temp != *b)
		{
			score++;
			temp = temp->next;
		}
	}
	return (score);
}

static void	last_b(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	temp->score_ar = ar_score(temp->index, stack_a);
	temp->score_arr = arr_score(temp->index, stack_a);
	temp->score_br = 0;
	temp->score_brr = 0;
}

void	scoring(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = *stack_b;
	if (temp->next == NULL)
	{
		last_b(temp, stack_a, stack_b);
		return ;
	}
	while (temp->next != *stack_b)
	{
		temp->score_ar = ar_score(temp->index, stack_a);
		temp->score_arr = arr_score(temp->index, stack_a);
		temp->score_br = b_score(temp, stack_b, 0);
		temp->score_brr = b_score(temp, stack_b, 1);
		temp = temp->next;
	}
	temp->score_ar = ar_score(temp->index, stack_a);
	temp->score_arr = arr_score(temp->index, stack_a);
	temp->score_br = b_score(temp, stack_b, BR);
	temp->score_brr = b_score(temp, stack_b, BRR);
}
