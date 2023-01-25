/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:37:31 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 18:46:51 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				bubble_swap(&arr[j], &arr[j + 1]);
			j++;
		}	
		i++;
	}	
}
