/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:24:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/21 17:53:27 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	t_stack	*old_head;

	if ((*head) == NULL || (*head)->next == NULL)
		return (0);
	old_head = *head;
	*head = (*head)->next;
	(*head)->prev = old_head->prev;
	(*head)->prev->next = *head;
	old_head->prev = *head;
	old_head->next = (*head)->next;
	old_head->next->prev = old_head;
	(*head)->next = old_head;
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