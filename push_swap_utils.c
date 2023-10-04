/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:07:12 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/17 16:22:49 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int val, int len, int *arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (val == arr[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_min_index(t_stack *stack)
{
	int	i;
	int	idx;
	int	min;

	i = 0;
	idx = 0;
	min = stack_top(stack);
	while (stack != NULL)
	{
		if (min >= stack->value)
		{
			min = stack->value;
			idx = i;
		}
		stack = stack->next;
		i++;
	}
	return (idx);
}

int	to_ordered_int_array(int *arr, int len)
{
	int	*sorted;
	int	i;

	i = 0;
	sorted = (int *)malloc(sizeof(int) * len);
	if (sorted == NULL)
		return (0);
	while (i < len)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort(sorted, 0, len - 1);
	i = 0;
	while (i < len)
	{
		arr[i] = get_index(arr[i], len, sorted);
		i++;
	}
	free(sorted);
	return (1);
}

t_stack	*to_stack(int *arr, int len)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (i < len)
	{
		push_bottom_stack(&stack, arr[i]);
		i++;
	}
	return (stack);
}
