/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/05 23:38:45 by tlemma           ###   ########.fr       */
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

	if(*b == NULL || (*a)->value > (*b)->value)
	{
		if (*b == NULL)
			push(a, b, 'a');
		else
		{
			max = (*b)->value;
			while((*a)->value > (*b)->value)
			{
				rev_rotate(b, 'b');
				if ((*b)->value <= max)
					break ;
				max = (*b)->value;
			}
			rotate(b, 'b');
			push(a, b, 'a');
		}
	}
	else
	{
		min = (*b)->value;
		while((*a)->value < (*b)->value)
		{
			rotate(b, 'b');
			if ((*b)->value >= min)
				break ;
			min = (*b)->value;
		}
		push(a, b, 'a');
	}
	rotate(a, 'a');
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = init_stack(argc - 1, &(argv[1]));
	print_stacks(a, b);
	int steps = 0;
	// scanf("%d", &steps);
	while(a != NULL)
	{
		sort_stack(&a, &b, argc - 1);
		// steps--;	
		// if(!steps)
		// {
		// 	print_stacks(a, b);
		// 	// scanf("%d", &steps);
		// }
	}
	print_stacks(a, b);

	return (0);
}
