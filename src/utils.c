/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:49:32 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/04 17:49:52 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("|_%d_|\n", temp->value);
		temp = temp->next;
	}
}

t_stack	*init_stack(int count, char **input)
{
	int		i;
	t_stack	*a;
	t_stack	*temp;

	i = 0;
	a->value = ft_atoi(input[i]);
	a->next = NULL;
	temp = a;
	i++;
	while (i < count)
	{
		temp->next = (t_stack *)malloc(sizeof(t_stack));
		temp->next->value = ft_atoi(input[i++]);
		temp->next->next = NULL;
		temp = temp->next;
	}
	
	return (a);
}