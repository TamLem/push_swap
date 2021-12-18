/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:17 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/18 20:27:09 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

#define BOTH_STACKS '2'

typedef struct	s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;

}				t_stack;

void	print_stacks(t_stack **a, t_stack **b);
t_stack	*init_stack(int count, char **input);
int		push(t_stack **src, t_stack **dest, char id);
int		rotate(t_stack **head, char id);
int		rev_rotate(t_stack **head, char id);
int		swap_head(t_stack **head, char id);
int		comb_oper(int (*oper)(t_stack **head, char id), t_stack **src1, t_stack **src2, char id);
int		peak_ahead(int val, t_stack *b);
int		get_len(t_stack *head);
int		peak_ahead(int val, t_stack *b);
void	sort(t_stack **a, t_stack **b);
int		ft_substrlen(char **s);
void	ft_error(char *msg);
int		ft_substrlen(char **s);
void	ft_error(char *msg);

#endif