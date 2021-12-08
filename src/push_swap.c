/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/08 18:29:08 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (-1);
}

int	peak_ahead(int val, t_stack *b, int len)
{
	while(len >= 0 && b != NULL)
	{
		if (val > b->value)
			return (1);
		b = b->next;
	}
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b, int len)
{
	int max;
	int min;
	static int iter = 0;
	int inner_iter = 0;
	int check = 0;

	iter++;
	if (*b == NULL)
		push(a, b, 'b');

	while((*a)->value > (*b)->value)
	{
		if(!((*a)->value > get_tail(b)->value) || !((*b)->value < get_tail(b)->value))
		{
			push(a, b, 'b');
			break;
		}
		rev_rotate(b, 'b');
	}
	
	if (*a == NULL)
		return ; 

	while((*a)->value < (*b)->value)
	{
		if ((*a)->value > (*b)->next->value 
			|| (*b)->value < (*b)->next->value)
		{
			rotate(b, 'b');
			push(a, b, 'b');
			break;
		}
		// if (peak_ahead((*a)->value, (*b)->next, 10))
		// {
		// 	printf("peaked\n");
		// 	rotate(b, 'b');
		// }
		// else
			// rotate(a, 'b');
			comb_oper(rotate, a, b, 'r');
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
			rev_rotate(a, 'a');
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

// if ((*a)->next && (*a)->next->value > (*a)->value)
// {
// 	rotate(a, 'a');
// 	continue ;
// }
// else
// else
// {
// 	rotate(b, 'b');
// }
// if (b_rot < 2)
// {
// 	rotate(b, 'a');
// }
// else