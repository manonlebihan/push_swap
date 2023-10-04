/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:04:12 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/17 17:42:29 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_stack(t_stack **stack, int val)
{
	t_stack	*new_node;

	if (stack != NULL)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (new_node == NULL)
			return ;
		new_node->value = val;
		new_node->next = *stack;
		*stack = new_node;
	}
}

void	push_bottom_stack(t_stack **stack, int val)
{
	t_stack	*new;
	t_stack	*old;

	if (stack != NULL)
	{
		new = NULL;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (new != NULL)
		{
			new->value = val;
			new->next = NULL;
			if (*stack == NULL)
				*stack = new;
			else
			{
				old = *stack;
				while (old->next != NULL)
					old = old->next;
				old->next = new;
			}
		}
	}
}

int	pop_stack(t_stack **stack)
{
	int		ret;
	t_stack	*old;
	t_stack	*new;

	ret = 0;
	if (stack != NULL && *stack != NULL)
	{
		old = *stack;
		new = old->next;
		ret = old->value;
		free(old);
		old = NULL;
		*stack = new;
	}
	return (ret);
}

int	pop_bottom_stack(t_stack **stack)
{
	int		ret;
	t_stack	*old;
	t_stack	*prev;

	ret = 0;
	if (stack != NULL && *stack != NULL)
	{
		old = *stack;
		prev = NULL;
		while (old->next != NULL)
		{
			prev = old;
			old = old->next;
		}
		ret = old->value;
		free(old);
		old = NULL;
		if (prev != NULL)
			prev->next = NULL;
	}
	return (ret);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
	{
		while (*stack_a != NULL)
			pop_stack(stack_a);
	}
	if (stack_b != NULL && *stack_b != NULL)
	{
		while (*stack_b != NULL)
			pop_stack(stack_b);
	}
}
