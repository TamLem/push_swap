/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:00:59 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/23 02:04:50 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	isvalidstr(char *s)
{
	int	i;
	int	foundnum;

	i = 0;
	foundnum = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			foundnum = 1;
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
				|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'
				|| s[i] == '+' || s[i] == '-'))
			if (!foundnum)
				return (0);
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **nums)
{
	char	*num;

	while (*nums)
	{
		num = *nums;
		if (!isvalidstr(num))
			return (0);
		if (ft_atoi(num) > INT_MAX || ft_atoi(num) < INT_MIN)
			return (0);
		while (*num)
		{
			if (!ft_isdigit(*num) && *num != ' ' && *num != '-')
				return (0);
			num++;
		}
		nums++;
	}
	return (1);
}

void	free_dp(char **i)
{
	while (*i)
	{
		free(*i);
		i++;
	}
}

void	free_stacks(t_stack **a, t_stack **head)
{
	if ((*a)->next != *head)
		free_stacks(&((*a)->next), head);
}

int	check_duplicates(t_stack *a)
{
	t_stack	*temp;
	int		last;

	last = a->prev->value;
	if (a->value == last)
		return (0);
	while (a->value != last)
	{
		temp = a;
		if (temp->value == last)
			return (0);
		while (temp->value != last)
		{
			temp = temp->next;
			if (temp->value == a->value)
				return (0);
		}
		a = a->next;
	}
	return (1);
}
