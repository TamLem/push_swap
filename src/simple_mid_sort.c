/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_mid_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:22:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/22 23:00:22 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simple_sort(t_stack **a)
{
	if (get_len(*a) == 2)
		rotate(a, 'a');
	else
	{
		while (!is_sorted(*a))
		{
			if ((*a)->value < (*a)->prev->value
				&& (*a)->value > (*a)->next->value)
				swap_head(a, 'a');
			else
				rotate(a, 'a');
		}
	}
}

int	get_mid(t_stack *a)
{
	int	val;
	int	index;
	int	arr_index;

	index = 0;
	arr_index = 0;
	val = a->value;
	while (1)
	{
		a = a->next;
		if (val == a->value)
		{
			if (index == 0)
				break ;
			val = a->next->value;
			a = a->next->next;
			index = 0;
		}
		if (val > a->value)
			index++;
		else
			index--;
	}
	return (val);
}

void	mid_sort(t_stack **a, t_stack **b)
{
	int		mid;

	mid = get_mid(*a);
	while (get_len(*b) < 2)
	{
		if ((*a)->value < mid)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	simple_sort(a);
	if (is_sorted(*b))
		rotate(b, 'b');
	while (*b != NULL)
		push(b, a, 'a');
}
