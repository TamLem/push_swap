/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:18:37 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/23 04:27:00 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	is_sorted(t_stack *a)
{
	int	start;

	if (a == NULL || a->next == NULL)
		return (0);
	start = a->value;
	while (a->next->value != start)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	init_single(char *next, char **nums, t_stack **temp)
{
	int	i;

	i = 0;
	while (nums[i] != NULL)
	{
		(*temp)->value = ft_atoi(nums[i]);
		if (next == NULL && nums[i + 1] == NULL)
			return (0);
		(*temp)->next = (t_stack *)malloc(sizeof(t_stack));
		if ((*temp)->next == NULL)
			return (0);
		(*temp) = (*temp)->next;
		i++;
	}
	return (1);
}

void	init_stack(int count, char **input, t_stack **a)
{
	int		i;
	t_stack	*temp;
	char	**nums;

	i = 0;
	temp = *a;
	while (i < count)
	{
		nums = ft_split(input[i], ' ');
		if (!check_input(nums))
			ft_error("Error");
		init_single(input[i + 1], nums, &temp);
		free_dp(nums);
		free(nums);
		i++;
	}
	if (temp == *a)
		return ;
	temp->next = *a;
	(*a)->prev = temp;
	temp = (*a)->next;
	temp->prev = *a;
	while (temp != *a)
	{
		temp->next->prev = temp;
		temp = temp->next;
	}
}
