/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_developement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:56:26 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/15 23:43:45 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	uroboros(t_node **list)
{
	t_node	*last;

	last = NULL;
	if (*list)
	{
		last = *list;
		while (last->prev)
			last = last->prev;
		last->prev = *list;
		(*list)->next = last;
	}
}

t_node	*init_list(int value, int index, t_node *list, int e_num)
{
	t_node	*element;

	element = (t_node *)malloc(sizeof(t_node));
	if (element == NULL)
		return (NULL);
	element->value = value;
	element->index = index;
	element->next = NULL;
	element->prev = list;
	element->score_br = 0;
	element->score_brr = 0;
	element->score_ar = 0;
	element->score_arr = 0;
	element->decision = 0;
	element->median = e_num / 2;
	element->fin = e_num - 1;
	element->min_ind = 0;
	element->swap_flag = 0;
	element->rrr_flag = 0;
	return (element);
}

static void	new_elem(t_node **list, int value, int index, int e_num)
{
	t_node	*head;

	if (*list == NULL)
		*list = init_list(value, index, NULL, e_num);
	else
	{
		head = init_list(value, index, *list, e_num);
		(*list)->next = head;
		*list = head;
	}
}

t_node	*list_developement(char **original, int *arr, int e_num,
t_node **stack_b)
{
	t_node	*list;
	int		index;
	int		value;
	int		arr_ind;

	*stack_b = NULL;
	list = NULL;
	index = 0;
	while (original[index])
	{
		arr_ind = 0;
		value = ft_atoi(original[index]);
		while (arr[arr_ind] != value)
			arr_ind++;
		new_elem(&list, value, arr_ind, e_num);
		index++;
	}
	uroboros(&list);
	return (list->next);
}
