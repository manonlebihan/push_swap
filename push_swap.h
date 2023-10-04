/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:36:55 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/17 16:17:37 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "quick_sort.h"
# include "libft.h"
# include <limits.h>

// push swap utils
int		get_index(int val, int argc, int *arr);
int		get_min_index(t_stack *stack);
int		to_ordered_int_array(int *arr, int len);
t_stack	*to_stack(int *arr, int len);

// push swap
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	simple_push_swap(t_stack **stack_a, t_stack **stack_b);

#endif