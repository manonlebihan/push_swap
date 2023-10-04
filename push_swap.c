/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:36:46 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/18 13:09:28 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	int	val1;
	int	val2;

	val1 = (*stack)->value;
	val2 = ((*stack)->next)->value;
	if (val1 > val2)
		swap_stack(stack, "sa\n");
}

void	sort_three(t_stack **stack)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*stack)->value;
	val2 = ((*stack)->next)->value;
	val3 = (((*stack)->next)->next)->value;
	if (val1 > val2 && val2 < val3 && val1 < val3)
		swap_stack(stack, "sa\n");
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		reverse_rotate_stack(stack, "rra\n");
		swap_stack(stack, "sa\n");
	}
	else if (val1 > val2 && val1 > val3 && val2 < val3)
		rotate_stack(stack, "ra\n");
	else if (val1 < val2 && val1 > val3 && val2 > val3)
		reverse_rotate_stack(stack, "rra\n");
	else if (val1 > val2 && val2 > val3)
	{
		rotate_stack(stack, "ra\n");
		swap_stack(stack, "sa\n");
	}
}

int	tiny_sort(t_stack **stack)
{
	int	len;

	len = stack_len(*stack);
	if (stack_is_sorted(*stack))
		return (1);
	if (len == 2)
	{
		sort_two(stack);
		return (1);
	}
	else if (len == 3)
	{
		sort_three(stack);
		return (1);
	}
	return (0);
}

void	simple_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (!tiny_sort(stack_a))
	{
		min = get_min_index(*stack_a);
		if (min >= (stack_len(*stack_a) / 2))
		{
			while (min < stack_len(*stack_a))
			{
				reverse_rotate_stack(stack_a, "rra\n");
				min++;
			}
		}
		else
		{
			while (min > 0)
			{
				rotate_stack(stack_a, "ra\n");
				min--;
			}
		}
		stack_push_from_pop_to(stack_a, stack_b, "pb\n");
		simple_push_swap(stack_a, stack_b);
		stack_push_from_pop_to(stack_b, stack_a, "pa\n");
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	num;
	int	len;
	int	i;
	int	j;

	len = stack_len(*stack_a);
	i = 0;
	while (!stack_is_sorted(*stack_a))
	{
		j = 0;
		while (j < len)
		{
			num = stack_top(*stack_a);
			if (((num >> i) & 1) == 1)
				rotate_stack(stack_a, "ra\n");
			else
				stack_push_from_pop_to(stack_a, stack_b, "pb\n");
			j++;
		}
		while (!stack_empty(*stack_b))
			stack_push_from_pop_to(stack_b, stack_a, "pa\n");
		i++;
	}
}
