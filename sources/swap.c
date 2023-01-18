/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:32 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/18 17:52:58 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char c, t_vars *vars)
{
	int	aux;

	if (c == 'a')
	{
		if (vars->len_a < 2)
			return ;
		aux = vars->stack_a.nums[0];
		vars->stack_a.nums[0] = vars->stack_a.nums[1];
		vars->stack_a.nums[1] = aux;
		ft_printf("sa\n");
	}
	else
	{
		if (vars->len_b < 2)
			return ;
		aux = vars->stack_b.nums[0];
		vars->stack_b.nums[0] = vars->stack_b.nums[1];
		vars->stack_b.nums[1] = aux;
		ft_printf("sb\n");
	}
}

void	swap_both(t_vars vars)
{
	swap('a', &vars);
	swap('b', &vars);
}
