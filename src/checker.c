/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:03:51 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/21 16:58:53 by tlemma           ###   ########.fr       */
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



int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	t_stack head;
	char **nums;
	int count;
	int mem_alloc;
	char *cmd;

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
	while((cmd = get_next_line(0)) != NULL)
		run_cmds(cmd, &a, &b);
	if(is_sorted(a) && get_len(a) == count)
		printf("OK");
	else
		printf("KO");
	return (0);
}
