/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:08:14 by mle-biha          #+#    #+#             */
/*   Updated: 2023/01/16 23:02:40 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[end];
	i = (start - 1);
	j = start;
	while (j < end)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
				swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pi;

	if (start < end)
	{
		pi = partition(arr, start, end);
		quick_sort(arr, start, pi - 1);
		quick_sort(arr, pi + 1, end);
	}
}
