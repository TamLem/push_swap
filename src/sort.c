/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:16:00 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/22 19:20:04 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	peak_ahead(int val, t_stack *b)
{
	int	i;
	int	start;

	i = 1;
	start = b->value;
	b = b->next;
	while (b != NULL && b->value != start)
	{
		if ((val > b->value && val < b->prev->value)
			|| (val > b->value && b->value > b->prev->value)
			|| (val < b->prev->value && b->value > b->prev->value))
			return (i);
		b = b->next;
		i++;
	}
	return (0);
}

int	calc_steps(int *pos_a, int *pos_b, t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	steps;

	steps = 0;
	len_a = get_len(a);
	len_b = get_len(b);
	if ((*pos_b) > len_b / 2)
		(*pos_b) -= len_b;
	if ((*pos_a) > len_a / 2)
		(*pos_a) -= len_a;
	if ((*pos_a) * (*pos_b) > 0)
		steps = max(ft_abs((*pos_a)), ft_abs((*pos_b)));
	else
		steps = ft_abs((*pos_a)) + ft_abs((*pos_b));
	return (steps);
}

void	profiler(t_stack *a, t_stack *b, int i[])
{
	int	start;
	int	steps;
	int	pos[2];
	int	index;
	int	min_steps;

	index = 0;
	start = a->value;
	while ((a->value != start || index == 0))
	{
		pos[0] = index;
		pos[1] = peak_ahead(a->value, b);
		steps = calc_steps(&pos[0], &pos[1], a, b);
		if (steps < min_steps || index == 0)
		{
			i[0] = pos[0];
			i[1] = pos[1];
			min_steps = steps;
		}
		a = a->next;
		index++;
	}
}

int	insert(t_stack **a, t_stack **b)
{
	if (((*a)->value > (*b)->value && (*a)->value < (*b)->prev->value)
		|| ((*a)->value > (*b)->value && (*b)->value > (*b)->prev->value)
		|| ((*a)->value < (*b)->prev->value && (*b)->value > (*b)->prev->value))
	{
		push(a, b, 'b');
		return (1);
	}
	return (0);
}

void	large_sort(t_stack **a, t_stack **b)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	if (insert(a, b))
		return ;
	profiler(*a, *b, i);
	while (i[0] != 0 || i[1] != 0)
	{
		if (i[0] > 0 && i[1] > 0 && i[0]-- && i[1]--)
			comb_oper(rotate, a, b, 'r');
		if (i[0] < 0 && i[1] < 0 && i[0]++ && i[1]++)
			comb_oper(rev_rotate, a, b, 'R');
		if (i[0] * i[1] <= 0 && i[0] > 0 && i[0]--)
			rotate(a, 'a');
		if (i[0] * i[1] <= 0 && i[0] < 0 && i[0]++)
			rev_rotate(a, 'a');
		if (i[0] * i[1] <= 0 && i[1] > 0 && i[1]--)
			rotate(b, 'b');
		if (i[0] * i[1] <= 0 && i[1] < 0 && i[1]++)
			rev_rotate(b, 'b');
	}
}
