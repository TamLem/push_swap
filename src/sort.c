/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:16:00 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/15 22:11:49 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	profiler(t_stack *a, t_stack *b, int i[])
{
	int start;
	int pos;
	int index;
	int len;

	pos = 0;
	index = 0;
	len = get_len(b);
	if (a == NULL || b == NULL)
		return ;
	start = a->value;
	while (a->value != start || index == 0)
	{
		pos = peak_ahead(a->value, b);
		if ((pos + index) < (i[0] + i[1]) || (i[0] + i[1] == 0)) 
		{
			i[0] = index;
			i[1] = pos; 
		}
		a = a->next;
		index++;
	}
	// printf("Val %d P_back %d\n", a->value, peak_back(a->value, b));
	index = 0;
	while (a->value != start || index == 0) 
	{
		pos = peak_back(a->value, b);
		if ((pos + index) < (i[2] + i[3]) || (i[2] + i[3] == 0))
		{
			i[2] = index;
			i[3] = pos; 
		}
		a = a->prev;
		index++;
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

	// int pa = peak_ahead((*a)->value, *b, 5);
	// int pb = peak_back((*a)->value, *b, 5);

	// printf("Peak ahead %d\n", pa);
	// printf("Peak back %d\n", pb);
	// if (pa != 0 && (pa <= pb || pb == 0))
	// {
	// 	rotate(b, 'b');
	// }
	// else if (pb != 0 && (pb <= pa || pa == 0))
	// {
	// 	rev_rotate(b, 'b');
	// }
	// else
	// 	comb_oper(rotate, a, b, 'r');

	// if (*a == NULL)
	// 	return ; 
		
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