/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:03:51 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/18 21:42:04 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	run_cmds(char *cmd, t_stack **a, t_stack **b)
{

	if(ft_strncmp(cmd, "pb\n", 3) == 0)
		push(a, b, 'b');
	else if(ft_strncmp(cmd, "pa\n", 3) == 0)
		push(b, a, 'a');
	else if(ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(a, 'a');
	else if(ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(b, 'b');
	else if(ft_strncmp(cmd, "rra\n", 3) == 0)
		rev_rotate(a, 'a');
	else if(ft_strncmp(cmd, "rrb\n", 3) == 0)
		rev_rotate(b, 'b');
	else if(ft_strncmp(cmd, "rr\n", 3) == 0)
		comb_oper(rotate, a, b, 'r');
	else if(ft_strncmp(cmd, "rrr\n", 3) == 0)
		comb_oper(rev_rotate, a, b, 'R');
	else if(ft_strncmp(cmd, "sa\n", 3) == 0)
		swap_head(a, 'a');
	else if(ft_strncmp(cmd, "sb\n", 3) == 0)
		swap_head(b, 'b');
	else if(ft_strncmp(cmd, "ss\n", 3) == 0)
		comb_oper(swap_head, a, b, 's');
	else
		printf("Wrong command\n");
}

int	check_sort(t_stack *a, int count)
{
	int	start;

	start = a->value;
	while (count > 0 || a->value != start)
	{
		if (a->value > a->next->value)
			break ;
	}
	if (count != 0)
		
}

int	main(int argc, char *argv[])
{
	t_stack **a;
	t_stack **b;
	char	**nums;
	int		count;
	char	*cmd;

	if (argc < 2)
		ft_error("not enough arguments.");
	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (a == NULL || b == NULL)
		ft_error("memory allocation not possible.");
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = &(argv[1]);
	count = ft_substrlen(nums);
	*a = init_stack(count, nums);
	while((cmd = get_next_line(0)) != NULL)
	{
		run_cmds(cmd, a, b);
		print_stacks(a, b);
	}
	return (0);
}
