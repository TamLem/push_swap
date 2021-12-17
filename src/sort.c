/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:16:00 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/17 18:10:46 by tlemma           ###   ########.fr       */
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

void	profiler2(t_stack *a, t_stack *b, int i[])
{
	int start;
	int steps;
	int pos_b;
	int pos_a;
	int index;
	int len_a;
	int	len_b;
	int min_steps;

	pos_a = 0;
	pos_b = 0;
 	index = 0;
	len_a = get_len(a);
	len_b = get_len(b);
	if (a == NULL || b == NULL)
		return ;
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
			// printf("steps %d\n", min_steps);
		}
		a = a->next;
		index++;
	}
}

void	profiler(t_stack *a, t_stack *b, int i[])
{
	int start;
	int pos_f;
	int pos_b;
	int index;
	int len;

	pos_f = 0;
	pos_b = 0;
 	index = 0;
	len = get_len(b);
	if (a == NULL || b == NULL)
		return ;
	start = a->value;
	while (a->value != start || index == 0)
	{
		pos_f = peak_ahead(a->value, b);
		pos_b = peak_back(a->value, b);
		if ((index + ft_abs(pos_f - index))< (i[0] + abs(i[0] - i[1])) || (i[0] + i[1] == 0)) 
		{
			i[0] = index;
			i[1] = pos_f; 
		}
		a = a->next;
		index++;
	}
	// printf("Val %d P_back %d\n", a->value, peak_back(a->value, b));
	index = 0;
	while (a->value != start || index == 0) 
	{
		pos_f = peak_back(a->value, b);
		if ((index + ft_abs(pos_f - index)) < (i[2] + abs(i[3] - i[2])) || (i[2] + i[3] == 0))
		{
			i[2] = index;
			i[3] = pos_f; 
		}
		a = a->prev;
		index++;
	}
}

void	sort_3(t_stack **a, t_stack **b, int len)
{
	int i[2];
	char r_o_R;

	i[0] = 0;
	i[1] = 0;
	if (*b == NULL || (*b)->next == NULL)
	{
		push(a, b, 'b');
		return ;
	}
	profiler2(*a, *b, i);
	// printf("%d, %d \n", i[0], i[1]);
	// printf("%d, %d, %d, %d \n", i[0], i[1], i[2], i[3]);

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

void	sort_2(t_stack **a, t_stack **b, int len)
{
	int i[4];
	char r_o_R;
	int (*move)(t_stack **, char id);

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	if (*b == NULL || (*b)->next == NULL)
	{
		push(a, b, 'b');
		return ;
	}
	profiler(*a, *b, i);
	// printf("%d, %d, %d, %d \n", i[0], i[1], i[2], i[3]);
	if ((i[0] + i[1]) <= (i[2] + i[3]))
	{
		move = &rotate;
		r_o_R = 'r';
	}
	else
	{
		move = &rev_rotate;
		i[0] = i[2];
		i[1] = i[3];
		r_o_R = 'R';
	}
	// printf("%d, %d, %d, %d \n", i[0], i[1], i[2], i[3]);

	while (i[0] != 0 || i[1] != 0)
	{
		if (i[0] != 0 && i[1] != 0)
		{
			comb_oper(*move, a, b, r_o_R);
			i[0]--;
			i[1]--;
		}
		else if (i[0] != 0)
		{
			move(a, 'a');
			i[0]--;
		}
		else
		{
			move(b, 'b');
			i[1]--;
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

void	init_scan(t_stack **a, t_stack **b, int len)
{
	int cplen = len;
	while(len >= 0)
	{
		if (*b == NULL)
		{
			push(a, b, 'b');
			continue ;
		}
		else if ((*a)->value > (*b)->value)
			push(a, b, 'b');
		else
		{
			rotate(a, 'a');
		}
		len--;
	}
	// len = cplen;
	// while(len >= 0)
	// {
	// 	if (*b == NULL)
	// 	{
	// 		push(a, b, 'b');
	// 		continue ;
	// 	}
	// 	else if ((*a)->value < (*b)->value)
	// 		push(a, b, 'b');
	// 	else
	// 	{
	// 		rev_rotate(a, 'a');
	// 	}
	// 	len--;
	// }
}


void	pop_sort(t_stack **a, t_stack **b)
{
	while(*a != NULL)
	{
		if (*b == NULL)
			push(a, b, 'b');
		if ((*b)->value > (*a)->value)
		{
			push(b, a, 'a');
			rotate(a, 'a');
		}
		else
		push(a, b, 'b');
	}
}