/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:24:56 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/16 16:24:31 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_vars(t_vars *vars, char *argv[], int argc)
{
	int	i;

	vars->stack_b.nums = NULL;
	vars->n_elem = argc - 1;
	vars->sorted = ft_calloc(vars->n_elem, sizeof(int));
	vars->stack_a.nums = ft_calloc(vars->n_elem, sizeof(int));
	if (!vars->sorted || !vars->stack_a.nums)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i <= vars->n_elem)
	{
		vars->sorted[i - 1] = ft_atoi(argv[i]);
		vars->stack_a.nums[i - 1] = ft_atoi(argv[i]);
	}
	vars->min = get_min_value(vars->sorted, vars->n_elem);
	vars->max = get_max_value(vars->sorted, vars->n_elem);
	if (vars->min < 0)
	{
		i = -1;
		while (++i < vars->n_elem)
			vars->sorted[i] = vars->sorted[i] - vars->min;
	}
}
