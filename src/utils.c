/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:49:32 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/21 17:18:05 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (-1);
}

int	is_sorted(t_stack *a)
{
	int	start;

	start = a->value;
	while (a->next->value != start)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_substrlen(char **s)
{
	int	i;

	i = 0;
	while (*s != NULL)
	{
		s++;
		i++;
	}
	return (i);
}

int		get_len(t_stack *head)
{
	int len;
	int head_val;

	len = 0;
	if (head == NULL)
		return (len);	
	len++;
	head_val = head->value;
	while (head->next != NULL && head->next->value != head_val)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	print_stacks(t_stack **a_stack, t_stack **b_stack)
{
	int lines;
	t_stack *a;
	t_stack *b;
	int		len_a;
	int		len_b;

	a = *a_stack;
	b = *b_stack;
	len_a = get_len(a);
	len_b = get_len(b);
	lines = 55;
	FILE *fptr = fopen("stack.txt", "w");
	fprintf(fptr, "\n\nStack a\t\tStack b\n\n");
	while (lines-- > 0)
	{
		if (a != NULL && len_a-- > 0)
		{
			fprintf(fptr, "|_%d_|\t\t", a->value);
			a = a->next;
		}
		else 
			fprintf(fptr, "|____|\t\t");
		if (b != NULL && len_b-- > 0)
		{
			fprintf(fptr, "|_%d_|", b->value);
			b = b->next;
		}
		else
			fprintf(fptr, "|____|");
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}


void	init_stack(int count, char **input, t_stack **a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	(*a)->value = ft_atoi(input[i]);
	(*a)->next = NULL;
	(*a)->prev = NULL;
	temp = *a;
	i++;
	while (i < count)
	{
		temp->next = (t_stack *)malloc(sizeof(t_stack));
		temp->next->value = ft_atoi(input[i++]);
		temp->next->prev = temp;
		temp->next->next = NULL;
		temp = temp->next;
	}
	temp->next = *a;
	(*a)->prev = temp;
}
