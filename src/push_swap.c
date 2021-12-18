/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/18 20:26:18 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	main(int argc, char *argv[])
{
	t_stack **a;
	t_stack **b;
	// int steps = 0;
	char **nums;
	int count;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = &(argv[1]);
	count = ft_substrlen(nums);
	*a = init_stack(count, nums);
	print_stacks(a, b);
	// init_scan(&a, &b, argc -1);
	// scanf("%d", &steps);
	while(*a != NULL)
	{
		sort(a, b);
		// steps--;	
		// if(!steps)
		// {
		// 	print_stacks(a, b);
		// 	scanf("%d", &steps);
		// }
	}
	while ((*b)->value < (*b)->prev->value)
			rotate(b, 'b');
	while (*b != NULL)
		push(b, a, 'a');
	return (0);
}
