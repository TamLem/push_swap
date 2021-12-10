#include "../include/push_swap.h"

void	sort_2(t_stack **a, t_stack **b, int len)
{
	if (*b == NULL)
		push(a, b, 'b');

	if((*a)->value > (*b)->value)
	{
		if(!((*a)->value > get_tail(*b)->value) || !((*b)->value < get_tail(*b)->value))
		{
			push(a, b, 'b');
		}
		rev_rotate(b, 'b');
	}
	print_stacks(*a, *b);
	
	if (*a == NULL)
		return ; 

	if((*a)->value < (*b)->value)
	{
		if ((*a)->value > (*b)->next->value 
			|| (*b)->value < (*b)->next->value)
		{
			rotate(b, 'b');
			push(a, b, 'b');
		}
		rotate(b, 'b');
		return ;
	}
	comb_oper(rotate, a, b, 'r');
	
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
	// len = cplen;
	// while(len >= 0)
	// {
	// 	if (*b == NULL)
	// 	{
	// 		push(a, b, 'b');
	// 		continue ;
	// 	}
	// 	else if ((*a)->value < (*b)->value)
	// 		push(a, b, 'b');
	// 	else
	// 	{
	// 		rev_rotate(a, 'a');
	// 	}
	// 	len--;
	// }
}


void	pop_sort(t_stack **a, t_stack **b)
{
	while(*a != NULL)
	{
		if (*b == NULL)
			push(a, b, 'b');
		if ((*b)->value > (*a)->value)
		{
			push(b, a, 'a');
			rotate(a, 'a');
		}
		else
		push(a, b, 'b');
	}
}