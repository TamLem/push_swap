/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/14 23:52:36 by tlemma           ###   ########.fr       */
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
	int i;

	i = 1;
	b = b->next;
	while(len >= 0 && b != NULL)
	{
		if ((val > b->value && val < b->prev->value)
			|| (val > b->value && b->value > b->prev->value)
			|| (val < b->prev->value && b->value > b->prev->value))
			return (i);
		b = b->next;
		i++;
		len--;
	}
	return (0);
}

int	peak_back(int val, t_stack *b, int len)
{
	int	i;

	i = 1;
	b = b->next;
	while(len >= 0 && b != NULL)
	{
		if ((val > b->value && val < b->prev->value)
			|| (val > b->value && b->value > b->prev->value)
			|| (val < b->prev->value && b->value > b->prev->value))
			return (i);
		b = b->prev;
		i++;
		len--;
	}
	return (0);
}

// int	pick(int val, t_stack *b, int len)
// {
	
// }

void	sort_stack(t_stack **a, t_stack **b, int len)
{
	int max = 0;
	int min;
	int iter = 2;
	int inner_iter = 0;
	int check = 0;

	
	if (*b == NULL)
		push(a, b, 'b');

	while((*a)->value > (*b)->value)
	{
		if((*b)->prev == NULL || !((*a)->value > (*b)->prev->value) 
		|| !((*b)->value < (*b)->prev->value))
		{
			push(a, b, 'b');
			break;
		}
		rev_rotate(b, 'b');
	}
	print_stacks(a, b);
	if (*a == NULL)
		return ; 

	while((*a)->value < (*b)->value)
	{
		if ((*a)->value < (*b)->prev->value && (*b)->value > (*b)->prev->value)
		{
			push(a, b, 'b');
			break ;
		}
		if ((*a)->value > (*b)->next->value 
			|| (*b)->value < (*b)->next->value)
		{
			rotate(b, 'b');
			push(a, b, 'b');
			break;
		}
	
		if ((*a)->next == NULL || peak_ahead((*a)->value, (*b)->next, 5))
		{
			rotate(b, 'b');
		}
		else
			comb_oper(rotate, a, b, 'r');
			// rotate(a, 'a');
	}
	
}

void	run_cmds(char *cmd, t_stack **a, t_stack **b, int len)
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
	t_stack **a;
	t_stack **b;
	int steps = 0;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	*a = init_stack(argc - 1, &(argv[1]));
	// init_scan(&a, &b, argc -1);
	scanf("%d", &steps);
	while(*a != NULL)
	{
		sort_stack(a, b, argc - 1);
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

/* 
 Tried but not working 
if ((*a)->next->value > (*a)->value && (*a)->value > (*b)->value)
			rotate(a, 'a');
		else
 */
/* 
	char *cmd;
	while((cmd = get_next_line(0)) != NULL)
		{
			run_cmds(cmd, &a, &b, argc - 1);
			print_stacks(a, b);
		}
	return 1;
 */
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