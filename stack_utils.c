/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:44:12 by mle-biha          #+#    #+#             */
/*   Updated: 2022/12/21 19:33:28 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	stack_top(t_stack *stack)
{
	if (stack != NULL)
		return (stack->value);
	return (-1);
}

int	stack_empty(t_stack *stack)
{
	return (stack == NULL);
}

int	stack_is_sorted(t_stack *stack)
{
	int	prev;

	prev = stack->value;
	while (stack != NULL)
	{
		if (prev > stack->value)
			return (0);
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}
