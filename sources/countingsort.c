/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countingsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:37:31 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/16 16:25:51 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	cumulative_arr(t_vars *vars, int *count_arr, int digit, int place)
{
	int	i;

	i = -1;
	while (++i < vars->n_elem)
		count_arr[(vars->sorted[i] / place) % 10]++;
	i = 0;
	while (++i < digit + 1)
		count_arr[i] += count_arr[i - 1];
}

static int	find_biggest_digit(t_vars *vars, int place)
{
	int	i;
	int	big_digit;

	big_digit = (vars->sorted[0] / place) % 10;
	i = 0;
	while (++i < vars->n_elem)
	{
		if (((vars->sorted[i] / place) % 10) > big_digit)
			big_digit = vars->sorted[i];
	}
	return (big_digit);
}

// Using counting sort to sort the elements in the basis of significant places
void	countingsort(t_vars *vars, int place)
{
	int	i;
	int	biggest_digit;
	int	*out;
	int	*count_array;

	biggest_digit = (vars->sorted[0] / place) % 10;
	out = ft_calloc(vars->n_elem + 1, sizeof(int));
	if (!out)
		exit(EXIT_FAILURE);
	biggest_digit = find_biggest_digit(vars, place);
	count_array = ft_calloc(biggest_digit + 1, sizeof(int));
	if (!count_array)
		exit(EXIT_FAILURE);
	cumulative_arr(vars, count_array, biggest_digit, place);
	i = vars->n_elem;
	while (--i >= 0)
	{
		out[count_array[(vars->sorted[i] / place) % 10] - 1] = vars->sorted[i];
		count_array[(vars->sorted[i] / place) % 10]--;
	}
	i = -1;
	while (++i < vars->n_elem)
		vars->sorted[i] = out[i];
	free(out);
	free(count_array);
}
