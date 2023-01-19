/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:03:00 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/19 15:01:52 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_value(int *array, int n)
{
	int	i;
	int	max;

	max = array[0];
	i = 0;
	while (++i < n)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

int	get_min_value(int *array, int n)
{
	int	i;
	int	min;
	int	value;

	min = array[0];
	i = -1;
	while (++i < n)
	{
		value = array[i];
		if (value < min)
			min = array[i];
	}
	return (min);
}

// Main function to implement radix sort
void	radixsort(t_vars *vars)
{
	int	max;
	int	place;

	max = get_max_value(vars->sorted, vars->len_a);
	place = 1;
	while (max / place > 0)
	{
		countingsort(vars, place);
		place *= 10;
	}
}

// Print an array
void	print_sorted(t_vars *vars)
{
	int	i;

	printf("\nSorted:\n");
	i = -1;
	while (++i < vars->len_a)
	{
		if (vars->min < 0)
			vars->sorted[i] = vars->sorted[i] + vars->min;
		else
			vars->sorted[i] = vars->sorted[i];
	}
	i = -1;
	while (++i < vars->len_a)
		printf("%d ", vars->sorted[i]);
	printf("\n\n");
}
