/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:49:32 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/17 17:17:29 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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


t_stack	*init_stack(int count, char **input)
{
	int		i;
	static t_stack	a;
	t_stack	*temp;

	i = 0;
	a.value = ft_atoi(input[i]);
	a.next = NULL;
	a.prev = NULL;
	temp = &a;
	i++;
	while (i < count)
	{
		temp->next = (t_stack *)malloc(sizeof(t_stack));
		temp->next->value = ft_atoi(input[i++]);
		temp->next->prev = temp;
		temp->next->next = NULL;
		temp = temp->next;
	}
	temp->next = &a;
	a.prev = temp;
	return (&a);
}

t_stack	*get_before_tail(t_stack **head)
{
	t_stack *before_tail;

	before_tail = *head;
	while(before_tail->next->next != NULL && *head != NULL)
		before_tail = before_tail->next;
	return (before_tail);
}

t_stack	*get_tail(t_stack *head)
{
	t_stack *tail;

	tail = head;
	while(tail->next != NULL && head != NULL)
		tail = tail->next;
	return (tail);
}

/*
t_stack	*get_tail(t_stack **head)
{
	t_stack *tail;

	tail = *head;
	while(tail->next != NULL && *head != NULL)
		tail = tail->next;
	return (tail);
}
*/