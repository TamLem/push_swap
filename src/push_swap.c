/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/05 20:35:41 by tlemma           ###   ########.fr       */
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
		
	push(a, b, 'a');

	comb_oper(rotate, a, b, 'r');		
	comb_oper(rotate, a, b, 'r');

}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = init_stack(argc - 1, &(argv[1]));
	int steps = 0;
	scanf("%d", &steps);
	while(steps)
	{
		sort_stack(&a, &b, argc - 1);
		steps--;	
		if(!steps)
		{
			print_stacks(a, b);
			scanf("%d", &steps);
		}
	}
	return (0);
}
