/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:00:19 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/17 23:36:43 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "push_swap.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if ((ft_strlen(str) == 1 && (str[i] == '-' || str[i] == '+'))
		|| (ft_strlen(str) == 2 && (str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+')) || str[i] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	return_free(int ret, int *to_free)
{
	if (to_free != NULL)
		free(to_free);
	return (ret);
}

int	check_args(int **argv_int, int argc, char *argv[])
{
	int	i;

	i = 1;
	*argv_int = (int *)malloc(sizeof(int) * (argc - 1));
	if (*argv_int == NULL)
		return (0);
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (return_free(0, *argv_int));
		(*argv_int)[i - 1] = ft_atoi(argv[i]);
		if ((ft_strlen(argv[i]) > 11
				|| (argv[i][0] == '-' && (*argv_int)[i - 1] > 0))
				|| (argv[i][0] != '-' && (*argv_int)[i - 1] < 0))
			return (return_free(0, *argv_int));
		i++;
	}
	if (has_duplicate(*argv_int, argc - 1))
		return (return_free(0, *argv_int));
	if (to_ordered_int_array(*argv_int, (argc - 1)) == 0)
	{
		free(*argv_int);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*argv_int;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		return (0);
	if (check_args(&argv_int, argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = to_stack(argv_int, (argc - 1));
	if (stack_a == NULL)
	{
		free(argv_int);
		return (0);
	}
	if (argc < 10)
		simple_push_swap(&stack_a, &stack_b);
	else
		push_swap(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	free(argv_int);
}
