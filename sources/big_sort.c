/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:04:02 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/24 13:18:38 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int sorted_pos(int num, t_vars *vars)
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

void	big_sort(int i, t_vars *vars)
{
	int	len;

	len = vars->len_a + vars->len_b;
	vars->sorted_pos = ft_calloc((len), sizeof(int));
	if (!vars->sorted_pos)
		exit(EXIT_FAILURE);
	while (i++ < len)
		vars->sorted_pos[i - 1] = sorted_pos(vars->stack_a.nums[i-1], vars);
	i = -1;
	while (++i <= len)
		if (vars->stack_a.nums[0] < vars->sorted[len / 2])
			push_b(vars);
		else
			rotate('a', vars);
	while (vars->len_a > 3)
		push_b(vars);
	three_sort(vars);
	free(vars->sorted_pos);
}