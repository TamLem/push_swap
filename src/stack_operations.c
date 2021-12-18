/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:24:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/18 20:21:39 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		push(t_stack **src_head, t_stack **dest_head, char id)
{	
	t_stack *old_head;

	if (*src_head == NULL)
		return (0);
	old_head = *dest_head;
	*dest_head = *src_head;
	if ((*src_head)->next == *src_head || (*src_head)->next == NULL)
		*src_head = NULL;
	else
	{
		(*src_head)->next->prev = (*src_head)->prev;
		(*src_head)->prev->next = (*src_head)->next;
		*src_head = (*src_head)->next;
	}
	if (old_head == NULL)
	{
		(*dest_head)->next = NULL;
		(*dest_head)->prev = NULL;
		if (id != BOTH_STACKS)
		printf("p%c\n",id);
		return (1);
	}
	(*dest_head)->next = old_head;
	if (old_head->prev == NULL && old_head->next == NULL)
	{
		(*dest_head)->prev = old_head;
		old_head->prev = *dest_head;
		old_head->next = *dest_head;
	}
	else
	{
		(*dest_head)->prev = old_head->prev;
		old_head->prev->next = *dest_head;
		old_head->prev = *dest_head;
	}
	
	if (id != BOTH_STACKS)
		printf("p%c\n",id);
	return (1);
}

int		rotate(t_stack **head, char id)
{
	if ((*head) == NULL || (*head)->next == NULL)
		return (0);
	*head = (*head)->next;
	if (id != BOTH_STACKS)
		printf("r%c\n",id);
	return (1);
}

int		rev_rotate(t_stack **head, char id)
{
	if ((*head) == NULL || (*head)->prev == NULL)
		return (0);
	*head = (*head)->prev;
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
	(*head)->prev = temp->prev;
	(*head)->prev->next = *head;
	temp->next = (*head)->next;
	temp->prev = *head;
	temp->next->prev = temp;
	(*head)->next = temp;
	if (id != BOTH_STACKS)
		printf("s%c\n",id);
	return (1);
}

int comb_oper(int (*oper)(t_stack **head, char id), t_stack **src1, t_stack **src2, char id)
{
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