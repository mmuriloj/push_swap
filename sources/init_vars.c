/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:24:56 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/23 10:21:46 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_vars(t_vars *vars, char *argv[], int argc)
{
	int i;

	vars->n_elem = argc - 1;
	//vars->array = malloc((vars->n_elem - 1) * sizeof(int));
	vars->array = ft_calloc(vars->n_elem, sizeof(int));
	if (!vars->array)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i <= vars->n_elem)
	{
		vars->array[i-1] = ft_atoi(argv[i]);
	}
	vars->min = get_min_value(vars->array, vars->n_elem);
	vars->max = get_max_value(vars->array, vars->n_elem);
	if (vars->min < 0)
	{
		i = -1;
		while (++i < vars->n_elem)
			vars->array[i] = vars->array[i] - vars->min;
	}
}