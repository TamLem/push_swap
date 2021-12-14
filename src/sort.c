#include "../include/push_swap.h"

void	sort_2(t_stack **a, t_stack **b, int len)
{
	int max = 0;
	int min;
	int inner_iter = 2;
	int check = 0;


	if (*b == NULL || (*b)->next == NULL)
	{
		push(a, b, 'b');
		return ;
	}

	if (((*a)->value > (*b)->value && (*a)->value < (*b)->prev->value)
		|| ((*a)->value > (*b)->value && (*b)->value > (*b)->prev->value)
		|| ((*a)->value < (*b)->prev->value && (*b)->value > (*b)->prev->value))
		{
			push(a, b, 'b');
			return ;
		}

	int pa = peak_ahead((*a)->value, *b, 5);
	int pb = peak_back((*a)->value, *b, 5);

	// printf("Peak ahead %d\n", pa);
	// printf("Peak back %d\n", pb);
	if (pa != 0 && (pa <= pb || pb == 0))
	{
		rotate(b, 'b');
	}
	else if (pb != 0 && (pb <= pa || pa == 0))
	{
		rev_rotate(b, 'b');
	}
	else
		comb_oper(rotate, a, b, 'r');

	if (*a == NULL)
		return ; 
		
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