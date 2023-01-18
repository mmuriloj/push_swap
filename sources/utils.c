/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:24:56 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/18 17:46:50 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_vars(t_vars *vars, char *argv[], int argc)
{
	int	i;

	vars->stack_a.nums = NULL;
	vars->stack_b.nums = NULL;
	vars->len_a = argc - 1;
	vars->len_b = 0;
	vars->sorted = ft_calloc(vars->len_a, sizeof(int));
	vars->stack_a.nums = ft_calloc(vars->len_a - 1, sizeof(int));
	if (!vars->sorted || !vars->stack_a.nums)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i <= vars->len_a)
	{
		vars->sorted[i - 1] = ft_atoi(argv[i]);
		vars->stack_a.nums[i - 1] = ft_atoi(argv[i]);
	}
	vars->min = get_min_value(vars->sorted, vars->len_a);
	vars->max = get_max_value(vars->sorted, vars->len_a);
	if (vars->min < 0)
	{
		i = -1;
		while (++i < vars->len_a)
			vars->sorted[i] = vars->sorted[i] - vars->min;
	}
}

/*
int *realloc_stack(int *stack, unsigned int len, int size)
{
	int		*new;
	size_t	i;

	new = ft_calloc(len, size);
	i = -1;
	while (stack[++i])
		new[i] = stack[i];
	free(stack);
	return (new);
}

int	stack_length(int *stack)
{
	int	len;

	len = 0;
	while (stack[len])
		len++;
	return (len);
	
}*/