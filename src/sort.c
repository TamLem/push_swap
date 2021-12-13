#include "../include/push_swap.h"

void	sort_2(t_stack **a, t_stack **b, int len)
{
	int max = 0;
	int min;
	int inner_iter = 2;
	int check = 0;


	if (*b == NULL)
		push(a, b, 'b');

	if((*a)->value > (*b)->value)
	{
		if(!((*a)->value > (*b)->prev->value) || !((*b)->value < (*b)->prev->value))
		{
			// printf("1\n");
			push(a, b, 'b');
			return ;
		}
		if (get_tail(*a)->value > get_tail(*b)->value)
			comb_oper(rev_rotate, a, b, 'R');
		else
			rev_rotate(b, 'b');
	}
	if (*a == NULL)
		return ; 
	
	if ((*a)->value < (*b)->value) 
	{
		
		if ((*a)->value > (*b)->next->value 
			|| (*b)->value < (*b)->next->value)
		{
			rotate(b, 'b');
			push(a, b, 'b');
			return ;
		}
		// if ((*a)->next == NULL || peak_ahead((*a)->value, (*b)->next, 5) )
		// {
		// 	rotate(b, 'b');
		// }
		// else
			rotate(b, 'b');
			// comb_oper(rotate, a, b, 'r');
	}
		
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