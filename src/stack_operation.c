/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:24:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/05 19:29:31 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		push(t_stack **src, t_stack **dest, char id)
{	
	t_stack *temp;

	if (*src == NULL)
		return (0);
	temp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = temp;
	if (id != BOTH_STACKS)
		printf("p%c\n",id);
	return (1);
}

int		rotate(t_stack **head, char id)
{
	t_stack *temp;
	t_stack *tail;

	if ((*head) == NULL || (*head)->next == NULL)
		return (0);
	temp = *head;
	*head = (*head)->next;
	tail = *head;
	while(tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	temp->next = NULL;
	if (id != BOTH_STACKS)
		printf("r%c\n",id);
	return (1);
}

int		rev_rotate(t_stack **head, char id)
{
	t_stack *temp;
	t_stack *tail;
	t_stack *before_tail;

	if ((*head) == NULL || (*head)->next == NULL)
		return (0);
	temp = *head;
	before_tail = get_before_tail(head);
	tail = before_tail->next;
	before_tail->next = NULL;
	*head = tail;
	(*head)->next = temp;
	if (id != BOTH_STACKS)
		printf("rr%c\n",id);
	return (1);
}

int		swap_head(t_stack **head, char id)
{
	t_stack	*temp;

	if ((*head) == NULL || (*head)->next == NULL)
		return (0);
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if (id != BOTH_STACKS)
		printf("s%c\n",id);
	return (1);
}

int comb_oper(int (*oper)(t_stack **head, char id), t_stack **src1, t_stack **src2, char id)
{
	int res;

	if ((oper(src1, '2') + oper(src2, '2')) > 0)
	{
		if (id == 'R')
			printf("rrr\n");
		if (id == 'r')
			printf("rr\n");
		if (id == 's')
			printf("ss\n");
		return (1);
	}
	return (0);
}