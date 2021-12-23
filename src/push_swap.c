/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/23 05:26:15 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pushback_sorted(t_stack **a, t_stack **b)
{
	int		max_pos;
	int		len;
	t_stack	*temp;

	max_pos = 0;
	len = get_len(*b);
	temp = *b;
	while (temp->value > temp->next->value && ++max_pos)
		temp = temp->next;
	while ((*b)->value < (*b)->prev->value)
	{
		if (max_pos < len / 2)
			rotate(b, 'b');
		else
			rev_rotate(b, 'b');
	}
	while (*b != NULL)
		push(b, a, 'a');
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = get_len(*a);
	if (len > 1 && !check_duplicates(*a))
	{
		free_stacks(a, a);
		ft_error("Error");
	}
	if (len == 1 || is_sorted(*a))
		return ;
	if (len < 4)
		simple_sort(a);
	else if (len == 5)
		mid_sort(a, b);
	else
	{
		push(a, b, 'b');
		push(a, b, 'b');
		while (*a != NULL)
			large_sort(a, b);
		pushback_sorted(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	head;
	char	**nums;

	a = &head;
	b = NULL;
	if (argc < 2)
		ft_error("Error");
	nums = &(argv[1]);
	init_stack(ft_substrlen(nums), nums, &a);
	sort(&a, &b);
	return (0);
}
