/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:02:17 by tlemma            #+#    #+#             */
/*   Updated: 2021/12/13 19:17:33 by tlemma           ###   ########.fr       */
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
t_stack	*get_tail(t_stack *head);
t_stack	*get_before_tail(t_stack **head);
int		push(t_stack **src, t_stack **dest, char id);
int		rotate(t_stack **head, char id);
int		rev_rotate(t_stack **head, char id);
int		swap_head(t_stack **head, char id);
int		comb_oper(int (*oper)(t_stack **head, char id), t_stack **src1, t_stack **src2, char id);
void	pop_sort(t_stack **a, t_stack **b);
void	init_scan(t_stack **a, t_stack **b, int len);
void	sort_2(t_stack **a, t_stack **b, int len);
int		peak_ahead(int val, t_stack *b, int len);
int		get_len(t_stack *head);




#endif