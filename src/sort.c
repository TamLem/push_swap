/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:16:00 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/21 18:28:31 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	peak_ahead(int val, t_stack *b)
{
	int i;
	int start;

	i = 1;
	start = b->value;
	b = b->next;
	while(b != NULL && b->value != start)
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

void	profiler(t_stack *a, t_stack *b, int i[])
{
	int start;
	int steps;
	int pos_b;
	int pos_a;
	int index;
	int len_a;
	int	len_b;
	int min_steps;

 	index = 0;
	len_a = get_len(a);
	len_b = get_len(b);
	start = a->value;
	while (a->value != start || index == 0)
	{
		pos_a = index;
		pos_b = peak_ahead(a->value, b);

		if (pos_b > len_b / 2)
			pos_b -= len_b;
		if (index > len_a / 2)
			pos_a -= len_a;
		if (pos_a * pos_b > 0)
			steps = max(abs(pos_a), abs(pos_b));
		else
			steps = ft_abs(pos_a) + ft_abs(pos_b);
		if ( steps < min_steps || index == 0) 
		{
			i[0] = pos_a;
			i[1] = pos_b; 
			min_steps = steps;
		}
		a = a->next;
		index++;
	}
}

void	large_sort(t_stack **a, t_stack **b)
{
	int i[2];

	i[0] = 0;
	i[1] = 0;
	if (*b == NULL || (*b)->next == NULL)
	{
		push(a, b, 'b');
		return ;
	}
	profiler(*a, *b, i);
	while (i[0] != 0 || i[1] != 0)
	{
		if (i[0] > 0 && i[1] > 0)
		{
			comb_oper(rotate, a, b, 'r');
			i[0]--;
			i[1]--;
			continue ;
		}
		else if (i[0] < 0 && i[1] < 0)
		{
			comb_oper(rev_rotate, a, b, 'R');
			i[0]++;
			i[1]++;
			continue ;
		}
		if (i[0] > 0)
		{
			rotate(a, 'a');
			i[0]--;
		}
		if (i[0] < 0)
		{
			rev_rotate(a, 'a');
			i[0]++;
		}
		if (i[1] > 0)
		{
			rotate(b, 'b');
			i[1]--;
		}
		if (i[1] < 0)
		{
			rev_rotate(b, 'b');
			i[1]++;
		}		
	}

	if (((*a)->value > (*b)->value && (*a)->value < (*b)->prev->value)
		|| ((*a)->value > (*b)->value && (*b)->value > (*b)->prev->value)
		|| ((*a)->value < (*b)->prev->value && (*b)->value > (*b)->prev->value))
		{
			push(a, b, 'b');
			return ;
		}
}
