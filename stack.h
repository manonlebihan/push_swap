/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:50:31 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/17 17:43:09 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// stack management
void	push_stack(t_stack **stack, int val);
void	push_bottom_stack(t_stack **stack, int val);
int		pop_stack(t_stack **stack);
int		pop_bottom_stack(t_stack **stack);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);

// to move in the stack
void	swap_stack(t_stack **stack, char *label);
void	rotate_stack(t_stack **stack, char *label);
void	reverse_rotate_stack(t_stack **stack, char *label);
void	stack_push_from_pop_to(t_stack **sf, t_stack **st, char *l);

// stacks utils
int		stack_len(t_stack *stack);
int		stack_top(t_stack *stack);
int		stack_empty(t_stack *stack);
int		stack_is_sorted(t_stack *stack);

#endif
