/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:04:02 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 13:38:20 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sorted_pos(int num, t_vars *vars)
{
	int	pos;

	pos = 0;
	while (pos < vars->len_a + vars->len_b)
	{
		if (num == vars->sorted[pos])
			return (pos);
		pos++;
	}
	return (pos);
}

void	big_sort(int max_bits, t_vars *vars)
{
	int	j;
	int	i;
	int	max;
	int	num;

	i = -1;
	while (++i < vars->len_a)
		vars->stack_a.nums[i] = sorted_pos(vars->stack_a.nums[i], vars);
	max = get_max_value(vars->stack_a.nums, vars->len_a);
	while ((max >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < vars->len_a + vars->len_b)
		{
			num = vars->stack_a.nums[0];
			if (((num >> i) & 1) == 1)
				rotate('a', vars);
			else
				push_b(vars);
			j++;
		}
		while (vars->len_b != 0)
			push_a(vars);
		i++;
	}
}
