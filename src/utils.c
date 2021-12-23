/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:49:32 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/23 01:25:43 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit (-1);
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

int	get_len(t_stack *head)
{
	int	len;
	int	head_val;

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
