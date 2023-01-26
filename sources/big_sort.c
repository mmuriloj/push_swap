/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:04:02 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 21:35:09 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(int max, int num, int max_bits, t_vars *vars)
{
	int	j;
	int	i;

	max = get_max_value(vars->stack_a.nums, vars->len_a);
	while ((max >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = -1;
		while (++j < vars->len_a + vars->len_b)
		{
			num = vars->stack_a.nums[0];
			if (((num >> i) & 1) == 1)
				rotate('a', vars);
			else
				push_b(0, vars);
		}
		while (vars->len_b != 0)
			push_a(0, vars);
		i++;
	}
}
