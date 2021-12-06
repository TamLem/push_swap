/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/06 23:49:54 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (-1);
}

void	sort_stack(t_stack **a, t_stack **b, int len)
{
	int max;
	int min;
	static int iter = 0;

	iter++;
	if (*b == NULL)
	{
		push(a, b, 'b');
		return ;
	}

	while((*a)->value > (*b)->value)
	{
		if(!((*a)->value > get_tail(b)->value) || !((*b)->value < get_tail(b)->value))
		{
			push(a, b, 'b');
			break;
		}
		rev_rotate(b, 'b');
	}
	
	while((*a)->value < (*b)->value)
	{
		min = (*b)->value;
		rotate(b, 'b');
		if ((*b)->value >= min || (*a)->value > (*b)->value)
		{
			push(a, b, 'b');
			break ;
		}
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
	len = cplen;
	while(len >= 0)
	{
		if (*b == NULL)
		{
			push(a, b, 'b');
			continue ;
		}
		else if ((*a)->value < (*b)->value)
			push(a, b, 'b');
		else
		{
			rotate(a, 'a');
		}
		len--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int steps = 0;

	b = NULL;
	a = init_stack(argc - 1, &(argv[1]));
	// init_scan(&a, &b, argc -1);
	print_stacks(a, b);
	scanf("%d", &steps);
	while(a != NULL)
	{
		sort_stack(&a, &b, argc - 1);
		steps--;	
		if(!steps)
		{
			print_stacks(a, b);
			scanf("%d", &steps);
		}
	}
	print_stacks(a, b);

	return (0);
}
