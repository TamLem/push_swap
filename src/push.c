/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:24:03 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/22 23:17:30 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	put_to_b(t_stack *old_head, t_stack **dest_head, char id)
{
	if (old_head == NULL)
	{
		(*dest_head)->next = NULL;
		(*dest_head)->prev = NULL;
		if (id != NO_PRINT)
			ft_printf("p%c\n", id);
		return ;
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
		(*dest_head)->prev->next = *dest_head;
		old_head->prev = *dest_head;
	}
	if (id != NO_PRINT)
		ft_printf("p%c\n", id);
}

int	push(t_stack **src_head, t_stack **dest_head, char id)
{	
	t_stack	*old_head;

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
	put_to_b(old_head, dest_head, id);
	return (1);
}
