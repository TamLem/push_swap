/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:03:51 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/23 04:53:30 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	checker_comb_oper(int (*oper)(t_stack **head, char id),
	t_stack **src1, t_stack **src2, char id)
{
	if ((oper(src1, id) + oper(src2, id)) > 0)
		return (1);
	return (0);
}

static void	run_cmd(char *cmd, t_stack **a, t_stack **b)
{
	if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push(a, b, NO_PRINT);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push(b, a, NO_PRINT);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(a, NO_PRINT);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(b, NO_PRINT);
	else if (ft_strncmp(cmd, "rra\n", 3) == 0)
		rev_rotate(a, NO_PRINT);
	else if (ft_strncmp(cmd, "rrb\n", 3) == 0)
		rev_rotate(b, NO_PRINT);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		checker_comb_oper(rotate, a, b, NO_PRINT);
	else if (ft_strncmp(cmd, "rrr\n", 3) == 0)
		checker_comb_oper(rev_rotate, a, b, NO_PRINT);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap_head(a, NO_PRINT);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap_head(b, NO_PRINT);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		comb_oper(swap_head, a, b, NO_PRINT);
	else
		ft_error("wrong command");
}

void	run_cmds(t_stack **a, t_stack **b)
{
	char	*cmd;

	if (!check_duplicates(*a) && get_len(*a) > 1)
	{
		free_stacks(a, a);
		ft_error("Error");
	}
	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		run_cmd(cmd, a, b);
		cmd = get_next_line(0);
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
		return (0);
	nums = &(argv[1]);
	init_stack(ft_substrlen(nums), nums, &a);
	run_cmds(&a, &b);
	if (is_sorted(a) && b == NULL)
		ft_printf("OK");
	else
		ft_printf("KO");
	return (0);
}
