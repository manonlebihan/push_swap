/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:16:03 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/17 17:06:53 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void	swap_stack(t_stack **stack, char *label)
{
	int	first_val;
	int	second_val;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_val = pop_stack(stack);
	second_val = pop_stack(stack);
	push_stack(stack, first_val);
	push_stack(stack, second_val);
	ft_putstr(label);
}

void	rotate_stack(t_stack **stack, char *label)
{
	push_bottom_stack(stack, pop_stack(stack));
	ft_putstr(label);
}

void	reverse_rotate_stack(t_stack **stack, char *label)
{
	push_stack(stack, pop_bottom_stack(stack));
	ft_putstr(label);
}

void	stack_push_from_pop_to(t_stack **sf, t_stack **st, char *l)
{
	push_stack(st, pop_stack(sf));
	ft_putstr(l);
}
