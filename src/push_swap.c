/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/21 17:20:16 by tlemma           ###   ########.fr       */
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


void	sort(t_stack **a, t_stack **b, int len)
{
	if (!check_duplicates(*a))
	{
		free_stacks(a, a);
		ft_error("Input list contains duplicates");
	}
	if (len == 1 || is_sorted(*a)) 
		return ;
	if (len < 4)
		simple_sort(a);
	else
	{
		while(*a != NULL)
			large_sort(a, b);
		while ((*b)->value < (*b)->prev->value)
				rotate(b, 'b');
		while (*b != NULL)
			push(b, a, 'a');
	}
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	t_stack head;
	char **nums;
	int count;
	int mem_alloc;

	a = &head;
	b = NULL;
	mem_alloc = 0;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		mem_alloc = 1;
	}
	else
		nums = &(argv[1]);
	if(!check_input(nums))
		ft_error("Input list contains unallowed charachters");
	count = ft_substrlen(nums);
	init_stack(count, nums, &a);
	sort(&a, &b, count);
	if (mem_alloc)
		free_dp(nums);
	return (0);
}
